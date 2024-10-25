//
// Created by Nicolas on 14/10/2024.
//

#ifndef GESTORTXT_H
#define GESTORTXT_H

#include "GestorBase.h"

#include "ProgramaAcademico.h"
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

class GestorTxt : public GestorBase
{
public:
    void crearArchivo(string&, map<int, ProgramaAcademico*>&, const char &) override;
    bool crearArchivoExtra(string&, vector<vector<string>>, const char &) override;
};

#endif //GESTORTXT_H