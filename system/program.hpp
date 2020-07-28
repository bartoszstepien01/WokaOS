#pragma once
#include "../utils/types.hpp"

class Program
{
private:
    string programHint1;
    string programHint2;
public:
    Program(string hint1 = "", string hint2 = ""): programHint1(hint1), programHint2(hint2) {}
    virtual void start() {}
    virtual void loop() {}
    string getProgramHint1() {return programHint1;}
    string getProgramHint2() {return programHint2;}
};