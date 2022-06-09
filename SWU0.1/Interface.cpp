#include "Interface.h"
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
void Interface::open(std::string filename) { 
	
    ofstream of(filename.c_str(), ios::out | ios::binary);
	
    if (!of)
    {
        throw runtime_error("File not open");
    }
    
    of.close();
}

void Interface::add_planet(const std::string &filename) { Planet(filename); }