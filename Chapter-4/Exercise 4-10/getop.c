#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'
#define LETTERS 26

int getch(void);
void ungetch(int);
void push(double f);
double gettop();
double VARS[LETTERS];

void l(char c) { /* a log like thing */
    printf(" *%c* ", c);
}

/* to get the next operator or operand */
int getop(char s[]) {
    int i, c;

    /* skip the whitespaces */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    //printf(" #%s# ", s);
    if (!isdigit(c) && 
            c != '.' && 
            c != '-' && 
            c != 'S' && 
            c != '+' &&
            !isupper(c))
        return c; /* not a number */
    i = 0;
    int next;

    /* to handle sin first*/
    if (c == 'S') {
        next = getch();
        if (next == 'I' && (next = getch() == 'N'))
            return 'S';
        else {
            ungetch(next);
            return c;
        }
    }
    
    /*handle the variables later*/
    if (isupper(c)) {
        return c;
    }

    /* to handle save to variable */
    if (c == '+') {
        next = getch();
        if (next >= 'A' && next <= 'Z') {
            VARS[next - 'A'] = gettop();
            return next;
        }
        else {
            ungetch(next);
            return c;
        }
    }


    /* to handle negative numbers */
    if (c == '-') {
        next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return c;
        }
        c = next;
        if (isdigit(c)) s[++i] = c;
    }

    /* collect the rest of the integer part */
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    /* collect the fracitonal part */
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) {
        //printf(" +%c+ ", c);
        ungetch(c);
    }
    return NUMBER;
}

double getvar(char V) {
    return VARS[V-'A'];
}

void setvar(double val, char var) {
    VARS[var - 'A'] = val;
}
