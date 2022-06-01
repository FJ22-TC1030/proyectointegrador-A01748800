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
    Episodio(string id, string nombre, string fecha_estreno, double cali, int temporada, int numEp);
    int getTemp();
    int getNoEp();
};
#endif
