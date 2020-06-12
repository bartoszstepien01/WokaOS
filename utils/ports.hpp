#pragma once
#include "types.hpp"

namespace Ports
{
    uint8 inport(uint16 port)
    {
        uint8 rv;
        __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));
        return rv;
    }

    void outport(uint16 port, uint8 data)
    {
        __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
    }
}