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

#include "View.h"

using namespace std;

class GestorBase
{
public:
    virtual  ~GestorBase() = default;
    virtual void crearArchivo(string&, map<int, ProgramaAcademico*>&, const char &) = 0;
    virtual bool crearArchivoExtra(string&, vector<vector<string>>, const char &) = 0;
};

#endif //GESTORBASE_H