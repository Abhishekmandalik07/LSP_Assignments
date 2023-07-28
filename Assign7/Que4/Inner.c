#include "Inner.h"

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  Factorial
//  Description :   Used to return Factorial of Number
//  Input :         Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

int Factorial(int iNo)
{
    int iMult =1;

    while (iNo!=0)
    {
        iMult = iMult*iNo;
        iNo--;
    }

    return iMult;
    
}
