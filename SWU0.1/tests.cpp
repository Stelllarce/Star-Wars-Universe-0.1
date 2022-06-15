#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "Jedi.h"
#include "Interface.h"
//#include "Planet.h"
#include <iostream>
#include <cstring>

TEST_SUITE("Testing jedi class") {

    Jedi bob(std::string("Obi-Wan"), 0, 48, std::string("#00000"), 15);
    Jedi chosen(std::string("Anakin Skywalker"), 0, 22, std::string("#2E67F8"), 10);
    TEST_CASE("Testing rank display") {

        CHECK(bob.get_rank() == std::string("YOUNGLING"));
    }
    // TEST_CASE("Testing file funcitonality") {

    //     bob.save(std::string("Jedi.txt"));
    //     bob.load(std::string("Jedi.txt"), std::string("Obi-Wan"));
    //     chosen.save(std::string("Jedi.txt"));
    //     chosen.load(std::string("Jedi.txt"), std::string("Anakin Skywalker"));
        
    //     CHECK(bob.get_name() == std::string("Obi-Wan"));
    //     CHECK_EQ(bob.get_color(), std::string("#00000"));
    //     CHECK_EQ(bob.get_age(), 10);
    //     CHECK_EQ(bob.get_might(), 10);

    //     CHECK(chosen.get_name() == std::string("Anakin Skywalker"));
    //     CHECK_EQ(chosen.get_color(), std::string("#2E67F8"));
    //     CHECK_EQ(chosen.get_age(), 22);
    //     CHECK_EQ(chosen.get_might(), 10);

    // }
    TEST_CASE("Testing promote/demote methods") {

        bob.promote(0.5);
        CHECK_EQ(bob.get_rank(), std::string("PADWAN"));
        CHECK_EQ(bob.get_might(), 22.5);
        bob.promote(0.2);
        CHECK_EQ(bob.get_rank(), std::string("KNIGHT-ASPIRANT"));
        CHECK_EQ(bob.get_might(), 27);
        bob.demote(0.2);
        CHECK_EQ(bob.get_rank(), std::string("PAWAN"));
        CHECK_EQ(bob.get_might(), 21.6);

        std::cout << "Trying to promote higher than GRANDMASTER\n";
        for (int i = 0; i < 4; i++)
        {
            bob.promote(0.2);
        }
        CHECK_EQ(bob.get_rank(), std::string("GRAND_MASTER"));
        std::cout << '\n'; 
        bob.promote(0.1);
        CHECK_EQ(bob.get_rank(), std::string("GRAND_MASTER"));
        std::cout << '\n'; 

        
    }
    TEST_CASE("Testing demote method") { 
        std::cout << "Trying to demote lower than YOUNGLING\n";
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
    TEST_CASE("Testing Anakin") { 
    
        for (size_t i = 0; i < 2; i++)
        {
            chosen.promote(0.9);
        }
        std::cout << chosen.get_name() << "'s rank is " << chosen.get_rank() << '\n';
        std::cout << chosen.get_name() << " wants to be promoted to " << ranks[3] << '\n';
        try
        {
            chosen.promote(1);
        }
        catch(const std::runtime_error &rte)
        {
            std::cerr << rte.what() << '\n';
        }
        std::cout << chosen.get_name() << "'s rank is " << chosen.get_rank() << '\n';
        
    }
    
    
}
TEST_SUITE("Testing Interface") { 
    TEST_CASE("Testing if add_planet creates proper file") {
        try
        {
            //Interface::add_planet(std::string("Mustafar"));
            //Interface::add_planet(std::string("Tatooine"));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
         
        std::ifstream f("Tatooine.txt");
        CHECK(f.good() == true);
        f.close();
    }
    TEST_CASE("Testing created file") {
        try
        {
            //Interface::create_jedi(std::string("Tatooine"), std::string("Obi-Wan"), 0, 48, std::string("#00000"), 15);
            //Interface::create_jedi(std::string("Tatooine"), std::string("Anakin Skywalker"), 0, 22, std::string("#2E67F8"), 10);
            //Interface::removeJedi(std::string("Tatooine"), std::string("Obi-Wan"));
            Interface::promote_jedi(std::string("Obi-Wan"), 1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    
}