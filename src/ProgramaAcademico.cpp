#include "ProgramaAcademico.h"

using namespace std;

ProgramaAcademico::ProgramaAcademico()
{
    consolidados = vector<Consolidado *>(8);
}

void ProgramaAcademico::setCodigoDeLaInstitucion(int nuevoCodigoDeLaInstitucion)
{
    codigoDeLaInstitucion = nuevoCodigoDeLaInstitucion;
}

int ProgramaAcademico::getCodigoDeLaInstitucion()
{
    return codigoDeLaInstitucion;
}

void ProgramaAcademico::setIesPadre(int nuevoIesPadre)
{
    iesPadre = nuevoIesPadre;
}

int ProgramaAcademico::getIesPadre()
{
    return iesPadre;
}

void ProgramaAcademico::setInstitucionDeEducacionSuperiorIes(string &nuevoInstitucionDeEducacionSuperiorIes)
{
    institucionDeEducacionSuperiorIes = nuevoInstitucionDeEducacionSuperiorIes;
}
string ProgramaAcademico::getInstitucionDeEducacionSuperiorIes()
{
    return institucionDeEducacionSuperiorIes;
}

void ProgramaAcademico::setPrincipalOSeccional(string &nuevoPrincipalOSeccional)
{
    principalOSeccional = nuevoPrincipalOSeccional;
}

string ProgramaAcademico::getPrincipalOSeccional()
{
    return principalOSeccional;
}

void ProgramaAcademico::setIdSectorIes(int nuevoIdSectorIes)
{
    idSectorIes = nuevoIdSectorIes;
}

int ProgramaAcademico::getIdSectorIes()
{
    return idSectorIes;
}

void ProgramaAcademico::setSectorIes(string &nuevoSectorIes)
{
    sectorIes = nuevoSectorIes;
}

string ProgramaAcademico::getSectorIes()
{
    return sectorIes;
}

void ProgramaAcademico::setIdCaracter(int nuevoIdCaracter)
{
    idCaracter = nuevoIdCaracter;
}

int ProgramaAcademico::getIdCaracter()
{
    return idCaracter;
}

void ProgramaAcademico::setCaracterIes(string &nuevoCaracterIes)
{
    caracterIes = nuevoCaracterIes;
}

string ProgramaAcademico::getCaracterIes()
{
    return caracterIes;
}

void ProgramaAcademico::setCodigoDelDepartamentoIes(int nuevoCodigoDelDepartamentoIes)
{
    codigoDelDepartamentoIes = nuevoCodigoDelDepartamentoIes;
}

int ProgramaAcademico::getCodigoDelDepartamentoIes()
{
    return codigoDelDepartamentoIes;
}

void ProgramaAcademico::setDepartamentoDeDomicilioDeLaIes(string &nuevoDepartamentoDeDomicilioDeLaIes)
{
    departamentoDeDomicilioDeLaIes = nuevoDepartamentoDeDomicilioDeLaIes;
}

string ProgramaAcademico::getDepartamentoDeDomicilioDeLaIes()
{
    return departamentoDeDomicilioDeLaIes;
}

void ProgramaAcademico::setCodigoDelMunicipioIes(int nuevoCodigoDelMunicipioIes)
{
    codigoDelMunicipioIes = nuevoCodigoDelMunicipioIes;
}

int ProgramaAcademico::getCodigoDelMunicipioIes()
{
    return codigoDelMunicipioIes;
}

void ProgramaAcademico::setMunicipioDeDomicilioDeLaIes(string &nuevoMunicipioDeDomicilioDeLaIes)
{
    municipioDeDomicilioDeLaIes = nuevoMunicipioDeDomicilioDeLaIes;
}

string ProgramaAcademico::getMunicipioDeDomicilioDeLaIes()
{
    return municipioDeDomicilioDeLaIes;
}

void ProgramaAcademico::setCodigoSniesDelPrograma(int nuevoCodigoSniesDelPrograma)
{
    codigoSniesDelPrograma = nuevoCodigoSniesDelPrograma;
}

int ProgramaAcademico::getCodigoSniesDelPrograma()
{
    return codigoSniesDelPrograma;
}

void ProgramaAcademico::setProgramaAcademico(string &nuevoProgramaAcademico)
{
    a = nuevoProgramaAcademico;
}

string ProgramaAcademico::getProgramaAcademico()
{
    return a;
}

void ProgramaAcademico::setIdNivelAcademico(int nuevoIdNivelAcademico)
{
    idNivelAcademico = nuevoIdNivelAcademico;
}

int ProgramaAcademico::getIdNivelAcademico()
{
    return idNivelAcademico;
}

void ProgramaAcademico::setNivelAcademico(string &nuevoNivelAcademico)
{
    nivelAcademico = nuevoNivelAcademico;
}

string ProgramaAcademico::getNivelAcademico()
{
    return nivelAcademico;
}

void ProgramaAcademico::setIdNivelDeFormacion(int nuevoIdNivelDeFormacion)
{
    idNivelDeFormacion = nuevoIdNivelDeFormacion;
}

int ProgramaAcademico::getIdNivelDeFormacion()
{
    return idNivelDeFormacion;
}

void ProgramaAcademico::setNivelDeFormacion(string &nuevoNivelDeFormacion)
{
    nivelDeFormacion = nuevoNivelDeFormacion;
}

string ProgramaAcademico::getNivelDeFormacion()
{
    return nivelDeFormacion;
}

void ProgramaAcademico::setIdMetodologia(int nuevoIdMetodologia)
{
    idMetodologia = nuevoIdMetodologia;
}

int ProgramaAcademico::getIdMetodologia()
{
    return idMetodologia;
}

void ProgramaAcademico::setMetodologia(string &nuevaMetodologia)
{
    metodologia = nuevaMetodologia;
}

string ProgramaAcademico::getMetodologia()
{
    return metodologia;
}

void ProgramaAcademico::setIdArea(int nuevoIdArea)
{
    idArea = nuevoIdArea;
}

int ProgramaAcademico::getIdArea()
{
    return idArea;
}

void ProgramaAcademico::setAreaDeConocimiento(string &areaConocimiento)
{
    areaDeConocimiento = areaConocimiento;
}
string ProgramaAcademico::getAreaDeConocimiento()
{
    return areaDeConocimiento;
}

void ProgramaAcademico::setIdNucleo(int nuevoIdNucleo)
{
    idNucleo = nuevoIdNucleo;
}
int ProgramaAcademico::getIdNucleo()
{
    return idNucleo;
}

void ProgramaAcademico::setNucleoBasicoDelConocimientoNbc(string &nuevoNucleoBasicoDelConocimientoNbc)
{
    nucleoBasicoDelConocimientoNbc = nuevoNucleoBasicoDelConocimientoNbc;
}
string ProgramaAcademico::getNucleoBasicoDelConocimientoNbc()
{
    return nucleoBasicoDelConocimientoNbc;
}

void ProgramaAcademico::setIdCineCampoAmplio(int nuevoIdCineCampoAmplio)
{
    idCineCampoAmplio = nuevoIdCineCampoAmplio;
}
int ProgramaAcademico::getIdCineCampoAmplio()
{
    return idCineCampoAmplio;
}

void ProgramaAcademico::setDescCineCampoAmplio(string &nuevoDescCineCampoAmplio)
{
    descCineCampoAmplio = nuevoDescCineCampoAmplio;
}
string ProgramaAcademico::getDescCineCampoAmplio()
{
    return descCineCampoAmplio;
}

void ProgramaAcademico::setIdCineCampoEspecifico(int nuevoIdCineCampoEspecifico)
{
    idCineCampoEspecifico = nuevoIdCineCampoEspecifico;
}
int ProgramaAcademico::getIdCineCampoEspecifico()
{
    return idCineCampoEspecifico;
}

void ProgramaAcademico::setDescCineCampoEspecifico(string &nuevoDescCineCampoEspecifico)
{
    descCineCampoEspecifico = nuevoDescCineCampoEspecifico;
}

string ProgramaAcademico::getDescCineCampoEspecifico()
{
    return descCineCampoEspecifico;
}

void ProgramaAcademico::setIdCineCodigoDetallado(int nuevoIdCineCodigoDetallado)
{
    idCineCodigoDetallado = nuevoIdCineCodigoDetallado;
}
int ProgramaAcademico::getIdCineCodigoDetallado()
{
    return idCineCodigoDetallado;
}

void ProgramaAcademico::setDescCineCodigoDetallado(string &nuevoDescCineCodigoDetallado)
{
    descCineCodigoDetallado = nuevoDescCineCodigoDetallado;
}
string ProgramaAcademico::getDescCineCodigoDetallado()
{
    return descCineCodigoDetallado;
}

void ProgramaAcademico::setCodigoDelDepartamentoPrograma(int nuevoCodigoDelDepartamentoPrograma)
{
    codigoDelDepartamentoPrograma = nuevoCodigoDelDepartamentoPrograma;
}
int ProgramaAcademico::getCodigoDelDepartamentoPrograma()
{
    return codigoDelDepartamentoPrograma;
}

void ProgramaAcademico::setDepartamentoDeOfertaDelPrograma(string &nuevoDepartamentoDeOfertaDelPrograma)
{
    departamentoDeOfertaDelPrograma = nuevoDepartamentoDeOfertaDelPrograma;
}
string ProgramaAcademico::getDepartamentoDeOfertaDelPrograma()
{
    return departamentoDeOfertaDelPrograma;
}

void ProgramaAcademico::setCodigoDelMunicipioPrograma(int nuevoCodigoDelMunicipioPrograma)
{
    codigoDelMunicipioPrograma = nuevoCodigoDelMunicipioPrograma;
}
int ProgramaAcademico::getCodigoDelMunicipioPrograma()
{
    return codigoDelMunicipioPrograma;
}

void ProgramaAcademico::setMunicipioDeOfertaDelPrograma(string &nuevoMunicipioDeOfertaDelPrograma)
{
    municipioDeOfertaDelPrograma = nuevoMunicipioDeOfertaDelPrograma;
}
string ProgramaAcademico::getMunicipioDeOfertaDelPrograma()
{
    return municipioDeOfertaDelPrograma;
}

void ProgramaAcademico::setConsolidado(Consolidado *nuevoConsolidado, int pos)
{
    consolidados[pos] = nuevoConsolidado;
}

Consolidado *ProgramaAcademico::getConsolidado(int posicionConsolidado)
{
    return consolidados[posicionConsolidado];
}

void ProgramaAcademico::setMapConsolidados(int anio, int idSexo, int semestre, Consolidado *consolidado)
{
    mapConsolidados[anio][idSexo][semestre] = consolidado;
}

Consolidado * ProgramaAcademico::getConsolidadoDeMapa(int anio, int idSexo, int semestre)
// (Función solicitada a ChatGPT)
// Evalúa si el consolidado existe para que no se creen entradas indeseadas cómo cuando se accede con []
{
    // Verificamos si existe el anio
    auto itAnio = mapConsolidados.find(anio);
    if (itAnio != mapConsolidados.end()) {
        // Verificamos si existe el idSexo dentro del anio
        auto itSexo = itAnio->second.find(idSexo);
        if (itSexo != itAnio->second.end()) {
            // Verificamos si existe el semestre dentro del idSexo
            auto itSemestre = itSexo->second.find(semestre);
            if (itSemestre != itSexo->second.end()) {
                // Si lo anterior existe, devolvemos el Consolidado correspondiente
                return itSemestre->second;
            }
        }
    }
    // Si no existe la combinación de claves, retornamos nullptr
    return nullptr;
}
// TODO: HACER FUNCIÓN PARA SETTEAR TODO EL PROGRAMA ACADÉMICO.
void ProgramaAcademico::setTodoElProgramaAcademico(vector<string> vectorConInfo)
{
    codigoDeLaInstitucion = stoi(vectorConInfo[0]);         // CÓDIGO DE LA INSTITUCIÓN
    iesPadre = stoi(vectorConInfo[1]);                      // IES_PADRE
    institucionDeEducacionSuperiorIes = vectorConInfo[2];   // INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
    principalOSeccional = vectorConInfo[3];                 // PRINCIPAL O SECCIONAL
    idSectorIes = stoi(vectorConInfo[4]);                   // ID SECTOR IES
    sectorIes = vectorConInfo[5];                           // SECTOR IES
    idCaracter = stoi(vectorConInfo[6]);                    // ID CARÁCTER
    caracterIes = vectorConInfo[7];                         // CARACTER IES
    codigoDelDepartamentoIes = stoi(vectorConInfo[8]);      // CÓDIGO DEL DEPARTAMENTO (IES)
    departamentoDeDomicilioDeLaIes = vectorConInfo[9];      // DEPARTAMENTO DE DOMICILIO DE LA IES
    codigoDelMunicipioIes = stoi(vectorConInfo[10]);        // CÓDIGO DEL MUNICIPIO IES
    municipioDeDomicilioDeLaIes = vectorConInfo[11];        // MUNICIPIO DE DOMICILIO DE LA IES
    codigoSniesDelPrograma = stoi(vectorConInfo[12]);       // CÓDIGO SNIES DEL PROGRAMA
    a = vectorConInfo[13];                                  // PROGRAMA ACADÉMICO
    idNivelAcademico = stoi(vectorConInfo[14]);             // ID NIVEL ACADÉMICO
    nivelAcademico = vectorConInfo[15];                     // NIVEL ACADÉMICO
    idNivelDeFormacion = stoi(vectorConInfo[16]);             // ID NIVEL DE FORMACIÓN
    nivelDeFormacion = vectorConInfo[17];                   // NIVEL DE FORMACIÓN
    idMetodologia = stoi(vectorConInfo[18]);                // ID METODOLOGÍA
    metodologia = vectorConInfo[19];                        // METODOLOGÍA
    idArea = stoi(vectorConInfo[20]);                       // ID ÁREA
    areaDeConocimiento = vectorConInfo[21];                 // ÁREA DE CONOCIMIENTO
    idNucleo = stoi(vectorConInfo[22]);                     // ID NÚCLEO
    nucleoBasicoDelConocimientoNbc = vectorConInfo[23];     // NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
    idCineCampoAmplio = stoi(vectorConInfo[24]);            // ID CINE CAMPO AMPLIO
    descCineCampoAmplio = vectorConInfo[25];                // DESC CINE CAMPO AMPLIO
    idCineCampoEspecifico = stoi(vectorConInfo[26]);        // ID CINE CAMPO ESPECÍFICO
    descCineCampoEspecifico = vectorConInfo[27];            // DESC CINE CAMPO ESPECÍFICO
    idCineCodigoDetallado = stoi(vectorConInfo[28]);        // ID CINE CÓDIGO DETALLADO
    descCineCodigoDetallado = vectorConInfo[29];            // DESC CINE CÓDIGO DETALLADO
    codigoDelDepartamentoPrograma = stoi(vectorConInfo[30]);    // CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
    departamentoDeOfertaDelPrograma = vectorConInfo[31];    // DEPARTAMENTO DE OFERTA DEL PROGRAMA
    codigoDelMunicipioPrograma = stoi(vectorConInfo[32]);   // CÓDIGO DEL MUNICIPIO (PROGRAMA)
    municipioDeOfertaDelPrograma = vectorConInfo[33];       // MUNICIPIO DE OFERTA DEL PROGRAMA
}

ProgramaAcademico::~ProgramaAcademico()
{
    for (Consolidado *consolidado : consolidados)
    {
        delete consolidado;
    }
}