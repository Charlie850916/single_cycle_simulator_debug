#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void OverFlow_add(int s, int t, int d)
{
    if( (s>0 && t>0 && d<=0) || (s<0 && t<0 && d>=0) ) fprintf(fp_err, "In cycle %d: Number Overflow\n", cycle);
    return;
}

int s0_Overwrite(int d)
{
    if(d==0)
    {
        fprintf(fp_err, "In cycle %d: Write $0 Error\n", cycle);
        return 1;
    }
    return 0;
}

int Misalignment(int i)
{
    if( i!=0 )
    {
        halt = 1;
        fprintf(fp_err, "In cycle %d: Misalignment Error\n", cycle);
        return 1;
    }
    return 0;
}

int AddressOverflow(int sp, int b)
{
    if( sp >= 1024-(b-1) || sp < 0)
    {
        halt = 1;
        fprintf(fp_err, "In cycle %d: Address Overflow\n", cycle);
        return 1;
    }
    return 0;
}
