#pragma once
#include "../utils/types.hpp"
#include "../utils/ports.hpp"
#include "../utils/string.hpp"

enum Colour{
    black, blue, green, cyan, red, purple, brown, gray, darkGray, lightBlue, lightGreen, lightCyan, lightRed, lightPurple, yellow, white
};

namespace ScreenDriver
{
    namespace
    {
        string videoMemory = (string) 0xB8000;
        uint8 cursorX = 0, cursorY = 0;
        uint16 colour = 0x07;
        bool cursorEnabled = true;
    }

    uint16 getColour()
    {
        return colour;
    }

    void setColour(Colour foregroundColour, Colour backgroundColour)
    {
        colour = (backgroundColour << 4) | (foregroundColour & 0x0F); 
    }

    uint8 getCursorX()
    {
        return cursorX;
    }

    uint8 getCursorY()
    {
        return cursorY;
    }

    void setCursorPosition(uint8 x, uint8 y)
    {
        unsigned position =  y * 80 + x;
        Ports::outport(0x3D4, 14);
        Ports::outport(0x3D5, position >> 8);
        Ports::outport(0x3D4, 15);
        Ports::outport(0x3D5, position); 
    }

    void enableCursor()
    {
        setCursorPosition(cursorX, cursorY);
        cursorEnabled = true;
    }

    void disableCursor()
    {
        Ports::outport(0x3D4, 0x0A);
        Ports::outport(0x3D5, 0x20);
        cursorEnabled = false;
    }

    bool isCursorEnabled()
    {
        return cursorEnabled;
    }

    void clearLines(uint8 from, uint8 to)
    {
        uint16 i = 80 * from * 2;
        for(i; i < (80 * to * 2); i++)
        {
            videoMemory[(i / 2) * 2] = 0;
            videoMemory[(i / 2) * 2 + 1] = colour;
        }
    }

    void clearLinesWithColour(uint8 from, uint8 to, Colour foregroundColour, Colour backgroundColour)
    {
        uint16 i = 80 * from * 2;
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);
        for(i; i < (80 * to * 2); i++)
        {
            videoMemory[(i / 2) * 2] = 0;
            videoMemory[(i / 2) * 2 + 1] = colour;
        }
    }

    void clearScreen()
    {
        setCursorPosition(0, 0);
        clearLines(0, 25);
    }

    void clearScreenWithColour(Colour foregroundColour, Colour backgroundColour)
    {
        setCursorPosition(0, 0);
        clearLinesWithColour(0, 25, foregroundColour, backgroundColour);
    }

    void printCharacter(char character)
    {
        switch(character)
        {
            case(0x08):
                if(cursorX > 0)
                {
                    cursorX--;
                    videoMemory[((cursorY * 80 + cursorX)) * 2] = 0;
                    videoMemory[((cursorY * 80 + cursorX)) * 2 + 1] = colour;
                }
                break;
            case('\r'):
                cursorX = 0;
                break;
            case('\n'):
                cursorX = 0;
                cursorY++;
                break;
            default:
                videoMemory[((cursorY * 80 + cursorX)) * 2] = character;
                videoMemory[((cursorY * 80 + cursorX)) * 2 + 1] = colour;
                cursorX++;
                break; 
        }
        if(cursorEnabled) setCursorPosition(cursorX, cursorY);
    }

    void printCharacterAtPosition(char character, uint8 x, uint8 y)
    {
        switch(character)
        {
            case(0x08):
                if(x > 0)
                {
                    x--;
                    videoMemory[((y * 80 + x)) * 2] = 0;
                    videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                }
                break;
            case('\r'): break;
            case('\n'): break;
            default:
                videoMemory[((y * 80 + x)) * 2] = character;
                videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                x++;
                break; 
        }
    }

    void printCharacterWithColour(char character, Colour foregroundColour, Colour backgroundColour)
    {
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);    
        switch(character)
        {
            case(0x08):
                if(cursorX > 0)
                {
                    cursorX--;
                    videoMemory[((cursorY * 80 + cursorX)) * 2] = 0;
                    videoMemory[((cursorY * 80 + cursorX)) * 2 + 1] = colour;
                }
                break;
            case('\r'):
                cursorX = 0;
                break;
            case('\n'):
                cursorX = 0;
                cursorY++;
                break;
            default:
                videoMemory[((cursorY * 80 + cursorX)) * 2] = character;
                videoMemory[((cursorY * 80 + cursorX)) * 2 + 1] = colour;
                cursorX++;
                break; 
        }
        if(cursorEnabled) setCursorPosition(cursorX, cursorY);
    }

    void printCharacterWithColourAtPosition(char character, uint8 x, uint8 y, Colour foregroundColour, Colour backgroundColour)
    {
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);
        switch(character)
        {
            case(0x08):
                if(x > 0)
                {
                    x--;
                    videoMemory[((y * 80 + x)) * 2] = 0;
                    videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                }
                break;
            case('\r'): break;
            case('\n'): break;
            default:
                videoMemory[((y * 80 + x)) * 2] = character;
                videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                x++;
                break; 
        }
    }

    void printString(string text)
    {
        uint8 length = String::length(text);
        for(uint8 i = 0; i < length; i++)
            printCharacter(text[i]);
    }

    void printStringAtPosition(string text, uint8 x, uint8 y)
    {
        uint8 length = String::length(text);
        for(uint8 i = 0; i < length; i++)
            switch(text[i])
            {
                case(0x08):
                    if(x > 0)
                    {
                        x--;
                        videoMemory[((y * 80 + x)) * 2] = 0;
                        videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                    }
                    break;
                case('\r'):
                    x = 0;
                    break;
                case('\n'):
                    x = 0;
                    y++;
                    break;
                default:
                    videoMemory[((y * 80 + x)) * 2] = text[i];
                    videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                    x++;
                    break; 
            }
    }

    void printStringWithColour(string text, Colour foregroundColour, Colour backgroundColour)
    {
        uint8 length = String::length(text);
        for(uint8 i = 0; i < length; i++)
            printCharacterWithColour(text[i], foregroundColour, backgroundColour);
    }

    void printStringWithColourAtPosition(string text, uint8 x, uint8 y, Colour foregroundColour, Colour backgroundColour)
    {
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);
        uint8 length = String::length(text);
        for(uint8 i = 0; i < length; i++)
            switch(text[i])
            {
                case(0x08):
                    if(x > 0)
                    {
                        x--;
                        videoMemory[((y * 80 + x)) * 2] = 0;
                        videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                    }
                    break;
                case('\r'):
                    x = 0;
                    break;
                case('\n'):
                    x = 0;
                    y++;
                    break;
                default:
                    videoMemory[((y * 80 + x)) * 2] = text[i];
                    videoMemory[((y * 80 + x)) * 2 + 1] = colour;
                    x++;
                    break; 
            }
    }

    void setCellColour(uint8 x, uint8 y, Colour foregroundColour, Colour backgroundColour)
    {
        uint16 colour = (backgroundColour << 4) | (foregroundColour & 0x0F);
        videoMemory[((y * 80 + x)) * 2 + 1] = colour;
    }
};