#include "ProgramaAcademico.h"

using namespace std;


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

map<int, map<int, map<int, Consolidado *> > > ProgramaAcademico::getMapaDeConsolidados() {
    return mapConsolidados;
}

void ProgramaAcademico::setTodoElProgramaAcademico(vector<string> vectorConInfo, map<string, int> mapPosiciones)
{
    codigoDeLaInstitucion = stoi(vectorConInfo[mapPosiciones["CÓDIGO_DE_LA_INSTITUCIÓN" ]]);         // CÓDIGO DE LA INSTITUCIÓN
    iesPadre = stoi(vectorConInfo[mapPosiciones["IES_PADRE"]]);                      // IES_PADRE
    institucionDeEducacionSuperiorIes = vectorConInfo[mapPosiciones["INSTITUCIÓN_DE_EDUCACIÓN_SUPERIOR_(IES)"]];   // INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
    principalOSeccional = vectorConInfo[mapPosiciones["PRINCIPAL_O_SECCIONAL"]];                 // PRINCIPAL O SECCIONAL
    idSectorIes = stoi(vectorConInfo[mapPosiciones["ID_SECTOR_IES"]]);                   // ID SECTOR IES
    sectorIes = vectorConInfo[mapPosiciones["SECTOR_IES"]];                           // SECTOR IES
    idCaracter = stoi(vectorConInfo[mapPosiciones["ID_CARACTER"]]);                    // ID CARÁCTER
    caracterIes = vectorConInfo[mapPosiciones["CARACTER_IES"]];                         // CARACTER IES
    codigoDelDepartamentoIes = stoi(vectorConInfo[mapPosiciones["CÓDIGO_DEL_DEPARTAMENTO_(IES)"]]);      // CÓDIGO DEL DEPARTAMENTO (IES)
    departamentoDeDomicilioDeLaIes = vectorConInfo[mapPosiciones["DEPARTAMENTO_DE_DOMICILIO_DE_LA_IES"]];      // DEPARTAMENTO DE DOMICILIO DE LA IES
    codigoDelMunicipioIes = stoi(vectorConInfo[mapPosiciones["CÓDIGO_DEL_MUNICIPIO_(IES)"]]);        // CÓDIGO DEL MUNICIPIO IES
    municipioDeDomicilioDeLaIes = vectorConInfo[mapPosiciones["MUNICIPIO_DE_DOMICILIO_DE_LA_IES"]];        // MUNICIPIO DE DOMICILIO DE LA IES
    codigoSniesDelPrograma = stoi(vectorConInfo[mapPosiciones["CÓDIGO_SNIES_DEL_PROGRAMA"]]);       // CÓDIGO SNIES DEL PROGRAMA
    a = vectorConInfo[mapPosiciones["PROGRAMA_ACADÉMICO"]];                                  // PROGRAMA ACADÉMICO
    idNivelAcademico = stoi(vectorConInfo[mapPosiciones["ID_NIVEL_ACADÉMICO"]]);             // ID NIVEL ACADÉMICO
    nivelAcademico = vectorConInfo[mapPosiciones["NIVEL_ACADÉMICO"]];                     // NIVEL ACADÉMICO
    idNivelDeFormacion = stoi(vectorConInfo[mapPosiciones["ID_NIVEL_DE_FORMACIÓN"]]);             // ID NIVEL DE FORMACIÓN
    nivelDeFormacion = vectorConInfo[mapPosiciones["NIVEL_DE_FORMACIÓN"]];                   // NIVEL DE FORMACIÓN
    idMetodologia = stoi(vectorConInfo[mapPosiciones["ID_METODOLOGÍA"]]);                // ID METODOLOGÍA
    metodologia = vectorConInfo[mapPosiciones["METODOLOGÍA"]];                        // METODOLOGÍA
    idArea = stoi(vectorConInfo[mapPosiciones["ID_ÁREA_DE_CONOCIMIENTO"]]);                       // ID ÁREA
    areaDeConocimiento = vectorConInfo[mapPosiciones["ÁREA_DE_CONOCIMIENTO"]];                 // ÁREA DE CONOCIMIENTO
    idNucleo = stoi(vectorConInfo[mapPosiciones["ID_NÚCLEO"]]);                     // ID NÚCLEO
    nucleoBasicoDelConocimientoNbc = vectorConInfo[mapPosiciones["NÚCLEO_BÁSICO_DEL_CONOCIMIENTO_(NBC)"]];     // NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
    idCineCampoAmplio = stoi(vectorConInfo[mapPosiciones["ID_CINE_CAMPO_AMPLIO"]]);            // ID CINE CAMPO AMPLIO
    descCineCampoAmplio = vectorConInfo[mapPosiciones["DESC_CINE_CAMPO_AMPLIO"]];                // DESC CINE CAMPO AMPLIO
    idCineCampoEspecifico = stoi(vectorConInfo[mapPosiciones["ID_CINE_CAMPO_ESPECIFICO"]]);        // ID CINE CAMPO ESPECÍFICO
    descCineCampoEspecifico = vectorConInfo[mapPosiciones["DESC_CINE_CAMPO_ESPECIFICO"]];            // DESC CINE CAMPO ESPECÍFICO
    idCineCodigoDetallado = stoi(vectorConInfo[mapPosiciones["ID_CINE_CODIGO_DETALLADO"]]);        // ID CINE CÓDIGO DETALLADO
    descCineCodigoDetallado = vectorConInfo[mapPosiciones["DESC_CINE_CODIGO_DETALLADO"]];            // DESC CINE CÓDIGO DETALLADO
    codigoDelDepartamentoPrograma = stoi(vectorConInfo[mapPosiciones["CÓDIGO_DEL_DEPARTAMENTO_(PROGRAMA)"]]);    // CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
    departamentoDeOfertaDelPrograma = vectorConInfo[mapPosiciones["DEPARTAMENTO_DE_OFERTA_DEL_PROGRAMA"]];    // DEPARTAMENTO DE OFERTA DEL PROGRAMA
    codigoDelMunicipioPrograma = stoi(vectorConInfo[mapPosiciones["CÓDIGO_DEL_MUNICIPIO_(PROGRAMA)"]]);   // CÓDIGO DEL MUNICIPIO (PROGRAMA)
    municipioDeOfertaDelPrograma = vectorConInfo[mapPosiciones["MUNICIPIO_DE_OFERTA_DEL_PROGRAMA"]];       // MUNICIPIO DE OFERTA DEL PROGRAMA
}

ProgramaAcademico::~ProgramaAcademico()
{

}


/*
    CÓDIGO DE LA INSTITUCIÓN;
    CÓDIGO DE LA INSTITUCIÓN;
    IES_PADRE;
    INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES);
    PRINCIPAL O SECCIONAL;
    ID SECTOR IES;
    SECTOR IES;
    ID CARACTER;
    CARACTER IES;
    CÓDIGO DEL DEPARTAMENTO (IES);
    DEPARTAMENTO DE DOMICILIO DE LA IES;
    CÓDIGO DEL MUNICIPIO IES;
    MUNICIPIO DE DOMICILIO DE LA IES;
    CÓDIGO SNIES DEL PROGRAMA;
    PROGRAMA ACADÉMICO;
    ID NIVEL ACADÉMICO;
    NIVEL ACADÉMICO;
    ID NIVEL DE FORMACIÓN;
    NIVEL DE FORMACIÓN;
    ID METODOLOGÍA;
    METODOLOGÍA;
    ID ÁREA;
    ÁREA DE CONOCIMIENTO;
    ID NÚCLEO;
    NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC);
    ID CINE CAMPO AMPLIO;
    DESC CINE CAMPO AMPLIO;
    ID CINE CAMPO ESPECIFICO;
    DESC CINE CAMPO ESPECIFICO;
    ID CINE CODIGO DETALLADO;
    DESC CINE CODIGO DETALLADO;
    CÓDIGO DEL DEPARTAMENTO (PROGRAMA);
    DEPARTAMENTO DE OFERTA DEL PROGRAMA;
    CÓDIGO DEL MUNICIPIO (PROGRAMA);
    MUNICIPIO DE OFERTA DEL PROGRAMA;
    ID SEXO;
    SEXO;
    AÑO;
    SEMESTRE;
    ADMITIDOS;
     */