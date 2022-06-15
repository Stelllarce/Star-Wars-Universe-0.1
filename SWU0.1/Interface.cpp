#include "Interface.h"
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
void Interface::open(std::string filename) { 
	
    ofstream of(filename.c_str(), ios::out | ios::binary);
	
    if (!of)
    {
        throw runtime_error("File not open");
    }
    
    of.close();
}

void Interface::add_planet(const std::string name) { 
    
    if (planet_created(name))
    {
        throw std::runtime_error("Planet already exists!");
        return;
    }
    
    Planet newp(name);
    return;
}

void Interface::create_jedi(std::string planet_name, std::string jedi_name, int rank, int age, std::string color, double strgh)
{
    
    if (!planet_created(planet_name))
    {
        throw std::runtime_error("There is no planet with that name");
        return;
    }
    Jedi yungl(jedi_name, rank, age, color, strgh);
    if (jedi_exists(planet_name, yungl))
    {
        throw std::runtime_error("Jedi already exists on this planet");
        return;
    }
    
    std::string full_file = planet_name + ".txt";
    yungl.save(full_file.c_str());
    std::cout << "Jedi created successfully" << '\n';
}

void Interface::removeJedi(std::string planet_name, std::string jedi_name)
{
    if (!jedi_exists(planet_name, jedi_name))
    {
        throw std::runtime_error("There is no such jedi on this planet");
    }
    
}


bool Interface::planet_created(std::string name)
{
    std::string filename = name + ".txt";
    ifstream check(filename.c_str());
    bool state = check.good();
    check.close();
    return state;
}

bool Interface::jedi_exists(std::string planet_name, Jedi& jedi)
{
    Planet a(planet_name.c_str());
    a.load(planet_name);
    return a.seek_jedi(jedi);
}

bool Interface::jedi_exists(std::string planet_name,std::string jedi_name)
{
    Planet a(planet_name.c_str());
    a.load(planet_name);
    return a.seek_jedi(jedi_name);
}


