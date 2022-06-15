#include "Pelicula.h"
#include <iostream>
#include <string>
#include "Video.h"
using std ::string;

Pelicula::Pelicula()
{
    generoN = "no tiene genero";
}
Pelicula::Pelicula(string id, string nombre, string fecha_estreno, double cali, int duracion, string genero) : Video(id, nombre, fecha_estreno, cali, duracion)
{
    generoN = genero;
}
string Pelicula::getGenero() { return generoN; }

void Pelicula::display()
{
    Video::display();
    cout << "Género: " << generoN << endl;
}

bool Pelicula::operator>=(float cal)
{
    if (getCalificacion() >= cal)
    {
        return true;
    }

    else
    {
        return false;
    }
}