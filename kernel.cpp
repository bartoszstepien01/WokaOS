#include "drivers/screen.hpp"

extern "C" void kmain()
{
    ScreenDriver::clearScreen(red, green);
    ScreenDriver::printCharacter('a', 0, 24, red, green);
}