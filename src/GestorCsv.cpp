#include "GestorCsv.h"
// FIXME: LA LECTURA DE ARCHIVOS CON GETLINE FUNCIONA HORRIBLEMENTE, NO TENEMOS IDEA DE POR QUÉ
vector<int> GestorCsv::leerProgramasCsv(string &ruta)
{
    vector<int> codigosSniesRetorno;
    ifstream archivoProgramasCsv(ruta);
    if (!(archivoProgramasCsv.is_open()))
    {
        cout << "Archivo " << ruta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string linea;
        string dato;
        // Mantenimiento (Revisión): Se puede mejorar la lectura de archivos con getline y
        // No debería saltarse la primera linea para así determinar qué está leyendo.
        // Saltarse la primera linea
        getline(archivoProgramasCsv, linea);
        // Leer los programas
        while (getline(archivoProgramasCsv, linea))
        {
            stringstream streamLinea(linea);
            getline(streamLinea, dato, ';');
            // Manteniemiento: Se puede mejorar la forma de leer los datos de la línea y
            // los nombres de los métodos y variables.
            codigosSniesRetorno.push_back(stoi(dato));
        }
    }
    archivoProgramasCsv.close();
    return codigosSniesRetorno;
}

// Complejidad: Este metodo tiene una alta complejidad ciclomática y computacional, reducir en metodos más pequeños
// Estructuras de control anidadas profundamente.
vector<vector<string>> GestorCsv::leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies)
// Esta función retorna matriz con todos los valores encontrados en el archivo
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";

    map <string, int> posicionesColumnasMap = conseguirPosicionesColumnas(rutaCompleta);
    int POS_COD_SNIES = posicionesColumnasMap["CÓDIGO_SNIES_DEL_PROGRAMA"];
    int TAMANIO_ARCHIVO = conseguirCantColumnas(posicionesColumnasMap) + 1;

    ifstream archivoPrimero(rutaCompleta);
    if (!(archivoPrimero.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila;
        stringstream streamFila;
        int columna;
        vector<int>::iterator it;

        // Primera iteracion del ciclo para guardar las etiquetas
        getline(archivoPrimero, fila);
        vectorFila = vector<string>(TAMANIO_ARCHIVO);
        streamFila = stringstream(fila);
        columna = 0;
        while ((getline(streamFila, dato, ';')))
        {

            vectorFila[columna] = dato;
            columna++;
        }
        matrizResultado.push_back(vectorFila);

        // Leer el resto del archivo
        while (getline(archivoPrimero, fila))
        {
            streamFila = stringstream(fila);
            columna = 0;
            while ((getline(streamFila, dato, ';')) && (columna <= POS_COD_SNIES))
            {
                vectorFila[columna] = dato;
                columna++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[POS_COD_SNIES] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[12]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso donde si estaba dentro de los programas que me interesan
            {
                // Termino de leer y guardar primera fila
                vectorFila[columna] = dato; // Guardamos el dato que habiamos geteado justo antes de hacer la verificacion
                columna++;
                while ((getline(streamFila, dato, ';')))
                {
                    vectorFila[columna] = dato;
                    columna++;
                }
                matrizResultado.push_back(vectorFila);

                // Leo y guardo filas restantes
                for (int j = 0; j < 3; j++)
                {
                    getline(archivoPrimero, fila);
                    streamFila = stringstream(fila);
                    columna = 0;
                    while ((getline(streamFila, dato, ';')))
                    {
                        vectorFila[columna] = dato;
                        columna++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Si es de los programas que no me interesan, sigo a la siguiente fila, sin guardar la fila en la matriz de resultados
        }
    }

    archivoPrimero.close();

    return matrizResultado;
}

// Complejidad: Este metodo tiene una alta complejidad ciclomática y computacional, reducir en metodos más pequeños
// Parece hacer lo mismo que el metodo leerArchivoPrimera

vector<vector<string>> GestorCsv::leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies)
// Esta función retorna matriz con valores del consolidado
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";

    map <string, int> posicionesColumnasMap = conseguirPosicionesColumnas(rutaCompleta);
    int POS_COD_SNIES = posicionesColumnasMap["CÓDIGO_SNIES_DEL_PROGRAMA"];
    int POS_ULTIMA_COLUMNA = posicionesColumnasMap["SEMESTRE"] + 1;
    int POS_ID_SEXO = posicionesColumnasMap["ID_SEXO"];

    ifstream archivoSegundo(rutaCompleta);
    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila(6);
        stringstream streamFila;
        int columnaArchivo;
        int columnaVector;
        vector<int>::iterator it;

        // Nos saltamos las etiquetas para no interferir en el bucle
        getline(archivoSegundo, fila);

        // Leemos las filas
        while (getline(archivoSegundo, fila))
        {
            streamFila = stringstream(fila);
            columnaArchivo = 0;
            columnaVector = 0;
            while (getline(streamFila, dato, ';') && columnaArchivo < POS_COD_SNIES + 1)
            {
                if (columnaArchivo == POS_COD_SNIES)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
                columnaArchivo++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[0] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso cuando SI es parte de los que me interesan
            {
                // Termino de leer y guardar primera fila
                columnaArchivo++; // Esto se debe a la iteracion en que hacemos getline sin subirle a la columaArchivo porque nos salimos del bucle
                while (getline(streamFila, dato, ';'))
                {
                    if (columnaArchivo >= POS_ID_SEXO)
                    {
                        vectorFila[columnaVector] = dato;
                        columnaVector++;
                    }
                    columnaArchivo++;
                }

                // TODO: AQUI CREAR EL PUNTERO DE CONSOLIDADO Y AGREGARLO EN EL MAPA AL PROGRAMA ACADÉMICO QUE CORRESPONDE
                // TODO: EDITAR EL CONSOLIDADO CON LOS VALORES DE LA FILA QUE ACABAMOS DE LEER.

                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, ';'))
                    {
                        if ((columnaArchivo >= POS_ID_SEXO) || (columnaArchivo == POS_COD_SNIES))
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Cuando no me interesa no hago nada
        }
    }

    archivoSegundo.close();

    return matrizResultado;
}

vector<vector<string>> GestorCsv::leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies)
// Esta función retorna únicamente el valor de la última columna de cada archivo
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";

    map <string, int> posicionesColumnasMap = conseguirPosicionesColumnas(rutaCompleta);
    int POS_COD_SNIES = posicionesColumnasMap["CÓDIGO_SNIES_DEL_PROGRAMA"];
    // FIXME: Buscar una forma para que la posición de la última columna no tenga que estar obligatoriamente a la derecha de semestre.
    int POS_ULTIMA_COLUMNA = posicionesColumnasMap["SEMESTRE"] + 1;

    ifstream archivoSegundo(rutaCompleta);
    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila(2);
        stringstream streamFila;
        int columnaArchivo;
        int columnaVector;
        vector<int>::iterator it;

        // Nos saltamos las etiquetas para no interferir en el bucle
        getline(archivoSegundo, fila);

        // Leemos las filas
        while (getline(archivoSegundo, fila))
        {
            streamFila = stringstream(fila);
            columnaArchivo = 0;
            columnaVector = 0;
            while ((getline(streamFila, dato, ';')) && (columnaArchivo < (POS_COD_SNIES + 1)))
            {
                if (columnaArchivo == POS_COD_SNIES)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
                columnaArchivo++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[0] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso cuando SI es parte de los que me interesan
            {
                // Terminar de leer primera fila
                while (getline(streamFila, dato, ';'))
                {
                    vectorFila[columnaVector] = dato;
                }

                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;

                    while (getline(streamFila, dato, ';') && columnaArchivo < POS_ULTIMA_COLUMNA)
                    {
                        if (columnaArchivo == POS_COD_SNIES)
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    vectorFila[columnaVector] = dato;
                    matrizResultado.push_back(vectorFila);
                }
            }

        }
    }


    archivoSegundo.close();

    return matrizResultado;
}

vector<string> GestorCsv::leerEtiquetasArchivo(ifstream &archivo, int CANT_COLUMNAS_ARCHIVO)
{
    string fila;
    string dato;
    vector<string> vectorFila;
    stringstream streamFila;
    int columna;

    vectorFila = vector<string>(CANT_COLUMNAS_ARCHIVO);
    streamFila = stringstream(fila);
    columna = 0;
    while ((getline(streamFila, dato, ';')))
    {

        vectorFila[columna] = dato;
        columna++;
    }

    return vectorFila;
}

vector<vector<string>> GestorCsv::leerArchivoFinal(string &rutaBase, string &ano, map<int, ProgramaAcademico *>  &mapaProgramasAcademicos, bool &primeraVez, string &atributoAModificar)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";

    map <string, int> posicionesColumnasMap = conseguirPosicionesColumnas(rutaCompleta);
    int POS_COD_SNIES = posicionesColumnasMap["CÓDIGO_SNIES_DEL_PROGRAMA"];
    int POS_ID_SEXO = posicionesColumnasMap["ID_SEXO"];
    int POS_SEXO = posicionesColumnasMap["SEXO"];
    int POS_ANIO = posicionesColumnasMap["AÑO"];
    int POS_SEMESTRE = posicionesColumnasMap["SEMESTRE"];
    int POS_ULTIMA_COLUMNA = POS_SEMESTRE + 1;
    int TAMANIO_ARCHIVO = conseguirCantColumnas(posicionesColumnasMap) + 1;

    ifstream archivo(rutaCompleta);

    // FIXME: MANEJAR EL ERROR BIEN. NO SOLO IMPRIMIENDO. Y ASÍ BORRAR EL else{}
    if (!(archivo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila;
        stringstream streamFila;
        int columna;
        string codSniesActual;
        // vector<int>::iterator it;
        size_t existeEnMapaProgsAcademicos;
        size_t existeEnMapaConsolidados;

        // Primera iteracion del ciclo para leer las etiquetas
        getline(archivo, fila);

        // Si es la primera lectura, guardamos las etiquetas y la agregamos a la matriz de resultados
        if (primeraVez)
        {
            vector<string> vectorConEtiquetas = leerEtiquetasArchivo(archivo, TAMANIO_ARCHIVO);
            matrizResultado.push_back(vectorConEtiquetas);
        }
        // Si no es la primera lectura, no agregamos nada a la matriz de resultados.


        // Leer el resto del archivo
        while (getline(archivo, fila))
        {
            streamFila = stringstream(fila);
            columna = 0;
            while ((getline(streamFila, dato, ';')) && (columna <= POS_COD_SNIES))
            {
                vectorFila[columna] = dato;
                columna++;
            }

            codSniesActual = vectorFila[POS_COD_SNIES];
            // Verificamos que la fila no sea una fila de error
            if (codSniesActual != "Sin programa especifico")
            {
                existeEnMapaProgsAcademicos = mapaProgramasAcademicos.count(stoi(codSniesActual));
            }
            else
            {
                existeEnMapaProgsAcademicos = 0;
            }

            // Verificar si hace parte de los programas que me interesan
            if (existeEnMapaProgsAcademicos) // Caso donde si está dentro de los programas que me interesan
            {
                // Termino de leer y guardar primera fila
                vectorFila[columna] = dato; // Guardamos el dato que habiamos geteado justo antes de hacer la verificacion
                columna++;
                while ((getline(streamFila, dato, ';')))
                {
                    vectorFila[columna] = dato;
                    columna++;
                }

                int COD_SNIES = stoi(vectorFila[POS_COD_SNIES]);
                int ID_SEXO = stoi(vectorFila[POS_ID_SEXO]);
                string SEXO = vectorFila[POS_SEXO];
                int ANIO = stoi(vectorFila[POS_ANIO]);
                int SEMESTRE = stoi(vectorFila[POS_SEMESTRE]);
                int ULTIMA_COLUMNA = stoi(vectorFila[POS_ULTIMA_COLUMNA]);

                // Accedemos al ProgramaAcademico * desde el mapa
                ProgramaAcademico * progAcademicoActual = mapaProgramasAcademicos[COD_SNIES];
                // FIXME: CAMBIAR EL NOMBRE DE LA FUNCION getMapConsolidado POR getConsolidadoDeMapa cuando acabe de hacer toda la transición de vector a mapa
                Consolidado * consolidadoActual = progAcademicoActual->getMapConsolidados(ANIO, ID_SEXO, SEMESTRE);

                // En caso de que el consolidado no exista, se crea uno y se settea en el mapa
                if (consolidadoActual == nullptr)
                {
                    consolidadoActual = new Consolidado(ID_SEXO, SEXO, ANIO, SEMESTRE);
                    // Setteamos el consolidado en el mapa existente
                    progAcademicoActual -> setMapConsolidados(ANIO, ID_SEXO, SEMESTRE, consolidadoActual);
                }

                if (atributoAModificar == "admitidos") {
                    consolidadoActual -> setAdmitidos(ULTIMA_COLUMNA);
                }
                else if (atributoAModificar == "inscritos") {
                    consolidadoActual -> setInscritos(ULTIMA_COLUMNA);
                }
                else if (atributoAModificar == "matriculados") {
                    consolidadoActual -> setMatriculados(ULTIMA_COLUMNA);
                }
                else if (atributoAModificar == "neos") {
                    consolidadoActual -> setMatriculadosPrimerSemestre(ULTIMA_COLUMNA);
                }
                else if (atributoAModificar == "graduados") {
                    consolidadoActual -> setGraduados(ULTIMA_COLUMNA);
                }

                // TODO: AQUI CREAR EL CONSOLIDADO Y AGREGARLO A mapaProgramasAcademicos QUE LE CORRESPONDE
                // TODO: EDITAR EL CONSOLIDADO CON LOS VALORES DE LA FILA QUE ACABAMOS DE LEER.
                // TODO: CREAR UN MAPA Y AGREGAR LOS VALORES GUARDADOS NO A UN VECTOR SINO A UN MAPA PARA LUEGO DE AHÍ SETTEAR LA INFORMACIÓN. SE PUEDE? COMO SE SETTEARÍAN?


                // Leo y guardo filas restantes
                for (int j = 0; j < 3; j++)
                {
                    getline(archivo, fila);
                    streamFila = stringstream(fila);
                    columna = 0;
                    while ((getline(streamFila, dato, ';')))
                    {
                        vectorFila[columna] = dato;
                        columna++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Si es de los programas que no me interesan, sigo a la siguiente fila, sin guardar la fila en la matriz de resultados
        }
    }

    archivo.close();

    // FIXME: PARECE QUE NO SE NECESITA EXPORTAR NADA.
    return matrizResultado;
}

bool GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << ";";
        }
        archivoResultados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        map<int, ProgramaAcademico *>::iterator it;
        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Imprimimos cada uno de los 8 consolidados por programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos toda la información base del programa academico
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << ";";
                archivoResultados << (it->second)->getIesPadre() << ";";
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << ";";
                archivoResultados << (it->second)->getPrincipalOSeccional() << ";";
                archivoResultados << (it->second)->getIdSectorIes() << ";";
                archivoResultados << (it->second)->getSectorIes() << ";";
                archivoResultados << (it->second)->getIdCaracter() << ";";
                archivoResultados << (it->second)->getCaracterIes() << ";";
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << ";";
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << ";";
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << ";";
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << ";";
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << ";";
                archivoResultados << (it->second)->getProgramaAcademico() << ";";
                archivoResultados << (it->second)->getIdNivelAcademico() << ";";
                archivoResultados << (it->second)->getNivelAcademico() << ";";
                archivoResultados << (it->second)->getIdNivelDeFormacion() << ";";
                archivoResultados << (it->second)->getNivelDeFormacion() << ";";
                archivoResultados << (it->second)->getIdMetodologia() << ";";
                archivoResultados << (it->second)->getMetodologia() << ";";
                archivoResultados << (it->second)->getIdArea() << ";";
                archivoResultados << (it->second)->getAreaDeConocimiento() << ";";
                archivoResultados << (it->second)->getIdNucleo() << ";";
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << ";";
                archivoResultados << (it->second)->getIdCineCampoAmplio() << ";";
                archivoResultados << (it->second)->getDescCineCampoAmplio() << ";";
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << ";";
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << ";";
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << ";";
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << ";";
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << ";";
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << ";";
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << ";";
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << ";";

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << ";";
                archivoResultados << consolidadoActual->getSexo() << ";";
                archivoResultados << consolidadoActual->getAno() << ";";
                archivoResultados << consolidadoActual->getSemestre() << ";";
                archivoResultados << consolidadoActual->getAdmitidos() << ";";
                archivoResultados << consolidadoActual->getGraduados() << ";";
                archivoResultados << consolidadoActual->getInscritos() << ";";
                archivoResultados << consolidadoActual->getMatriculados() << ";";
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.csv";
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {

        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << ";";
        }
        archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << ";";
                archivoBuscados << (*it)->getIesPadre() << ";";
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << ";";
                archivoBuscados << (*it)->getPrincipalOSeccional() << ";";
                archivoBuscados << (*it)->getIdSectorIes() << ";";
                archivoBuscados << (*it)->getSectorIes() << ";";
                archivoBuscados << (*it)->getIdCaracter() << ";";
                archivoBuscados << (*it)->getCaracterIes() << ";";
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << ";";
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << ";";
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << ";";
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << ";";
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << ";";
                archivoBuscados << (*it)->getProgramaAcademico() << ";";
                archivoBuscados << (*it)->getIdNivelAcademico() << ";";
                archivoBuscados << (*it)->getNivelAcademico() << ";";
                archivoBuscados << (*it)->getIdNivelDeFormacion() << ";";
                archivoBuscados << (*it)->getNivelDeFormacion() << ";";
                archivoBuscados << (*it)->getIdMetodologia() << ";";
                archivoBuscados << (*it)->getMetodologia() << ";";
                archivoBuscados << (*it)->getIdArea() << ";";
                archivoBuscados << (*it)->getAreaDeConocimiento() << ";";
                archivoBuscados << (*it)->getIdNucleo() << ";";
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << ";";
                archivoBuscados << (*it)->getIdCineCampoAmplio() << ";";
                archivoBuscados << (*it)->getDescCineCampoAmplio() << ";";
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << ";";
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << ";";
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << ";";
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << ";";
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << ";";
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << ";";
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << ";";
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << ";";

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << ";";
                archivoBuscados << consolidadoActual->getSexo() << ";";
                archivoBuscados << consolidadoActual->getAno() << ";";
                archivoBuscados << consolidadoActual->getSemestre() << ";";
                archivoBuscados << consolidadoActual->getAdmitidos() << ";";
                archivoBuscados << consolidadoActual->getGraduados() << ";";
                archivoBuscados << consolidadoActual->getInscritos() << ";";
                archivoBuscados << consolidadoActual->getMatriculados() << ";";
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creo el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.csv";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Imprimimos la matriz de datos que queremos imprimir
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Imprimimos cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Imprimimos cada dato separado por ';'
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << ";";
                }
            }
            // Saltamos de linea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}

map<string, int> GestorCsv::conseguirPosicionesColumnas(string &rutaArchivo) {
    // TODO: agregar las claves sin espacio y todo en mayúsculas
    map<string, int> mapaConPosiciones;


    ifstream archivo(rutaArchivo);
    // TODO: manejar la excepción. Throw a dónde? Al SNIESController?
    if (!(archivo.is_open()))
    {
        cout << "Archivo " << rutaArchivo << " no se pudo abrir correctamente" << endl;
    }
    else {
        string fila;
        string dato;
        vector<string> vectorFila;
        stringstream streamFila;
        int columna;


        // Primera iteracion del ciclo para guardar las etiquetas
        getline(archivo, fila);
        streamFila = stringstream(fila);
        columna = 0;
        while ((getline(streamFila, dato, ';')))
        {
            dato = quitarEspacioYAgregarMayus(dato);
            mapaConPosiciones[dato] = columna;
            columna++;
        }
    }
    archivo.close();

    // Imprimir el mapa
    /*
    cout << "" << endl;
    for (const auto& par : mapaConPosiciones) {
        cout << "Nombre: " << par.first << ", Posicion: " << par.second << endl;
    }
    */

    return mapaConPosiciones;
}

int GestorCsv::conseguirCantColumnas(map<string, int> mapa) {
    int maxPosicion = 0;

    // Recorrer el mapa y encontrar la posición más grande
    for (const auto& par : mapa) {
        if (par.second > maxPosicion) {
            maxPosicion = par.second;
        }
    }

    return maxPosicion;
}

string GestorCsv::quitarEspacioYAgregarMayus(string cadena) {
    std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::toupper);
    std::replace(cadena.begin(), cadena.end(), ' ', '_');

    return cadena;
}


/*
    CÓDIGO DE LA INSTITUCIÓN
    CÓDIGO DE LA INSTITUCIÓN
    IES_PADRE
    INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
    PRINCIPAL O SECCIONAL
    ID SECTOR IES
    SECTOR IES
    ID CARACTER
    CARACTER IES
    CÓDIGO DEL DEPARTAMENTO (IES)
    DEPARTAMENTO DE DOMICILIO DE LA IES
    CÓDIGO DEL MUNICIPIO IES
    MUNICIPIO DE DOMICILIO DE LA IES
    CÓDIGO SNIES DEL PROGRAMA
    PROGRAMA ACADÉMICO
    ID NIVEL ACADÉMICO
    NIVEL ACADÉMICO
    ID NIVEL DE FORMACIÓN
    NIVEL DE FORMACIÓN
    ID METODOLOGÍA
    METODOLOGÍA
    ID ÁREA
    ÁREA DE CONOCIMIENTO
    ID NÚCLEO
    NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
    ID CINE CAMPO AMPLIO
    DESC CINE CAMPO AMPLIO
    ID CINE CAMPO ESPECIFICO
    DESC CINE CAMPO ESPECIFICO
    ID CINE CODIGO DETALLADO
    DESC CINE CODIGO DETALLADO
    CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
    DEPARTAMENTO DE OFERTA DEL PROGRAMA
    CÓDIGO DEL MUNICIPIO (PROGRAMA)
    MUNICIPIO DE OFERTA DEL PROGRAMA
    ID SEXO
    SEXO
    AÑO
    SEMESTRE
    ADMITIDOS
     */