#include "Planet.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
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
        current.save(filepath);
    }
    
}

void Planet::load(std::string planet_name)
{
    string filename = planet_name + ".txt";
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        cout << "File not open\n";
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

bool Planet::seek_jedi_print(std::string jedi_name)
{
    for (auto &sought : jedi)
    {
        
        if (sought.get_name() == jedi_name)
        {
            std::cout << "On " << name << ": " << '\n';
            sought.print_jedi();
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
            return true;
        }
        
        
    }
    return false;
}

Jedi Planet::find_stongest() const
{
    Jedi strongest;
    for (auto current : jedi) {

        if (current.get_might() > strongest.get_might())
        {
            strongest = current;
        }
        
    }
    return strongest;
}

bool Planet::is_empty() const
{
    return jedi.size() == 0;
}

Jedi Planet::find_youngest(int rank) const
{
    Jedi youngest;
    bool temp = true;
    for (auto current : jedi) 
    {
        if (current.getRank() == rank && temp)
        {
            youngest = current;
            temp = false;
        }
        
        if (current.getRank() == rank && current.get_age() < youngest.get_age())
        {
            youngest = current;
            
        }
        if (current.get_age() == youngest.get_age())
        {
            if (strcmp(current.get_name().c_str(), youngest.get_name().c_str()) < 0)
            {
                youngest = current;
            }
            else
            {
                continue;
            }
            
            
        }
        
        
    }
    if (youngest.get_age() != 0)
    {
        // cout << "The youngest jedi on planet " << name << " is ";
        // youngest.print_jedi();
        return youngest;
    }
    else
    {
        throw std::runtime_error("\nThere are no jedi with such rank\n");
    }
    
    
}

std::string sort_and_find(std::vector<std::string>&);
std::string sort_and_find_gm(std::vector<std::string>& v, std::vector<std::string> &used);

std::string Planet::find_ms_color(int rank) const
{
    std::vector<std::string> colors;
    for (auto current : jedi) 
    {
        if (current.getRank() == rank)
        {
            colors.push_back(current.get_color());
            
        }
        
    }

    if (colors.size() > 0)
    {
        std::string mscolor = sort_and_find(colors);
        //std::cout << "The most used color on planet " << name << " from rank " << rank << " is " << mscolor;
        return mscolor;
    }
    else
    {
        throw std::runtime_error("\nThere are no jedi with such rank\n");
    }
    
}

std::string Planet::find_msgm_color() const
{
    std::vector<std::string> colors;
    std::vector<std::string> gm_colors;
    std::vector<std::string> used_colors;
    int gmcount = 0;
    for (auto &current : jedi) 
    {
        if (current.getRank() == 5)
        {
            //std::cout << current.getRank() << current.get_name() << current.get_color() << '\n';
            gm_colors.push_back(current.get_color());
            ++gmcount;
        }
        colors.push_back(current.get_color()); 
    }
    if (gmcount == 0)
    {
        throw std::runtime_error("\nThere are no grandmasters on this planet!\n");
    }
    for (int i = 0; i < colors.size(); ++i)
    {
        std::string mscolor = sort_and_find_gm(colors, used_colors);
        for (auto &gm : gm_colors) 
        {
            // std::cout << mscolor << std::endl;
            // std::cout << gm << std::endl;

            if (mscolor == gm)
            {
                return mscolor;
            }
            
        }
        used_colors.push_back(mscolor);
    }
    throw std::runtime_error("\nThere is no frequent color\n");
}

void Planet::print_rank()
{
    sort_rank(jedi);
    std::cout << name << ":\n";
    for (auto j : jedi) {

        j.print_jedi();
    }
}

void Planet::print_name()
{
    sort_name(jedi);
    for (auto j : jedi) {

        j.print_jedi();
    }
}

Planet::Planet(): name{std::string("Empty world")} {}

Planet::Planet(const char* name): name{std::string(name)} {}

std::string sort_and_find(std::vector<std::string>& v) {

    int max_count = 0, current_count = 0;
    std::string most_used = v[0];

    for (auto &curr : v)
    {
        for (int i = 0; i < v.size(); i++)  
        {
            if (curr == v[i])
            {
                current_count++;
            }
        }
        if (current_count > max_count)   
        {
            max_count = current_count;
            most_used = curr;
        }
        current_count = 0;
        
    }
    return most_used;

}

std::string sort_and_find_gm(std::vector<std::string>& v, std::vector<std::string> &used) {

    int max_count = 0, current_count = 0;
    std::string most_used = v[0];

    for (auto &curr : v)
    {
        for (int i = 0; i < v.size(); i++)  
        {
            if (used.size() == 0 )
            {
                if (curr == v[i])
                {
                    current_count++;
                    continue;
                } 
            }
            
            for (auto use : used)
            {
                if (curr == v[i] && curr != use)
                {
                    current_count++;
                }  
            } 
        }
        if (current_count > max_count)   
        {
            max_count = current_count;
            most_used = curr;
        }
        current_count = 0;
        
    }
    return most_used;

}

void Planet::sort_rank(std::vector<Jedi> & v)
{
    for (auto &curr : v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (curr.getRank() < v[i].getRank())
            {
                std::swap(curr, v[i]);
            }
            if (curr.getRank() == v[i].getRank() && curr.get_name() != v[i].get_name())
            {
                if (strcmp(curr.get_name().c_str(), v[i].get_name().c_str()) < 0)
                {
                    std::swap(curr, v[i]);
                }
                
            }
            
            
        }
        
    }
    
}
void Planet::sort_name(std::vector<Jedi> & v) 
{
    for (auto &curr : v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (strcmp(curr.get_name().c_str(), v[i].get_name().c_str()) < 0)
            {
                std::swap(curr, v[i]);
            }
        }
        
    }
}
