#include<stdio.h>
int main()
{
    int x;
    int y;
    int z;
    int m;
    printf("*****Welcome to Calculator App****\n");
    printf("1-Addition\n");
    printf("2-Subtarction\n");
    printf("3-Multiplication\n");
    printf("4-Divison\n");
    printf("Otherwise error\n");
    scanf(" %d",&x);

    if (x==1)
    {
    scanf(" %d",&y);
    scanf(" %d",&z);
        m=y+z;
        printf("ans=%d",m);
    }
    else if (x==2)
    {
    scanf(" %d",&y);
    scanf(" %d",&z);
        m=y-z;
        printf("ans=%d",m);
    }
    else if (x==3)
    {
    scanf(" %d",&y);
    scanf(" %d",&z);
        m=y*z;
        printf("ans=%d",m);
    }
    else if (x==4)
    {
    scanf(" %d",&y);
    scanf(" %d",&z);
        m=y/z;
        printf("ans=%d",m);
    }
    else 
    {
        printf("Error");
    }


        return 0;
}