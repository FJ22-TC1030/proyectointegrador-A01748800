#ifndef SERIE_H
#define SERIE_H
#include <iostream>
#include <string>
#include <vector>
#include "Episodio.h"
using std ::string;

class Serie
{
private:
    vector<Episodio> episodios;
    string nombreSerie;
    string idSerie;
    string generoSerie;

public:
    Serie();
    Serie(string idSerie, string nombreSerie, string generoSerie);
    string getIdSerie();
    string getNombreSerie();
    string getGeneroSerie();
    void agregarEpisodio(Episodio e);
    void display();

    bool operator>=(float cal); // opción 2
    void display(float cal);

    void buscarEpisodio(string nombre, float c);

    bool operator==(string gen);
};
#endif