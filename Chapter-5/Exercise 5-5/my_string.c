/* copy n characters of t to s,
 * pad with '\0' if t has fewer characters than n */
void my_strncpy(char *s, char *t, int n) {
    while ((*s = *t) != '\0' && n-- > 0) {
        //printf(" *%c|%d* ", *s, n);
        s++;
        t++;
    }
    *s = '\0';
}

void my_strncat(char *s, char *t, int n) {
    while (*s != '\0')
        s++;
    my_strncpy(s, t, n);
}

int my_strncmp(char *s, char *t, int n) {
    while (n-- > 0) {
        //printf(" *%c|%c* ", *s, *t);
        if (*s != *t) return (*s - *t);
        s++;
        t++;
    }
    return 0;
}
