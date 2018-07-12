#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXOP 100 /* max size of operand or operator  */
#define NUMBER '0' /* signal that a number was found */

/* debug string */
#define ds(s) printf(#s " : %s\n", s);
#define dc(c) printf(#c " : %c\n", c);

/* converter helper function */
double atof(char []);

/* operator and operand functions */
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

int main(int argc, char **argv) {
    int type, len;
    double op2;
    char s[MAXOP];
    /*while (--argc > 0 ) {
        printf("%s\n", *++argv);
    }*/

    /*help();
    printf(">> ");*/
    //printf("no. of arguments : #%d#\n", argc);
    while (--argc > 0) {
        type = getop(*++argv);
        //ds(*argv);
        //dc(type);
        switch (type) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
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
                else {
                    printf("error : zero divisor\n");
                    return -1;
                }
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
            default:
                printf("Usage : expr <reverse polish operations>\n");
        }
    }
    if (argc != 0)
        printf("Usage : expr <reverse polish operations>\n");
    else {
        setvar(pop(), 'A');
        printf("ANS :\t%.8g\n", getvar('A'));
    }
    return 0;
}

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
