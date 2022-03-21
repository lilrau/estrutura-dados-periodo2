// Raul Souza Silva RA2407418

#include <stdio.h>

void ordene(int *x, int *y, int *z);

int main()
{
int a = 0 ;
int b = 0 ;
int c = 0 ;
int *pa = &a ;
int *pb = &b ;
int *pc = &c ;
scanf("%i%i%i",pa,pb,pc);
ordene(&pa,&pb,&pc);
printf("PA = %i, ",*pa);
printf("PB = %i, ",*pb);
printf("PC = %i",*pc);
}

void ordene(int *x, int *y, int *z)
{
    int troca=0;

    if (*x > *y)
    {
        troca = *x;
        *x = *y;
        *y = troca;
    }

    if (*y > *z)
    {
        troca = *y;
        *y = *z;
        *z = troca;
    }

    if (*x > *y)
    {
        troca = *x;
        *x = *y;
        *y = troca;
    }
}
