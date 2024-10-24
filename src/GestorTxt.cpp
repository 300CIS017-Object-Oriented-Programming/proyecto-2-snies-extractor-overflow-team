//
// Created by Nicolas on 14/10/2024.
//

#include "GestorTxt.h"
#include "GestorCsv.h"
#include <iostream>
#include <fstream>

using namespace std;

void GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos)
{
    vector<string> etiquetasColumnas;   // Está vacío. Se puso solo para que el código no muera.
    // FIXME: ARREGLAR PARA QUE FUNCIONE CON EL MAPA DE CONSOLIDADOS. VER EJEMPLO DE GestorCsv
    string rutaCompleta = ruta + "resultados.txt";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Iteramos sobre los programas académicos
        for (map<int, ProgramaAcademico *>::iterator it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); ++it)
        {
            ProgramaAcademico *programa = it->second;
            // Imprimimos las etiquetas y los valores del programa académico
            archivoResultados << etiquetasColumnas[0] << ": " << programa->getCodigoDeLaInstitucion() << endl;
            archivoResultados << etiquetasColumnas[1] << ": " << programa->getIesPadre() << endl;
            archivoResultados << etiquetasColumnas[2] << ": " << programa->getInstitucionDeEducacionSuperiorIes() << endl;
            archivoResultados << etiquetasColumnas[3] << ": " << programa->getPrincipalOSeccional() << endl;
            archivoResultados << etiquetasColumnas[4] << ": " << programa->getIdSectorIes() << endl;
            archivoResultados << etiquetasColumnas[5] << ": " << programa->getSectorIes() << endl;
            archivoResultados << etiquetasColumnas[6] << ": " << programa->getIdCaracter() << endl;
            archivoResultados << etiquetasColumnas[7] << ": " << programa->getCaracterIes() << endl;
            archivoResultados << etiquetasColumnas[8] << ": " << programa->getCodigoDelDepartamentoIes() << endl;
            archivoResultados << etiquetasColumnas[9] << ": " << programa->getDepartamentoDeDomicilioDeLaIes() << endl;
            archivoResultados << etiquetasColumnas[10] << ": " << programa->getCodigoDelMunicipioIes() << endl;
            archivoResultados << etiquetasColumnas[11] << ": " << programa->getMunicipioDeDomicilioDeLaIes() << endl;
            archivoResultados << etiquetasColumnas[12] << ": " << programa->getCodigoSniesDelPrograma() << endl;
            archivoResultados << etiquetasColumnas[13] << ": " << programa->getProgramaAcademico() << endl;
            archivoResultados << etiquetasColumnas[14] << ": " << programa->getIdNivelAcademico() << endl;
            archivoResultados << etiquetasColumnas[15] << ": " << programa->getNivelAcademico() << endl;
            archivoResultados << etiquetasColumnas[16] << ": " << programa->getIdNivelDeFormacion() << endl;
            archivoResultados << etiquetasColumnas[17] << ": " << programa->getNivelDeFormacion() << endl;
            archivoResultados << etiquetasColumnas[18] << ": " << programa->getIdMetodologia() << endl;
            archivoResultados << etiquetasColumnas[19] << ": " << programa->getMetodologia() << endl;
            archivoResultados << etiquetasColumnas[20] << ": " << programa->getIdArea() << endl;
            archivoResultados << etiquetasColumnas[21] << ": " << programa->getAreaDeConocimiento() << endl;
            archivoResultados << etiquetasColumnas[22] << ": " << programa->getIdNucleo() << endl;
            archivoResultados << etiquetasColumnas[23] << ": " << programa->getNucleoBasicoDelConocimientoNbc() << endl;
            archivoResultados << etiquetasColumnas[24] << ": " << programa->getIdCineCampoAmplio() << endl;
            archivoResultados << etiquetasColumnas[25] << ": " << programa->getDescCineCampoAmplio() << endl;
            archivoResultados << etiquetasColumnas[26] << ": " << programa->getIdCineCampoEspecifico() << endl;
            archivoResultados << etiquetasColumnas[27] << ": " << programa->getDescCineCampoEspecifico() << endl;
            archivoResultados << etiquetasColumnas[28] << ": " << programa->getIdCineCodigoDetallado() << endl;
            archivoResultados << etiquetasColumnas[29] << ": " << programa->getDescCineCodigoDetallado() << endl;
            archivoResultados << etiquetasColumnas[30] << ": " << programa->getCodigoDelDepartamentoPrograma() << endl;
            archivoResultados << etiquetasColumnas[31] << ": " << programa->getDepartamentoDeOfertaDelPrograma() << endl;
            archivoResultados << etiquetasColumnas[32] << ": " << programa->getCodigoDelMunicipioPrograma() << endl;
            archivoResultados << etiquetasColumnas[33] << ": " << programa->getMunicipioDeOfertaDelPrograma() << endl;
            // Agregamos los consolidados del programa
            archivoResultados << "Consolidados:" << endl;
            /*
            for (int i = 0; i < 8; ++i)
            {
                Consolidado *consolidadoActual = programa->getConsolidado(i);
                archivoResultados << "  - Consolidado " << i + 1 << ":" << endl;
                archivoResultados << "    ID_SEXO: " << consolidadoActual->getIdSexo() << endl;
                archivoResultados << "    SEXO: " << consolidadoActual->getSexo() << endl;
                archivoResultados << "    AÑO: " << consolidadoActual->getAno() << endl;
                archivoResultados << "    SEMESTRE: " << consolidadoActual->getSemestre() << endl;
                archivoResultados << "    ADMITIDOS: " << consolidadoActual->getAdmitidos() << endl;
                archivoResultados << "    GRADUADOS: " << consolidadoActual->getGraduados() << endl;
                archivoResultados << "    INSCRITOS: " << consolidadoActual->getInscritos() << endl;
                archivoResultados << "    MATRICULADOS: " << consolidadoActual->getMatriculados() << endl;
                archivoResultados << "    MATR. PRIMER SEMESTRE: " << consolidadoActual->getMatriculadosPrimerSemestre() << endl;
            }
            */
            archivoResultados << endl; // Espacio entre programas
        }
        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }
    archivoResultados.close();

}

bool GestorTxt::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.txt";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Iteramos sobre los datos para escribir cada fila
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << " "; // Separador entre columnas
                }
            }
            archivoExtra << endl;
        }
        estadoCreacion = true;
        cout << "Archivo TXT creado en: " << rutaCompleta << endl;
    }
    archivoExtra.close();
    return estadoCreacion;
}