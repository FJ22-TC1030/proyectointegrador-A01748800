#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include <string>
#include "Video.h"
using std ::string;

class Pelicula : public Video
{
private:
    string generoN;

public:
    Pelicula();
    Pelicula(string id, string nombre, string fecha_estreno, double cali, int duracion, string genero);
    string getGenero();

    void display();

    bool operator>=(float cal); // opción 2
    bool operator==(string gen);
};
#endif