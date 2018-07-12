#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 5

#define ds(s) printf(#s " : %s\n", s); /* debug string      */
#define dc(c) printf(#c " : %c\n", c); /* debug character   */
#define di(d) printf(#d " : %d\n", d); /* debug integer     */

int _getline(char line[], int maxline);
double atof(char *s);

int main(int argc, char **argv) {
    int len;
    char line[MAXLINE], longest[MAXLINE];
    int max = 0;
    int tabstop = 5, start = -1;
    int c;
    char *name = *argv;
    while (--argc > 0) {
            //dc(c);
            switch(c = **++argv) {
                case '+':
                    //ds(*argv+1);
                    tabstop = (int) atof(*argv+1);
                    break;
                case '-':
                    //ds(*argv+1);
                    start = (int) atof(*argv+1);
                    break;
                default :
                    printf("%s: illegal option %c\n", name, c);
                    argc = -1;
                    break;
            }
        //printf("%s\n", *++argv);
    }
    //printf(" #%d# ", argc);
    /* di(tabstop);
    di(start); */
    if (argc != 0) {
        printf("Usage : %s -m +n\n", name);
        return 0;
    }
    while (_getline(line, MAXLINE) > 0) {
        int i = 0, m = 0, flag = 0;
        while (i < start && line[i] != '\0') {
            putchar(line[i++]);
            //++i;
        }
        while (line[i] != '\0') {
            if (line[i] == '\t') {
                int tab = m%tabstop;
                for (int j = 0 ; j < (tabstop - tab) ; j++) {
                    putchar('_'); // for testing
                    //putchar(' ');
                    m++;
                    flag = 1;
                }
            }
            else putchar(line[i]);
            if (flag == 1) {m--; flag = 0;}
            //if (flag != 1) {m++;flag = 0;}
            i++;m++;
        }
    }
    return 0;
}

int _getline(char s[], int lim) {
    int c, i;
    for (i = 0 ; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
