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

void GestorCsv::leerArchivoFinal(string &rutaBase, string &ano, map<int, ProgramaAcademico *>  &mapaProgramasAcademicos, bool primeraVez, string atributoAModificar)
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
        // FIXME : BORRAR LINEA
        cout << "El archivo " << rutaCompleta << " abrio correctamente" << endl;
        string fila;
        string dato;
        string codSniesActual;
        int columna;
        vector<string> vectorFila(TAMANIO_ARCHIVO);
        stringstream streamFila;
        ProgramaAcademico * progAcademicoActual;

        size_t existeEnMapaProgsAcademicos;

        // Primera iteracion del ciclo para leer las etiquetas
        getline(archivo, fila);

        // Si es la primera lectura, guardamos las etiquetas y la agregamos a la matriz de resultados
        if (primeraVez)
        {
            // vectorFila = vector<string>(TAMANIO_ARCHIVO);
            streamFila = stringstream(fila);
            columna = 0;
            while ((getline(streamFila, dato, ';')))
            {

                vectorFila[columna] = dato;
                columna++;
            }
            matrizResultado.push_back(vectorFila);
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
                matrizResultado.push_back(vectorFila);

                int COD_SNIES = stoi(vectorFila[POS_COD_SNIES]);
                int ID_SEXO = stoi(vectorFila[POS_ID_SEXO]);
                string SEXO = vectorFila[POS_SEXO];
                int ANIO = stoi(vectorFila[POS_ANIO]);
                int SEMESTRE = stoi(vectorFila[POS_SEMESTRE]);
                int ULTIMA_COLUMNA = stoi(vectorFila[POS_ULTIMA_COLUMNA]);

                // Accedemos al ProgramaAcademico * desde el mapa
                progAcademicoActual = mapaProgramasAcademicos[COD_SNIES];
                // Setteamos el programa académico
                progAcademicoActual->setTodoElProgramaAcademico(vectorFila, posicionesColumnasMap);

                Consolidado * consolidadoActual = progAcademicoActual->getConsolidadoDeMapa(ANIO, ID_SEXO, SEMESTRE);

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
            }
        }
    }
    archivo.close();
}

void GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << ";";
        }

        archivoResultados << "\xEF\xBB\xBF";    // Permite escribir los caracteres con tildes correctamente
        archivoResultados << "CÓDIGO DE LA INSTITUCIÓN;"
                             "IES_PADRE;"
                             "INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES);"
                             "PRINCIPAL O SECCIONAL;"
                             "ID SECTOR IES;"
                             "SECTOR IES;"
                             "ID CARACTER;"
                             "CARACTER IES;"
                             "CÓDIGO DEL DEPARTAMENTO (IES);"
                             "DEPARTAMENTO DE DOMICILIO DE LA IES;"
                             "CÓDIGO DEL MUNICIPIO IES;"
                             "MUNICIPIO DE DOMICILIO DE LA IES;"
                             "CÓDIGO SNIES DEL PROGRAMA;"
                             "PROGRAMA ACADÉMICO;"
                             "ID NIVEL ACADÉMICO;"
                             "NIVEL ACADÉMICO;"
                             "ID NIVEL DE FORMACIÓN;"
                             "NIVEL DE FORMACIÓN;"
                             "ID METODOLOGÍA;"
                             "METODOLOGÍA;"
                             "ID ÁREA;"
                             "ÁREA DE CONOCIMIENTO;"
                             "ID NÚCLEO;"
                             "NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC);"
                             "ID CINE CAMPO AMPLIO;"
                             "DESC CINE CAMPO AMPLIO;"
                             "ID CINE CAMPO ESPECIFICO;"
                             "DESC CINE CAMPO ESPECIFICO;"
                             "ID CINE CODIGO DETALLADO;"
                             "DESC CINE CODIGO DETALLADO;"
                             "CÓDIGO DEL DEPARTAMENTO (PROGRAMA);"
                             "DEPARTAMENTO DE OFERTA DEL PROGRAMA;"
                             "CÓDIGO DEL MUNICIPIO (PROGRAMA);"
                             "MUNICIPIO DE OFERTA DEL PROGRAMA;"
                             "ID SEXO;"
                             "SEXO;"
                             "AÑO;"
                             "SEMESTRE;"
                             "ADMITIDOS;"
                             "GRADUADOS;"
                             "INSCRITOS;"
                             "MATRICULADOS;"
                             "NEOS" << endl;

        for (const auto &entryPrograma : mapadeProgramasAcademicos)
        {
            ProgramaAcademico * programaActual = entryPrograma.second;
            for (const auto &entryAno : programaActual->getMapaDeConsolidados())
            {
                int ano = entryAno.first;
                for (const auto &entrySexo : entryAno.second)
                {
                    int idSexo = entrySexo.first;
                    for (const auto &entrySemestre : entrySexo.second)
                    {
                        int semestre = entrySemestre.first;
                        Consolidado * consolidadoActual = entrySemestre.second;
                        // Imprimimos toda la información base del programa academico
                        archivoResultados << programaActual->getCodigoDeLaInstitucion() << ";";
                        archivoResultados << programaActual->getIesPadre() << ";";
                        archivoResultados << programaActual->getInstitucionDeEducacionSuperiorIes() << ";";
                        archivoResultados << programaActual->getPrincipalOSeccional() << ";";
                        archivoResultados << programaActual->getIdSectorIes() << ";";
                        archivoResultados << programaActual->getSectorIes() << ";";
                        archivoResultados << programaActual->getIdCaracter() << ";";
                        archivoResultados << programaActual->getCaracterIes() << ";";
                        archivoResultados << programaActual->getCodigoDelDepartamentoIes() << ";";
                        archivoResultados << programaActual->getDepartamentoDeDomicilioDeLaIes() << ";";
                        archivoResultados << programaActual->getCodigoDelMunicipioIes() << ";";
                        archivoResultados << programaActual->getMunicipioDeDomicilioDeLaIes() << ";";
                        archivoResultados << programaActual->getCodigoSniesDelPrograma() << ";";
                        archivoResultados << programaActual->getProgramaAcademico() << ";";
                        archivoResultados << programaActual->getIdNivelAcademico() << ";";
                        archivoResultados << programaActual->getNivelAcademico() << ";";
                        archivoResultados << programaActual->getIdNivelDeFormacion() << ";";
                        archivoResultados << programaActual->getNivelDeFormacion() << ";";
                        archivoResultados << programaActual->getIdMetodologia() << ";";
                        archivoResultados << programaActual->getMetodologia() << ";";
                        archivoResultados << programaActual->getIdArea() << ";";
                        archivoResultados << programaActual->getAreaDeConocimiento() << ";";
                        archivoResultados << programaActual->getIdNucleo() << ";";
                        archivoResultados << programaActual->getNucleoBasicoDelConocimientoNbc() << ";";
                        archivoResultados << programaActual->getIdCineCampoAmplio() << ";";
                        archivoResultados << programaActual->getDescCineCampoAmplio() << ";";
                        archivoResultados << programaActual->getIdCineCampoEspecifico() << ";";
                        archivoResultados << programaActual->getDescCineCampoEspecifico() << ";";
                        archivoResultados << programaActual->getIdCineCodigoDetallado() << ";";
                        archivoResultados << programaActual->getDescCineCodigoDetallado() << ";";
                        archivoResultados << programaActual->getCodigoDelDepartamentoPrograma() << ";";
                        archivoResultados << programaActual->getDepartamentoDeOfertaDelPrograma() << ";";
                        archivoResultados << programaActual->getCodigoDelMunicipioPrograma() << ";";
                        archivoResultados << programaActual->getMunicipioDeOfertaDelPrograma() << ";";

                        // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
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
            }
        }

        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
}

bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
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

        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }
    archivoBuscados.close();
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
    // FIXME: manejar la excepción. Throw a dónde? Al SNIESController?
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