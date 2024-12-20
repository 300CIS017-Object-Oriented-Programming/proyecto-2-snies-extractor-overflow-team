#include "View.h"
#include "Settings.h"


View::View()
{
    controlador = SNIESController();
    controlador.rutaProgramasCSV = Settings::PROGRAMAS_FILTRAR_FILE_PATH;
    controlador.rutaAdmitidos = Settings::ADMITIDOS_FILE_PATH;
    controlador.rutaGraduados = Settings::GRADUADOS_FILE_PATH;
    controlador.rutaInscritos = Settings::INSCRITOS_FILE_PATH;
    controlador.rutaMatriculados = Settings::MATRICULADOS_FILE_PATH;
    controlador.rutaMatriculadosPrimerSemestre = Settings::MATRICULADOS_PRIMER_SEMESTRE_FILE_PATH;
    controlador.rutaOutputResultados = Settings::RESULTADO_FILE_PATH;
    controlador.rutaOutputFiltrado = Settings::FILTRADO_FILE_PATH;

}
bool View::mostrarPantallaBienvenido()
{
    const char delimitador = Settings::DELIMITADOR;
    // Mantenimiento: Nombre confuso de la variable, cambiar a algo más descriptivo
    bool parametrizacionBool = false;

    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "=========================================" << endl;
    cout << "Recuerde que para el correcto funcionamiento del programa tuvo que haber parametrizado" << endl;
    cout << "antes la carpeta SNIES_EXTRACTOR en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivo CSV del SNIES." << endl;
    cout << "Si ya hizo esto, escriba 'Y', de lo contrario 'N', y Enter: " << endl;
    char userAnswer = 'Y';
    // cin >> userAnswer;
    // cout << endl;
    userAnswer = static_cast<char>(tolower(userAnswer));
    // Código muy extenso, se puede simplificar
    if (userAnswer == 'y')
    {
        parametrizacionBool = true;

        string userText;
        cout << "A continuacion se procesaran los datos de los programas academicos seleccionados en /programas.csv..." << endl;
        // Manteniemiento: Cambiar el nombre de las variables a algo más descriptivo
        // y quitar las variables que no se usan
        string anio1("abc");
        string ano2("abc");
        int i = 0;
        bool anosValido = false;
        // FIXME pasar la lógica del bucle a un método reutlizable
        // Usar en el while una bandera y simplificar el código
        // Bucle para leer un valor valido del año1
        // Mantenimiento: Alta complejidad y repetición de código, refactorizar.
        while (!(isConvetibleToInt(anio1)))
        {
            if (i == 1)
            {
                cout << "El valor ingresado fue invalido!" << endl;
                cout << "Por favor ingrese un valor valido la proxima" << endl;
                cout << "Presione 'OK' y Enter para continuar: " << endl;
                cin >> userText;
                cout << endl;
            }
            cout << "Escriba el primer ano de busqueda: " << endl;
            cin >> anio1;
            cout << endl;
            i = 1;
        }

        i = 0;
        // Bucle para leer un valor valido del año2
        while (!(isConvetibleToInt(ano2)))
        {
            if (i == 1)
            {
                cout << "El valor ingresado fue invalido!" << endl;
                cout << "Por favor ingrese un valor valido la proxima" << endl;
                cout << "Presione 'OK' y Enter para continuar: " << endl;
                cin >> userText;
                cout << endl;
            }
            cout << "Escriba el segundo ano de busqueda: " << endl;
            cin >> ano2;
            cout << endl;
            i = 1;
        }

        // Organizo los años
        // FIXME: Crear un método para hacer que el segundo año sea siempre
        // mayor que el primer año
        // Mantenimiento: Simplificar el código, implementar o usar funciones auxiliares como swap
        if (stoi(ano2) < stoi(anio1))
        {
            swap(anio1,ano2);
        }

        cout << "Procesando datos ..." << endl;
        controlador.procesarDatosCsv(anio1, ano2, delimitador);
        cout << "Datos procesados con exito!" << endl;
    }
    return parametrizacionBool;
}

// Mantenimiento: Mejorar el nombre del metodo, es posible hacerlo más claro.
void View::salir()
{
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
}

// Mantenimiento: Mejorar el nombre del metodo, es posible hacerlo más claro.
void View::mostrarDatosExtra()
{
    // Mantenimiento: La variable opcionYN se relaciona con otra de otros métodos, pero no tienen el
    // mismo nombre, la estructura es confusa.
    char opcionYN;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << "\n"
         << endl;
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): " << endl;
    cin >> opcionYN;
    // Recomendacion Linter: No dejar la conversión implicita de int a char.
    opcionYN = tolower(opcionYN);
    cout << "\n";
    // FIXME verificar que el usuario ingrese un valor igual al esperado, return true si es Y, false si es N, y no sale si no retorna un valor válido
    // Simplificar el código de acuerdo a ese ajuste
    if (opcionYN == 'y')
    {
        //controlador.calcularDatosExtra(true);
    }

    else
    {
        //controlador.calcularDatosExtra(false);
    }
}

// Mantenimiento: Mejorar el nombre del metodo, es posible hacerlo más claro.
void View::buscarPorPalabraClaveYFormacion()
{
    // Mantenimiento: La variable opcionYN se relaciona con otra de otros métodos, pero no tienen el
    // mismo nombre, la estructura es confusa.
    const char delimitador = Settings::DELIMITADOR;
    char opcionYN = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> opcionYN;
        // Recomendacion Linter: es preferible usar endl a \n.
        cout << "\n";
        opcionYN = tolower(opcionYN);

        // Alta complejidad ciclomática, refactorizar
        if (opcionYN == 'y')
        {
            // Coesión y Organización: Baja coesión, este metodo hace cosas que no debería,
            // separar en métodos más pequeños
            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formacion para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n 3->Doctorado\n 4->Formacion Tecnica Profesional \n 5->Tecnologico\n 6->Universitario\n 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n 10->Especializacion Medico Quirurgica\n " << endl;
            cin >> idFormacionAcademica;
            cout << "\n";
            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n"
                     << endl;
                cin >> idFormacionAcademica;
            }

            cout << "Deseas exportar los datos del programa academico en un archivo?(Y/N): " << endl;
            cin >> opcionCSV;
            cout << "\n";
            opcionCSV = tolower(opcionCSV);

            if (opcionCSV == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica, delimitador);
        }
    }
}

bool View::isConvetibleToInt(const string &str)
{
    try
    {
        std::size_t pos;
        // Recomendación Linter: La variable num nunca se usa.
        int num = std::stoi(str, &pos);

        // Verificamos si se ha convertido toda la cadena
        return pos == str.length();
    }
    catch (const std::invalid_argument &)
    {
        // No se pudo convertir: la cadena no es un número válido
        return false;
    }
    catch (const std::out_of_range &)
    {
        // No se pudo convertir: el número está fuera del rango de int
        return false;
    }
}