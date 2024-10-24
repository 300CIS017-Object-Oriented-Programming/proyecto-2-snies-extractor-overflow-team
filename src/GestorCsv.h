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
    void crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;

    vector<int> leerProgramasCsv(string &ruta);
    void leerArchivo(string &rutaBase, string &ano, map<int, ProgramaAcademico *>  &mapaProgramasAcademicos, bool primeraVez, string atributoAModificar);
    map<string, int> conseguirPosicionesColumnas(string &rutaArchivo);
    int conseguirCantColumnas(map<string, int>);
    string quitarEspacioYAgregarMayus(string cadena);
};

#endif