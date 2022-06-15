#include "Planet.h"
#include <fstream>
#include <iostream>
using namespace std;
Planet::Planet(const std::string& pname): name(pname) {
    std::string filename = pname + ".txt";
    
    ofstream infile(filename.c_str(), ios::app);
    infile.close();
}

void Planet::save(std::string filename)
{
    std::string filepath = filename + ".txt";
    remove(filepath.c_str());
    std::ofstream of(filepath.c_str(), std::ios::app);
    if (!of.is_open())
    {
        throw std::runtime_error("Error with opening of file");
    }
    
    of.close();
    for (auto &current : jedi)
    {
        cout << current.get_might();
        current.save(filepath);
    }
    
}

void Planet::load(std::string planet_name)
{
    string filename = planet_name + ".txt";
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        cout << "File not open";
        return;
    }
    std::string line;
    while (getline(infile, line))
    {
        std::string jedi_name = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);

        std::string light_saber_col = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        
        std::string rank = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);

        std::string age = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);

        std::string might = line;

        Jedi youngl(jedi_name, stoi(rank), stoi(age), light_saber_col, stod(might));
        add_to_planet(youngl);
    }
    
    infile.close();
    
}

void Planet::add_to_planet(Jedi njedi)
{
    jedi.push_back(njedi);
}

bool Planet::seek_jedi(Jedi& sought_jedi)
{
    for (auto sought : jedi) {

        if (sought_jedi == sought)
        {
            return true;
        }
        
    }
    return false;
}

bool Planet::seek_jedi(std::string jedi_name)
{
    for (auto sought : jedi)
    {
        if (sought.get_name() == jedi_name)
        {
            return true;
        }
        
    }
    return false;
}

void Planet::banish_jedi(std::string name)
{
    for (int i = 0; i < jedi.size(); i++)
    {
        if (jedi[i].get_name() == name)
        {
            jedi.erase(jedi.begin() + i);
        }
        
    }
    
}

bool Planet::prom_dem_jed(std::string jedi_name, double m, int prom_dem)
{
    for (auto &sought : jedi) { 
    
        if (sought.get_name() == jedi_name && prom_dem == 1)
        {
            sought.promote(m);
            return true;
        }
        if (sought.get_name() == jedi_name && prom_dem == -1)
        {
            sought.demote(m);
            // std::string filepath = name + ".txt";
            // sought.save(filepath);
            return true;
        }
        
        
    }
    return false;
}

int Planet::capacity = 100;

Planet::Planet(): name{std::string("Empty world")} {}

Planet::Planet(const char* name): name{std::string(name)} {}
