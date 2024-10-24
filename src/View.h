#ifndef VIEW_H
#define VIEW_H
#include "SNIESController.h"
//Todo el codigo va entre estas guarda

#include <cctype>
// Recomendación Linter: Dejar de usar using namespace std y usar std::.
using namespace std;

class View
{
private:
    SNIESController controlador;

public:
    View()=default;
    ~View()=default;
    // Estructura: El View debería tener solo una función pública.
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra();
    void buscarPorPalabraClaveYFormacion();
    void cerrarPrograma();
    // Recomendación Linter: La función isConvetibleToInt debería ser privada.
    bool isConvetibleToInt(const string &);
};

#endif