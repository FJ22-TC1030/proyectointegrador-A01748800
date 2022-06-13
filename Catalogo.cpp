#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Episodio.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Catalogo.h"

using namespace std;
using std::cout;
using std::endl;
using std::ifstream;
using std::stof;
using std::stoi;
using std ::string;
using std::stringstream;

void Catalogo::agregarSerie(Serie s)
{
    lista_series.push_back(s);
}
void Catalogo::agregarPelicula(Pelicula p)
{
    lista_peliculas.push_back(p);
}

void Catalogo::setCalificacion(int cal, string v)
{
}

void Catalogo::display()
{
    cout << "Lista de series: " << endl;
    for (int i = 0; i < lista_series.size(); i++) //
    {
        lista_series[i].display();
    }

    cout << "\nLista de Películas: " << endl;
    for (int j = 0; j < lista_peliculas.size(); j++) // hacer comparacion en lista
    {
        lista_peliculas[j].display();
        cout << endl;
    }
}
void Catalogo::leerCatalogo()
{
    ifstream archivo;
    string line;
    archivo.open("BasePeliculas.csv");
    getline(archivo, line);
    while (getline(archivo, line))
    {
        stringstream token(line);
        string id, nombre, duracion, genero, calificacion, fechaEstreno, nombreEpisodio, temporada, numEpisodio, idEpi;

        getline(token, id, ',');
        getline(token, nombre, ',');
        getline(token, duracion, ',');
        getline(token, genero, ',');
        getline(token, calificacion, ',');
        getline(token, fechaEstreno, ',');
        getline(token, nombreEpisodio, ',');
        getline(token, temporada, ',');
        getline(token, numEpisodio, ',');
        getline(token, idEpi);
        int durac = stoi(duracion);
        float cali = stof(calificacion);

        // cout << idEpisodio << endl;
        //  cout << id1 << " " << nombre << " " << duracion << " " << genero << " " << calificacion << " " << fechaEstreno << " " << nombreEpisodio << " " << temporada << " " << numEpisodio << " " << idEpisodio << endl;

        if (temporada == "")
        {
            Pelicula pelicula(id, nombre, fechaEstreno, cali, durac, genero);
            agregarPelicula(pelicula);
        }
        else
        {
            bool bandera = false;
            int temp = stoi(temporada);
            int numEp = stoi(numEpisodio);
            if (lista_series.size() == 0)
            {
                Serie serie1(id, nombre, genero);
                Episodio episodio(idEpi, nombreEpisodio, fechaEstreno, cali, durac, temp, numEp);
                serie1.agregarEpisodio(episodio);
                agregarSerie(serie1);
            }
            else
            {
                for (int i = 0; i < lista_series.size(); i++)
                {
                    if (lista_series[i].getNombreSerie() == nombre)
                    {
                        Episodio episodio(idEpi, nombreEpisodio, fechaEstreno, cali, durac, temp, numEp);
                        lista_series[i].agregarEpisodio(episodio);
                        bandera = true;
                    }
                }
                if (bandera == false)
                {
                    Serie serie(id, nombre, genero);
                    Episodio episodio(idEpi, nombreEpisodio, fechaEstreno, cali, durac, temp, numEp);
                    serie.agregarEpisodio(episodio);
                    agregarSerie(serie);
                }
            }
        }
    }

    archivo.close();
}
