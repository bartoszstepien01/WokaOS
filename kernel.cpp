#include "drivers/screen.hpp"
#include "drivers/keyboard.hpp"

extern "C" void kmain()
{
    ScreenDriver::disableCursor();
    ScreenDriver::setColour(gray, black);
    ScreenDriver::clearScreen();
    ScreenDriver::printStringWithColourAtPosition("WOKA", 38, 11, Colour::white, Colour::blue);
    Key key = KeyboardDriver::getKey();
    if(key == Key::KeypadFour)
        ScreenDriver::printCharacterAtPosition('W', 0, 10);
}