#include <cstdio>
#include <iostream>
#define INF 99999999

using namespace std;

void insertionSort(int *arr, int p, int r)
{
    for(int i = p + 1; i <= r; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= p && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;
    int L[n + 2];
    int R[m + 2];
    for(int i = 1; i <= n; i++) L[i] = arr[p + i - 1];
    for(int j = 1; j <= m; j++) R[j] = arr[q + j];
    L[n + 1] = INF;
    R[m + 1] = INF;
    int i = 1, j = 1;
    for(int k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int *arr, int p, int r)
{
    if(p < r)
    {
        if((r - p + 1) <= 14)
        {
            insertionSort(arr, p, r);
            return;
        }
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    int arr[] = {-99, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int) - 1;
    mergeSort(arr, 1, n);
    for(int i = 1; i <= n; i++) printf("%d ", arr[i]);
}


