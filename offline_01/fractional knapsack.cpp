#include <cstdio>
#include <cstdlib>
#define MAX 100

using namespace std;

struct Item
{
    double weight;
    double profit;
    double rate;

    bool operator>(const Item &a) const
    {
        return rate > a.rate;
    }
};

/// data structure part : heap ///

int heapSize;

int parent(int i)
{
    return (i / 2);
}

int left(int i)
{
    return (2 * i);
}

int right(int i)
{
    return (2 * i + 1);
}

void maxHeapify(Item *item, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= heapSize && item[l] > item[i]) largest = l;
    else largest = i;
    if(r <= heapSize && item[r] > item[largest]) largest = r;
    if(largest != i)
    {
        Item *temp = new Item;
        *temp = item[i];
        item[i] = item[largest];
        item[largest] = *temp;
        delete temp;
        maxHeapify(item, largest);
    }
}

void buildMaxHeap(Item *item, int n)
{
    heapSize = n;
    for(int i = (n / 2); i > 0; i--)
    {
        maxHeapify(item, i);
    }
}

Item extractMax(Item *item)
{
    if(heapSize < 1)
    {
        printf("heap underflow");
        exit(-1);
    }
    Item Max = item[1];
    item[1] = item[heapSize];
    heapSize--;
    maxHeapify(item, 1);
    return Max;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int cap, n;
    scanf("%d %d", &n, &cap);
    Item *item = new Item[n + 1];
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf %lf", &item[i].weight, &item[i].profit);
        item[i].rate = item[i].profit / item[i].weight;
    }
    buildMaxHeap(item, n);
    int remains = cap;
    Item best;
    double profit = 0;
    while(remains > 0)
    {
        best = extractMax(item);
        if(best.weight <= remains)
        {
            remains =  remains - best.weight;
            profit = profit + best.profit;
            printf("taking 100.0%% of %.2lf weight %.2lf profit\n", best.weight, best.profit);
        }
        else
        {
            profit = profit + best.rate * remains;
            printf("taking %.2lf%% of %.2lf weight %.2lf profit\n", remains / best.weight * 100, best.weight, best.profit);
            remains = 0;
        }
    }
    printf("Total profit : %.2lf", profit);
}
