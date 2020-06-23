#pragma once
#include "types.hpp"

namespace String
{
    uint8 length(string text)
    {
        uint8 i = 0;
        while(text[i++]);  
        return i - 1;
    }

    string itoa(int val, int base)
    {
        static char buf[32] = {0};
        int i = 30;
        for(; val && i; --i, val /= base)
        {
            buf[i] = "0123456789abcdef"[val % base];
        }
        return &buf[i+1];
    }
}