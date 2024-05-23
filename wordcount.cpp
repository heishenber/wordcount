#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_BUFFER_SIZE 1024

int count_characters(FILE *file) {
    int count = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int count_words(FILE *file) {
    int count = 0;
    int in_word = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *filename = argv[2];
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    int count;
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file);
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file);
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        printf("Invalid option. Please use '-c' or '-w'\n");
        return 1;
    }

    fclose(file);
    return 0;
}
