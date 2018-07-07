#include <stdio.h>
#include <math.h>
#define MAXOP 100 /* max size of operand or operator  */
#define NUMBER '0' /* signal that a number was found */

double atof(char []);
int getop(char []);
void push(double f);
double pop();
void swaptop();
double gettop();
void copytop();
void clear();
void help();

int main() {
    int type, len;
    double op2;
    char s[MAXOP];
    help();
    printf(">> ");
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
                printf("ANS :\t%.8g\n", pop());
                printf(">> ");
                break;
            default :
                printf("error : unknown command %s\n", s);
                break;
        }
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
            "? : PRINT TOP\n"
            "# : CLEAR STACK\n"
            "& : SWAP TOP\n"
            "H : HELP !! :O\n"
            "Q : QUIT\n"
            "\n");
 
}
