#include "system/mainframe.hpp"

extern "C" void kmain()
{
    MainFrame::draw(green, black);
    Program program = Program("Main menu", "Keycodes");
    MainFrame::setProgram(program);
    MainFrame::runLoop();
}