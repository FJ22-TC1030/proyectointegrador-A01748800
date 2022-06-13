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
    int opcion;
    Catalogo catalogo;

public:
    Streaming();
    void start();
    void menu();
    int setOpcion(int op);
};
#endif