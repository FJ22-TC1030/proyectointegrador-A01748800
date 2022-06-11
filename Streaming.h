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
    string nombreplat;

public:
    Streaming();
    Streaming(string nombrep);
    void start();
};
#endif