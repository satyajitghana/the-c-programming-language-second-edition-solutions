#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "buffer.h"

#define MAXLENGTH 128

enum { FUNCTION, BRACKETS, NAME };
int tokentype = -1;
char name[MAXLENGTH];
char datatype[MAXLENGTH];
char token[MAXLENGTH];
char out[1024];

void dcl();
void directdcl();
int gettoken();

#define ds(s) printf(#s " : %s ", s);

int main() {
    while (gettoken() != EOF) {
        *out = '\0';
        /* copy the datatype */
        strcpy(datatype, token);
        //ds(datatype);
        /* now parse the dcl */
        dcl();
        if (tokentype != '\n')
            printf("syntax error \n");
        printf("%s:%s %s\n", name, out, datatype);
    }
    return 0;
}

void dcl() {
    int np;
    for (np = 0 ; gettoken() == '*' ; ++np)
        ;
    directdcl();
    while (np--)
        strcat(out, " pointer to");
}

void directdcl() {
    if (tokentype == '(') {
        //printf(" found ( ");
        /* parse the dcl */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n", tokentype, tokentype);
    } else if (tokentype == NAME) {
        strcpy(name, token);
        //ds(name);
    } else
        printf(" expected name or (dcl)\n", tokentype);

    /* parse the inside */
    int type;
    while ((type = gettoken()) == FUNCTION || type == BRACKETS) {
        if (type == FUNCTION) {
            strcat(out, " function returning");
        }
        
        if (type == BRACKETS) {
            strcat(out, " array [");
            strcat(out, token);
            strcat(out, "] of");
        }
    }
}

int gettoken() {
    int c, next;
    char *ptoken = token;

    /* skip the whitespaces */
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        //printf("found ( ");
        next = getch();
        if (next == ')')
            return tokentype = FUNCTION;
        else {
            ungetch(next);
            return tokentype = c;
        }
    } else if (c == '[') {
        while ((c = getch()) != ']')
            *ptoken++ = c;
        *ptoken = '\0';
        return tokentype = BRACKETS;
    } else if (isalnum(c)) {
        *ptoken++ = c;
        while (isalnum(next = getch()))
            *ptoken++ = next;
        ungetch(next);
        *ptoken = '\0';
        return tokentype = NAME;
    } else
        return tokentype = c;
}
