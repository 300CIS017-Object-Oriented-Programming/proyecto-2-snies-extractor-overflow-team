#include "SNIESController.h"

#include "GestorJson.h"
#include "GestorTxt.h"

using namespace std;

SNIESController::SNIESController()
{
    gestorCsvObj = new GestorCsv();
}

SNIESController::~SNIESController()
{
    for (auto &pair : programasAcademicos)
    {
        ((pair).second)->~ProgramaAcademico();
        delete pair.second;
    }
}

void SNIESController::procesarDatosCsv(string &ano1, string &ano2)
{
    vector<vector<string>> programasAcademicosVector;
    int anoInicio = stoi(ano1);
    int anoFin = stoi(ano2);
    // cout << "antes leer programas csv" << endl;
    vector<int> codigosSnies = gestorCsvObj->leerProgramasCsv(rutaProgramasCSV);

    for (int i = 0; i < codigosSnies.size(); i++)
    {
        ProgramaAcademico *programaAcademico = new ProgramaAcademico();
        int codigoSniesActual = codigosSnies[i];
        programaAcademico->setCodigoSniesDelPrograma(codigoSniesActual);
        programasAcademicos[codigoSniesActual] = programaAcademico;
    }

    bool primeraLectura = true;
    for(int ano = anoInicio; ano <= anoFin; ano++) {
        string anoAEvaluar = to_string(ano);
        gestorCsvObj->leerArchivo(rutaAdmitidos, anoAEvaluar, programasAcademicos, primeraLectura, "admitidos");
        primeraLectura = false;
        gestorCsvObj->leerArchivo(rutaGraduados, anoAEvaluar, programasAcademicos, false, "graduados");
        gestorCsvObj->leerArchivo(rutaInscritos, anoAEvaluar, programasAcademicos, false, "inscritos");
        gestorCsvObj->leerArchivo(rutaMatriculados, anoAEvaluar, programasAcademicos, false, "matriculados");
        gestorCsvObj->leerArchivo(rutaMatriculadosPrimerSemestre, anoAEvaluar, programasAcademicos, false, "neos");
    }

    string formatoAExportar = exportarEnFormato();

    if (formatoAExportar == "1")
    {
        gestorCsvObj->crearArchivo(rutaOutputResultados, programasAcademicos);
    }
    else if (formatoAExportar == "2")
    {
        GestorTxt *gestorTxtObj = new GestorTxt();
        gestorTxtObj->crearArchivo(rutaOutputResultados, programasAcademicos);
    }
    else if (formatoAExportar == "3")
    {
        GestorJson * gestorJsonObj = new GestorJson();
        gestorJsonObj->crearArchivo(rutaOutputResultados, programasAcademicos);
    }

}

void SNIESController::buscarProgramas(bool flag, string &palabraClave, int idComparacion)
{
    map<int, ProgramaAcademico *> mapaProgramasFiltrados;
    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        ProgramaAcademico *programa = it->second;
        string nombre = programa->getProgramaAcademico();
        int id = programa->getIdNivelDeFormacion();
        if (nombre.find(palabraClave) != string::npos && id == idComparacion)
        {
            mapaProgramasFiltrados[programa->getCodigoSniesDelPrograma()] = programa;
            // codigo SNIES, nombre del programa, codigo de la institucion, nombre de la institucion y metodología
            cout << programa->getCodigoSniesDelPrograma() << ";"
                 << programa->getProgramaAcademico() << ";"
                 << programa->getCodigoDeLaInstitucion() << ";"
                 << programa->getInstitucionDeEducacionSuperiorIes() << ";"
                 << programa->getMetodologia() << endl;
        }
    }

    if (flag)
    {
        string formatoAExportar = exportarEnFormato();

        if (formatoAExportar == "1")
        {
            gestorCsvObj->crearArchivo(rutaOutputFiltrado, mapaProgramasFiltrados);
        }
        else if (formatoAExportar == "2")
        {
            GestorTxt *gestorTxtObj = new GestorTxt();
            gestorTxtObj->crearArchivo(rutaOutputFiltrado, mapaProgramasFiltrados);
        }
        else if (formatoAExportar == "3")
        {
            GestorJson * gestorJsonObj = new GestorJson();
            gestorJsonObj->crearArchivo(rutaOutputFiltrado, mapaProgramasFiltrados);
        }
    }
}

void SNIESController::calcularDatosExtra(bool flag)
{
    /*
    vector<vector<string>> matrizFinal;
    vector<vector<string>> matrizEtiquetas1;
    vector<vector<string>> matrizEtiquetas2;
    vector<vector<string>> matrizEtiquetas3;
    vector<string> etiquetas1 = {"Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual) Primer año", "Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual)"};
    matrizEtiquetas1.push_back(etiquetas1);
    vector<string> etiquetas2 = {"Codigo Snies", "Nombre del Programa", "Nombre del Institucion", "Diferencial porcentual anual de NEOS"};
    matrizEtiquetas2.push_back(etiquetas2);
    vector<string> etiquetas3 = {"Codigo Snies", " Nombre del Programa sin NEOS en los ultimos 3 semestres"};
    matrizEtiquetas3.push_back(etiquetas3);
    vector<string> datosEtiquetas1;
    vector<string> datosEtiquetas2;
    int sumaPrimerAno = 0;
    int sumaSegundoAno = 0;

    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        int neosPrimerAno = 0;
        int neosSegundoAno = 0;
        int diferenciaNeos = 0;
        ProgramaAcademico *programa = it->second;
        int idMetodologiaBuscada = programa->getIdMetodologia();
        if (idMetodologiaBuscada == 1 || idMetodologiaBuscada == 3)
        {
            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i);
                int matriculados = consolidado->getMatriculados();
                sumaPrimerAno += matriculados;
            }

            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i + 4);
                int matriculados = consolidado->getMatriculados();
                sumaSegundoAno += matriculados;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosPrimerAno += numNeos;
        }

        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i + 4);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosSegundoAno += numNeos;
        }

        if (neosPrimerAno != 0)
        {
            diferenciaNeos = ((neosSegundoAno - neosPrimerAno) * 100) / neosPrimerAno;
        }
        else
        {
            diferenciaNeos = 0;
        }
        datosEtiquetas2 = {to_string(programa->getCodigoSniesDelPrograma()), programa->getProgramaAcademico(), programa->getInstitucionDeEducacionSuperiorIes(), to_string(diferenciaNeos)};
        matrizEtiquetas2.push_back(datosEtiquetas2);
        int SumaNeosPrimerSemestre;
        int SumaNeosSegundoSemestre;
        int SumaNeosTercerSemestre;
        int SumaNeosCuartoSemestre;
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidados[8];
            if (i == 0)
            {
                consolidados[0] = programa->getConsolidado(i);
                consolidados[1] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[0]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[1]->getMatriculadosPrimerSemestre();
                SumaNeosPrimerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 1)
            {
                consolidados[2] = programa->getConsolidado(i);
                consolidados[3] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[2]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[3]->getMatriculadosPrimerSemestre();
                SumaNeosSegundoSemestre = neosHombres + neosMujeres;
            }
            else if (i == 2)
            {
                consolidados[4] = programa->getConsolidado(i + 2);
                consolidados[5] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[4]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[5]->getMatriculadosPrimerSemestre();
                SumaNeosTercerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 3)
            {
                consolidados[6] = programa->getConsolidado(i + 2);
                consolidados[7] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[6]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[7]->getMatriculadosPrimerSemestre();
                SumaNeosCuartoSemestre = neosHombres + neosMujeres;
            }
        }

        if ((SumaNeosPrimerSemestre == 0 && SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0) || (SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0 && SumaNeosCuartoSemestre == 0))
        {
            etiquetas3 = {to_string(programa->getCodigoSniesDelPrograma()),
                          programa->getProgramaAcademico()};
        }
    }
    etiquetas1 = {to_string(sumaPrimerAno), to_string(sumaSegundoAno)};
    matrizEtiquetas1.push_back(etiquetas1);
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas1.begin(), matrizEtiquetas1.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas2.begin(), matrizEtiquetas2.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas3.begin(), matrizEtiquetas3.end());

    for (const auto &fila : matrizFinal)
    {
        for (size_t i = 0; i < fila.size(); ++i)
        {
            cout << fila[i];
            if (i < fila.size() - 1)
            {
                cout << ";";
            }
        }
        cout << endl;
    }

    if (flag)
    {
        bool creado;
        creado = gestorCsvObj->crearArchivoExtra(rutaOutput, matrizFinal);
    }
    */
}

string SNIESController::exportarEnFormato() {
    string opcionArchivoAExportar;
    cout << "A que tipo de archivo quiere exportar el archivo?: " << endl;
    cout << "1. Csv \n2. Txt \n3. Json: " << endl;
    cin >> opcionArchivoAExportar;

    while (opcionArchivoAExportar != "1" && opcionArchivoAExportar != "2" && opcionArchivoAExportar != "3") {
        cout << "Seleccione una opcion valida: " << endl;
        cin >> opcionArchivoAExportar;
    }
    return  opcionArchivoAExportar;
}
