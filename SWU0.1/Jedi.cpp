#include "Jedi.h"
#include <iostream>
#include <fstream>
#include <exception>


const char* const Jedi::get_rank() {

    return ranks[jedi_rank];
}

int Jedi::getRank() const
{
    return jedi_rank;
}

std::string Jedi::get_color() const
{
    return light_saber_color;
}

int Jedi::get_age() const
{
    return age;
}

double Jedi::get_might() const
{
    return might;
}

void Jedi::promote(double multiplier)
{
    if (name == "Anakin Skywalker" && jedi_rank == 2)
    {
        throw std::runtime_error("- You are on this council, but we do not grant you the rank of master.\n"
        "- What? How can you do this? This is outrageous! It's unfair! How can you be on the council and not be a master?\n");
    }
    
    if (jedi_rank < 5)
    {
        jedi_rank += 1;
    }
    else
    {
        std::cout << "Jedi has the highest possible rank!\n";
        return;
    }
    
    might *= (1 + multiplier);
    std::cout << "Jedi " << name << " promoted succesfully to " << get_rank() << " by mult of " << multiplier << '\n';   

}

void Jedi::demote(double multiplier)
{
   if (jedi_rank > 0)
    {
        jedi_rank -= 1;
    }
    else
    {
        std::cout << "Jedi has the lowest possible rank!\n";
        return;
    } 
    might *= (1 - multiplier);
    std::cout << "Jedi " << name << " demoted succesfully to " << get_rank() << " by mult of " << multiplier << '\n';
}

void Jedi::print_jedi() 
{
    std::cout << name << ", light saber color: " << light_saber_color <<
    ", rank: " << ranks[jedi_rank] << ", age: " << age << ", might: " << might << "\n";
}

bool operator==(const Jedi& one, const Jedi& other)
{
    return (one.get_name() == other.get_name() && one.get_age() == other.get_age());
}

void Jedi::save(std::string filename)
{
    std::ofstream of(filename.c_str(), std::ios::app);
    if (!of)
    {
        throw std::runtime_error("File error save");
    }
    
    of << name << "," << light_saber_color << "," << jedi_rank << "," <<  age << "," <<  might << '\n';

    of.close(); 
    if (!of.good())
    {
        throw std::runtime_error("Error after closing save");
    }
    
}

void Jedi::load(std::string filename, std::string jedi_name)
{
    std::ifstream fs(filename.c_str(), std::ios::in);

    if (!fs)
    {
        throw std::runtime_error("File error read");
    }
    do 
    {
        fs >> name >> light_saber_color >> jedi_rank >> age >> might;
    }while (name != jedi_name);
    
    fs.close();
    if (!fs.good())
    {
        throw std::runtime_error("Error after closing read");
    }
}

std::string Jedi::get_name() const { return name; }


Jedi::Jedi(std::string name, int rank, int age, std::string light_saber_color, double might): name(name), age(age), light_saber_color(light_saber_color), might(might), jedi_rank(rank) {}

Jedi::Jedi(): jedi_rank(0), age(0), might(0) {}

Jedi::Jedi(const Jedi& other)
{
    name = other.name;
    light_saber_color = other.light_saber_color;
    jedi_rank = other.jedi_rank;
    age = other.age;
    might = other.might;
}

Jedi& Jedi::operator=(const Jedi& other)
{
    // name.erase();
    // light_saber_color.erase();
    if (this != &other)
    {
        name = other.name;
        light_saber_color = other.light_saber_color;
        jedi_rank = other.jedi_rank;
        age = other.age;
        might = other.might;
    }
    return *this;
}
