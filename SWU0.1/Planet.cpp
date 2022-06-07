#include "Planet.h"
#include <fstream>
Planet::Planet(String name): name(name) {}

void Planet::save(String filename)
{
   for (int i = 0; i < jedi.getSize(); i++)
   {
       jedi[i].save(filename);             
   }
    std::ofstream of(filename.cStr(), std::ios::out | std::ios::binary);
    of.write((char*) jedi.getSize(), sizeof(jedi.getSize()));
    of.close();
}

void Planet::load(String filename)
{
    int size;
    std::ifstream fs(filename.cStr(), std::ios::in | std::ios::binary);
    fs.read((char*) jedi.getSize(), sizeof(jedi.getSize()));
    fs.close();
    for (int i = 0; i < size; i++)
    {
        jedi[i].load(filename);
    }
    
}

int Planet::capacity = 100;



