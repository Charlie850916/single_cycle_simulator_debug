#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void R_type_func(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int C, unsigned int func)
{
    long long a, b;
    switch(func)
    {
    case 0x20: // add
        s0_Overwrite(rd);
        OverFlow_add(s[rs], s[rt], s[rs] + s[rt]);
        s[rd] = s[rs] + s[rt];
        break;
    case 0x21: // addu
        if(s0_Overwrite(rd)) break;
        s[rd] = s[rs] + s[rt];
        break;
    case 0x22: // sub
        s0_Overwrite(rd);
        OverFlow_add(s[rs], -s[rt], s[rs] - s[rt]);
        s[rd] = s[rs] - s[rt];
        break;
    case 0x24: // and
        if(s0_Overwrite(rd)) break;
        s[rd] = (s[rs] & s[rt]);
        break;
    case 0x25: // or
        if(s0_Overwrite(rd)) break;
        s[rd] = (s[rs] | s[rt]);
        break;
    case 0x26: // xor
        if(s0_Overwrite(rd)) break;
        s[rd] = (s[rs] ^ s[rt]);
        break;
    case 0x27: // nor
        if(s0_Overwrite(rd)) break;
        s[rd] = ~(s[rs] | s[rt]);
        break;
    case 0x28: // nand
        if(s0_Overwrite(rd)) break;
        s[rd] = ~(s[rs] & s[rt]);
        break;
    case 0x2a: // slt
        if(s0_Overwrite(rd)) break;
        s[rd] = (s[rs] < s[rt]);
        break;
    case 0x00: // sll nop
        if(rt!=0||rd!=0||C!=0)
        {
            s0_Overwrite(rd);
            s[rd] = s[rt] << C;
            break;
        }
        break;
    case 0x02: // srl
        if(s0_Overwrite(rd)) break;
        if(C==0)
        {
            s[rd] = s[rt];
        }
        else if(s[rt]>=0)
        {
            s[rd] = s[rt] >> C;
        }
        else
        {
            int i = 0x7fffffff;
            i = i >> (C-1);
            s[rd] = (s[rt] >> C) & i;
        }
        break;
    case 0x03: // sra
        if(s0_Overwrite(rd)) break;
        s[rd] = s[rt] >> C;
        break;
    case 0x08: // jr
        PC = s[rs];
        break;
    case 0x18: // mult
        a = s[rs];
        b = s[rt];
        HI = a*b >> 32;
        LO = a*b & 0x00000000ffffffff ;
        if(overwriteHL) fprintf(fp_err ,"In cycle %d: Overwrite HI-LO registers\n", cycle);
        overwriteHL = 1;
        break;
    case 0x19: // multu
        a = ( s[rs] & 0x00000000ffffffff);
        b = ( s[rt] & 0x00000000ffffffff);
        HI = a*b >> 32;
        LO = a*b & 0x00000000ffffffff ;
        if(overwriteHL) fprintf(fp_err ,"In cycle %d: Overwrite HI-LO registers\n", cycle);
        overwriteHL = 1;
        break;
    case 0x10: // mfhi
        s0_Overwrite(rd);
        s[rd] = HI;
        overwriteHL = 0;
        break;
    case  0x12: // mflo
        s0_Overwrite(rd);
        s[rd] = LO;
        overwriteHL = 0;
        break;
    }
    s[0] = 0;
    return;
}
