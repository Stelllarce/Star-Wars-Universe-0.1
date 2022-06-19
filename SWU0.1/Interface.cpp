#include "Interface.h"
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
void Interface::open(std::string& filename, Planet& p, bool& is_open) { 
	
    if (!(filename.find(".txt") != string::npos))
    {
        throw std::invalid_argument("File should be of .txt format.");
    }
    filename = filename.erase(filename.find(".txt"), filename.find(".txt") + 3);
    p.load(filename);
    is_open = true;
    cout << filename << ".txt opened succesfully!\n";
}

void Interface::save_as(std::string& filename, Planet& p,const bool is_open)
{
    if (!(filename.find(".txt") != string::npos))
    {
        throw std::invalid_argument("File should be of .txt format.");
    }
    if (!is_open)
    {
        throw std::runtime_error("There is no current file opened!");
    }
    
    std::ofstream infile(filename, std::ios::app);
    infile.close();
    filename = filename.erase(filename.find(".txt"), filename.find(".txt") + 3);
    p.save(filename);
    cout << "File saved succesfully as " << filename << ".txt!\n";
}

void Interface::save(std::string& filename, Planet& p, const bool is_open)
{
    if (!is_open)
    {
        throw std::runtime_error("There is no current file opened!");
    }
    p.save(filename);
    cout << filename << ".txt saved succesfully!\n";
}

void Interface::close(std::string filename, Planet& p, bool& is_open)
{
    if (!is_open)
    {
        throw std::runtime_error("There is no current file opened!");
    }
    p.clear_memory();
    is_open  = false;
    cout << filename << ".txt closed succesfully!\n";
}

void Interface::exit(bool& is_open)
{
    if (is_open)
    {
        std::cout << "You have unsaved changes. Please select '>close' to ignore changes or '>save'/'saveas' and then use '>close' to save them.\n";
        return;
    }
    is_open = false;
    return;
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
    std::cout << "Jedi " << jedi_name << " removed successfully from planet " << planet_name << '\n';
}

void Interface::promote_jedi(std::string jedi_name, double multiplier)
{
    search_through_files(jedi_name, multiplier, 1);
}

void Interface::demote_jedi(std::string jedi_name, double multiplier)
{
    search_through_files(jedi_name, multiplier, -1);
}

Jedi Interface::get_strongest_jedi(std::string planet_name)
{
    Planet chosen_p(planet_name.c_str());
    chosen_p.load(planet_name);
    if (chosen_p.is_empty())
    {
        throw std::runtime_error("There are no jedi on this planet\n");
    }
    
    Jedi strongest;
    strongest = chosen_p.find_stongest();
    return strongest;
}

Jedi Interface::get_youngest_jedi(std::string planet_name, int r)
{
    Planet chosen_p(planet_name.c_str());
    chosen_p.load(planet_name);
    if (chosen_p.is_empty())
    {
        throw std::runtime_error("There are no jedi on this planet\n");
        
    }
    Jedi young;
    try
    {
        young = chosen_p.find_youngest(r);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return young;
    
}

std::string Interface::get_most_used_saber_color(std::string planet_name, int r)
{
    Planet chosen_p(planet_name.c_str());
    chosen_p.load(planet_name);
    if (chosen_p.is_empty())
    {
        throw std::runtime_error("There are no jedi on this planet\n");
  
    }
    std::string ms;
    try
    {
        ms = chosen_p.find_ms_color(r);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return ms;
}

std::string Interface::get_most_used_saber_color(std::string planet_name)
{
    Planet chosen_p(planet_name.c_str());
    chosen_p.load(planet_name);
    if (chosen_p.is_empty())
    {
        throw std::runtime_error("There are no jedi on this planet\n");
  
    }
    std::string ms;
    try
    {
        ms = chosen_p.find_msgm_color();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return ms;
}

void Interface::print_planet(std::string planet_name)
{
    Planet p(planet_name.c_str());
    p.load(planet_name);
    p.print_rank();
}

void Interface::print_planets(std::string one, std::string other)
{
    std::cout << one << " and " << other << ":\n";
    Planet p(one.c_str());
    p.load(one);
    p.load(other);
    p.print_name();
}

void Interface::print_jedi(std::string jedi_name)
{
    search_through_files(jedi_name);
}

bool Interface::planet_created(std::string name)
{
    std::string filename = name + ".txt";
    ifstream check(filename.c_str());
    bool state = check.good();
    check.close();
    return state;
}

void Interface::search_through_files(std::string jedi_name)
{
    bool found = false;
    string filename;
    ifstream test("Planet_bodies.txt");
    while (getline(test,  filename))
    {
        Planet temp(filename.c_str());
        
        temp.load(filename);
        if (temp.seek_jedi_print(jedi_name)) {
            
            found = true;
            return;
        }

    }
    if (!found)
    {
        cout << "\nNo such jedi found on any planet!\n";
        return;
    }
    
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
        cout << "\nNo such jedi found on any planet!\n";
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
