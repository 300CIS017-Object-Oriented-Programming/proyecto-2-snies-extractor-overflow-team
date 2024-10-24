//
// Created by Nicolas on 14/10/2024.
//

#include "GestorJson.h"
#include <iostream>
#include <fstream>

using namespace std;

void GestorJson::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos)
{
    vector<string> etiquetasColumnas;   // Está vacío. Se puso solo para que el código no muera.
    // FIXME: ARREGLAR PARA QUE FUNCIONE CON EL MAPA DE CONSOLIDADOS. VER EJEMPLO DE GestorCsv
    string rutaCompleta = ruta + "resultados.json";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        json resultadoJson;
        // Iteramos sobre los programas académicos
        for (map<int, ProgramaAcademico *>::iterator it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); ++it)
        {
            json programaJson;
            ProgramaAcademico *programa = it->second;
            // Asignamos las etiquetas como llaves en el JSON, utilizando los métodos correspondientes para obtener los valores
            programaJson[etiquetasColumnas[0]] = programa->getCodigoDeLaInstitucion();
            programaJson[etiquetasColumnas[1]] = programa->getIesPadre();
            programaJson[etiquetasColumnas[2]] = programa->getInstitucionDeEducacionSuperiorIes();
            programaJson[etiquetasColumnas[3]] = programa->getPrincipalOSeccional();
            programaJson[etiquetasColumnas[4]] = programa->getIdSectorIes();
            programaJson[etiquetasColumnas[5]] = programa->getSectorIes();
            programaJson[etiquetasColumnas[6]] = programa->getIdCaracter();
            programaJson[etiquetasColumnas[7]] = programa->getCaracterIes();
            programaJson[etiquetasColumnas[8]] = programa->getCodigoDelDepartamentoIes();
            programaJson[etiquetasColumnas[9]] = programa->getDepartamentoDeDomicilioDeLaIes();
            programaJson[etiquetasColumnas[10]] = programa->getCodigoDelMunicipioIes();
            programaJson[etiquetasColumnas[11]] = programa->getMunicipioDeDomicilioDeLaIes();
            programaJson[etiquetasColumnas[12]] = programa->getCodigoSniesDelPrograma();
            programaJson[etiquetasColumnas[13]] = programa->getProgramaAcademico();
            programaJson[etiquetasColumnas[14]] = programa->getIdNivelAcademico();
            programaJson[etiquetasColumnas[15]] = programa->getNivelAcademico();
            programaJson[etiquetasColumnas[16]] = programa->getIdNivelDeFormacion();
            programaJson[etiquetasColumnas[17]] = programa->getNivelDeFormacion();
            programaJson[etiquetasColumnas[18]] = programa->getIdMetodologia();
            programaJson[etiquetasColumnas[19]] = programa->getMetodologia();
            programaJson[etiquetasColumnas[20]] = programa->getIdArea();
            programaJson[etiquetasColumnas[21]] = programa->getAreaDeConocimiento();
            programaJson[etiquetasColumnas[22]] = programa->getIdNucleo();
            programaJson[etiquetasColumnas[23]] = programa->getNucleoBasicoDelConocimientoNbc();
            programaJson[etiquetasColumnas[24]] = programa->getIdCineCampoAmplio();
            programaJson[etiquetasColumnas[25]] = programa->getDescCineCampoAmplio();
            programaJson[etiquetasColumnas[26]] = programa->getIdCineCampoEspecifico();
            programaJson[etiquetasColumnas[27]] = programa->getDescCineCampoEspecifico();
            programaJson[etiquetasColumnas[28]] = programa->getIdCineCodigoDetallado();
            programaJson[etiquetasColumnas[29]] = programa->getDescCineCodigoDetallado();
            programaJson[etiquetasColumnas[30]] = programa->getCodigoDelDepartamentoPrograma();
            programaJson[etiquetasColumnas[31]] = programa->getDepartamentoDeOfertaDelPrograma();
            programaJson[etiquetasColumnas[32]] = programa->getCodigoDelMunicipioPrograma();
            programaJson[etiquetasColumnas[33]] = programa->getMunicipioDeOfertaDelPrograma();
            // Agregamos los consolidados del programa
            json consolidadosJson = json::array();
            /*
            for (int i = 0; i < 8; ++i)
            {
                Consolidado *consolidadoActual = programa->getConsolidado(i);
                json consolidadoJson;
                consolidadoJson["ID_SEXO"] = consolidadoActual->getIdSexo();
                consolidadoJson["SEXO"] = consolidadoActual->getSexo();
                consolidadoJson["AÑO"] = consolidadoActual->getAno();
                consolidadoJson["SEMESTRE"] = consolidadoActual->getSemestre();
                consolidadoJson["ADMITIDOS"] = consolidadoActual->getAdmitidos();
                consolidadoJson["GRADUADOS"] = consolidadoActual->getGraduados();
                consolidadoJson["INSCRITOS"] = consolidadoActual->getInscritos();
                consolidadoJson["MATRICULADOS"] = consolidadoActual->getMatriculados();
                consolidadoJson["MATRICULADOS_PRIMER_SEMESTRE"] = consolidadoActual->getMatriculadosPrimerSemestre();
                consolidadosJson.push_back(consolidadoJson);
            }
            */
            // Asignamos el array de consolidados al programa
            programaJson["Consolidados"] = consolidadosJson;

            // Agregamos el programa completo al JSON general
            resultadoJson["Programa_" + to_string(it->first)] = programaJson;
        }
        // Escribimos el JSON en el archivo
        archivoResultados << resultadoJson.dump(4);

        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }
    archivoResultados.close();
}

bool GestorJson::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.csv";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << ";";
                }
            }
            archivoExtra << endl;
        }
        estadoCreacion = true;
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }
    archivoExtra.close();
    return estadoCreacion;
}