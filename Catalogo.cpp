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

void Catalogo::califVideos(float calif) // opcion 2.1
{
    if (calif < 1 || calif > 10)
    {
        cout << "No es válida esa calificación. Necesita ser del 1-10" << endl;
    }
    else
    {
        int contadorS = 0, contadorP = 0;

        cout << "\nLista de Películas con mayor calificación: " << endl;
        for (int i = 0; i < lista_peliculas.size(); i++)
        {
            if (lista_peliculas[i] >= calif)
            {
                lista_peliculas[i].display();
                cout << endl;
                contadorP += 1;
            }
        }
        if (contadorP == 0)
        {
            cout << "Lo sentimos, no tenemos películas con esa calificación" << endl;
        }
        cout << "\nLista de Series y Episodios con mayor calificación: " << endl;

        for (int j = 0; j < lista_series.size(); j++)
        {
            if (lista_series[j] >= calif)
            {
                lista_series[j].display(calif);
                contadorS += 1;
            }
        }
        if (contadorS == 0)
        {
            cout << "Lo sentimos, no tenemos episodios con esa calificación" << endl;
        }
    }
}

void Catalogo::clasificar_generos(string gen) // opcion 2.2
{
    int contador = 0;
    cout << "\nLista de Películas con ese género: " << endl;
    for (int i = 0; i < lista_peliculas.size(); i++)
    {
        if (lista_peliculas[i] == gen)
        {
            lista_peliculas[i].display();
            cout << endl;
            contador += 1;
        }
    }
    if (contador == 0)
    {
        cout << "Lo sentimos, no tenemos películas con ese género" << endl;
    }
    contador = 0;
    for (int i = 0; i < lista_series.size(); i++)
    {
        if (lista_series[i] == gen)
        {
            lista_series[i].display();
            cout << endl;
            contador += 1;
        }
    }
    if (contador == 0)
    {
        cout << "Lo sentimos, no tenemos series con ese género" << endl;
    }
}

void Catalogo::buscaSerie(string serie) // opción 3
{
    int contador = 0;
    for (int i = 0; i < lista_series.size(); i++)
    {
        if (lista_series[i].getNombreSerie() == serie)
        {
            lista_series[i].display();
            contador += 1;
        }
    }
    if (contador == 0)
    {
        cout << "Lo sentimos, no es válida esa serie" << endl;
    }
}

void Catalogo::clasificarP_cali(float c) // opción 4
{
    if (c > 10)
    {
        cout << "No es válida esa calificación. Debe ser menor a 10" << endl;
    }
    else
    {
        cout << "Películas con esa calificación o mayores" << endl;
        int contador = 0;
        for (int i = 0; i < lista_peliculas.size(); i++)
        {
            if (lista_peliculas[i] >= c)
            {
                lista_peliculas[i].display();
                cout << endl;
                contador += 1;
            }
        }
        if (contador == 0)
        {
            cout << "Lo sentimos, no tenemos películas con esa calificación o superior" << endl;
        }
    }
}
void Catalogo::calificarVideo(string video, float cali) // opción 5
{
    for (int i = 0; i < lista_peliculas.size(); i++)
    {
        if (lista_peliculas[i].getNombre() == video)
        {
            lista_peliculas[i].cambiarCaliPeli(cali);
            lista_peliculas[i].display();
        }
    }
    // entrar a listas episodios

    for (int i = 0; i < lista_series.size(); i++)
    {
        lista_series[i].buscarEpisodio(video, cali);
    }
}