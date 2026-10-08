char* longestCommonPrefix(char** strs, int strsSize) {
    static char result[201];
    int i, j;

    if (strsSize == 0)
        return "";

    for (i = 0; strs[0][i] != '\0'; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != strs[0][i]) {
                result[i] = '\0';
                return result;
            }
        }

        result[i] = strs[0][i];
    }

    result[i] = '\0';

    return result;
}
