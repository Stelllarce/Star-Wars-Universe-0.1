#include <iostream>
#include <fstream>
#include <string>
#include "Jedi.h"
using namespace std;

int main() {

    cout  << "-----------------------STAR WARS UNIVERSE 0.1-----------------------\n";
    cout << "To check available commands type '>help'" << '\n';
    cout << "Enter a command: ";

    std::string user_input;
    std::string current_file_name;
    while (cin >> user_input) 
    {
		
        if (user_input == std::string(">help"))
        {
            cout << "Available commands:\n";
            cout << ">open <filepath> - opens the specified file\n";
            cout << ">close - closes the file that is currently opened\n";
            cout << ">save - saves changes made in the currently opened file\n";
            cout << ">saveas <filepath> - creates a new file in the specified file path\n";
            cout << ">exit - exits the program\n\n";
            cout << "Enter a command: ";
        }

        if (user_input.substr(0, 5) == std::string(">open"))
        {
            std::string file_path = user_input.substr(6, user_input.size() - 6);
            current_file_name = file_path;
            cout << file_path << " opened succesfully!\n\n";
            cout << "Enter a command: "; 
        }
        
        if (user_input == std::string(">close"))
        {
            cout << current_file_name << " closed succesfully!\n\n";
            cout << "Enter a command: "; 
        }

        if (user_input.substr(0, 7) == std::string(">saveas"))
        {
            std::string file_path = user_input.substr(8, user_input.size() - 8);
            cout << "File saved succesfully as " << file_path << "!\n\n";
            cout << "Enter a command: "; 

        }

        if (user_input == std::string(">save"))
        {
            cout << current_file_name << " saved succesfully!\n\n";
            cout << "Enter a command: "; 

        }

        if (user_input == std::string(">exit"))
        {
            cout << "Exiting the program...";
            break;
        }
    }
    return 0;
}