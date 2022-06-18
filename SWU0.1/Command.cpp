#include "Command.h"
#include <iostream>
using namespace std;


void Command::init()
{
     cout  << "-----------------------STAR WARS UNIVERSE 0.1-----------------------\n";
    cout << "To check available commands type '>help'" << '\n';

    string input;
    string current_file_name;
    Planet load;
    cout << "Enter a command: ";
    while (true)
    {
        getline(std::cin, input);
        file_command(input, current_file_name, load);
        starwars_command(input, current_file_name, load);
        if (input == string(">exit"))
        {
            cout << "Exiting the program...";
            break;
        }
    
        cout << "Enter a command: ";
        

    }
    
}

void Command::file_command(std::string& user_input, std::string& current_file_name, Planet& p)
{
    
        if (user_input == string(">help"))
        {
            cout << "Available commands:\n";
            cout << ">open <filepath> - opens the specified file\n";
            cout << ">close - closes the file that is currently opened\n";
            cout << ">save - saves changes made in the currently opened file\n";
            cout << ">saveas <filepath> - creates a new file in the specified file path\n";
            cout << ">exit - exits the program\n";
            cout << "TYPE '>pg2' to go to next page\n\n";
        }
        if (user_input == string(">pg2"))
        {
            cout << "Available commands 2 (slashes are used as delimiters, don't ignore):\n";
            cout << ">add planet <planet_name> - adds a planet and saves it (it is not loaded in the memory)\n";
            cout << ">create jedi - stations a new jedi on the designated planet\n";
            cout << ">remove jedi <planet_name>/<jedi_name> - banishes the jedi from the desired planet\n";
            cout << ">promote <jedi_name>/<multiplier> - searches for the jedi on every planet, promotes him one rank up and upgrades his power\n";
            cout << ">demote <jedi_name>/<multiplier> - searches for the jedi on every planet, demotes him one rank down and degrades his power\n";
            cout << ">strongest <planet_name> - shows the jedi with most power on that planet\n";
            cout << ">youngest <planet_name>/<rank> - shows the youngest jedi on that planet amongst the chosen rank\n";
            cout << ">mostusedon <planet_name>/<rank> - shows the most used lightsaber color on that planet by the particular rank\n";
            cout << ">mostusedon <planet_name> - shows the most used lightsaber color on that planet that is owned by atleast one GRAND_MASTER\n";
            cout << ">printp <planet_name> - shows the information about every jedi stationed on this planet\n";
        }
        if (user_input.substr(0, strlen(">open")) == string(">open"))
        {
            string file_path = user_input.substr(strlen(">open") + 1);
            try
            {
                Interface::open(file_path, p);
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << '\n';
            }
            current_file_name = file_path;
            //cout << "Enter a command: "; 
        }
        
        if (user_input == string(">close"))
        {
            cout << current_file_name << " closed succesfully!\n\n";
            //cout << "Enter a command: "; 
        }

        if (user_input.substr(0, strlen(">saveas")) == string(">saveas"))
        {
            string file_path = user_input.substr(strlen(">saveas") + 1);
            cout << "File saved succesfully as " << file_path << "!\n\n";
            //cout << "Enter a command: "; 

        }

        if (user_input == string(">save"))
        {
            cout << current_file_name << " saved succesfully!\n\n";
            //cout << "Enter a command: "; 

        }

        
}

void Command::starwars_command(std::string& user_input, std::string& current_file_name, Planet& p)
{
    
    
        if (user_input.substr(0, strlen(">add planet")) == string(">add planet"))
        {
            string filename = user_input.substr(strlen(">add planet") + 1);
            Interface::add_planet(filename);
        }

        if (user_input.substr(0, strlen(">create jedi")) == string(">create jedi"))
        {
            string name, saber_col, rank_str, planet;
            int age, rank;
            double might;
            cout << "\nPlanet: ";
            cin >> planet;
            cout << "\nName: ";
            cin >> name;
            cout << "\nAge: ";
            cin >> age;
            cout << "\nRank: ";
            cin >> rank_str;
            cout << "\nSaber color: ";
            cin >> saber_col;
            cout << "\nPower: ";
            cin >> might;

            for (int i = 0; i < 6; i++)
            {
                if (!(strcmp(ranks[i], rank_str.c_str())))
                    {
                        rank =  i;
                    }
                
            }
            try
            {
                Interface::create_jedi(planet, name, rank, age, saber_col, might);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            

        }
        
        if (user_input.substr(0, strlen(">promote")) == string(">promote"))
        {
            string multiplier = user_input.substr(user_input.find("/") + 1);
            string name = user_input.substr(strlen(">promote") + 1, user_input.length() - (multiplier.length() + strlen(">promote") + 2));

            Interface::promote_jedi(name, stod(multiplier));
        }

        if (user_input.substr(0, strlen(">demote")) == string(">demote"))
        {
            string multiplier = user_input.substr(user_input.find("/") + 1);
            string name = user_input.substr(strlen(">demote") + 1, user_input.length() - (multiplier.length() + strlen(">demote") + 2));
         
            Interface::demote_jedi(name, stod(multiplier));

        }

        if (user_input.substr(0, strlen(">strongest")) == string(">strongest"))
        {
            string name = user_input.substr(strlen(">strongest") + 1);
            Jedi str;
            str = Interface::get_strongest_jedi(name);

            cout << "Strongest jedi on " << name << " is "; 
            str.print_jedi();
        }

        if (user_input.substr(0, strlen(">youngest")) == string(">youngest"))
        {
            string rank = user_input.substr(user_input.find("/") + 1);
            string name = user_input.substr(strlen(">youngest") + 1, user_input.length() - (rank.length() + strlen(">youngest") + 2));
            int rankI;
            for (int i = 0; i < 6; i++)
            {
                if (!strcmp(ranks[i], rank.c_str()))
                {
                    rankI =  i;
                }
                
            }
            Jedi young;
            young = Interface::get_youngest_jedi(name, rankI);
            std::cout << "The youngest jedi on planet " << name << " with rank " << rank << " is ";
            young.print_jedi();
        }
        if (user_input.substr(0, strlen(">mostusedon")) == string(">mostusedon")) {

            if (user_input.find("/") != string::npos)
            {
                string rank = user_input.substr(user_input.find("/") + 1);
                string name = user_input.substr(strlen(">mostusedon") + 1, user_input.size() - (rank.length() + strlen(">mostusedon") + 2));
                int rankI;
                for (int i = 0; i < 6; i++)
                {
                    if (!(strcmp(ranks[i], rank.c_str())))
                    {
                        rankI =  i;
                    }
                
                }
                string ms_color = Interface::get_most_used_saber_color(name, rankI);
                cout << "The most used saber color on " << name << " by jedi of rank " << rank << " is " << ms_color << '\n';

            }
            else
            {
                string name = user_input.substr(strlen(">mostusedon") + 1);
                string ms_color = Interface::get_most_used_saber_color(name);
                cout << "The most used saber color on " << name << " by at least one jedi of rank GRAND_MASTER is " << ms_color << '\n';
            }
            
        }
        if (user_input.substr(0, strlen(">printp")) == string(">printp")) {
            //cout << user_input << '\n';
            string name = user_input.substr(strlen(">printp") + 1);
            //cout << name << '\n';
            Interface::print_planet(name);
        }
        if (user_input.substr(0, strlen(">remove jedi")) == string(">remove jedi")) {

            string name = user_input.substr(user_input.find("/") + 1);
            string planet = user_input.substr(strlen(">remove jedi") + 1, user_input.length() - (name.length() + strlen(">remove jedi") + 2));
            try
            {
                Interface::removeJedi(planet, name);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (user_input.substr(0, strlen(">print jedi")) == string(">print jedi")) {

            string name = user_input.substr(strlen(">print jedi") + 1);
            
            Interface::print_jedi(name);
        }
        if (user_input.find("+") != string::npos) {

            string pname1 = user_input.substr(user_input.find("+") + 2);
            string pname2 = user_input.substr(0, user_input.length() - (pname1.length() + 3));
            cout << pname1 << " " << pname2 << endl; 
            pname1 + pname2;
        }

}
