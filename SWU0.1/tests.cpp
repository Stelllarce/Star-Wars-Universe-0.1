#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include <iostream>
#include "Jedi.h"

TEST_SUITE("Testing jedi class") {

    Jedi bob(String("Obi-Wan"), 10, String("#00000"), 15.3);
    TEST_CASE("Testing rank display") {

        CHECK(bob.get_rank() == String("YOUNGLING"));
    }
    TEST_CASE("Testing file funcitonality") {

        bob.save(String("Jedi.dat"));
        bob.load(String("Jedi.dat"));
        CHECK(bob.get_name() == String("Obi-Wan"));
        CHECK_EQ(bob.get_color(), String("#00000"));
        CHECK_EQ(bob.get_age(), 10);
        CHECK_EQ(bob.get_might(), 15.3);

    }
    
}