#pragma once
#include "../utils/ports.hpp"

namespace SoundDriver
{
    void stopSound()
    {
        uint8 temp = Ports::inport(0x61) & 0xFC;
        Ports::outport(0x61, temp);
    }

    void playSound(uint16 frequency)
    {
        stopSound();
        uint16 div;
        uint8 temp;
        div = 1193180 / frequency;
        Ports::outport(0x43, 0xB6);
        Ports::outport(0x42, (uint8) div);
        Ports::outport(0x42, (uint8) div >> 8);
        temp = Ports::inport(0x61);
        if(temp != temp | 3)
            Ports::outport(0x61, temp | 3);
    }
}