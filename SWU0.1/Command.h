#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "Interface.h"
#include <cstring>
using namespace std;
class Command {

    private:
    string input;
    string current_file_name;
    Planet load;
    bool is_open = false;

    void starwars_command();
    void file_command();
    public:
    Command() = default;
    void init();
};

#endif // _COMMAND_H_