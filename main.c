#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Declaration of the assembly function

int sum_array(const int *arr, int n); 

int main(int argc, char **argv) {

    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    // Open the file specified in the command line argument
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {              // If file cannot be opened
        perror("fopen");
        return 1;
    }

    int n = 0;

    // This number represents how many integers follow in the file
    if (fscanf(fp, "%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Invalid first line (expected non-negative count)\n");
        fclose(fp);
        return 1;
    }

    // Pointer that will store the dynamically allocated array
    int *arr = NULL;

    // Only allocate memory if n > 0
    if (n > 0) {

        // Allocate memory for n integers
        arr = (int *)malloc((size_t)n * sizeof(int));
        if (!arr) {        // Check if memory allocation failed
            perror("malloc");
            fclose(fp);
            return 1;
        }

        // Read the next n integers from the file into the array
        for (int i = 0; i < n; i++) {

            // fscanf reads one integer per line
            if (fscanf(fp, "%d", &arr[i]) != 1) {
                fprintf(stderr, "Invalid data at index %d\n", i);

                // Free allocated memory before exiting
                free(arr);
                fclose(fp);
                return 1;
            }
        }
    }

    // Close the file after reading all values
    fclose(fp);

    // Call the assembly function to compute the sum
    int sum = sum_array(arr, n);

    // Print the result returned from the assembly function
    printf("Sum = %d\n", sum);

    free(arr);

    return 0;
}