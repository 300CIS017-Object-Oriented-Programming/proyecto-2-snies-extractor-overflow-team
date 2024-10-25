#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
// Mantenimiento: Se incluyen librerías que no se utilizan
#include <sstream>
#include <list>
#include <algorithm>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "GestorBase.h"

// Recomendación Linter: Se debe evitar el uso de using namespace en archivos de cabecera
using namespace std;

class GestorCsv : public GestorBase
{
public:
    GestorCsv() = default;
    void crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, const char &) override ;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir, const char &) override;
    vector<int> leerProgramasCsv(string &ruta,const char &);
    void leerArchivo(string &rutaBase, string &ano, map<int, ProgramaAcademico *> &mapaProgramasAcademicos, bool primeraVez, string
                     atributoAModificar, const char &);
    map<string, int> conseguirPosicionesColumnas(string &rutaArchivo, const char &);
    int conseguirCantColumnas(map<string, int>);
    string quitarEspacioYAgregarMayus(string cadena);
};

#endif