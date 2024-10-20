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
    bool crearArchivo(string&, map<int, ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoBuscados(string&, list<ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoExtra(string&, vector<vector<string>>) override;
};

#endif //GESTORTXT_H