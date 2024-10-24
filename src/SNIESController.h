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

using namespace std;

class SNIESController
{
private:
    map<int, ProgramaAcademico *> programasAcademicos;
    GestorCsv *gestorCsvObj = new GestorCsv();
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
    SNIESController(string &, string &, string &, string &, string &, string &, string &);
    ~SNIESController();
    void procesarDatosCsv(string &, string &);
    void calcularDatosExtra(bool);
    void buscarProgramas(bool, string &, int);
};

#endif