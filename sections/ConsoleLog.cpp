void ConsoleLog()
{//Writes called console commands to the log.
    __asm__
    (
        "MOV DWORD PTR SS:[EBP-4],2 \n"
        "PUSH [ESP+0xF4] \n"
        "CALL 0x00937CB0 \n"
        "ADD ESP,4 \n"
        "JMP 0x0041CE11 \n"
    );
}