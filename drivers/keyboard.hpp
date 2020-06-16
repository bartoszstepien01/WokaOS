#pragma once
#include "../utils/ports.hpp"

enum Key{
    Esc = 0x01, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Zero, Hyphen, Equals, Backspace, 
    Tab, Q, W, E, R, T, Y, U, I, O, P, LeftSquareBracket, RightSquareBracket, 
    Enter, LeftCtrl, A, S, D, F, G, H, J, K, L, Semicolon, Apostrophe, BackTick,
    LeftShift, Backslash, Z, X, C, V, B, N, M, Comma, Dot, Slash, RightShift, 
    KeypadAsterisk, LeftAlt, Space, CapsLock,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
    NumLock, ScrollLock, 
    KeypadSeven, KeypadEight, KeypdadNine, KeypadHyphen, 
    KeypadFour, KeypadFive, KeypadSix, KeypadPlus,
    KeypadOne, KeypadTwo, KeypadThree, KeypadZero, KeypadDot,
    F11 = 0x57, F12
};

namespace KeyboardDriver
{
    Key getKey()
    {
        while(true)
            if(Ports::inport(0x64) & 0x1)
                return (Key) Ports::inport(0x60);
    }
}