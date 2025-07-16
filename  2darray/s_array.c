#include <stdio.h>
#include <stdlib.h>
int **makeArray(int x, int y);
int main()
{
    // example
    int **array = makeArray(10, 10);
}

int **makeArray(int x, int y)
{
    int **pointer = (int **)malloc(sizeof(int *) * x);
    for (int i = 0; i < x; i++)
    {
        pointer[i] = (int *)malloc(sizeof(int) * y);
    }
    return pointer;
}