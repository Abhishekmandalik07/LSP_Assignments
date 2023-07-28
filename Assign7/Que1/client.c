#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dlfcn.h>


int main()
{

    void *ptr = NULL;
    void(*fptr1)(int);
    int(*fptr2)(int);
    bool(*fptr3)(int);
    void(*fptr4)();
    int(*fptr5)(int,int);

    int choice = 1;
    int iValue = 0,iSum=0,iCount=0;
    int no1=0,no2=0,Result=0;
    bool bFlag = true;

    ptr = dlopen("NumbersLib.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;

    }

    while(choice!=0)
    {
        printf("******Please Enter your choice :******\n\n");
        printf("1.Return the Addition of 2 Numbers \n\n");
        printf("2.Return the Substraction of 2 Numbers \n\n");
        printf("3.Return the Division of 2 Numbers \n\n");
        printf("4.Return the Multiplication of 2 Numbers \n\n");
        printf("5.Display Factors of a Number \n\n");
        printf("6.Display Non-Factors of a Number \n\n");
        printf("7.Display Sum of the Factors of a Number \n\n");
        printf("8.Display count of the Factors of a Number  \n\n");
        printf("9.Check the number is Perfect or Not? \n\n");
        printf("10.Check the number is Prime or Not? \n\n");
        printf("11.Terminate the Application\n\n");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1:
                    
                    fptr5 = dlsym(ptr,"Addition");
                    if(fptr5 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter 1st Number:\n");
                    scanf("%d",&no1);
                    printf("Please Enter 2nd Number:\n");
                    scanf("%d",&no2);
                    Result = fptr5(no1,no2);
                    printf("Result is: %d\n\n",Result);
                    
                    break;

            case 2:
                    
                    fptr5 = dlsym(ptr,"Substraction");
                    if(fptr5 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter 1st Number:\n");
                    scanf("%d",&no1);
                    printf("Please Enter 2nd Number:\n");
                    scanf("%d",&no2);
                    Result = fptr5(no1,no2);
                    printf("Result is: %d\n\n",Result);
                    break;

            case 3:
                    
                    fptr5 = dlsym(ptr,"Division");
                    if(fptr5 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter 1st Number:\n");
                    scanf("%d",&no1);
                    printf("Please Enter 2nd Number:\n");
                    scanf("%d",&no2);
                    Result = fptr5(no1,no2);
                    printf("Result is: %d\n\n",Result);
                    break;

            case 4:
                    
                    fptr5 = dlsym(ptr,"Multiplication");
                    if(fptr5 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter 1st Number:\n");
                    scanf("%d",&no1);
                    printf("Please Enter 2nd Number:\n");
                    scanf("%d",&no2);
                    Result = fptr5(no1,no2);
                    printf("Result is: %d\n\n",Result);
                    break;

            case 5:
                    printf("Please Enter Number : \n");
                    scanf("%d",&iValue);
                    fptr1 = dlsym(ptr,"DisplayFactors");
                   
                    if(fptr1 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    
                    fptr1(iValue);
                    printf("\n");
                    break;

            case 6:
                    fptr1 = dlsym(ptr,"DisplayNonFactors");
                    if(fptr1 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter Number : \n");
                    scanf("%d",&iValue);
                    fptr1(iValue);
                    printf("\n");
                    break;

            case 7:
                    fptr2 = dlsym(ptr,"SumFactors");
                    if(fptr2 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter Number : \n");
                    scanf("%d",&iValue);
                    iSum = fptr2(iValue);
                    printf("Sum of the Factors is : %d\n\n",iSum);

                    break;
            case 8:
                    fptr2 = dlsym(ptr,"CountFactor");
                    if(fptr2 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter Number : \n");
                    scanf("%d",&iValue);
                    iCount = fptr2(iValue);
                    printf("Count of the Factors is : %d\n\n",iCount);

                    break;
            
            case 9:

                    fptr3 = dlsym(ptr,"CheckPerfect");
                    if(fptr3 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter Number : \n");
                    scanf("%d",&iValue);

                    bFlag = fptr3(iValue);
                    if(bFlag == true)
                    {
                        printf("It is a Perfect Number\n");
                    }
                    else
                    {
                        printf("It is Not a Perfect Number\n");
                    }
                    printf("\n");
                    break;
            case 10:

                    fptr3 = dlsym(ptr,"CheckPrime");
                    if(fptr3 == NULL)
                    {
                        printf("Unable to load the address of function\n");
                        return -1;
                    }
                    printf("Please Enter Number : \n");
                    scanf("%d",&iValue);

                    bFlag = fptr3(iValue);
                    if(bFlag == true)
                    {
                        printf("It is a Prime Number\n");
                    }
                    else
                    {
                        printf("It is Not a Non-Prime Number\n");
                    }
                    printf("\n");
                    break;

          
            case 11:
                    printf("Thank you for visiting my Application...\n");
                    choice = 0;
                    break;

            default:
                printf("Please Enter Poper choice\n");
                break;

        }


    }


    return 0;
}