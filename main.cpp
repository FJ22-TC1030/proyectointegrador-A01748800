#include <iostream>
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Catalogo.h"
#include "Streaming.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    Streaming netflix;
    netflix.start();
    return 0;
}