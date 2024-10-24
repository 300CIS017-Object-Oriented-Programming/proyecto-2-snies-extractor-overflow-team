//
// Created by Nicolas on 14/10/2024.
//

#include "GestorJson.h"
#include <iostream>
#include <fstream>

using namespace std;

void GestorJson::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos)
{
    json root; // Objeto principal JSON
    for (const auto &entryPrograma : mapadeProgramasAcademicos)
    {
        ProgramaAcademico *programaActual = entryPrograma.second;
        json jsonPrograma; // Objeto JSON para cada programa
        jsonPrograma["CÓDIGO DE LA INSTITUCIÓN"] = programaActual->getCodigoDeLaInstitucion();
        jsonPrograma["IES_PADRE"] = programaActual->getIesPadre();
        jsonPrograma["INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)"] = programaActual->getInstitucionDeEducacionSuperiorIes();
        jsonPrograma["PRINCIPAL O SECCIONAL"] = programaActual->getPrincipalOSeccional();
        jsonPrograma["ID SECTOR IES"] = programaActual->getIdSectorIes();
        jsonPrograma["SECTOR IES"] = programaActual->getSectorIes();
        jsonPrograma["ID CARACTER"] = programaActual->getIdCaracter();
        jsonPrograma["CARACTER IES"] = programaActual->getCaracterIes();
        jsonPrograma["CÓDIGO DEL DEPARTAMENTO (IES)"] = programaActual->getCodigoDelDepartamentoIes();
        jsonPrograma["DEPARTAMENTO DE DOMICILIO DE LA IES"] = programaActual->getDepartamentoDeDomicilioDeLaIes();
        jsonPrograma["CÓDIGO DEL MUNICIPIO IES"] = programaActual->getCodigoDelMunicipioIes();
        jsonPrograma["MUNICIPIO DE DOMICILIO DE LA IES"] = programaActual->getMunicipioDeDomicilioDeLaIes();
        jsonPrograma["CÓDIGO SNIES DEL PROGRAMA"] = programaActual->getCodigoSniesDelPrograma();
        jsonPrograma["PROGRAMA ACADÉMICO"] = programaActual->getProgramaAcademico();
        jsonPrograma["ID NIVEL ACADÉMICO"] = programaActual->getIdNivelAcademico();
        jsonPrograma["NIVEL ACADÉMICO"] = programaActual->getNivelAcademico();
        jsonPrograma["ID NIVEL DE FORMACIÓN"] = programaActual->getIdNivelDeFormacion();
        jsonPrograma["NIVEL DE FORMACIÓN"] = programaActual->getNivelDeFormacion();
        jsonPrograma["ID METODOLOGÍA"] = programaActual->getIdMetodologia();
        jsonPrograma["METODOLOGÍA"] = programaActual->getMetodologia();
        jsonPrograma["ID ÁREA"] = programaActual->getIdArea();
        jsonPrograma["ÁREA DE CONOCIMIENTO"] = programaActual->getAreaDeConocimiento();
        jsonPrograma["ID NÚCLEO"] = programaActual->getIdNucleo();
        jsonPrograma["NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)"] = programaActual->getNucleoBasicoDelConocimientoNbc();
        jsonPrograma["ID CINE CAMPO AMPLIO"] = programaActual->getIdCineCampoAmplio();
        jsonPrograma["DESC CINE CAMPO AMPLIO"] = programaActual->getDescCineCampoAmplio();
        jsonPrograma["ID CINE CAMPO ESPECIFICO"] = programaActual->getIdCineCampoEspecifico();
        jsonPrograma["DESC CINE CAMPO ESPECIFICO"] = programaActual->getDescCineCampoEspecifico();
        jsonPrograma["ID CINE CODIGO DETALLADO"] = programaActual->getIdCineCodigoDetallado();
        jsonPrograma["DESC CINE CODIGO DETALLADO"] = programaActual->getDescCineCodigoDetallado();
        jsonPrograma["CÓDIGO DEL DEPARTAMENTO (PROGRAMA)"] = programaActual->getCodigoDelDepartamentoPrograma();
        jsonPrograma["DEPARTAMENTO DE OFERTA DEL PROGRAMA"] = programaActual->getDepartamentoDeOfertaDelPrograma();
        jsonPrograma["CÓDIGO DEL MUNICIPIO (PROGRAMA)"] = programaActual->getCodigoDelMunicipioPrograma();
        jsonPrograma["MUNICIPIO DE OFERTA DEL PROGRAMA"] = programaActual->getMunicipioDeOfertaDelPrograma();
        for (const auto &entryAno : programaActual->getMapaDeConsolidados())
        {
            int ano = entryAno.first; // Año del consolidado
            for (const auto &entrySexo : entryAno.second)
            {
                int idSexo = entrySexo.first; // ID del sexo
                for (const auto &entrySemestre : entrySexo.second)
                {
                    int semestre = entrySemestre.first; // Semestre del consolidado
                    Consolidado *consolidadoActual = entrySemestre.second;
                    json jsonConsolidado; // Objeto JSON para cada consolidado
                    jsonConsolidado["ID SEXO"] = idSexo;
                    jsonConsolidado["SEXO"] = consolidadoActual->getSexo();
                    jsonConsolidado["AÑO"] = ano;
                    jsonConsolidado["SEMESTRE"] = semestre;
                    jsonConsolidado["ADMITIDOS"] = consolidadoActual->getAdmitidos();
                    jsonConsolidado["GRADUADOS"] = consolidadoActual->getGraduados();
                    jsonConsolidado["INSCRITOS"] = consolidadoActual->getInscritos();
                    jsonConsolidado["MATRICULADOS"] = consolidadoActual->getMatriculados();
                    jsonConsolidado["NEOS"] = consolidadoActual->getMatriculadosPrimerSemestre();
                    // Añadimos cada consolidado al programa académico
                    jsonPrograma["Consolidados"].push_back(jsonConsolidado);
                }
            }
        }
        // Añadimos el programa académico a la raíz del JSON
        root["Programas"].push_back(jsonPrograma);
    }
    // Guardamos el archivo JSON
    std::ofstream archivoResultados(ruta);
    archivoResultados << root.dump(4); // 4 es el nivel de indentación
    archivoResultados.close();
    // Imprimimos ruta donde quedó el archivo
    cout << "Archivo JSON creado en: " << ruta << endl;
}

bool GestorJson::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creó el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.json";
    json jsonDatos;
    // Abrimos el archivo JSON
    std::ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Iteramos sobre las filas de datos
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            json filaJson = json::array(); // Creamos una fila como un array JSON
            // Iteramos sobre las columnas de cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Añadimos cada elemento a la fila
                filaJson.push_back(datosAImprimir[i][j]);
            }
            // Añadimos la fila al JSON principal
            jsonDatos["fila_" + std::to_string(i)] = filaJson;
        }
        // Escribimos el contenido JSON en el archivo con una indentación de 4 espacios
        archivoExtra << jsonDatos.dump(4);
        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedó el archivo
        cout << "Archivo JSON creado en: " << rutaCompleta << endl;
    }
    archivoExtra.close();
    return estadoCreacion;
}