#include <stdio.h>

void factorize(int n) {
    int i, j;
    
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            j = n / i;
            printf("%d=%d*%d\n", n, j, i);
            return;
        }
    }
    
    printf("%d=%d*%d\n", n, n, 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        factorize(number);
    }

    fclose(file);

    return 0;
}

