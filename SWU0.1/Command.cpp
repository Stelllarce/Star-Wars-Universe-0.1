#include "Command.h"
#include <iostream>
using namespace std;


void Command::init()
{
     cout  << "-----------------------STAR WARS UNIVERSE 0.1-----------------------\n";
    cout << "To check available commands type '>help'" << '\n';

    string input;
    string current_file_name;
    cout << "Enter a command: ";
    while (true)
    {
        getline(std::cin, input);
        file_command(input, current_file_name);
        starwars_command(input, current_file_name);
        if (input == string(">exit"))
        {
            cout << "Exiting the program...";
            break;
        }
        cout << "Enter a command: ";

    }
    
}

void Command::file_command(std::string& user_input, std::string& current_file_name)
{
    
        if (user_input == string(">help"))
        {
            cout << "Available commands:\n";
            cout << ">open <filepath> - opens the specified file\n";
            cout << ">close - closes the file that is currently opened\n";
            cout << ">save - saves changes made in the currently opened file\n";
            cout << ">saveas <filepath> - creates a new file in the specified file path\n";
            cout << ">exit - exits the program\n\n";
            //cout << "Enter a command: ";
        }

        if (user_input.substr(0, strlen(">open")) == string(">open"))
        {
            string file_path = user_input.substr(strlen(">open") + 1);
            current_file_name = file_path;
            cout << file_path << " opened succesfully!\n\n";
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

void Command::starwars_command(std::string& user_input, std::string& current_file_name)
{
    
    
        if (user_input.substr(0, strlen(">add planet")) == string(">add planet"))
        {
            string filename = user_input.substr(strlen(">addplanet") + 1);
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
                if (ranks[i] == rank_str.c_str())
                {
                    rank =  i;
                }
                
            }
            Interface::create_jedi(planet, name, age, rank, saber_col, might);

        }
        
        if (user_input.substr(0, strlen(">promote")) == string(">promote"))
        {
            string name = user_input.substr(strlen(">promote") + 1, user_input.find(","));
            string multiplier = user_input.substr(user_input.find(",") + 1);
            Interface::promote_jedi(name, stod(multiplier));
        }

        if (user_input.substr(0, strlen(">demote")) == string(">demote"))
        {
            string name = user_input.substr(strlen("demote") + 1, user_input.find(","));
            string multiplier = user_input.substr(user_input.find(",") + 1);
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
            string name = user_input.substr(strlen(">youngest") + 1, user_input.find(","));
            string rank = user_input.substr(user_input.find(",") + 1);
            int rankI;
            for (int i = 0; i < 6; i++)
            {
                if (ranks[i] == rank.c_str())
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

            if (user_input.find(",") != string::npos)
            {
                string name = user_input.substr(strlen(">mostusedon") + 1, user_input.find(","));
                string rank = user_input.substr(user_input.find(",") + 1);
                int rankI;
                for (int i = 0; i < 6; i++)
                {
                    if (ranks[i] == rank.c_str())
                    {
                        rankI =  i;
                    }
                
                }
                string ms_color = Interface::get_most_used_saber_color(name, rankI);
                cout << "The most used saber color on " << name << " by jedi of rank " << rank << " is " << ms_color << '\n';

            }
            else
            {
                string name = user_input.substr(strlen(">mostusedon") + 1, user_input.find(","));
                string ms_color = Interface::get_most_used_saber_color(name);
                cout << "The most used saber color on " << name << " by at least one jedi of rank GRAND_MASTER is " << ms_color << '\n';
            }
            
        }
        if (user_input.substr(0, strlen(">printp")) == string(">printp")) {
            cout << user_input << '\n';
            string name = user_input.substr(strlen(">printp") + 1);
            cout << name << '\n';
            Interface::print_planet(name);
        }
}
