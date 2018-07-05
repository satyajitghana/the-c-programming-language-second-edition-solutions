#include <stdio.h>

int binsearch(int to_search, int vector[], int SIZE);

int main() {
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int SIZE = sizeof x / sizeof x[0];
    int to_find = 2;
    printf("%d\n", binsearch(to_find, x, SIZE));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, mid, high;
    
    low = 0; high = n-1;
    mid = (low + high) / 2;

    while (low <= high && v[mid] != x) {
        if (x < v[mid]) high = mid - 1;
        else low = mid + 1;
        mid = (low + high) / 2;
    }

    if (v[mid] == x) return mid;

    return -1;
}
