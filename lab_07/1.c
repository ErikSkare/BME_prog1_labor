#include <stdio.h>


// fib(5)-re:
//-------------------------
//             5
//      4             3
//   3      2      2      1
// 2   1  1   0  1   0
//1 0
//-------------------------
// fib(40)-re nagyon lassú, nem fut le.

int fib(int n) {
    printf("%d; ", n);
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    printf("A fuggveny hivasok: ");
    int eredmeny = fib(5);
    printf("\nAz eredmeny: %d", eredmeny);
    return 0;
}
