#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include <iostream>
#include "Jedi.h"
#include "Interface.h"
#include "Planet.h"

TEST_SUITE("Testing jedi class") {

    Jedi bob(std::string("Obi-Wan"), 10, std::string("#00000"), 10);
    TEST_CASE("Testing rank display") {

        CHECK(bob.get_rank() == std::string("YOUNGLING"));
    }
    TEST_CASE("Testing file funcitonality") {

        bob.save(std::string("Jedi.dat"));
        bob.load(std::string("Jedi.dat"));
        CHECK(bob.get_name() == std::string("Obi-Wan"));
        CHECK_EQ(bob.get_color(), std::string("#00000"));
        CHECK_EQ(bob.get_age(), 10);
        CHECK_EQ(bob.get_might(), 10);

    }
    TEST_CASE("Testing promote/demote methods") {

        bob.promote(0.5);
        CHECK_EQ(bob.get_rank(), std::string("PADWAN"));
        CHECK_EQ(bob.get_might(), 15);
        bob.promote(0.2);
        CHECK_EQ(bob.get_rank(), std::string("KNIGHT-ASPIRANT"));
        CHECK_EQ(bob.get_might(), 18);
        bob.demote(0.2);
        CHECK_EQ(bob.get_rank(), std::string("PADWAN"));
        CHECK_EQ(bob.get_might(), 14.4);

        for (int i = 0; i < 4; i++)
        {
            bob.promote(0.2);
        }
        CHECK_EQ(bob.get_rank(), std::string("GRAND_MASTER"));
        std::cout << '\n'; 
        bob.promote(0.1);
        CHECK_EQ(bob.get_rank(), std::string("GRAND_MASTER"));
        std::cout << '\n'; 

        for (int i = 0; i < 5; i++)
        {
            bob.demote(0.2);
        }
        CHECK_EQ(bob.get_rank(), std::string("YOUNGLING"));
        std::cout << '\n'; 
        bob.demote(0.1);
        CHECK_EQ(bob.get_rank(), std::string("YOUNGLING"));
        std::cout << '\n'; 
    }
    
}
TEST_SUITE("Testing Interface") { 

    // TEST_CASE("Testing add_planet") { 
    //     Interface::add_planet(std::string("Tatooine"));
    //     std::ifstream f("Tatooine.dat");
    //     CHECK(f.good() == true);
    //     f.close();
    // }
    // TEST_CASE("Testing crated file") {
    //     std::string name;
    //     std::ifstream fs("Tatooine.dat", std::ios::in | std::ios::binary);
    //     fs.read((char* ) name.c_str(), sizeof(name));
    //     CHECK_EQ(name.c_str(), std::string("Tatooine"));
    //     fs.close();
    // }

}