#include "drivers/screen.hpp"

extern "C" void kmain()
{
    ScreenDriver::disableCursor();
    ScreenDriver::setColour(gray, black);
    ScreenDriver::clearScreen();
    ScreenDriver::printStringWithColourAtPosition("WOKA", 38, 11, white, blue);
}