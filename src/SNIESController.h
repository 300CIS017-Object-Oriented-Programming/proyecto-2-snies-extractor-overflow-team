#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H
#include <vector>
#include <map>
#include <string>
#include "ProgramaAcademico.h"
#include "GestorCsv.h"
#include "GestorTxt.h"
#include "GestorJson.h"

using namespace std;

class SNIESController
{
private:
    map<int, ProgramaAcademico *> programasAcademicos;
    GestorCsv *gestorCsvObj = new GestorCsv();
    GestorTxt *gestorTxtObj = new GestorTxt();
    GestorJson *gestorJsonObj = new GestorJson();
    vector<string> etiquetasColumnas;
    string rutaProgramasCSV;
    string rutaAdmitidos;
    string rutaGraduados;
    string rutaInscritos;
    string rutaMatriculados;
    string rutaMatriculadosPrimerSemestre;
    string rutaOutputResultados;
    string rutaOutputFiltrado;

public:
    SNIESController();
    ~SNIESController();
    void procesarDatosCsv(string &, string &, const char &);
    void calcularDatosExtra(bool);
    void buscarProgramas(bool, string &, int, const char &);
    string exportarEnFormato();
};

#endif