#include "Command.h"
#include <iostream>
using namespace std;


void Command::init()
{
     cout  << "-----------------------STAR WARS UNIVERSE 0.1-----------------------\n";
    cout << "To check available commands type '>help'" << '\n';

    
    cout << "Enter a command: ";
    while (true)
    {
        getline(std::cin, input);
        file_command();
        starwars_command();
        if (input == string(">exit"))
        {
            try
            {
                Interface::exit(is_open);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            if (!is_open) 
            {
                cout << "Exiting the program...";
                break;
            }
        }
    
        cout << "Enter a command: ";
        

    }
    
}

void Command::file_command()
{
    
        if (input == string(">help"))
        {
            cout << "Available commands:\n";
            cout << ">open <filepath> - opens the specified file\n";
            cout << ">close - closes the file that is currently opened\n";
            cout << ">save - saves changes made in the currently opened file\n";
            cout << ">saveas <filepath> - creates a new file in the specified file path\n";
            cout << ">exit - exits the program\n";
            cout << "TYPE '>pg2' to go to next page\n\n";
            cout << "-----------------------------------------------------------\n";
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
        
        if (input.substr(0, strlen(">open")) == string(">open"))
        {
            string file_path = input.substr(strlen(">open") + 1);
            try
            {
                Interface::open(file_path, load, is_open);
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << '\n';
            }
            current_file_name = file_path;
            //cout << "Enter a command: "; 
        }
        
        if (input == string(">close"))
        {
            try
            {
                Interface::close(current_file_name, load, is_open);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        if (input.substr(0, strlen(">saveas")) == string(">saveas"))
        {
            string file_path = input.substr(strlen(">saveas") + 1);
            try
            {
                Interface::save_as(file_path, load, is_open);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }

        if (input == string(">save"))
        {
            try
            {
                Interface::save(current_file_name, load, is_open);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }

        
}

void Command::starwars_command()
{
    
    
        if (input.substr(0, strlen(">add planet")) == string(">add planet"))
        {
            string filename = input.substr(strlen(">add planet") + 1);
            Interface::add_planet(filename);
            cout << filename << " successfully created!\n";
        }

        if (input.substr(0, strlen(">create jedi")) == string(">create jedi"))
        {
            string name, saber_col, rank_str, planet;
            int age, rank;
            double might;
            cout << "\nPlanet: ";
            getline(cin, planet);
            cout << "\nName: ";
            getline(cin, name);
            cout << "\nAge: ";
            cin >> age;
            cin.ignore();
            cout << "\nRank: ";
            getline(cin, rank_str);
            cout << "\nSaber color: ";
            getline(cin, saber_col);
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
        
        if (input.substr(0, strlen(">promote")) == string(">promote"))
        {
            string multiplier = input.substr(input.find("/") + 1);
            string name = input.substr(strlen(">promote") + 1, input.length() - (multiplier.length() + strlen(">promote") + 2));
            try
            {
                
                Interface::promote_jedi(name, stod(multiplier));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }

        if (input.substr(0, strlen(">demote")) == string(">demote"))
        {
            string multiplier = input.substr(input.find("/") + 1);
            string name = input.substr(strlen(">demote") + 1, input.length() - (multiplier.length() + strlen(">demote") + 2));
            try
            {
                
                Interface::demote_jedi(name, stod(multiplier));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            

        }

        if (input.substr(0, strlen(">strongest")) == string(">strongest"))
        {
            string name = input.substr(strlen(">strongest") + 1);
            Jedi str;
            str = Interface::get_strongest_jedi(name);

            cout << "Strongest jedi on " << name << " is "; 
            str.print_jedi();
        }

        if (input.substr(0, strlen(">youngest")) == string(">youngest"))
        {
            string rank = input.substr(input.find("/") + 1);
            string name = input.substr(strlen(">youngest") + 1, input.length() - (rank.length() + strlen(">youngest") + 2));
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
        if (input.substr(0, strlen(">mostusedon")) == string(">mostusedon")) {

            if (input.find("/") != string::npos)
            {
                string rank = input.substr(input.find("/") + 1);
                string name = input.substr(strlen(">mostusedon") + 1, input.size() - (rank.length() + strlen(">mostusedon") + 2));
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
                string name = input.substr(strlen(">mostusedon") + 1);
                string ms_color = Interface::get_most_used_saber_color(name);
                cout << "The most used saber color on " << name << " by at least one jedi of rank GRAND_MASTER is " << ms_color << '\n';
            }
            
        }
        if (input.substr(0, strlen(">printp")) == string(">printp")) {
            //cout << input << '\n';
            string name = input.substr(strlen(">printp") + 1);
            //cout << name << '\n';
            Interface::print_planet(name);
        }
        if (input.substr(0, strlen(">remove jedi")) == string(">remove jedi")) {

            string name = input.substr(input.find("/") + 1);
            string planet = input.substr(strlen(">remove jedi") + 1, input.length() - (name.length() + strlen(">remove jedi") + 2));
            try
            {
                Interface::removeJedi(planet, name);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (input.substr(0, strlen(">print jedi")) == string(">print jedi")) {

            string name = input.substr(strlen(">print jedi") + 1);
            
            Interface::print_jedi(name);
        }
        if (input.find("+") != string::npos) {

            string pname1 = input.substr(input.find("+") + 2);
            string pname2 = input.substr(0, input.length() - (pname1.length() + 3));
            cout << pname1 << " " << pname2 << endl; 
            Interface::print_planets(pname1, pname2);
        }

}
