//
// Created by Nicolas on 20/10/2024.
//

#ifndef GESTORBASE_H
#define GESTORBASE_H

#include "ProgramaAcademico.h"
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class GestorBase
{
public:
    virtual  ~GestorBase() = default;
    virtual void crearArchivo(string&, map<int, ProgramaAcademico*>&) = 0;
    virtual bool crearArchivoExtra(string&, vector<vector<string>>) = 0;
};

#endif //GESTORBASE_H