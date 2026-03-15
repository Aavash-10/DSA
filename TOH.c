#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void TOH(int n, char source, char auxiliary, char destination)
{
    // Base condition
    if(n == 1)//if only one disk, move it directly to the destination
    {
        printf("Move the disk from %c to %c.\n", source, destination);
        return;   // terminate the0 recursion
    }
    //if n!=1
    // Step 1: Move n-1 disks from source to auxiliary using destination as helper
    TOH(n-1, source, destination, auxiliary);

    // Step 2: Move the largest disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the n-1 disks from auxiliary to destination using source as helper
    TOH(n-1, auxiliary, source, destination);
}

int main()
{
    int n;  // n = no. of disks

    // to enter/input number of disks from user
    printf("Enter number of disks: ");
    scanf("%d", &n);//storing the value of n

    // Calling the recursive function
    // A = Source, B = Auxiliary, C = Destination
    TOH(n, 'A', 'B', 'C');

    return 0;  // terminating the program
}
