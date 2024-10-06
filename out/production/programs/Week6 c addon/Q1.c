#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare file pointer
    FILE *filePtr;
    char data[100];
    char filename[50];

    // Get the filename from the user
    printf("Enter the name of the file to append data to: ");
    scanf("%s", filename);

    // Open the file in append mode
    filePtr = fopen(filename, "a");  // "a" mode will open the file for appending data
    if (filePtr == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Get data from the user
    printf("Enter the data to append to the file: ");
    getchar(); // To consume the leftover newline from the previous input
    fgets(data, sizeof(data), stdin);

    // Append data to the file
    fputs(data, filePtr);

    // Close the file
    fclose(filePtr);

    printf("Data successfully appended to the file %s\n", filename);

    return 0;
}
