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
    Jedi();
    Jedi(std::string name, int rank, int age, std::string light_saber_color, double might);
 	Jedi(const Jedi& other);
    Jedi& operator=(const Jedi& other);
        
    void save(std::string filename);
    void load(std::string filename, std::string jedi_name);
    
    //getters
    std::string get_name() const;
    const char* const get_rank();
    int getRank() const;
    std::string get_color() const;
    int get_age() const;
    double get_might() const;

    void promote(double);
    void demote(double);

    void print_jedi();

    friend bool operator==(const Jedi&, const Jedi&);
    
};
bool operator==(const Jedi&, const Jedi&);
#endif // _JEDI_H_