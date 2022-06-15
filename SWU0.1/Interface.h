#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Jedi.h"
#include "Planet.h"
#include <cstring>
class Interface {
    
    private:
    static void save_to_planet_list(std::string planet_name);
    static bool jedi_exists(std::string planet_name,Jedi&);
    static bool jedi_exists(std::string planet_name,std::string jedi_name);
    static bool planet_created(std::string name);
    static void search_through_files(std::string jedi_name, double multiplier, int prom_dem);
    public:
	// void save();
    void open(std::string filename);
    // void save_as();
    // void close();
    // void exit();
    // void help();

    static void add_planet(std::string name);
    static void create_jedi(std::string, std::string, int, int, std::string, double);
    static void removeJedi(std::string, std::string);
    static void promote_jedi(std::string, double);
    static void demote_jedi(std::string, double);
    static Jedi get_strongest_jedi(std::string);
    static Jedi get_youngest_jedi(std::string, int);
    static std::string get_most_used_saber_color(std::string, int);
    // virtual void get_most_used_saber_color(std::string);
    static void print_planet(std::string);
};

#endif // _INTERFACE_H_