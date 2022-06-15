#ifndef VIDEO_H
#define VIDEO_H
using namespace std;
#include <iostream>
#include <string>
using std::string;

class Video
{
private:
    // Atributos
    string idN;
    string nombreN;
    string fecha_estrenoN;
    float caliN;
    int duracionN;

public:
    // métodos
    Video();
    Video(string id, string nombre, string fecha_estreno, float cali, int duracion);
    string getId();
    string getNombre();
    string getFechaE();
    float getCalificacion();
    int getDuracion();
    void setCalificacion(float numero);
    void display();
};
#endif
