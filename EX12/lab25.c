#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char res[10][10], arg1[10][10], op[10][5], arg2[10][10];

    printf("Enter number of lines: ");
    scanf("%d", &n);

    // Input TAC lines
    printf("Format:\n- Copy: t1 = a\n- Operation: t2 = b + c\n");
    for (i = 0; i < n; i++) {
        scanf("%s = %s", res[i], arg1[i]);
        char next = getchar();
        if (next != '\n') {
            scanf("%s %s", op[i], arg2[i]);
        } else {
            strcpy(op[i], "=");
            strcpy(arg2[i], "");
        }
    }

    // Apply Copy Propagation
    for (i = 0; i < n; i++) {
        // Only if it's a copy like: t1 = a
        if (strcmp(op[i], "=") == 0 && strcmp(arg2[i], "") == 0) {
            for (j = i + 1; j < n; j++) {
                if (strcmp(arg1[j], res[i]) == 0)
                    strcpy(arg1[j], arg1[i]);
                if (strcmp(arg2[j], res[i]) == 0)
                    strcpy(arg2[j], arg1[i]);
            }
        }
    }

    // Output after propagation
    printf("\nAfter Copy Propagation:\n");
    for (i = 0; i < n; i++) {
        if (strcmp(op[i], "=") == 0 && strcmp(arg2[i], "") == 0)
            printf("%s = %s\n", res[i], arg1[i]);
        else
            printf("%s = %s %s %s\n", res[i], arg1[i], op[i], arg2[i]);
    }

    return 0;
}