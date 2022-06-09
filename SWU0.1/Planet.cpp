#include "Planet.h"
#include <fstream>
using namespace std;
Planet::Planet(const std::string& pname) {
    this->name = pname;
    std::string filename = pname + ".dat";
    ofstream of(filename.c_str(), ios::out | ios::binary);
    of.write(pname.c_str(), sizeof(pname));
    of.close();
}

void Planet::save(std::string filename)
{
   for (int i = 0; i < jedi.size(); i++)
   {
       jedi[i].save(filename);             
   }
    std::ofstream of(filename.c_str(), std::ios::out | std::ios::binary);
    of.write((char*) jedi.size(), sizeof(jedi.size()));
    of.close();
}

void Planet::load(std::string filename)
{
    int size;
    std::ifstream fs(filename.c_str(), std::ios::in | std::ios::binary);
    fs.read((char*) jedi.size(), sizeof(jedi.size()));
    fs.close();
    for (int i = 0; i < size; i++)
    {
        jedi[i].load(filename);
    }
    
}

int Planet::capacity = 100;

Planet::Planet(): name{std::string()}, jedi{std::vector<Jedi>()} 
{
    
}
