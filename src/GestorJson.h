//
// Created by Nicolas on 14/10/2024.
//

#ifndef GESTORJSON_H
#define GESTORJSON_H

#include "GestorCsv.h"
#include "ProgramaAcademico.h"
#include "../include/single_include/nlohmann/json.hpp"
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;
using json = nlohmann::json;

class GestorJson : public GestorCsv
{
public:
    bool crearArchivo(string& ruta, map<int, ProgramaAcademico*>& mapadeProgramasAcademicos, vector<string> etiquetasColumnas) override;
    bool crearArchivoBuscados(string& ruta, list<ProgramaAcademico*>& programasBuscados, vector<string> etiquetasColumnas) override;
    bool crearArchivoExtra(string& ruta, vector<vector<string>> datosAImprimir) override;
};

#endif //GESTORJSON_H