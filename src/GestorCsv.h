#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include "GestorBase.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <list>
#include "ProgramaAcademico.h"

// Recomendación Linter: Se debe evitar el uso de using namespace en archivos de cabecera
using namespace std;

class GestorCsv : public GestorBase
{
public:
    GestorCsv() = default;
    vector<int> leerProgramasCsv(string &ruta);
    // Mantenimiento: Se puede mejorar la firma y nombre de los metodos para que sea más descriptiva
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies);
    bool crearArchivo(string &, map<int, ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoBuscados(string &, list<ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoExtra(string &, vector<vector<string>>) override;
    map<string, int> conseguirPosicionesColumnas(string &rutaArchivo);
    int conseguirCantColumnas(map<string, int>);
    string quitarEspacioYAgregarMayus(string cadena);
};

#endif