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
    scanf(" %d",&operationType);

switch(operationType)
{
case 1:
scanf(" %d",&firstNum);
scanf(" %d",&secondNum);
result=firstNum+secondNum;
printf("ans=%d",result);

break;

case 2:
scanf(" %d",&firstNum);
scanf(" %d",&secondNum);
result=firstNum-secondNum;
printf("ans=%d",result);

case 3:
scanf(" %d",&firstNum);
scanf(" %d",&secondNum);
result=firstNum*secondNum;
printf("ans=%d",result);

case 4:
scanf(" %d",&firstNum);
scanf(" %d",&secondNum);
result=firstNum/secondNum;
printf("ans=%d",result);

default :
printf("Error");
}
    return 0;
}