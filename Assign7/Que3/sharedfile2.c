#include "sharedfile.h"

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  CheckPerfect
//  Description :   Used to check Number is Perfect or Not
//  Input :         Integer
//  Output :        Boolean
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

bool CheckPerfect(int iNo)
{
    int iAns = 0;
    int iCnt = 0;
    int iSum = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }
    for(iCnt = 1; iCnt <= (iNo /2); iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum =  iSum + iCnt;
        }
    }

    
    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
