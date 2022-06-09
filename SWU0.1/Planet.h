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
    Planet() = default;
    Planet(std::string name);
    void save(std::string filename);
    void load(std::string filename);
	
    
};
#endif // _PLANET_H_