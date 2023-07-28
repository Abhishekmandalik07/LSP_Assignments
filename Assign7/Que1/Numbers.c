#include "Numbers.h"

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  Addition
//  Description :   Used to return the Addition of Two Numbers.
//  Input :         Integer,Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////
int Addition(int No1,int No2)
{
    int Ans = 0;

    Ans = No1+No2;

    return Ans;

}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  Substraction
//  Description :   Used to return the Substraction of Two Numbers.
//  Input :         Integer,Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

int Substraction(int No1,int No2)
{
    int Ans = 0;
    Ans = No1-No2;

   return Ans;

}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  Division
//  Description :   Used to return the Division of Two Numbers.
//  Input :         Integer,Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

int Division(int No1,int No2)
{
    int Ans = 0;
    Ans = No1/No2;

   return Ans;

}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  Multiplication
//  Description :   Used to return the Multiplication of Two Numbers.
//  Input :         Integer,Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

int Multiplication(int No1,int No2)
{
    int Ans = 0;
    
    Ans = No1*No2;

    return Ans;

}


/////////////////////////////////////////////////////////////////////
//
//  Function Name:  DisplayFactors
//  Description :   Used to display Factors of Number
//  Input :         Integer
//  Output :        -
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

void DisplayFactors(int iNo)
{
    int iCnt = 0;
    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt <= (iNo/2) ; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            printf("%d\n",iCnt);
        }
    }
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  DisplayNonFactors
//  Description :   Used to display Non-Factors of Number
//  Input :         Integer
//  Output :        -
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////
void DisplayNonFactors(int iNo)
{
    int iCnt = 0;
    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt < iNo ; iCnt++)
    {
        if((iNo % iCnt) != 0)
        {
            printf("%d\n",iCnt);
        }
    }
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  SumFactors
//  Description :   Used to display Sum of the Factors of Number
//  Input :         Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

int SumFactors(int iNo)
{
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
    return iSum;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  CheckPerfect
//  Description :   Used to check Number is Perfect or Not
//  Input :         Integer
//  Output :        Integer
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

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  CountFactor
//  Description :   Used to Count Factors of Number
//  Input :         Integer
//  Output :        Integer
//  Date :          28-July-2023
//  Author :        Abhishek Balasaheb Mandalik
//
/////////////////////////////////////////////////////////////////////

int CountFactor(int iNo)
{
    int iCnt = 0;
    int iFactCnt = 0;

    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iFactCnt++;
        }
    }
    return iFactCnt;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name:  CheckPrime
//  Description :   Used to check the Number is Prime or Not
//  Input :         Integer
//  Output :        Integer
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

