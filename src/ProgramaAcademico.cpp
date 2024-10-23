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
    programaAcademico = nuevoProgramaAcademico;
}

string ProgramaAcademico::getProgramaAcademico()
{
    return programaAcademico;
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

Consolidado * ProgramaAcademico::getMapConsolidados(int anio, int idSexo, int semestre)
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


ProgramaAcademico::~ProgramaAcademico()
{
    for (Consolidado *consolidado : consolidados)
    {
        delete consolidado;
    }
}