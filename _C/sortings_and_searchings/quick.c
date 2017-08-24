#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int lo, int hi)
{
    int pivot = arr[hi];
    int i, j;
    i = lo - 1;

    for(j = lo; j < hi; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[hi]);
    return(i+1);
}

void quickSort(int *arr, int lo, int hi)
{
    if(lo < hi)
    {
        int pi = partition(arr, lo, hi);
        quickSort(arr, lo, pi-1);
        quickSort(arr, pi+1, hi);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
        int i;
            for (i=0; i < size; i++)
                        printf("%d ", arr[i]);
                printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11, 100, 1, 45, 22, 3, 1, 98};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
