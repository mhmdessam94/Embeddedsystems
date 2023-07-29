/*Author:Mohammed Essam
/Date:7/29/2023
filename:forLoop.c*/
#include<stdio.h>
int main(void)
{
    /*input num of star lines*/
    int numLines;
    printf("enter num of lines\n");
    scanf(" %d",&numLines);
    /*loop for duplicating the lines*/
    for (int i=0;i<numLines;++i)
    {
        printf("******\n",numLines); 
    }
    return 0;
}