#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Jedi.h"
#include "Planet.h"
#include <cstring>
class Interface {
    
    private:
    static void save_to_planet_list(std::string planet_name);
    static bool jedi_exists(std::string planet_sname,Jedi&);
    static bool jedi_exists(std::string planet_name,std::string jedi_name);
    static bool planet_created(std::string name);
    static void search_through_files(std::string jedi_name, double multiplier, int prom_dem);
    static void search_through_files(std::string jedi_name);
    public:
	static void save(std::string& filename, Planet& p,const bool is_open);
    static void open(std::string& filename, Planet& p, bool& is_open);
    static void save_as(std::string& filename, Planet& p,const bool is_open);
    static void close(std::string filename, Planet& p, bool& is_open);
    static void exit(bool& is_open);

    static void add_planet(std::string name);
    static void create_jedi(std::string, std::string, int, int, std::string, double);
    static void removeJedi(std::string, std::string);
    static void promote_jedi(std::string, double);
    static void demote_jedi(std::string, double);
    static Jedi get_strongest_jedi(std::string);
    static Jedi get_youngest_jedi(std::string, int);
    static std::string get_most_used_saber_color(std::string, int);
    static std::string get_most_used_saber_color(std::string);
    static void print_planet(std::string);
    static void print_planets(std::string one, std::string other);
    static void print_jedi(std::string);

};
#endif // _INTERFACE_H_