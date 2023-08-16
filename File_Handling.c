#include <stdio.h>

int main()
{
    char str[10];
    FILE *ptr = NULL;

    ptr = fopen("receipt.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(ptr, "%s", str);
        printf("%s ", str);
    }
    fclose(ptr);

    ptr = fopen("receipt.txt", "r");
    for (int i = 0; i < 24; i++)
    {
        int c = fgetc(ptr);
        printf("%c", c);
    }
    fclose(ptr);

    ptr = fopen("receipt.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fgets(str, 6, ptr);
        printf("%s", str);
    }
    fclose(ptr);

    ptr = fopen("receipt.txt", "w");
    fputc('h', ptr);

    fputs("ello bro love you too.", ptr);
    fclose(ptr);
    // "r", "w", "r+", "w+", "a", "a+"
    return 0;
}