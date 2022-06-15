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

void Interface::add_planet(std::string name) { 
    
    if (planet_created(name))
    {
        throw std::runtime_error("Planet already exists!");
        return;
    }
    Planet newp(name);
    save_to_planet_list(name);
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
    std::cout << "Jedi " << jedi_name << " created successfully" << '\n';
}

void Interface::removeJedi(std::string planet_name, std::string jedi_name)
{
    if (!jedi_exists(planet_name, jedi_name))
    {
        throw std::runtime_error("There is no such jedi on this planet");
        return;
    }
    Planet temp(planet_name.c_str());
    temp.load(planet_name);
    temp.banish_jedi(jedi_name);
    temp.save(planet_name);
    std::cout << "Jedi " << jedi_name << " removed successfully" << '\n';
}

void Interface::promote_jedi(std::string jedi_name, double multiplier)
{
    search_through_files(jedi_name, multiplier, 1);
}

void Interface::demote_jedi(std::string jedi_name, double multiplier)
{
    search_through_files(jedi_name, multiplier, -1);
}


bool Interface::planet_created(std::string name)
{
    std::string filename = name + ".txt";
    ifstream check(filename.c_str());
    bool state = check.good();
    check.close();
    return state;
}

void Interface::search_through_files(string jedi_name, double mult, int promote_demote)
{
    bool found = false;
    string filename;
    ifstream test("Planet_bodies.txt");
    while (getline(test,  filename))
    {
        Planet temp(filename.c_str());
        
        temp.load(filename);
        if (temp.prom_dem_jed(jedi_name, mult, promote_demote)) {
            
            temp.save(filename);
            found = true;
            
            return;
        }

    }
    if (!found)
    {
        cout << "No such jedi found on any planet!";
        return;
    }
    
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



void Interface::save_to_planet_list(std::string planet_name)
{
    ofstream planets("Planet_bodies.txt", ios::app);
    planets << planet_name << '\n';
    planets.close();
}
