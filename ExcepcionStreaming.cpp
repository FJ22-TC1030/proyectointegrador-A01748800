#include <iostream>
#include "ExcepcionStreaming.h"
using namespace std;
#include <string>

ExcepcionStreaming::ExcepcionStreaming()
{
}
ExcepcionStreaming::ExcepcionStreaming(string txt)
{
    texto = txt;
}

void ExcepcionStreaming::mensaje() const
{
    cout << "\n¡Error! " << texto << endl;
}
