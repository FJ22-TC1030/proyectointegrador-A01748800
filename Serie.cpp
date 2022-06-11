#include <string>
#include <vector>
#include <iostream>
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