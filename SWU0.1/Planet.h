#ifndef _PLANET_H_
#define _PLANET_H_
#include "Jedi.h"
#include "../String/Stringh.h"
#include "../Vector/Vector.h"
class Planet {
    
    private: 
    String name;
    Vector<Jedi> jedi;
    static int capacity;	
    public: 
    Planet(String name);
    void save(String filename);
    void load(String filename);
	
};
#endif // _PLANET_H_