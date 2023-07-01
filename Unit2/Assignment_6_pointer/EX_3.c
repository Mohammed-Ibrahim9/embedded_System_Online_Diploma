#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fflush(stdin); fflush(stdout);
    scanf("%s", str);

    char *ptr = str;

    /* Move the pointer to the end of the string*/
    while (*ptr != '\0') {
        ptr++;
    }
    ptr--; /*Move back one position to skip the null character*/

    printf("Reversed string: ");
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }

    return 0;
}
