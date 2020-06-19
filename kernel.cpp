#include "drivers/screen.hpp"
#include "drivers/keyboard.hpp"
#include "drivers/cmos.hpp"

extern "C" void kmain()
{
    //ScreenDriver::disableCursor();
    ScreenDriver::setColour(gray, black);
    ScreenDriver::clearScreen();
    //ScreenDriver::printStringWithColourAtPosition("WOKA", 38, 11, Colour::white, Colour::blue);
    while(true)
    {
        char key = KeyboardDriver::keyToChar(KeyboardDriver::getKey());
        if(key != 0) ScreenDriver::printCharacter(key);
    }
}