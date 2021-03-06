#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Serie.h"
#include "Episodio.h"
using std::cout;
using std::endl;
using std ::string;

Serie::Serie()
{
    idSerie = "no tiene id";
    nombreSerie = "no tiene nombre";
    generoSerie = "no tiene genero";
}
Serie::Serie(string idS, string nombreS, string generoS)
{
    idSerie = idS;
    nombreSerie = nombreS;
    generoSerie = generoS;
}
string Serie::getIdSerie() { return idSerie; }

string Serie::getNombreSerie() { return nombreSerie; }

string Serie::getGeneroSerie() { return generoSerie; }

void Serie::agregarEpisodio(Episodio e)
{
    episodios.push_back(e);
}
void Serie::display()
{
    cout << "\nId: " << idSerie << endl;
    cout << "Nombre: " << nombreSerie << endl;
    cout << "Género: " << generoSerie << endl;

    cout << "Lista de episodios de esa serie: " << endl;
    for (int i = 0; i < episodios.size(); i++)
    {
        episodios[i].display();
    }
}

void Serie::display(float cal)
{
    cout << "\nId: " << idSerie << endl;
    cout << "Nombre: " << nombreSerie << endl;
    cout << "Género: " << generoSerie << endl;

    cout << "Lista de episodios de esa serie: " << endl;
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i] >= cal)
        {
            episodios[i].display();
        }
    }
}

void Serie::buscarEpisodio(string nombre, float c)
{
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i].getNombre() == nombre)
        {
            episodios[i].cambiarCaliEpi(c);
            episodios[i].display();
        }
    }
}

bool Serie::operator>=(float cal)
{
    int bandera = 0;
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i] >= cal)
        {
            bandera += 1;
        }
    }
    if (bandera >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Serie::operator==(string gen) // para opción 2.2
{
    stringstream token(generoSerie);
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
