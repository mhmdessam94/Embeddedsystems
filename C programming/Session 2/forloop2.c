/*Author:Mohammed Essam
/Date:7/29/2023
filename:forLoop2.c*/
#include<stdio.h>
int main(void)
{
    char numStar;
    scanf(" %d",&numStar);
    int i;
    int j;
    for (i=0;i<numStar;++i)
    {
        for (j=0;j<numStar;++j)
        {
            printf("*",numStar);
        }
        printf("\n");
    }

}