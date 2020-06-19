#pragma once
#include "../utils/ports.hpp"

enum Key{
    None = 0x00, Esc, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Zero, Hyphen, Equals, Backspace, 
    Tab, Q, W, E, R, T, Y, U, I, O, P, LeftSquareBracket, RightSquareBracket, 
    Enter, LeftCtrl, A, S, D, F, G, H, J, K, L, Semicolon, Apostrophe, BackTick,
    LeftShift, Backslash, Z, X, C, V, B, N, M, Comma, Dot, Slash, RightShift, 
    KeypadAsterisk, LeftAlt, Space, CapsLock,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
    NumLock, ScrollLock, 
    KeypadSeven, KeypadEight, KeypadNine, KeypadHyphen, 
    KeypadFour, KeypadFive, KeypadSix, KeypadPlus,
    KeypadOne, KeypadTwo, KeypadThree, KeypadZero, KeypadDot,
    F11 = 0x57, F12,
    EscReleased = 0x81, OneReleased, TwoReleased, ThreeReleased, FourReleased, FiveReleased, SixReleased, SevenReleased, EightReleased, NineReleased, ZeroReleased, HyphenReleased, EqualsReleased, BackspaceReleased, 
    TabReleased, QReleased, WReleased, EReleased, RReleased, TReleased, YReleased, UReleased, IReleased, OReleased, PReleased, LeftSquareBracketReleased, RightSquareBracketReleased, 
    EnterReleased, LeftCtrlReleased, AReleased, SReleased, DReleased, FReleased, GReleased, HReleased, JReleased, KReleased, LReleased, SemicolonReleased, ApostropheReleased, BackTickReleased,
    LeftShiftReleased, BackslashReleased, ZReleased, XReleased, CReleased, VReleased, BReleased, NReleased, MReleased, CommaReleased, DotReleased, SlashReleased, RightShiftReleased, 
    KeypadAsteriskReleased, LeftAltReleased, SpaceReleased, CapsLockReleased,
    F1Released, F2Released, F3Released, F4Released, F5Released, F6Released, F7Released, F8Released, F9Released, F10Released,
    NumLockReleased, ScrollLockReleased, 
    KeypadSevenReleased, KeypadEightReleased, KeypadNineReleased, KeypadHyphenReleased, 
    KeypadFourReleased, KeypadFiveReleased, KeypadSixReleased, KeypadPlusReleased,
    KeypadOneReleased, KeypadTwoReleased, KeypadThreeReleased, KeypadZeroReleased, KeypadDotReleased,
    F11Released = 0xD7, F12Released,
};

namespace KeyboardDriver
{
    Key getKey()
    {
        if(Ports::inport(0x64) & 0x1)
            return (Key) Ports::inport(0x60);
        return Key::None;
    }

    char keyToChar(Key key)
    {
        switch(key)
        {
            case Esc: return '\e';
            case One: case KeypadOne: return '1';
            case Two: case KeypadTwo: return '2';
            case Three: case KeypadThree: return '3';
            case Four: case KeypadFour: return '4';
            case Five: case KeypadFive: return '5';
            case Six: case KeypadSix: return '6';
            case Seven: case KeypadSeven: return '7';
            case Eight: case KeypadEight: return '8';
            case Nine: case KeypadNine: return '9';
            case Zero: case KeypadZero: return '0';
            case Hyphen: case KeypadHyphen: return '-';
            case Equals: return '=';
            case Backspace: return '\b';
            case Tab: return '\t';
            case Q: return 'q';
            case W: return 'w';
            case E: return 'e';
            case R: return 'r';
            case T: return 't';
            case Y: return 'y';
            case U: return 'u';
            case I: return 'i';
            case O: return 'o';
            case P: return 'p';
            case LeftSquareBracket: return '[';
            case RightSquareBracket: return ']';
            case Enter: return '\n';
            case A: return 'a';
            case S: return 's';
            case D: return 'd';
            case F: return 'f';
            case G: return 'g';
            case H: return 'h';
            case J: return 'j';
            case K: return 'k';
            case L: return 'l';
            case Semicolon: return ';';
            case Apostrophe: return '\'';
            case BackTick: return '`';
            case Backslash: return '\\';
            case Z: return 'z';
            case X: return 'x';
            case C: return 'c';
            case V: return 'v';
            case B: return 'b';
            case N: return 'n';
            case M: return 'm';
            case Comma: return ',';
            case Dot: case KeypadDot: return '.';
            case Slash: return '/';
            case KeypadAsterisk: return '*';
            case Space: return ' ';
            case KeypadPlus: return '+';
            default: return 0;
        }
    }
}