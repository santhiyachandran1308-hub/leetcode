char* longestPalindrome(char* s) {
    static char result[1001];
    int n = strlen(s);

    if (n == 0)
        return "";

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        int left = i;
        int right = i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }

            left--;
            right++;
        }
        left = i;
        right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }

            left--;
            right++;
        }
    }

    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}
