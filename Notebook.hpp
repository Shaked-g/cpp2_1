#pragma once
#include <string>
#include "Direction.hpp"

using namespace std;
namespace ariel {
    class Notebook {
        public:
            void write (int page, int row , int column , Direction direction, string str);
            string read (int page, int row , int column , Direction direction, int length);
            string erase (int page, int row , int column , Direction direction, int length);
            void show (int pageNumber);
    };
};