#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;

    for(i = 0; i < n-1; i++)
    {
        swapped = false;
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
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
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
