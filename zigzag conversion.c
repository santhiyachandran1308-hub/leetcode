#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        return s;
    }

    char *result = (char *)malloc((len + 1) * sizeof(char));
    int index = 0;

    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {

        for (int i = row; i < len; i += cycle) {

            result[index++] = s[i];

            int diagonal = i + cycle - 2 * row;

            if (row != 0 && row != numRows - 1 && diagonal < len) {
                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';

    return result;
}
