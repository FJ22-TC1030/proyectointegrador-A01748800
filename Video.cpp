#include <iostream>
#include "Video.h"
#include <string>

using namespace std;

Video::Video()
{
    idN = "";
    nombreN = "";
    fecha_estrenoN = "";
    caliN = 0;
    duracionN = 0;
}
Video::Video(string id, string nombre, string fecha_estreno, float cali, int duracion)
{
    idN = id;
    nombreN = nombre;
    fecha_estrenoN = fecha_estreno;
    caliN = cali;
    duracionN = duracion;
}
string Video::getId() { return idN; }
string Video::getNombre() { return nombreN; }
string Video::getFechaE() { return fecha_estrenoN; }
float Video::getCalificacion() { return caliN; }
int Video::getDuracion() { return duracionN; }

void Video::setCalificacion(float numero)
{
    caliN = numero;
}

void Video::display()
{
    cout << "Id: " << idN << endl;
    cout << "Nombre: " << nombreN << endl;
    cout << "Fecha de estreno: " << fecha_estrenoN << endl;
    cout << "Calificación: " << caliN << endl;
    cout << "Duración: " << duracionN << endl;
}