#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "Interface.h"
class Command {


    public:
    Command() = default;
    void init();
    void file_command(std::string&, std::string&);
    void starwars_command(std::string&, std::string&);
};

#endif // _COMMAND_H_