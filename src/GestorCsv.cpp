#include "GestorCsv.h"

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

void GestorCsv::leerArchivo(string &rutaBase, string &ano, map<int, ProgramaAcademico *>  &mapaProgramasAcademicos, bool primeraVez, string atributoAModificar)
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

void GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos)
{
    string DELIMITADOR = ";";
    ofstream archivoResultados(ruta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        archivoResultados << "\xEF\xBB\xBF";    // Permite escribir los caracteres con tildes correctamente
        archivoResultados << "CÓDIGO DE LA INSTITUCIÓN" << DELIMITADOR;
        archivoResultados << "IES_PADRE" << DELIMITADOR;
        archivoResultados << "INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)" << DELIMITADOR;
        archivoResultados << "PRINCIPAL O SECCIONAL" << DELIMITADOR;
        archivoResultados << "ID SECTOR IES" << DELIMITADOR;
        archivoResultados << "SECTOR IES" << DELIMITADOR;
        archivoResultados << "ID CARACTER" << DELIMITADOR;
        archivoResultados << "CARACTER IES" << DELIMITADOR;
        archivoResultados << "CÓDIGO DEL DEPARTAMENTO (IES)" << DELIMITADOR;
        archivoResultados << "DEPARTAMENTO DE DOMICILIO DE LA IES" << DELIMITADOR;
        archivoResultados << "CÓDIGO DEL MUNICIPIO IES" << DELIMITADOR;
        archivoResultados << "MUNICIPIO DE DOMICILIO DE LA IES" << DELIMITADOR;
        archivoResultados << "CÓDIGO SNIES DEL PROGRAMA" << DELIMITADOR;
        archivoResultados << "PROGRAMA ACADÉMICO" << DELIMITADOR;
        archivoResultados << "ID NIVEL ACADÉMICO" << DELIMITADOR;
        archivoResultados << "NIVEL ACADÉMICO" << DELIMITADOR;
        archivoResultados << "ID NIVEL DE FORMACIÓN" << DELIMITADOR;
        archivoResultados << "NIVEL DE FORMACIÓN" << DELIMITADOR;
        archivoResultados << "ID METODOLOGÍA" << DELIMITADOR;
        archivoResultados <<"METODOLOGÍA" << DELIMITADOR;
        archivoResultados << "ID ÁREA" << DELIMITADOR;
        archivoResultados << "ÁREA DE CONOCIMIENTO" << DELIMITADOR;
        archivoResultados << "ID NÚCLEO" << DELIMITADOR;
        archivoResultados << "NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)" << DELIMITADOR;
        archivoResultados << "ID CINE CAMPO AMPLIO" << DELIMITADOR;
        archivoResultados << "DESC CINE CAMPO AMPLIO" << DELIMITADOR;
        archivoResultados << "ID CINE CAMPO ESPECIFICO" << DELIMITADOR;
        archivoResultados << "DESC CINE CAMPO ESPECIFICO" << DELIMITADOR;
        archivoResultados << "ID CINE CODIGO DETALLADO" << DELIMITADOR;
        archivoResultados << "DESC CINE CODIGO DETALLADO" << DELIMITADOR;
        archivoResultados << "CÓDIGO DEL DEPARTAMENTO (PROGRAMA)" << DELIMITADOR;
        archivoResultados << "DEPARTAMENTO DE OFERTA DEL PROGRAMA" << DELIMITADOR;
        archivoResultados << "CÓDIGO DEL MUNICIPIO (PROGRAMA)" << DELIMITADOR;
        archivoResultados << "MUNICIPIO DE OFERTA DEL PROGRAMA" << DELIMITADOR;
        archivoResultados << "ID SEXO" << DELIMITADOR;
        archivoResultados << "SEXO" << DELIMITADOR;
        archivoResultados << "AÑO" << DELIMITADOR;
        archivoResultados << "SEMESTRE" << DELIMITADOR;
        archivoResultados << "ADMITIDOS" << DELIMITADOR;
        archivoResultados << "GRADUADOS" << DELIMITADOR;
        archivoResultados << "INSCRITOS" << DELIMITADOR;
        archivoResultados << "MATRICULADOS" << DELIMITADOR;
        archivoResultados << "NEOS" << endl;

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
        cout << "Archivo Creado en: " << ruta << endl;
    }

    archivoResultados.close();
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