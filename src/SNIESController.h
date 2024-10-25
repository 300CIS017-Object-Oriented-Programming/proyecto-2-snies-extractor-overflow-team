#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
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

public:
    string rutaProgramasCSV;
    string rutaAdmitidos;
    string rutaGraduados;
    string rutaInscritos;
    string rutaMatriculados;
    string rutaMatriculadosPrimerSemestre;
    string rutaOutputResultados;
    string rutaOutputFiltrado;
    SNIESController();
    ~SNIESController();
    void procesarDatosCsv(string &, string &, const char &);
    void calcularDatosExtra(bool, const char &);
    void buscarProgramas(bool, string &, int, const char &);
    string exportarEnFormato();
};

#endif