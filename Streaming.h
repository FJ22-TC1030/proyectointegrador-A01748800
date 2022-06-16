#ifndef STREAMING_H
#define STREAMING_H
#include <iostream>
using namespace std;
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Catalogo.h"

class Streaming
{
private:
    string opcion;
    Catalogo catalogo;

public:
    Streaming();
    void start();
    void menu();
    int setOpcion(int op);

    void opcion2();
    void opcion3();
    void opcion4();
    void opcion5();
};

#endif