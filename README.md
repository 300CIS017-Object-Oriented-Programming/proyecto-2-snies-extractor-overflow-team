[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/QApazJy0)

## SNIES Extractor
Gracias al grupo que me presetó el código fuente de este proyecto

## Presentación general
En este proyecto se utiliza 8 clases para cumplir el propósito de extraer la información del Sistema Nacional de Información de Educación Superior. Para el usuario, este tendrá una interfaz por terminal que le indicará los pasos a seguir y la información que necesita digitar.


## Cumplimiento de Requerimientos

1. **Solicitar rango de años a analizar**  
   En el menú, se le pregunta al usuario el rango de años de búsqueda.
![img_1.png](docs/images/img_1.png)
2. **Lectura de archivos .csv correspondientes**  
   A partir de los años ingresados por el usuario, el controlador (clase `SNIESController`) leerá la información de los archivos apropiados uno por uno.

3. **Calcular admitidos, inscritos, graduados, matriculados y matriculados de primer semestre por programa y por año**  
   El SNIES-Extractor, mediante su controlador, leerá estos datos en los archivos correspondientes y en los años de búsqueda solicitados

4. **Generación de Archivos de Salida**  
   Al terminar de extraer la información y procesarla, el SNIES-Extractor generará un archivo de resultados en la siguiente carpeta que ya debería estar parametrizada en el disco duro:  
   `C:\SNIES_EXTRACTOR\outputs\resultados.csv`.
![img.png](docs/images/img.png)
![img_3.png](docs%2Fimages%2Fimg_3.png)
![img_2.png](docs%2Fimages%2Fimg_2.png)

5. **Visualización de Datos**  
   **(PENDIENTE)** El SNIES-Extractor muestra al usuario el consolidado de estudiantes por año en programas presenciales o virtuales, la diferencia porcentual anual entre la cantidad de nuevos matriculados durante los años de búsqueda por programa y la lista de programas sin nuevos matriculados en 3 semestres consecutivos. Además, permitirá al usuario exportar esta información en un archivo ubicado en la carpeta ya parametrizada:  
   `C:\SNIES_EXTRACTOR\outputs\extras.csv`.

6. **Filtrado de Programas**  
   Se le pregunta al usuario si desea hacer una búsqueda con 2 filtros entre los programas solicitados: una palabra clave para buscar según los nombres de programas y el nivel de formación de los programas.
![img_4.png](docs%2Fimages%2Fimg_4.png)
![img_5.png](docs%2Fimages%2Fimg_5.png)
![img_6.png](docs%2Fimages%2Fimg_6.png)
![img_7.png](docs%2Fimages%2Fimg_7.png)


7. **Validación de Datos**  
   El SNIES-Extractor es un programa de C++ robusto que puede detectar errores a la hora de recibir información fuera de rangos esperados, tanto de parte del usuario como de la lectura de los archivos .csv.


## **MEJORAS FUNCIONALES**
1. El programa soporta cualquier tamaño de archivos gracias a funciones de lectura y almacenamiento de las posiciones de las columnas
2. El programa soporta cualquier rango de años. Solo debe tener en la carpeta de inputs los archivos en los que se desesa buscar.
![img_8.png](docs%2Fimages%2Fimg_8.png)
![img_9.png](docs%2Fimages%2Fimg_9.png)
![img_10.png](docs%2Fimages%2Fimg_10.png)
En este caso, los datos de _ADMITIDOS_ del 2023 están en blanco ya que el archivo admitidos2023.csv tiene en la columna de años, en vez de un 2023, tiene un 2021. Esto hace que el consolidado se guarde en el correspondiente año (en 2021) 
Por lo tanto, para el correcto funcionamiento del código, las columnas deben estar bien hechas.

3. El sistema genera archivos únicamente archivos CSV. TXT y JSON aún no están oganizados para que funcionen con el mapa de Consolidados.
4. (RECOMENDACIÓN) El programa usa mapas en vez de vectores e índices para ubicarse. Se ubican gracias a las claves y los nombres que se guardan en los mapas.
5. El delimitador de caracteres puede cambiar fácilmente ya que se ubica en settings.
![img_11.png](docs%2Fimages%2Fimg_11.png)


# Diagrama Mermaid


```mermaid
classDiagram
   direction BT
   class ProgramaAcademico {
      -int codigoDeLaInstitucion
      -int iesPadre
      -map<int, map<int, map<int, Consolidado *>>> mapConsolidados;

      +ProgramaAcademico()
      +~ProgramaAcademico()
      +set()
      +get()
      +Consolidado * getConsolidadoDeMapa()
      +map<int, map<int, map<int, Consolidado *>>> getMapaDeConsolidados()
      +void setMapConsolidados()
      +void setTodoElProgramaAcademico()
   }
   class Consolidado {
      -int inscritos
      -int admitidos
      -int matriculadosPrimerSemestre
      -int matriculados
      -int graduados
      -int idSexo
      -string sexo
      -int ano
      -int semestre
      +set()
      +get()

   }
   class GestorBase {
      <<abstract>>
      +void crearArchivo()
      +bool crearArchivosExtra()
   }

   class GestorCsv {
      +GestorCsv() = default
      +void crearArchivo() override
      +bool crearArchivoExtra() override

      +vector<int> leerProgramasCsv()
      +void leerArchivo()
      +map<string, int> conseguirPosicionesColumnas()
      +int conseguirCantColumnas()
      +string quitarEspacioYAgregarMayus()
   }

   class GestorTxt {
      +GestorTxt() = default
      +void crearArchivo() override
      +bool crearArchivoExtra() override
   }

   class GestorJson {
      +GestorJson() = default
      +void crearArchivo() override
      +bool crearArchivoExtra() override
   }

   class SNIESController {
      -map <int, ProgramaAcademico*> programasAcademicos
      -GestorCsv * gestorCsvObj;
      -GestorTxt *gestorTxtObj;
      -GestorJson *gestorJsonObj;
      -vector<string> etiquetasColumnas
      -string rutaProgramasCsv
      -string rutaAdmitidos
      -string rutaGraduados
      -string rutaInscritos
      -string rutaMatriculados
      -string rutaMatriculadosPrimerSemestre
      -string rutaOutputResultados;
      -string rutaOutputFiltrado;
      +SNIESController("incializar con strings de rutas")
      +~SNIESController()
      +void procesarDatosCsv()
      +void calcularDatosExtra()
      +void buscarProgramas()
   }
   class View {
      SNIESController controlador
      +View()
      +~View()
      +bool pantallaBienvenido()
      +void visualizacionDatosExtra()
      +void buscarPorPalabraClaveYFormacion()
      +void salir()
      +bool isConvetibleToInt()
   }
   class Main {
      + int main()
   }

   ProgramaAcademico o-- Consolidado : tiene varios
   View <.. Main : usa
   View --> SNIESController : tiene un
   GestorBase <|-- GestorCsv : hereda
   GestorBase <|-- GestorTxt : hereda
   GestorBase <|-- GestorJson : hereda
   SNIESController o-- GestorBase: tiene

   SNIESController o-- ProgramaAcademico
```