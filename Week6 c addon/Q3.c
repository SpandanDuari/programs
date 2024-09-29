#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int charcount = 0, wordcount = 0, linecount = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        charcount++;

        if (ch == ' ' || ch == '\t') {
            wordcount++;
        }

        if (ch == '\n') {
            linecount++;
        }
    }

    // Count the last word
    if (charcount > 0) {
        wordcount++;
    }

    printf("Number of characters: %d\n", charcount);
    printf("Number of words: %d\n", wordcount);
    printf("Number of lines: %d\n", linecount + 1);

    fclose(file);
    return 0;
}