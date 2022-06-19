#ifndef _PLANET_H_
#define _PLANET_H_
#include "Jedi.h"
#include <cstring>
#include <vector>
class Planet {
    
    private: 
    std::string name;
    std::vector<Jedi> jedi;
    void sort_rank(std::vector<Jedi> & v);	
    void sort_name(std::vector<Jedi> & v);
    public: 
    Planet();
    Planet(const std::string& name);
    Planet(const char* name);
    void save(std::string filename);
    void load(std::string filename);
	
    void add_to_planet(Jedi);
    bool seek_jedi(Jedi&);
    bool seek_jedi(std::string jedi_name);
    void banish_jedi(std::string name);
    bool prom_dem_jed(std::string jedi_name, double multiplier, int prom_dem);
    Jedi find_stongest() const;
    bool is_empty() const;
    Jedi find_youngest(int rank) const;
    std::string find_ms_color(int rank) const;
    std::string find_msgm_color() const;
    bool seek_jedi_print(std::string jedi_name);
    void clear_memory();

    void print_rank();
    void print_name();
};

#endif // _PLANET_H_