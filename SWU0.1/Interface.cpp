#include "Interface.h"
#include <iostream>
#include <fstream>

void Interface::open(String filename) { 
	
    ofstream of(filename.cStr(), ios::out | ios::binary);
	
    if (!of)
    {
        throw runtime_error("File not open");
    }
    
    of.close();
}

void Interface::add_planet(const String &name) {
	String filename = name + String(".dat");
    ofstream of(filename.cStr(), ios::out | ios::binary);
    of.write(name.cStr(), sizeof(name.cStr()));
    of.close();
}