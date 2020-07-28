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
        ScreenDriver::printStringAtPosition(options[0], 4, 3);
        ScreenDriver::printCharacterAtPosition('>', 76, 3);
        for(uint8 i = 3; i <= 76; i++)
            ScreenDriver::setCellColour(i, cursorPosition+3, MainFrame::backgroundColour, MainFrame::foregroundColour);
        for(uint8 i = 1; i < optionsCount; i++)
        {
            ScreenDriver::printStringAtPosition(options[i], 4, i+3);
            ScreenDriver::printCharacterAtPosition('>', 76, i+3);
        }
    }

    void loop()
    {
        Key current_key = KeyboardDriver::getKey();

        if(current_key == S)
        {
            for(uint8 i = 3; i <= 76; i++)
                ScreenDriver::setCellColour(i, cursorPosition+3, MainFrame::foregroundColour, MainFrame::backgroundColour);
            cursorPosition++;
            if(cursorPosition >= optionsCount) cursorPosition = 0;
            for(uint8 i = 3; i <= 76; i++)
                ScreenDriver::setCellColour(i, cursorPosition+3, MainFrame::backgroundColour, MainFrame::foregroundColour);
        }
        if(current_key == W)
        {
            for(uint8 i = 3; i <= 76; i++)
                ScreenDriver::setCellColour(i, cursorPosition+3, MainFrame::foregroundColour, MainFrame::backgroundColour);
            cursorPosition--;
            if(cursorPosition < 0) cursorPosition = optionsCount - 1;
            for(uint8 i = 3; i <= 76; i++)
                ScreenDriver::setCellColour(i, cursorPosition+3, MainFrame::backgroundColour, MainFrame::foregroundColour);
        }
    }
};