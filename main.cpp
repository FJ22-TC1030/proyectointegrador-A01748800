#include <iostream>
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Catalogo.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    Pelicula pelicula1("ID35", "Shrek", "2/2008", 8.5, 57, "Terror");
    Episodio epi1("ID36", "Cap2", "6/2009", 9.5, 57, 2, 5);
    Serie serie1("ID35", "River dale", "terror");
    Catalogo catalogo;

    serie1.agregarEpisodio(epi1);
    catalogo.agregarPelicula(pelicula1);
    catalogo.agregarSerie(serie1);
    catalogo.display();
}