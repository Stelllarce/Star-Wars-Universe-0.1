#include "Planet.h"
#include <fstream>
using namespace std;
Planet::Planet(const std::string& pname): name(pname) {
    std::string filename = pname + ".txt";
    ofstream infile(filename.c_str(), ios::app);
    infile.close();
}

void Planet::save(std::string filename)
{
    std::ofstream of(filename.c_str(), std::ios::app);
    if (!of.is_open())
    {
        throw std::runtime_error("Error with opening of file");
    }
    
    for (int i = 0; i < jedi.size(); i++)
    {
        jedi[i].save(filename);
    }
    
    of.close();
}

void Planet::load(std::string planet_name)
{
    string filename = planet_name + ".txt";
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        throw std::runtime_error("Error with opening of file");
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

int Planet::capacity = 100;

Planet::Planet(): name{std::string("Empty world")} {}

Planet::Planet(const char* name): name{std::string(name)} {}
