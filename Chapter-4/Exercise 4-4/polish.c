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

int main() {
    int type, len;
    double op2;
    char s[MAXOP];
    printf("COMMANDS AND OPERATIONS SUPPORTED\n"
            "+ : ADD\n"
            "* : MULTIPLY\n"
            "- : SUBTRACT\n"
            "/ : DIVIDE\n"
            "% : REMAINDER\n"
            "? : PRINT TOP\n"
            "# : CLEAR STACK\n"
            "& : SWAP TOP\n"
            "Q : QUIT\n"
            "\n");
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
