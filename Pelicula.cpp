#include "Pelicula.h"
#include <iostream>
#include <string>
#include "Video.h"
#include <fstream>
#include <sstream>
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
bool Pelicula::operator==(string gen)
{
    stringstream token(generoN);
    string gen1, gen2, gen3, gen4, gen5, gen6;
    getline(token, gen1, '/');
    getline(token, gen2, '/');
    getline(token, gen3, '/');
    getline(token, gen4, '/');
    getline(token, gen5, '/');
    getline(token, gen6, '/');
    if (gen == gen1 | gen == gen2 | gen == gen3 | gen == gen4 | gen == gen5 | gen == gen6)
    {
        return true;
    }
    else
    {
        return false;
    }
}
