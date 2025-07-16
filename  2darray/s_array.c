#include <stdio.h>
#include <stdlib.h>
int **makeArray(int x, int y);
void freeArray(int **array, int x);
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

void freeArray(int **array, int x)
{
    if (array == NULL)
    {
        return;
    }
    for (int i = 0; i < x; i++)
    {
        free(array[i]);
    }
    // 1. 각 행마다 메모리 해제

    free(array);

    // 2. 배열 포인터의 메모리 해제
}