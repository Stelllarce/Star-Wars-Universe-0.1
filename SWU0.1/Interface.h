#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Jedi.h"
#include "Planet.h"
#include <string>
class Interface {

    public:
	void save();
    void open(std::string filename);
    void save_as();
    void close();
    void exit();
    void help();

    static Planet& add_planet(const std::string &name);
    // virtual void create_jedi(std::string, std::string, int, int, std::string, int);
    // virtual void removeJedi(std::string, std::string);
    // virtual void promote_jedi(std::string, double);
    // virtual void demote_jedi(std::string, double);
    // virtual void get_strongest_jedi(std::string);
    // virtual void get_youngest_jedi(std::string, int);
    // virtual void get_most_used_saber_color(std::string, int);
    // virtual void get_most_used_saber_color(std::string);
    // virtual void print(std::string);
    
    
};

#endif // _INTERFACE_H_