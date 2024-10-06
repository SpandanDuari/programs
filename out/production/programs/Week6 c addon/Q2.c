#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFilename[100], destFilename[100];
    char ch;

    printf("Enter the name of the source file: ");
    scanf("%s", sourceFilename);

    printf("Enter the name of the destination file: ");
    scanf("%s", destFilename);

    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file %s\n", sourceFilename);
        exit(1);
    }

    destinationFile = fopen(destFilename, "w");
    if (destinationFile == NULL) {
        printf("Error: Could not open destination file %s\n", destFilename);
        fclose(sourceFile);
        exit(1);
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully from %s to %s\n", sourceFilename, destFilename);

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}