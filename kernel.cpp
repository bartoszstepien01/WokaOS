#include "system/mainframe.hpp"
#include "system/menu.hpp"

extern "C" void kmain()
{
    MainFrame::draw(green, black);
    string options[] = {"Accessories", "Office", "Audio & graphics", "Games", "Internet", "Programming", "Administration", "Settings", "Favourites", "Others"};
    Menu menu = Menu(options, 10, "Main menu", "WS - change option, Enter - select");
    MainFrame::setProgram(&menu);
    MainFrame::runLoop();
}