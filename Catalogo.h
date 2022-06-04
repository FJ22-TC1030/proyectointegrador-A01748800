#ifndef CATALOGO_H
#define CATALOGO_H
#include <iostream>
#include <string>
#include <vector>
#include "Serie.h"
#include "Pelicula.h"
using namespace std;

class Catalogo
{
private:
    vector<Serie> lista_series;
    vector<Pelicula> lista_peliculas;

public:
    void agregarSerie(Serie s);
    void agregarPelicula(Pelicula p);
    void display();
};
#endif
