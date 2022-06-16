#ifndef EXCEPCIONSTREAMING_H
#define EXCEPCIONSTREAMING_H

#include <exception>
#include <string>

using std::exception;
using std::string;

class ExcepcionStreaming : public exception
{
private:
    string texto;

public:
    ExcepcionStreaming();
    ExcepcionStreaming(string txt);

    void mensaje() const;
};
#endif