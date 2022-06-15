#ifndef _PLANET_H_
#define _PLANET_H_
#include "Jedi.h"
#include <string>
#include <vector>
class Planet {
    
    private: 
    std::string name;
    std::vector<Jedi> jedi;
    static int capacity;	
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
};
#endif // _PLANET_H_