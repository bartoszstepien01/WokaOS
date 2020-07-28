#pragma once
#include "program.hpp"
#include "../drivers/sound.hpp"
#include "../drivers/screen.hpp"
#include "../drivers/keyboard.hpp"

class Menu: public Program
{
private:
    string* options;
    uint8 optionsCount;
    int8 cursorPosition = 0;
public:
    Menu(string options[], uint8 optionsCount, string hint1 = "", string hint2 = ""):Program(hint1, hint2) 
    {
        this->options = options;
        this->optionsCount = optionsCount;
    }
    
    void start()
    {
        ScreenDriver::printCharacterAtPosition('>', 3, 3);
        for(uint8 i = 0; i < optionsCount; i++)
            ScreenDriver::printStringAtPosition(options[i], 5, i+3);
    }

    void loop()
    {
        Key current_key = KeyboardDriver::getKey();

        if(current_key == S)
        {
            cursorPosition++;
            if(cursorPosition >= optionsCount) cursorPosition = 0;
            for(uint8 i = 0; i < optionsCount; i++)
                ScreenDriver::printCharacterAtPosition(0, 3, i+3);
            ScreenDriver::printCharacterAtPosition('>', 3, cursorPosition+3);
        }
        if(current_key == W)
        {
            cursorPosition--;
            if(cursorPosition < 0) cursorPosition = optionsCount - 1;
            for(uint8 i = 0; i < optionsCount; i++)
                ScreenDriver::printCharacterAtPosition(0, 3, i+3);
            ScreenDriver::printCharacterAtPosition('>', 3, cursorPosition+3);
        }
    }
};