#pragma once

#include <string>

#include "Material.h"

using std::string;

class Film : public Material
{
private:
    string director;
    string writer;
    string productionCo;

public:
    Film(string, string, string, int, double, string, string, string) ;

    void setWriter(string);
    void setDirector(string);
    void setProdCo(string);

    string toString();

    ~Film() override;

};