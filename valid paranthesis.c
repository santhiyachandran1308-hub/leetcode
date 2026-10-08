#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);

    char* stack = malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {

        // Opening brackets → push into stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }

        // Closing brackets
        else {
            if (top == -1) {
                free(stack);
                return false;
            }

            char open = stack[top--];

            if ((s[i] == ')' && open != '(') ||
                (s[i] == '}' && open != '{') ||
                (s[i] == ']' && open != '[')) {

                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);

    free(stack);
    return valid;
}
