#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXOP 100 /* max size of operand or operator  */
#define NUMBER '0' /* signal that a number was found */

/* converter helper function */
double atof(char []);

/* operator and opearnd functions */
int getop(char []);
double getvar(char variable);
void setvar(double value, char variable);

/* stack functions */
void push(double f);
double pop();
void swaptop();
double gettop();
void copytop();
void clear();

/* pretty printing functions */
void help();

/* buffer functions */
void ungets(char s[]);
void ungetch(int c);

/* getline function */
#define MAXLINE 1000
int _getline(char str[], int limit);

int main() {
    int type, len;
    double op2;
    char s[MAXOP], line[MAXLINE];
    help();
    printf(">> ");
    while (_getline(line, MAXLINE) > 0) {
        /* debug printf(" * %s * ", line);*/
        ungets(line);
        while ((type = getop(s)) != EOF) {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error : zero divisor\n");
                    break;
                case '%':
                    op2 = pop();
                    push(fmod(pop(), op2));
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case 'e':
                    push(exp(pop()));
                    break;
                case 'S':
                    push(sin(pop()));
                    break;
                case '?':
                    printf("\t%.8g\n", gettop());
                    break;
                case '$':
                    copytop();
                    break;
                case '#':
                    clear();
                    break;
                case '&':
                    swaptop();
                    break;
                case 'H':
                    help();
                    break;
                case 'Q':
                    return 0;
                case '\n':
                    setvar(pop(), 'A');
                    printf("ANS :\t%.8g\n", getvar('A'));
                    printf(">> ");
                    break;
                default :
                    if (isupper(type))
                        push(getvar(type));
                    else
                        printf("error : unknown command %s\n", s);
                    break;
            } /* switch */
        } /* getop while */
    } /* getline while */
    return 0;
} /* main */

void help() {
    printf( "* * POLISH CALCULATOR * *\n"
            "COMMANDS AND OPERATIONS SUPPORTED\n"
            "+ : ADD\n"
            "* : MULTIPLY\n"
            "- : SUBTRACT\n"
            "^ : POWER\n"
            "e : EXPONENTIAL\n"
            "SIN : SINE\n"
            "/ : DIVIDE\n"
            "% : REMAINDER\n"
            "+<UPPER CASE LETTER> SAVE TO VAR\n"
            "<UPPER CASE LETTER> USE THE VALUE OF VAR\n"
            "? : PRINT TOP\n"
            "# : CLEAR STACK\n"
            "& : SWAP TOP\n"
            "H : HELP !! :O\n"
            "Q : QUIT\n"
            "\n");
 
}
