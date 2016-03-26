#include <cstdio>
#include <iostream>
#define INF 99999999

using namespace std;

int merge(int *arr, int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;
    int cnt = 0;
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
            cnt += (n - i + 1);
            arr[k] = R[j];
            j++;
        }
    }
    return cnt;
}

int mergeSort(int *arr, int p, int r)
{
    int ret = 0;
    if(p < r)
    {
        int q = (p + r) / 2;
        ret += mergeSort(arr, p, q);
        ret += mergeSort(arr, q + 1, r);
        ret += merge(arr, p, q, r);
    }
    return ret;
}

int main()
{
    int arr[] = {-99, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int) - 1;
    printf("Count of inversion = %d\n", mergeSort(arr, 1, n));
}
