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
    nombreplat = "";
}
Streaming::Streaming(string nombrep)
{
    nombreplat = nombrep;
}
void Streaming::start()
{
    cout << "¡Bienvenido a " << nombreplat << "!" << endl;
    Catalogo catalogo;
    catalogo.leerCatalogo();
    catalogo.display();
}