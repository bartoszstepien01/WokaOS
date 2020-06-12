#include "drivers/screen.hpp"

extern "C" void kmain()
{
    ScreenDriver::setColour(lightRed, white);
    ScreenDriver::clearScreen();
    ScreenDriver::printString("WokaOS Alpha Version");
}