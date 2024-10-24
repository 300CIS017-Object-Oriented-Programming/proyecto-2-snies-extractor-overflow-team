#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include <string>
#include <vector>
#include <map>
#include "ProgramaAcademico.h"
#include "GestorBase.h"

// Recomendación Linter: Se debe evitar el uso de using namespace en archivos de cabecera
using namespace std;

class GestorCsv : public GestorBase
{
public:
    GestorCsv() = default;
    void crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, const char &delimitador) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir, const char &delimitador) override;

    vector<int> leerProgramasCsv(string &ruta, const char &delimitador);
    void leerArchivo(string &rutaBase, string &ano, map<int, ProgramaAcademico *>  &mapaProgramasAcademicos, bool primeraVez, string atributoAModificar, const char &delimitador);
    map<string, int> conseguirPosicionesColumnas(string &rutaArchivo, const char &delimitador);
    int conseguirCantColumnas(map<string, int>);
    string quitarEspacioYAgregarMayus(string cadena);
};

#endif