/*Write a program to find GCD using consecutive integer checking method and
analyze its time efficiency.*/

#include <stdio.h>
#include <stdlib.h>

int opcount=0;

int gcdFinder(int m, int n)
{
    int min = (n<m)?n:m;
    while(min>0)
    {
        opcount++;
        if(n%min==0 && m%min==0)
        {
            return min;
        }
        else{
            min--;
        }
    }
}

int main()
{
    int m,n;
    printf("Enter two numbers : ");
    scanf("%d %d", &m, &n);
    printf("The GCD is : %d\n",gcdFinder(m,n));
    printf("Opcount : %d\n",opcount);
}