#pragma once
#include "../drivers/screen.hpp"
#include "../drivers/cmos.hpp"

namespace MainFrame
{
    void printWithLeadingZeros(string text, int x, int y)
    {
        switch(String::length(text))
        {
            case 0: ScreenDriver::printStringAtPosition("00", x, y); break;
            case 1: 
                ScreenDriver::printCharacterAtPosition(48, x, y);
                ScreenDriver::printStringAtPosition(text, x + 1, y);
            break;
            default: ScreenDriver::printStringAtPosition(text, x, y); break;
        }
    }

    void printHourAndDate()
    {
        string seconds = String::itoa(CMOSDriver::getSeconds(), 16);
        printWithLeadingZeros(seconds, 77, 1);
        ScreenDriver::printCharacterAtPosition(':', 76, 1);
        string minutes = String::itoa(CMOSDriver::getMinutes(), 16);
        printWithLeadingZeros(minutes, 74, 1);
        ScreenDriver::printCharacterAtPosition(':', 73, 1);
        string hours = String::itoa(CMOSDriver::getHours(), 16);
        printWithLeadingZeros(hours, 71, 1);
        int len = 8;
        string year = String::itoa(CMOSDriver::getYear(), 16);
        len += String::length(year);
        ScreenDriver::printStringAtPosition(year, 78 - len, 1);
        string century = String::itoa(CMOSDriver::getCentury(), 16);
        len += String::length(century);
        ScreenDriver::printStringAtPosition(century, 78 - len, 1);
        string month = CMOSDriver::monthToString(CMOSDriver::getMonth());
        len += String::length(month) + 1;
        ScreenDriver::printStringAtPosition(month, 78 - len, 1);
        string dayOfMonth = String::itoa(CMOSDriver::getDayOfMonth(), 16);
        len += String::length(dayOfMonth) + 1;
        ScreenDriver::printStringAtPosition(dayOfMonth, 78 - len, 1);
        ScreenDriver::printStringAtPosition(", ", 78 - len - 2, 1);
        string weekday = CMOSDriver::weekdayToString(CMOSDriver::getWeekday());
        len += String::length(weekday) + 2;
        ScreenDriver::printStringAtPosition(weekday, 78 - len, 1);
    }

    void printTitleBar(string systemName)
    {
        ScreenDriver::printStringAtPosition(systemName, 1, 1);
        printHourAndDate();
    }

    void printFrame()
    {
        ScreenDriver::printCharacterAtPosition(201, 1, 2);
        ScreenDriver::printCharacterAtPosition(187, 78, 2);
        ScreenDriver::printCharacterAtPosition(200, 1, 21);
        ScreenDriver::printCharacterAtPosition(188, 78, 21);
        for(uint8 i = 2; i < 78; i++)        
        {            
            ScreenDriver::printCharacterAtPosition(205, i, 2);
            ScreenDriver::printCharacterAtPosition(205, i, 21);
        }
        for(uint8 i = 3; i < 21; i++)
        {
            ScreenDriver::printCharacterAtPosition(186, 1, i);
            ScreenDriver::printCharacterAtPosition(186, 78, i);
        }
    }

    void printInfoBar(string hint1, string hint2)
    {
        ScreenDriver::printStringAtPosition(hint1, 1, 22);
        ScreenDriver::printStringAtPosition(hint2, 1, 23);
    }

    void draw(Colour foregroundColour, Colour backgroundColour)
    {
        ScreenDriver::setColour(foregroundColour, backgroundColour);
        ScreenDriver::clearScreen();
        ScreenDriver::disableCursor();
        printTitleBar("Woka OS Dev");
        printFrame();
        printInfoBar("Program hint", "Program hint 2");
    }
}