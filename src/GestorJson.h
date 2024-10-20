//
// Created by Nicolas on 14/10/2024.
//

#ifndef GESTORJSON_H
#define GESTORJSON_H

#include "GestorBase.h"
#include "ProgramaAcademico.h"
#include "../include/single_include/nlohmann/json.hpp"
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;
using json = nlohmann::json;

class GestorJson : public GestorBase
{
public:
    bool crearArchivo(string&, map<int, ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoBuscados(string&, list<ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoExtra(string&, vector<vector<string>>) override;
};

#endif //GESTORJSON_H