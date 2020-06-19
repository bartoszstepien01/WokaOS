#pragma once
#include "../utils/ports.hpp"

enum Weekday{
    Sunday = 0x01, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

enum Month{
    January = 0x01, February, March, April, May, June, July, August, September, October, November, December
};

namespace CMOSDriver
{
    uint8 getSeconds()
    {
        Ports::outport(0x70, 0x00);
        return Ports::inport(0x71);
    }

    uint8 getMinutes()
    {
        Ports::outport(0x70, 0x02);
        return Ports::inport(0x71);
    }

    uint8 getHours()
    {
        Ports::outport(0x70, 0x04);
        return Ports::inport(0x71);
    }

    Weekday getWeekday()
    {
        Ports::outport(0x70, 0x06);
        return (Weekday) Ports::inport(0x71);
    }

    uint8 getDayOfMonth()
    {
        Ports::outport(0x70, 0x07);
        return Ports::inport(0x71);
    }

    Month getMonth()
    {
        Ports::outport(0x70, 0x08);
        return (Month) Ports::inport(0x71);
    }

    uint8 getYear()
    {
        Ports::outport(0x70, 0x09);
        return Ports::inport(0x71);
    }

    uint8 getCentury()
    {
        Ports::outport(0x70, 0x32);
        return Ports::inport(0x71);
    }
}