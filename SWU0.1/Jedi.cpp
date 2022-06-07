#include "Jedi.h"
#include <iostream>
#include <fstream>
#include <exception>


String Jedi::get_rank() {

    return ranks[jedi_rank];
}

String Jedi::get_color()
{
    return light_saber_color;
}

int Jedi::get_age()
{
    return age;
}

double Jedi::get_might()
{
    return might;
}

void Jedi::save(String filename)
{
    std::ofstream of(filename.cStr(), std::ios::out | std::ios::binary);
    if (!of)
    {
        throw std::runtime_error("File error");
    }
    
    of.write(name.cStr(), sizeof(name));
    of.write(light_saber_color.cStr(), sizeof(light_saber_color));
    of.write((char*) &jedi_rank, sizeof(jedi_rank));
    of.write((char*) &age, sizeof(age));
    of.write((char*) &might, sizeof(might));    

    of.close(); 
    if (!of.good())
    {
        throw std::runtime_error("Error after closing");
    }
    
}

void Jedi::load(String filename)
{
    std::ifstream fs(filename.cStr(), std::ios::in | std::ios::binary);

    if (!fs)
    {
        throw std::runtime_error("File error");
    }
    fs.read((char* ) name.cStr(), sizeof(name));
    fs.read((char* ) light_saber_color.cStr(), sizeof(light_saber_color));
    fs.read((char*) &jedi_rank, sizeof(jedi_rank));
    fs.read((char*) &age, sizeof(age));
    fs.read((char*) &might, sizeof(might));    

    fs.close();
    if (!fs.good())
    {
        throw std::runtime_error("Error after closing");
    }
}

String Jedi::get_name() const { return name; }


Jedi::Jedi(String name, int age, String light_saber_color, double might): name(name), age(age), light_saber_color(light_saber_color), might(might), jedi_rank(0) {}
