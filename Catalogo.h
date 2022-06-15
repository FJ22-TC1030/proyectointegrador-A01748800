#ifndef CATALOGO_H
#define CATALOGO_H
#include <iostream>
#include <string>
#include <vector>
#include "Serie.h"
#include "Pelicula.h"
#include <string>
using namespace std;
using std::ifstream;

class Catalogo
{
private:
    vector<Serie> lista_series;
    vector<Pelicula> lista_peliculas;

public:
    void agregarSerie(Serie s);
    void agregarPelicula(Pelicula p);
    void setCalificacion(int cal, string v);
    void display();
    void leerCatalogo();

    void califVideos(float calif); // opción 2.1

    void clasificar_generos(string gen);

    void buscaSerie(string serie);

    void claseficarP_cali(float c);
};

#endif
