#include <iostream>
using namespace std;
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Catalogo.h"
#include "Streaming.h"
#include "ExcepcionStreaming.h"
#include <fstream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::getline;
using std::ignore;

Streaming::Streaming() {}

void Streaming::start()
{
    catalogo.leerCatalogo();
    menu();
}
void Streaming::menu()
{
    opcion = "1";

    while (opcion != "6")
    {
        try
        {
            cout << "¡Bienvenido!" << endl;
            cout << "----------------¿Qué deseas hacer?---------------" << endl;
            cout << "1 Mostrar todas las series y películas que tenemos" << endl;
            cout << "2 Clasificar por calificación o genero los videos" << endl;
            cout << "3 Mostrar los episodios de una serie " << endl;
            cout << "4 Mostrar las películas con una calificación mayor" << endl;
            cout << "5 Calificar un video " << endl;
            cout << "6 Salir" << endl;
            cout << "Por favor, seleccione una opción: ";
            cin >> opcion;

            /*if (opcion < 1 || opcion > 6)

            {
                ExcepcionStreaming exc("El valor ingresado no es una opción");
                throw(exc);
            }*/

            if (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4" && opcion != "5" && opcion != "6")
            {
                ExcepcionStreaming exc("El valor ingresado no es valido");
                throw(exc);
            }

            if (opcion == "1")
            {
                catalogo.display(); // método para ver si el usuario regresa al menu o sale?
            }
            else if (opcion == "2")
            {
                opcion2();
            }
            else if (opcion == "3")
            {
                opcion3();
            }
            else if (opcion == "4")
            {
                opcion4();
            }
            else if (opcion == "5")
            {
                opcion5();
            }
            else if (opcion == "6")
            {
                cout << "¡Vuelve pronto!" << endl;
                break;
            }
        }
        catch (ExcepcionStreaming const &exc)
        {
            exc.mensaje();
        }
    }
}

void Streaming::opcion2()
{
    try
    {
        string o;
        string gen, califi1;
        float califi;
        cout << "¿Deseas clasificarlos por calificación (1) o por génereo (2)?" << endl;
        cin >> o;
        if (o != "1" && o != "2")
        {
            ExcepcionStreaming exc("El valor ingresado no es valido");
            throw(exc);
        }
        if (o == "1")
        {
            cout << "¿Desde qué calificación quieres que te los muestre?" << endl;
            cin >> califi1;
            califi = stof(califi1);
            catalogo.califVideos(califi);
        }
        else if (o == "2")
        {
            cout << "¿Qué genero deseas buscar? Nuestrass opciones son:" << endl;
            cout << "\nAccion \nAventura \nDrama \nFantasia \nRomance \nSci-Fi \nAnimacion \nFamiliar \nMusical \nGuerra \nCrimen \nMisterio \nTerror \nComedia \nWestern \nBiografia \nSuspenso \nPor favor, escribe el genero:" << endl;
            cin >> gen;
            if (gen != "Accion" && gen != "Aventura" && gen != "Drama" && gen != "Fantasia" && gen != "Romance" && gen != "Sci-Fi" && gen != "Animacion" && gen != "Familiar" && gen != "Musical" && gen != "Guerra" && gen != "Crimen" && gen != "Misterio" && gen != "Terror" && gen != "Comedia" && gen != "Western" && gen != "Biografia" && gen != "Suspenso")
            {
                ExcepcionStreaming exc("Ese genero no es valido");
                throw(exc);
            }
            catalogo.clasificar_generos(gen);
        }
    }
    catch (ExcepcionStreaming const &exc)
    {
        exc.mensaje();
    }
    catch (std::invalid_argument const &error)
    {
        cout << "Error, debe ser un número" << endl;
    }
}
void Streaming::opcion3()
{
    string serie;
    cout << "¿Qué serie quieres que te mostremos?" << endl;
    cin.ignore();
    getline(cin, serie);
    catalogo.buscaSerie(serie);
}

void Streaming::opcion4()
{
    float c;
    cout << "¿Desde qué calificación quieres que te muestre las películas (máximo es 10)?" << endl;
    cin >> c;
    catalogo.clasificarP_cali(c);
}
void Streaming::opcion5()
{
    try
    {
        string video;
        cout << "Ingresa el nombre del capitulo o pelicula que te gustaría calificar: " << endl;
        cin.ignore();
        getline(cin, video);
        float cali;
        cout << "Ingresa la calificación que quieres darle: " << endl;
        cin >> cali;

        if (cali < 1 || cali > 10)
        {
            ExcepcionStreaming exc("El valor ingresado no es valido");
            throw(exc);
        }

        catalogo.calificarVideo(video, cali);
    }
    catch (ExcepcionStreaming const &exc)
    {
        exc.mensaje();
    }
}