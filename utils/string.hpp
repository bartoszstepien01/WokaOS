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
}