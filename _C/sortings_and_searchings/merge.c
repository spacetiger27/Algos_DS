#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void merge(int *arr, int lo, int hi, int mid)
{
    int i, j, k;
    int n1 = mid - lo +1;
    int n2 = hi - mid;

    // Create temp arrays
    int L1[n1], L2[n2];

    // Copy elements from lo to mid into L1
    for(i = 0; i < n1; i++)
        L1[i] = arr[lo + i];

    // Copy elements from mid+1 to hi into L2
    for(j = 0; j < n2; j++)
        L2[j] = arr[mid + 1 + j];


    // Merge the temp arrays back to arr[lo..hi]
    i = 0;
    j = 0;
    k = lo;
    while(i < n1 && j < n2)
    {
        if(L1[i] <= L2[j])
        {
            arr[k] = L1[i];
            i++;
        }
        else{
            arr[k] = L2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L1[]
    while(i < n1)
    {
        arr[k] = L1[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = L2[j];
        j++;
        k++;
    }
}


void merge_sort(int *arr, int lo, int hi)
{
    if(lo < hi)
    {
        int mid = lo+(hi - lo)/2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid+1, hi);
        merge(arr, lo, hi, mid);
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
    merge_sort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
