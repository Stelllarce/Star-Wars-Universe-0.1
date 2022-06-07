#include <iostream>
#include <fstream>
#include "Jedi.h"
using namespace std;

int main() {

    cout  << "-----------------------STAR WARS UNIVERSE 0.1-----------------------\n";
    cout << "To check available commands type '>help'" << '\n';
    cout << "Enter a command: ";

    String user_input;
    String current_file_name;
    while (cin >> user_input) 
    {
		
        if (user_input == String(">help"))
        {
            cout << "Available commands:\n";
            cout << ">open <filepath> - opens the specified file\n";
            cout << ">close - closes the file that is currently opened\n";
            cout << ">save - saves changes made in the currently opened file\n";
            cout << ">saveas <filepath> - creates a new file in the specified file path\n";
            cout << ">exit - exits the program\n\n";
            cout << "Enter a command: ";
        }

        if (user_input.my_substr(0, 5) == String(">open"))
        {
            String file_path = user_input.my_substr(6, user_input.get_size() - 6);
            current_file_name = file_path;
            cout << file_path << " opened succesfully!\n\n";
            cout << "Enter a command: "; 
        }
        
        if (user_input == String(">close"))
        {
            cout << current_file_name << " closed succesfully!\n\n";
            cout << "Enter a command: "; 
        }

        if (user_input == String(">save"))
        {
            cout << current_file_name << " saved succesfully!\n\n";
            cout << "Enter a command: "; 

        }

        if (user_input.my_substr(0, 7) == String(">saveas"))
        {
            String file_path = user_input.my_substr(8, user_input.get_size() - 8);
            cout << "File saved succesfully as " << file_path << "!\n\n";
            cout << "Enter a command: "; 

        }

        if (user_input == String(">exit"))
        {
            cout << "Exiting the program...";
            break;
        }
    }
    return 0;
}