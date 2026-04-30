#include <stdio.h>
#include <stdlib.h>

extern int sum_array(int *arr, int n);

int main(int argc, char *argv[]) {
    FILE *file;
    int number;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("No file found\n");
        return 1;
    }

    int capacity = 10;
    int size = 0;
    int *arr = malloc(capacity * sizeof(int));

    while (fscanf(file, "%d", &number) == 1) {
        if (size >= capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
        }
        arr[size++] = number;
    }

    fclose(file);

    int result = sum_array(arr, size);
    printf("Sum = %d\n", result);

    free(arr);
    return 0;
}