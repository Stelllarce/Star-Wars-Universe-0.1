#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Jedi.h"
#include "Planet.h"
#include "../String/Stringh.h"
#include "../Vector/Vector.h"
class Interface {

    public:
	void save();
    void open(String filename);
    void save_as();
    void close();
    void exit();
    void help();

    virtual void add_planet(const String&);
    virtual void create_jedi(String, String, int, int, String, int) = 0;
    virtual void removeJedi(String, String);
    virtual void promote_jedi(String, double);
    virtual void demote_jedi(String, double);
    virtual void get_strongest_jedi(String);
    virtual void get_youngest_jedi(String, int);
    virtual void get_most_used_saber_color(String, int);
    virtual void get_most_used_saber_color(String);
    virtual void print(String);
    
    
};

#endif // _INTERFACE_H_