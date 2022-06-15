#ifndef EPISODIO_H
#define EPISODIO_H
#include <iostream>
#include <string>
#include "Video.h"
using std ::string;

class Episodio : public Video
{
private:
    int temporadaN;
    int numEpN;

public:
    Episodio();
    Episodio(string id, string nombre, string fecha_estreno, float cali, int duracion, int temporada, int numEp);
    int getTemp();
    int getNoEp();
    void cambiarCaliEpi(float num);
    void display();

    bool operator>=(float cal); // opción 2
};
#endif
