extern "C" void kmain()
{
    char* vidmem = (char*) 0xB8000;
    vidmem[0] = 'a';
}