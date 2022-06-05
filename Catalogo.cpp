#include <string>
#include <vector>
#include <iostream>
#include "Catalogo.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Catalogo.h"

using namespace std;
using std::cout;
using std::endl;
using std ::string;

void Catalogo::agregarSerie(Serie s)
{
    lista_series.push_back(s);
}
void Catalogo::agregarPelicula(Pelicula p)
{
    lista_peliculas.push_back(p);
}

void Catalogo::display()
{
    cout << "Lista de series: " << endl;
    for (int i = 0; i < lista_series.size(); i++) //
    {
        lista_series[i].display();
    }

    cout << "\nLista de Películas: " << endl;
    for (int j = 0; j < lista_peliculas.size(); j++) // hacer comparacion en lista
    {
        lista_peliculas[j].display();
    }
}
