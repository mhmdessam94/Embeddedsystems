//////Author:Mohammed Essam
/////////Date:7/28/2023
//////////filename:calculator.c
#include<stdio.h>
int main()
{
    ////////////input data
    char operationType;
    int firstNum;
    int secondNum;
    int result;
    /////////////background of the calc
    printf("*****Welcome to Calculator App****\n");
    printf("1-Addition\n");
    printf("2-Subtarction\n");
    printf("3-Multiplication\n");
    printf("4-Divison\n");
    printf("Otherwise error\n");
    //////////////input the data type
    scanf(" %d",&operationType);

////////////addition
    if (operationType==1)
    {
        printf("enter the numbers");
    scanf(" %d",&firstNum);
    scanf(" %d",&secondNum);
        result=firstNum+secondNum;
        printf("ans=%d",result);
    }
    else if (operationType==2)///////////subtarction
    {
        printf("enter the numbers");
    scanf(" %d",&firstNum);
    scanf(" %d",&secondNum);
        result=firstNum-secondNum;
        printf("ans=%d",result);
    }
    else if (operationType==3)//////////////multiplication
    {
        printf("enter the numbers");
    scanf(" %d",&firstNum);
    scanf(" %d",&secondNum);
        result=firstNum*secondNum;
        printf("ans=%d",result);
    }
    else if (operationType==4)///////////Divion
    {
        printf("enter the numbers");
    scanf(" %d",&firstNum);
    scanf(" %d",&secondNum);
        result=firstNum/secondNum;
        printf("ans=%d",result);
    }
    else ///////////error
    {
        printf("Error");
    }


        return 0;
}