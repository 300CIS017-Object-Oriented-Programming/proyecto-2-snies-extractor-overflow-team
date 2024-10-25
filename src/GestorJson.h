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

using namespace std;
using json = nlohmann::json;

class GestorJson : public GestorBase
{
public:
    void crearArchivo(string&, map<int, ProgramaAcademico*>&, const char &) override;
    bool crearArchivoExtra(string&, vector<vector<string>>, const char &) override;
};

#endif //GESTORJSON_H