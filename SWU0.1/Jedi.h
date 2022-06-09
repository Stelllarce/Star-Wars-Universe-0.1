#ifndef _JEDI_H_
#define _JEDI_H_
#include <string>

const char* const ranks[] = {"YOUNGLING", "PADWAN", "KNIGHT-ASPIRANT", "MASTER", "BATTLE_MASTER", "GRAND_MASTER"};
class Jedi{

    private:
    std::string name;
    std::string light_saber_color;
    int jedi_rank;
    int age;
    double might;

    public:
    Jedi(std::string name, int age, std::string light_saber_color, double might);
 	
        
    void save(std::string filename);
    void load(std::string filename);
    
    //getters
    std::string get_name() const;
    const char* const get_rank();
    std::string get_color();
    int get_age();
    double get_might();

};

#endif // _JEDI_H_