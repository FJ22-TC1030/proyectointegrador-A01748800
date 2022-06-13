#include <iostream>
using namespace std;
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Catalogo.h"
#include "Streaming.h"

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
        cout << "2 Clasificar por calificación o genero los videos" << endl;
        cout << "3 Mostrar los episodios de una serie " << endl;
        cout << "4 Mostrar las películas con una calificación mayor" << endl;
        cout << "5 Calificar un video " << endl;
        cout << "6 Salir" << endl;
        cout << "Por favor, seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1)
        {
            catalogo.display(); // método para ver si el usuario regresa al menu o sale?
        }
        /*else
            (opcion == 2)
            {
            }
        else(opcion == 3)
        {
        }
        else(opcion == 4)
        {
        }
        else(opcion == 5)
        {
        }*/
        else if (opcion == 6)
        {
            cout << "¡Vuelve pronto!" << endl;
            break;
        }
    }
}