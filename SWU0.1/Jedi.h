#ifndef _JEDI_H_
#define _JEDI_H_
#include "../String/Stringh.h"

const char* const ranks[] = {"YOUNGLING", "PADWAN", "KNIGHT-ASPIRANT", "MASTER", "BATTLE_MASTER", "GRAND_MASTER"};
class Jedi{

    private:
    String name;
    String light_saber_color;
    int jedi_rank;
    int age;
    double might;

    public:
    Jedi(String name, int age, String light_saber_color, double might);
 	
        
    void save(String filename);
    void load(String filename);
    
    //getters
    String get_name() const;
    String get_rank();
    String get_color();
    int get_age();
    double get_might();

};

#endif // _JEDI_H_