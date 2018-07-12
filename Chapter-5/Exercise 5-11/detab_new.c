#include <stdio.h>
#define MAXLINE 1000
#define MAXTABLIST 20
#define TABSTOP 5

int _getline(char line[], int maxline);
double atof(char *s);

int tablist[MAXTABLIST] = { 5 };

int main(int argc, char **argv) {
    int len;
    char line[MAXLINE], longest[MAXLINE];
    int tablistsize = (argc > 1) ? 0 : 1;
    while (--argc > 0 && **++argv) {
        //printf("%d\n", (int) atof(*argv));
        tablist[tablistsize++] = (int) atof(*argv);
    }

    /* for (int i = 0 ; i < tablistsize ; i++)
        printf("%d ", tablist[i]); */

    //return 0;
    int i_tab = 0;
    while (_getline(line, MAXLINE) > 0) {
        int i = 0, m = 0, flag = 0;
        while (line[i] != '\0') {
            if (line[i] == '\t') {
                int tab = m%tablist[i_tab%tablistsize];
                //printf(" *%d* ", tab);
                for (int j = 0 ; j < (tablist[i_tab%tablistsize] - tab) ; j++) {
                    putchar('_'); // for testing
                    //putchar(' ');
                    if (m > tablist[i_tab%tablistsize]) {
                        //printf(" c ");
                        i_tab++;
                        int tab = m%tablist[i_tab%tablistsize];
                    }
                    //printf(" *%d* ", m);
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
