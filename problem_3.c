//Write a program to find points (x,y) in an array such that between no
//two points there exists another value 'z' in the ptray which falls between 'x' and 'y'.
//ie: the point z should not be between x and y.
//Print the value of the points (x,y) which have no values between them
//and the distance between them.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the %d points:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    int x = 0, y = 0;     // Initialize x and y to the first point
    int max_distance = 0; // Initialize the maximum distance to 0
    for (int i = 1; i < n; i++)
    {
        int distance = ptr[i] - ptr[x];
        if (distance > max_distance)
        {
            max_distance = distance;
            y = i;
        }
    }
    for (int j = x + 1; j < y; j++)
    {
        if (ptr[j] > ptr[x] && ptr[j] < ptr[y])
        {
            x = j;
            break;
        }
    }
    printf("The points (%d,%d) have no values between them\n", ptr[x], ptr[y]);
    printf("The distance between them is %d\n", max_distance);
    free(ptr);

    return 0;
}