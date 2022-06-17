#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "Interface.h"
class Command {

    private:
    void starwars_command(std::string&, std::string&, Planet& p);
    void file_command(std::string&, std::string&, Planet& p);
    public:
    Command() = default;
    void init();
};

#endif // _COMMAND_H_