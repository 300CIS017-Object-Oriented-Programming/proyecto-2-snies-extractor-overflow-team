//
// Created by Nicolas on 14/10/2024.
//

#include "GestorTxt.h"
#include "GestorCsv.h"
#include <iostream>
#include <fstream>

using namespace std;

void GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, const char &delimitador)
{
    ofstream archivoResultados(ruta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        archivoResultados << "CÓDIGO DE LA INSTITUCIÓN" << "\t";
        archivoResultados << "IES_PADRE" << "\t";
        archivoResultados << "INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)" << "\t";
        archivoResultados << "PRINCIPAL O SECCIONAL" << "\t";
        archivoResultados << "ID SECTOR IES" << "\t";
        archivoResultados << "SECTOR IES" << "\t";
        archivoResultados << "ID CARACTER" << "\t";
        archivoResultados << "CARACTER IES" << "\t";
        archivoResultados << "CÓDIGO DEL DEPARTAMENTO (IES)" << "\t";
        archivoResultados << "DEPARTAMENTO DE DOMICILIO DE LA IES" << "\t";
        archivoResultados << "CÓDIGO DEL MUNICIPIO IES" << "\t";
        archivoResultados << "MUNICIPIO DE DOMICILIO DE LA IES" << "\t";
        archivoResultados << "CÓDIGO SNIES DEL PROGRAMA" << "\t";
        archivoResultados << "PROGRAMA ACADÉMICO" << "\t";
        archivoResultados << "ID NIVEL ACADÉMICO" << "\t";
        archivoResultados << "NIVEL ACADÉMICO" << "\t";
        archivoResultados << "ID NIVEL DE FORMACIÓN" << "\t";
        archivoResultados << "NIVEL DE FORMACIÓN" << "\t";
        archivoResultados << "ID METODOLOGÍA" << "\t";
        archivoResultados <<"METODOLOGÍA" << "\t";
        archivoResultados << "ID ÁREA" << "\t";
        archivoResultados << "ÁREA DE CONOCIMIENTO" << "\t";
        archivoResultados << "ID NÚCLEO" << "\t";
        archivoResultados << "NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)" << "\t";
        archivoResultados << "ID CINE CAMPO AMPLIO" << "\t";
        archivoResultados << "DESC CINE CAMPO AMPLIO" << "\t";
        archivoResultados << "ID CINE CAMPO ESPECIFICO" << "\t";
        archivoResultados << "DESC CINE CAMPO ESPECIFICO" << "\t";
        archivoResultados << "ID CINE CODIGO DETALLADO" << "\t";
        archivoResultados << "DESC CINE CODIGO DETALLADO" << "\t";
        archivoResultados << "CÓDIGO DEL DEPARTAMENTO (PROGRAMA)" << "\t";
        archivoResultados << "DEPARTAMENTO DE OFERTA DEL PROGRAMA" << "\t";
        archivoResultados << "CÓDIGO DEL MUNICIPIO (PROGRAMA)" << "\t";
        archivoResultados << "MUNICIPIO DE OFERTA DEL PROGRAMA" << "\t";
        archivoResultados << "ID SEXO" << "\t";
        archivoResultados << "SEXO" << "\t";
        archivoResultados << "AÑO" << "\t";
        archivoResultados << "SEMESTRE" << "\t";
        archivoResultados << "ADMITIDOS" << "\t";
        archivoResultados << "GRADUADOS" << "\t";
        archivoResultados << "INSCRITOS" << "\t";
        archivoResultados << "MATRICULADOS" << "\t";
        archivoResultados << "NEOS" << endl;
        for (const auto &entryPrograma : mapadeProgramasAcademicos)
        {
            ProgramaAcademico *programaActual = entryPrograma.second;
            for (const auto &entryAno : programaActual->getMapaDeConsolidados())
            {
                int ano = entryAno.first;
                for (const auto &entrySexo : entryAno.second)
                {
                    int idSexo = entrySexo.first;
                    for (const auto &entrySemestre : entrySexo.second)
                    {
                        int semestre = entrySemestre.first;
                        Consolidado *consolidadoActual = entrySemestre.second;

                        archivoResultados << programaActual->getCodigoDeLaInstitucion() << "\t";
                        archivoResultados << programaActual->getIesPadre() << "\t";
                        archivoResultados << programaActual->getInstitucionDeEducacionSuperiorIes() << "\t";
                        archivoResultados << programaActual->getPrincipalOSeccional() << "\t";
                        archivoResultados << programaActual->getIdSectorIes() << "\t";
                        archivoResultados << programaActual->getSectorIes() << "\t";
                        archivoResultados << programaActual->getIdCaracter() << "\t";
                        archivoResultados << programaActual->getCaracterIes() << "\t";
                        archivoResultados << programaActual->getCodigoDelDepartamentoIes() << "\t";
                        archivoResultados << programaActual->getDepartamentoDeDomicilioDeLaIes() << "\t";
                        archivoResultados << programaActual->getCodigoDelMunicipioIes() << "\t";
                        archivoResultados << programaActual->getMunicipioDeDomicilioDeLaIes() << "\t";
                        archivoResultados << programaActual->getCodigoSniesDelPrograma() << "\t";
                        archivoResultados << programaActual->getProgramaAcademico() << "\t";
                        archivoResultados << programaActual->getIdNivelAcademico() << "\t";
                        archivoResultados << programaActual->getNivelAcademico() << "\t";
                        archivoResultados << programaActual->getIdNivelDeFormacion() << "\t";
                        archivoResultados << programaActual->getNivelDeFormacion() << "\t";
                        archivoResultados << programaActual->getIdMetodologia() << "\t";
                        archivoResultados << programaActual->getMetodologia() << "\t";
                        archivoResultados << programaActual->getIdArea() << "\t";
                        archivoResultados << programaActual->getAreaDeConocimiento() << "\t";
                        archivoResultados << programaActual->getIdNucleo() << "\t";
                        archivoResultados << programaActual->getNucleoBasicoDelConocimientoNbc() << "\t";
                        archivoResultados << programaActual->getIdCineCampoAmplio() << "\t";
                        archivoResultados << programaActual->getDescCineCampoAmplio() << "\t";
                        archivoResultados << programaActual->getIdCineCampoEspecifico() << "\t";
                        archivoResultados << programaActual->getDescCineCampoEspecifico() << "\t";
                        archivoResultados << programaActual->getIdCineCodigoDetallado() << "\t";
                        archivoResultados << programaActual->getDescCineCodigoDetallado() << "\t";
                        archivoResultados << programaActual->getCodigoDelDepartamentoPrograma() << "\t";
                        archivoResultados << programaActual->getDepartamentoDeOfertaDelPrograma() << "\t";
                        archivoResultados << programaActual->getCodigoDelMunicipioPrograma() << "\t";
                        archivoResultados << programaActual->getMunicipioDeOfertaDelPrograma() << "\t";
                        // Datos del consolidado
                        archivoResultados << consolidadoActual->getIdSexo() << "\t";
                        archivoResultados << consolidadoActual->getSexo() << "\t";
                        archivoResultados << consolidadoActual->getAno() << "\t";
                        archivoResultados << consolidadoActual->getSemestre() << "\t";
                        archivoResultados << consolidadoActual->getAdmitidos() << "\t";
                        archivoResultados << consolidadoActual->getGraduados() << "\t";
                        archivoResultados << consolidadoActual->getInscritos() << "\t";
                        archivoResultados << consolidadoActual->getMatriculados() << "\t";
                        archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre() << endl;
                    }
                }
            }
        }
        // Imprimimos ruta donde quedó el archivo
        cout << "Archivo TXT Creado en: " << ruta << endl;
    }
    archivoResultados.close();
}

bool GestorTxt::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir, const char &delimitador)
{
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.txt";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Iteramos sobre la matriz de datos
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Iteramos sobre cada fila y la imprimimos
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << " | ";  // Separador de columnas
                }
            }
            archivoExtra << endl;  // Nueva línea al final de cada fila
        }
        // Cambiamos el valor del booleano si todo salió bien
        estadoCreacion = true;
        cout << "Archivo TXT creado en: " << rutaCompleta << endl;
    }
    archivoExtra.close();
    return estadoCreacion;
}