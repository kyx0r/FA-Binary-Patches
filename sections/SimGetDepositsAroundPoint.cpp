void SimGetDepositsAroundPoint()
{
    const char* s_X1 = "X1";
    const char* s_Z1 = "Z1";
    const char* s_X2 = "X2";
    const char* s_Z2 = "Z2";
    const char* s_Type = "Type";
    const char* s_Dist = "Dist";
    __asm__
    (
        "MOV EAX,[ESI+0xC] \n"
        "MOVSS XMM0,[EAX+0x4] \n"     // X
        "MOVSS XMM1,[EAX+0xC] \n"     // Z
        "MOVSS XMM2,[EAX+0x14] \n"    // Radius
        "CVTTSS2SI EAX,[EAX+0x1C] \n" // Type

        "SUB ESP,0x28 \n"
        "XORPS XMM5,XMM5 \n"
        "MOVUPS [ESP],XMM5 \n"
        "MOV ECX,ESP \n"
        "PUSH EAX \n"
        "PUSH 0 \n"
        "PUSH 0 \n"
        "PUSH [ESI+0x44] \n"
        "CALL 0x00909940 \n"          // CreateTable
        "POP EAX \n"
        "MOV DWORD PTR[ESP+0x24],1 \n"

        "MOV ECX,[0x10A63F0] \n"
        "MOV ECX,[ECX+0x8D0] \n"
        "MOV EDX,[ECX+0x14] \n"
        "MOV EDI,[ECX+0x10] \n"

        "L1: \n"
          "CMP EDI,EDX \n"
          "JGE L4 \n"

          "CMP EAX,0 \n"
          "JE L2 \n"
          "CMP EAX,[EDI+0x10] \n"
          "JNE L3 \n"

          "L2: \n"
          "MOV EBX,[EDI] \n"
          "ADD EBX,[EDI+0x8] \n"
          "CVTSI2SS XMM3,EBX \n"
          "MULSS XMM3,[0xE4F724] \n" // 0.5
          "SUBSS XMM3,XMM0 \n"
          "MULSS XMM3,XMM3 \n"

          "MOV EBX,[EDI+0x4] \n"
          "ADD EBX,[EDI+0xC] \n"
          "CVTSI2SS XMM4,EBX \n"
          "MULSS XMM4,[0xE4F724] \n" // 0.5
          "SUBSS XMM4,XMM1 \n"
          "MULSS XMM4,XMM4 \n"

          "ADDSS XMM3,XMM4 \n"
          "SQRTSS XMM3,XMM3 \n"
          "COMISS XMM3,XMM2 \n"
          "JA L3 \n"

          "MOVSS [ESP+0x14],XMM0 \n"
          "MOVSS [ESP+0x18],XMM1 \n"
          "MOV [ESP+0x1C],EAX \n"
          "MOV [ESP+0x20],EDX \n"

          "SUB ESP,0x14 \n"
          "MOVUPS [ESP],XMM5 \n"
          "MOV ECX,ESP \n"
          "PUSH 0 \n"
          "PUSH 0 \n"
          "PUSH [ESI+0x44] \n"
          "CALL 0x00909940 \n"        // CreateTable

          "MOV ECX,ESP \n"
          "PUSH [EDI] \n"
          "PUSH %[s_X1] \n"
          "CALL 0x009081F0 \n"        // PushInt

          "MOV ECX,ESP \n"
          "PUSH [EDI+0x4] \n"
          "PUSH %[s_Z1] \n"
          "CALL 0x009081F0 \n"        // PushInt

          "MOV ECX,ESP \n"
          "PUSH [EDI+0x8] \n"
          "PUSH %[s_X2] \n"
          "CALL 0x009081F0 \n"        // PushInt

          "MOV ECX,ESP \n"
          "PUSH [EDI+0xC] \n"
          "PUSH %[s_Z2] \n"
          "CALL 0x009081F0 \n"        // PushInt

          "MOV ECX,ESP \n"
          "PUSH [EDI+0x10] \n"
          "PUSH %[s_Type] \n"
          "CALL 0x009081F0 \n"        // PushInt

          "MOV ECX,ESP \n"
          "SUB ESP,4 \n"
          "MOVSS [ESP],XMM3 \n"
          "PUSH %[s_Dist] \n"
          "CALL 0x00908320 \n"        // PushNumber

          "MOV ECX,ESP \n"
          "PUSH [ESI+0x44] \n"
          "PUSH ESI \n"
          "CALL 0x00907D80 \n"        // PushStack

          "MOV ECX,[ESP] \n"
          "PUSH ESP \n"
          "PUSH [ESP+0x3C] \n"
          "CALL 0x009087A0 \n"        // PushTable

          "MOV ECX,ESP \n"
          "CALL 0x009075D0 \n"        // LuaObjectFinalize
          "ADD ESP,0x14 \n"

          "ADD DWORD PTR[ESP+0x24],0x1 \n"
          "MOV EDX,[ESP+0x20] \n"
          "MOV EAX,[ESP+0x1C] \n"
          "MOVSS XMM1,[ESP+0x18] \n"
          "MOVSS XMM0,[ESP+0x14] \n"

          "L3: \n"
          "ADD EDI,0x14 \n"
        "JMP L1 \n"

        "L4: \n"
        "MOV ECX,ESP \n"
        "PUSH [ESI+0x44] \n"
        "PUSH ESI \n"
        "CALL 0x00907D80 \n"          // PushStack

        "MOV ECX,ESP \n"
        "CALL 0x009075D0 \n"          // LuaObjectFinalize
        "ADD ESP,0x28 \n"

        "MOV EAX,0x1 \n"
        :
        : [s_X1] "i" (s_X1), [s_Z1] "i" (s_Z1), [s_X2] "i" (s_X2), [s_Z2] "i" (s_Z2), [s_Type] "i" (s_Type), [s_Dist] "i" (s_Dist)
        :
    );
}