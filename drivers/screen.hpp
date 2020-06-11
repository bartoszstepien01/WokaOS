#pragma once
#include "../utils/types.hpp"

enum Colour{
    black, blue, green, cyan, red, purple, brown, gray, darkGray, lightBlue, lightGreen, lightCyan, lightRed, lightPurple, yellow, white
};

namespace ScreenDriver
{
    string videoMemory = (string) 0xB8000;

    void clearLines(uint8 from, uint8 to, Colour foregroundColour = gray, Colour backgroundColour = black)
    {
        uint16 i = 80 * from * 2;
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);
        for(i; i < (80 * to * 2); i++)
        {
            videoMemory[(i / 2) * 2] = 0;
            videoMemory[(i / 2) * 2 + 1] = colour;
        }
    }

    void clearScreen(Colour foregroundColour = gray, Colour backgroundColour = black)
    {
        clearLines(0, 25, foregroundColour, backgroundColour);
    }

    void printCharacter(char character, uint8 x, uint8 y, Colour foregroundColour = gray, Colour backgroundColour = black)
    {
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);    
        videoMemory[((y * 80 + x))*2] = character;
        videoMemory[((y * 80 + x))*2+1] = colour; 
    }
};