/*Write a program to implement solution to partition problem using brute-force
technique and analyze its time efficiency theoretically. A partition problem takes
a set of numbers and finds two disjoint sets such that the sum of the elements in
the first set is equal to the second set. [Hint: You may generate power set]*/

#include <stdio.h>
#include <stdlib.h>

/*void selectionSort(int* arr, int len)
{
    int pos;
    for(int i=0; i<len; i++)
    {
        int min=arr[i];
        for(int j=i+1; j<len; j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                pos=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
}*/

int comparator(const void *p, const void *q) 
   { 
      return (*(int*)p-*(int*)q);
      }

int findSum(int a[], int len)
{
    int sum=0;
    for(int i=0; i<len; i++)
    {
        sum+=a[i];
    }
    return sum;
}

void findSubset(int arr[], int len, int sum)
{
    int set1[len];
    int set2[len];
    int checkSum1 = sum;
    int checkSum2 = sum;
    int flag1=0;
    int flag2=0;
    for(int i=len-1; i>=0; i--)
    {
        if(arr[i]<=checkSum1)
        {
            set1[flag1++]=arr[i];
            checkSum1-=arr[i];
        }
        else if(arr[i]<=checkSum2)
        {
            set2[flag2++]=arr[i];
            checkSum2-=arr[i];
        }
    }
    if(flag1==0 && flag2==0)
    {
        printf("The sets cannot be partitioned\n");
    }
    else{
        printf("Set 1 : ");
        for(int i=0; i<flag1; i++)
        {
            printf("%d ", set1[i]);
        }
        printf("\nSet 2 : ");
        for(int i=0; i<flag2; i++)
        {
            printf("%d ", set2[i]);
        }
        printf("\n");
    }
} 

int main()
{
    int len;
    printf("Enter size of array : ");
    scanf("%d", &len);
    int arr[len];
    printf("Enter array elements : ");
    for(int i=0; i<len; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort((void*)arr,len,sizeof(arr[0]), comparator);
    int totalSum = findSum(arr,len);
    if(totalSum%2==0)
    {
        findSubset(arr,len,totalSum/2);
    }
}