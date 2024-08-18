#include "constants.hpp"
#include "window.hpp"

using constants::WINDOW_TITLE;
using constants::WINDOW_SIZEX;
using constants::WINDOW_SIZEY;

int main () 
{
    window win(WINDOW_SIZEX, WINDOW_SIZEY, WINDOW_TITLE);
    return 0;
}
