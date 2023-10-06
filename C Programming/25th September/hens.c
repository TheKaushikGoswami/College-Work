#include <stdio.h>

int main() {
    int h, l;

    printf("Enter the number of heads: ");
    scanf("%d", &h);
    printf("Enter the number of legs: ");
    scanf("%d", &l);

    int goats = (l- (2 * h)) / 2;
    int hens = h - goats;

    if (goats < 0 || hens < 0 || l % 2 != 0){
        // printf("%d hens and %d goats cannot have %d legs.\n", hens, goats, l);
        printf("Invalid Input");
        return 0;
    }

    printf("Number of hens: %d\n", hens);
    printf("Number of goats: %d\n", goats);

    return 0;
}
