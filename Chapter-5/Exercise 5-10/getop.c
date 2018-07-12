#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define NUMBER '0'
#define LETTERS 26

/* debug string and debug character */
#define ds(s) printf(#s " : %s\n", s);
#define dc(c) printf(#c " : %c\n", c);

int getch(void);
void ungetch(int);
void push(double f);
double gettop();
double VARS[LETTERS];

void l(char c) { /* a log like thing */
    printf(" *%c* ", c);
}

/* to get the next operator or operand */
int getop(char *s) {
    int i;
    char *c = s;
    //printf(" *%d* ", strlen(c));

    /* there are no whitespaces, everything is tokenized    */
    /* less work for us ;)                                  */
    /* skip the whitespaces                                 */
    /* while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';*/
    //printf(" #%s# ", s);

    /* if it's not a number or SIN */
    //dc(*c);
    if (!isdigit(*c) /*&& 
            *c != '.' && 
            *c != '-' && 
            *c != 'S' && 
            *c != '+' &&
            !isupper(*c) */
            )
        return *c; /* not a number */
    i = 0;
    int next;
    
    /* to handle sin */
    /*if (!strcmp(c, "SIN"))
        return 'S';*/
   
    /* it might be a save variable, the value is then 
     * handled by main, which in turn uses the helper functions
     * to handle the variable */
    /*if (isupper(*c) && *(c+1) == '\0') {
        return *c;
    }*/

    /* to handle save to variable */
    /*if (*c == '+' && isupper(*(c+1)) && *(c+2) == '\0') {
        next = *++c;
        if (next >= 'A' && next <= 'Z') {
            VARS[next - 'A'] = gettop();
            return next;
        }
        else {
            return *c;
        }
    }*/


    /* to handle negative numbers */
    /*if (*c == '-') {
        next = *++c;
        if (!isdigit(next) && next != '.') {
            return *c;
        }
    }*/

    /*
    * collect the rest of the integer part */
    /*if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;*/
    /* collect the fracitonal part */
    /*if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';*/
    /*if (c != EOF) {
        //printf(" +%c+ ", c);
        ungetch(c);
    }*/
    return NUMBER;
}

double getvar(char V) {
    return VARS[V-'A'];
}

void setvar(double val, char var) {
    VARS[var - 'A'] = val;
}
