#include <stdio.h>

int fib(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return fib(num - 1) + fib(num - 2);
    }
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci number: ");
    scanf("%d", &n);
    
    int result = fib(n);
    printf("The %dth Fibonacci number is: %d\n", n, result);
    
    return 0;
}
