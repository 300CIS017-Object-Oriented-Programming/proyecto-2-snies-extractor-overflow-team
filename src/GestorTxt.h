//
// Created by Nicolas on 14/10/2024.
//

#ifndef GESTORTXT_H
#define GESTORTXT_H

#include "GestorCsv.h"
#include "ProgramaAcademico.h"
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

class GestorTxt : public GestorCsv
{
public:
    bool crearArchivo(string& ruta, map<int, ProgramaAcademico*>& mapadeProgramasAcademicos, vector<string> etiquetasColumnas) override;
    bool crearArchivoBuscados(string& ruta, list<ProgramaAcademico*>& programasBuscados, vector<string> etiquetasColumnas) override;
    bool crearArchivoExtra(string& ruta, vector<vector<string>> datosAImprimir) override;
};

#endif //GESTORTXT_H