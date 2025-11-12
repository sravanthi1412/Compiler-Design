#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char production[MAX][10];
char firstSet[MAX][10];
int n;

void findFirst(char *result, char c);
void addToResultSet(char *result, char val);

int main() {
    int i;
    char choice;
    char c;
    char result[20];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g., E->E+T):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    do {
        printf("\nFind FIRST of: ");
        scanf(" %c", &c);
        strcpy(result, "");
        findFirst(result, c);
        printf("FIRST(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++) {
            printf("%c ", result[i]);
        }
        printf("}\n");
        printf("\nFind FIRST of another symbol? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void findFirst(char *result, char c) {
    int i, j, k;
    char subResult[20];
    char right;

    // If terminal, return it
    if (!isupper(c)) {
        addToResultSet(result, c);
        return;
    }

    // For each production
    for (i = 0; i < n; i++) {
        if (production[i][0] == c) {
            // Example: E->E+T
            if (production[i][3] == '\0') continue;
            right = production[i][3];

            if (right == '$') { // epsilon
                addToResultSet(result, '$');
            } else if (!isupper(right)) {
                addToResultSet(result, right);
            } else {
                findFirst(subResult, right);
                for (k = 0; subResult[k] != '\0'; k++)
                    addToResultSet(result, subResult[k]);
            }
        }
    }
}

void addToResultSet(char *result, char val) {
    int k;
    for (k = 0; result[k] != '\0'; k++)
        if (result[k] == val)
            return;
    result[k] = val;
    result[k + 1] = '\0';
}