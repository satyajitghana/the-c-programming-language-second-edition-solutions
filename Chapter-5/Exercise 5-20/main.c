#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "buffer.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void prmdcl(void);

int gettoken(void);         
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* indetifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char out[1024];             /* output string */
int prevtoken = NO;         /* to indicate if there was a previous token */

int main() {
    while (gettoken() != EOF) {     /* 1st token on line */
        strcpy(datatype, token);    /* is the datatype */
        out[0] = '\0';
        dcl();  /* parse rest of the line */
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* dcl: parse a declarator */
void dcl(void) {
    int ns;

    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void) {
    int type;

    if (tokentype == '(') {         /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME)   /* variable name */
        strcpy(name, token);
    else {
        //printf("error: expected name or (dcl)\n");
        prevtoken = YES;
    }
    while ((type = gettoken()) == PARENS || type  == BRACKETS || type == '(')
        if (type == PARENS)
            strcat(out, " function returning");
        else if (type == '(') {
            strcat(out, " function expecting");
            prmdcl();
            strcat(out, " and returning");
        }
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

/* prmdcl: parse the parameters to a function */
void prmdcl(void) {
    int type;
    while ((type = gettoken()) != ')') {
        if (type != NAME && type != ',') {
            prevtoken = YES;
            dcl();
        }
        else if (type == ',')
            strcat(out, ",");
        else {
            strcat(out, " ");
            strcat(out, token);
        }
    }
}

int gettoken(void) /* return next token */ {
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (prevtoken == YES) {
        prevtoken = NO;
        return tokentype;
    }

    while((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}
