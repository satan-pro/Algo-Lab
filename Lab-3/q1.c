/*Write a program to sort set of integers using bubble sort. Analyze its time
efficiency. Obtain the experimental result of order of growth. Plot the result for
the best and worst case*/

#include <stdio.h>
#include <stdlib.h>

int opcount=0;

void bubbleSort(int n, int arr[])
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        opcount++;
        for(int j=0; j<n-i-1; j++)
        {
            opcount++;
            if(arr[j]>arr[j+1])
            {
                opcount++;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            
            }
        }
    }
}

void display(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter input\n");
    for(int i=0; i<n; i++)
    {       
        scanf("%d", &arr[i]);
    }
    display(n, arr);
    bubbleSort(n, arr);
    display(n, arr);
    printf("Opcount : %d\n", opcount);
    return 0;
}