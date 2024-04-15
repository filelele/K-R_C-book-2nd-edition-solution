//chatgpt do this to save time
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define MAXLINE 5000
#define MAXLINES 20

int getline(char* s);
void quicksort(char* lines[], int left, int right);

int readlines(char* lines[], int maxlines) {
    char line[MAXLINE];
    int nlines = 0;

    while (nlines < maxlines && getline(line) > 0) {
        lines[nlines++] = strdup(line); // Store a copy of the line in the array
    }

    return nlines;
}

int getline(char* s) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        *s++ = c;
    }

    if (c == '\n') {
        *s++ = c;
        ++i;
    }

    *s = '\0';

    return i;
}

void writelines(char* lines[], int nlines) {
    for (int i = 0; i < nlines; ++i) {
        printf("%s", lines[i]);
    }
}

void swap(char* lines[], int i, int j) {
    char* temp = lines[i];
    lines[i] = lines[j];
    lines[j] = temp;
}

int partition(char* lines[], int left, int right) {
    char* pivot = lines[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (strcmp(lines[j], pivot) < 0) {
            ++i;
            swap(lines, i, j);
        }
    }

    swap(lines, i + 1, right);
    return i + 1;
}

void quicksort(char* lines[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(lines, left, right);
        quicksort(lines, left, pivot_index - 1);
        quicksort(lines, pivot_index + 1, right);
    }
}

int main() {
    double time_used;
    clock_t start = clock(), end;
    char* lines[MAXLINES];
    int nlines;

    nlines = readlines(lines, MAXLINES);
    printf("Original lines:\n");
    writelines(lines, nlines);

    quicksort(lines, 0, nlines - 1);

    printf("\nSorted lines:\n");
    writelines(lines, nlines);
    end = clock();
    time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("%g", time_used);
    return 0;
}