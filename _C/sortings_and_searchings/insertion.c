#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//void swap(int *a, int *b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}

void insertionSort(int *arr, int n)
{
    int i, j; // iterate variables
    int key; //to store a element

    for(i = 1; i < n; i++)
    {
        j = i-1;
        key = arr[i];

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
