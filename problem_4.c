#include <stdio.h>
#include <string.h>



int getMaxpoints(char *s, int x, int y) {
    int n = strlen(s);
    int points = 0;

    // Remove "ab" and gain x points
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
            points += x;
            i += 1;
        }
    }

     // Remove "ba" and gain y points
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'b' && s[i + 1] == 'a') {
            points += y;
            i += 1;
        }
    }



    // Remove "aba" or "bab" and gain x + y points
    for (int i = 0; i < n - 2; i++) {
        if ((s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'a') ||
            (s[i] == 'b' && s[i + 1] == 'a' && s[i + 2] == 'b')) {
            points += x + y;
            i += 2;
        }
    }

    // Remove "aaa" or "bbb" and gain x * y points
    for (int i = 0; i < n - 2; i++) {
        if ((s[i] == 'a' && s[i + 1] == 'a' && s[i + 2] == 'a') ||
            (s[i] == 'b' && s[i + 1] == 'b' && s[i + 2] == 'b')) {
            points += x * y;
            i += 2;
        }
    }


    return points;
}

int main() {
    char s[50];
    int x, y;

    printf("Enter the string: ");
    scanf("%s", s);

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Enter the value of y: ");
    scanf("%d", &y);

    int max_points = getMaxpoints(s, x, y);

    printf("The maximum points  gained are %d \n", max_points);

    return 0;
}
