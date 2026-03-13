//The commented one is without using recursion
// #include <stdio.h>

// int main() {
//     int n, i;
//     int a = 0, b = 1, c;

//     printf("Enter any number of terms: ");
//     scanf("%d", &n);

//     printf("Fibonacci Series: ");

//     for(i = 1; i <= n; i++) {
//         printf("%d ", a);
//         c = a + b;
//         a = b;
//         b = c;
//     }

//     return 0;
// }


//The code for fibonacci series using recursion
#include <stdio.h>
//Function to run fibonacci using recursion
int fibo(int n)
{
    if (n == 0)
        return 0;//if number of terms is 0,outcome is also 0
    else if (n == 1)
        return 1;//if number of terms is 1,outcome is also 1
    else
        return fibo(n-1) + fibo(n-2);//recusive function
}

int main()
{
    int n, i;

    printf("Enter number of terms: ");//to input no. of terms from user
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for(i = 0; i < n; i++)//base condition
    {
        printf("%d ", fibo(i));
    }

    return 0;
}