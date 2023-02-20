#include "Film.h"

Film::Film(string id, string title, string subject, int copyrightYear, double cost, 
string director, string writer, string productionCo) : Material(id, title, subject, copyrightYear, cost)
{
    setDirector(director);
    setWriter(writer);
    setProdCo(productionCo);
}

void Film::setDirector(string director)
{
    this->director = director;
}

void Film::setWriter(string writer)
{
    this->writer = writer;
}

void Film::setProdCo(string productionCo)
{
    this->productionCo = productionCo;
}

Film::~Film()
{
    delete this;
}

string Film::toString()
{
    return Material::toString() +
    "\nDirector       : " + director +
    "\nWriter         : " + writer +
    "\nProductionCo   : " + productionCo +
    "\n";
}