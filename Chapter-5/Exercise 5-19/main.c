#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);

int gettoken(void);         
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* indetifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char out[1024];             /* output string */
int prevtoken = NO;         /* to indicate if there was a previous token */

/* undcl: convert word description to declaration */
int main() {
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {     /* 1st token on line */
        strcpy(out, token);    /* is the datatype */
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                int nexttype = gettoken();
                prevtoken = YES;
                if (nexttype != PARENS && nexttype != BRACKETS)
                    sprintf(temp, "*%s", out);
                else
                    sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        printf("%s\n", out);
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
        printf("error: expected name or (dcl)\n");
        prevtoken = YES;
    }
    while ((type = gettoken()) == PARENS || type  == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
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
