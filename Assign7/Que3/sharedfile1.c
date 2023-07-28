#include "sharedfile.h"

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  CheckPrime
//  Description :   Used to check the Number is Prime or Not
//  Input :         Integer
//  Output :        Boolean
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

bool CheckPrime(int iNo)
{
    int iCnt = 0;
    bool bFlag = true;

    for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            bFlag = false;
            break;
        }
    }
    return bFlag;
}

