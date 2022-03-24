/**
 * @file Test.cpp
 * @author Shaked Gofin (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 22-03-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
using namespace std;


ariel::Notebook notebook;

TEST_CASE("Good input") {
    CHECK_NOTHROW(notebook.write(1, 2, 3, Direction::Horizontal, "string"));
    CHECK_NOTHROW(notebook.read(1, 10, 1, Direction::Horizontal, 15)); 
    CHECK_NOTHROW(notebook.read(1, 10, 1, Direction::Horizontal, 110)); 
}

TEST_CASE("Bad input - Negetive input") {

    CHECK_THROWS(notebook.write(-1, 1, 1, Direction::Horizontal, "wrong"));
    CHECK_THROWS(notebook.read(-15,-5,-8,ariel::Direction::Horizontal,5));
    CHECK_THROWS(notebook.erase(-2,-3,-5,ariel::Direction::Horizontal,5));
    CHECK_THROWS(notebook.erase(-3,-4,-1,ariel::Direction::Horizontal,6));
    CHECK_THROWS(notebook.read(1, 10, 1, Direction::Horizontal, -50)); 
    CHECK_THROWS(notebook.read(1, 10, 1, Direction::Horizontal, -100)); 
    CHECK_THROWS(notebook.erase(1, 10, 1, Direction::Horizontal, -80)); 
    CHECK_THROWS(notebook.show(-6));
    CHECK_THROWS(notebook.show(-2));
}

TEST_CASE("Bad input - Row length cant be more than 100")
{
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(19,19,99,ariel::Direction::Horizontal,"testString"));
    CHECK_THROWS(notebook.write(20,21,95,ariel::Direction::Horizontal,"testString"));
    CHECK_THROWS(notebook.write(19,25,90,ariel::Direction::Horizontal,"testString"));
    CHECK_NOTHROW(notebook.write(3,2,2,ariel::Direction::Horizontal,"66"));
    CHECK_NOTHROW(notebook.write(5,6,9,ariel::Direction::Horizontal,"277"));
    CHECK_THROWS(notebook.erase(1, 4, 101, Direction::Vertical, 12));
}

TEST_CASE("Bad input - writing on wxisting test")
{
    ariel::Notebook notebook;
    notebook.write(4,4,4,ariel::Direction::Horizontal,"828");
    CHECK_THROWS(notebook.write(4,4,4,ariel::Direction::Horizontal,"828"));

    notebook.write(17,17,17,ariel::Direction::Horizontal,"stringg");
    CHECK_THROWS(notebook.write(17,17,17,ariel::Direction::Horizontal,"stringg"));

    notebook.write(19,19,19,ariel::Direction::Horizontal,"forTest");
    CHECK_THROWS(notebook.write(19,19,19,ariel::Direction::Horizontal,"forTest"));

    notebook.write(0, 0, 0, Direction::Horizontal, "wer");
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "wer"));
}