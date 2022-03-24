#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <string>
#include <iostream>

using namespace std;

namespace ariel {

            void Notebook::write (int page, int row , int column , Direction direction, string str) {

            };

            string Notebook::read (int page, int row , int column , Direction direction, int length) {
                string str = "read function";
                return str;
            };

            string Notebook::erase (int page, int row , int column , Direction direction, int length) {
                string str = "erase function";
                return str;
            };

            void Notebook::show (int pageNumber) {
                
            };

};