#include <iostream>
using namespace std;
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Catalogo.h"
#include "Streaming.h"
#include <fstream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::getline;
using std::ignore;

Streaming::Streaming()
{
}

void Streaming::start()
{
    catalogo.leerCatalogo();
    menu();
}
void Streaming::menu()
{
    opcion = 1;
    while (opcion != 6)
    {
        cout << "¡Bienvenido!" << endl;
        cout << "----------------¿Qué deseas hacer?---------------" << endl;
        cout << "1 Mostrar todas las series y películas que tenemos" << endl;
        cout << "2 Clasificar por calificación o genero los videos" << endl; // sobrecarga
        cout << "3 Mostrar los episodios de una serie " << endl;             //
        cout << "4 Mostrar las películas con una calificación mayor" << endl;
        cout << "5 Calificar un video " << endl;
        cout << "6 Salir" << endl;
        cout << "Por favor, seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1)
        {
            catalogo.display(); // método para ver si el usuario regresa al menu o sale?
        }
        else if (opcion == 2)
        {
            opcion2();
        }
        else if (opcion == 3)
        {
            opcion3();
        }
        else if (opcion == 4)
        {
            opcion4();
        }
        else if (opcion == 5)
        {
            opcion5();
        }
        else if (opcion == 6)
        {
            cout << "¡Vuelve pronto!" << endl;
            break;
        }
    }
}

void Streaming::opcion2()
{
    int o;
    string gen;
    float califi;
    cout << "¿Deseas clasificarlos por calificación (1) o por génereo (2)?" << endl;
    cin >> o;
    if (o == 1)
    {
        cout << "¿Desde qué calificación quieres que te los muestre?" << endl;
        cin >> califi;
        catalogo.califVideos(califi);
    }
    else if (o == 2)
    {
        cout << "¿Qué genero deseas buscar? Nuestrass opciones son:" << endl;
        cout << "\nAccion \nAventura \nDrama \nFantasia \nRomance \nSci-Fi \nAnimacion \nFamiliar \nMusical \nGuerra \nCrimen \nMisterio \nTerror \nComedia \nWestern \nBiografia \nHorror \nPor favor, escribe el genero:" << endl;
        cin >> gen;
        catalogo.clasificar_generos(gen);
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
    string video;
    cout << "Ingresa el nombre del capitulo o pelicula que te gustaría calificar: " << endl;
    cin.ignore();
    getline(cin, video);
    float cali;
    cout << "Ingresa la calificación que quieres darle: " << endl;
    cin << cali;
    catalogo.calificarVideo(video, cali); // modificar la cali
}