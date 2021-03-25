#include <stdio.h>

int recursion(unsigned int i);
int main()
{
    int i = 3;
    printf("%d! = %d\n",i, recursion(i));
    return 0;
}

int recursion(unsigned int i)
{
    if (i<=1)
    {
        return 1;
    }
    return i * recursion(i - 1);
}