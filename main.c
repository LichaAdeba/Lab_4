
#include <stdio.h>
#include <stdlib.h>


extern int sum_array(int *arr, int n);


int main(int argc, char *argv[])
{
    FILE *file;
    int number;
    int n;
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("No file found\n");
        return 1;
    }

    if (fscanf(file, "%d", &n) != 1) {
        printf("Invalid file format\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading number\n");
            return 1;
        }
    }
    fclose(file);
    int result = sum_array(arr, n);
    printf("Sum = %d\n", result);
    free(arr);

    return 0;
}


