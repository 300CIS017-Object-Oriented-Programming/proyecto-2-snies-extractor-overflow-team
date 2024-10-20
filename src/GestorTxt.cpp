//
// Created by Nicolas on 14/10/2024.
//

#include "GestorTxt.h"
#include <iostream>
#include <fstream>

using namespace std;

bool GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    bool estadoCreacion = false;
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
            archivoResultados << endl; // Espacio entre programas
        }
        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }
    archivoResultados.close();
    return estadoCreacion;
}

bool GestorTxt::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.txt";
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {
        // Escribimos las etiquetas al principio del archivo (separadas por espacios)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << " ";
        }
        archivoBuscados << "GRADUADOS INSCRITOS MATRICULADOS NEOS" << endl;
        // Recorremos la lista de programas buscados
        list<ProgramaAcademico *>::iterator it;
        for (it = programasBuscados.begin(); it != programasBuscados.end(); ++it)
        {
            for (int i = 0; i < 8; i++) // Iterar sobre los consolidados
            {
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << " "
                                << (*it)->getIesPadre() << " "
                                << (*it)->getInstitucionDeEducacionSuperiorIes() << " "
                                << (*it)->getPrincipalOSeccional() << " "
                                << (*it)->getIdSectorIes() << " "
                                << (*it)->getSectorIes() << " "
                                << (*it)->getIdCaracter() << " "
                                << (*it)->getCaracterIes() << " "
                                << (*it)->getCodigoDelDepartamentoIes() << " "
                                << (*it)->getDepartamentoDeDomicilioDeLaIes() << " "
                                << (*it)->getCodigoDelMunicipioIes() << " "
                                << (*it)->getMunicipioDeDomicilioDeLaIes() << " "
                                << (*it)->getCodigoSniesDelPrograma() << " "
                                << (*it)->getProgramaAcademico() << " "
                                << (*it)->getIdNivelAcademico() << " "
                                << (*it)->getNivelAcademico() << " "
                                << (*it)->getIdNivelDeFormacion() << " "
                                << (*it)->getNivelDeFormacion() << " "
                                << (*it)->getIdMetodologia() << " "
                                << (*it)->getMetodologia() << " "
                                << (*it)->getIdArea() << " "
                                << (*it)->getAreaDeConocimiento() << " "
                                << (*it)->getIdNucleo() << " "
                                << (*it)->getNucleoBasicoDelConocimientoNbc() << " "
                                << (*it)->getIdCineCampoAmplio() << " "
                                << (*it)->getDescCineCampoAmplio() << " "
                                << (*it)->getIdCineCampoEspecifico() << " "
                                << (*it)->getDescCineCampoEspecifico() << " "
                                << (*it)->getIdCineCodigoDetallado() << " "
                                << (*it)->getDescCineCodigoDetallado() << " "
                                << (*it)->getCodigoDelDepartamentoPrograma() << " "
                                << (*it)->getDepartamentoDeOfertaDelPrograma() << " "
                                << (*it)->getCodigoDelMunicipioPrograma() << " "
                                << (*it)->getMunicipioDeOfertaDelPrograma() << " ";
                // Información del consolidado
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << " "
                                << consolidadoActual->getSexo() << " "
                                << consolidadoActual->getAno() << " "
                                << consolidadoActual->getSemestre() << " "
                                << consolidadoActual->getAdmitidos() << " "
                                << consolidadoActual->getGraduados() << " "
                                << consolidadoActual->getInscritos() << " "
                                << consolidadoActual->getMatriculados() << " "
                                << consolidadoActual->getMatriculadosPrimerSemestre() << endl;
            }
        }
        estadoCreacion = true;
        cout << "Archivo TXT creado en: " << rutaCompleta << endl;
    }
    archivoBuscados.close();
    return estadoCreacion;
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