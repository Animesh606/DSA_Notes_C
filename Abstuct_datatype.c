#include <stdio.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
} myArray;

void createArray(myArray *a, int tsize, int usize)
{
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = (int *)malloc (tsize * sizeof(int));
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void showArray(myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}

void setValue(myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the %dth eliment: ", i + 1);
        scanf("%d", &(a->ptr)[i]);
    }
}

void insertEliment(myArray *a, int value, int pos)
{
    if (a->used_size == a->total_size)
        printf("Error! The array is fully occupied!!\n");
    else
    {
        for (int i = a->used_size - 1; i >= pos; i--)
        {
            (a->ptr)[i + 1] = (a->ptr)[i];
        }
        (a->ptr)[pos] = value;
        a->used_size++;
    }
}

void deleteEliment(myArray *a, int pos)
{
    if (a->used_size == 0)
        printf("Error! The array is empty!!");
    else
    {
        for (int i = pos; i < a->used_size - 1; i++)
        {
            (a->ptr)[i] = (a->ptr)[i + 1];
        }
        a->used_size--;
    }
}

int main()
{
    myArray marks;
    createArray(&marks, 10, 5);
    setValue(&marks);
    showArray(&marks);
    insertEliment(&marks, 10, 2);
    showArray(&marks);
    deleteEliment(&marks, 4);
    showArray(&marks);
    return 0;
}