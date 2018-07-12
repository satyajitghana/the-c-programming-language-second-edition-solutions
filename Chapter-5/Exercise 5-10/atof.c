#include <ctype.h>

double atof(char s[]) {
    double val = 0.0, power = 1.0, exp = 0.0;
    int i = 0, sign = 1, expsign = 1;

    while(isspace(s[i])) ++i;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;
    while (isdigit(s[i])) {
        val = val * 10.0 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.') i++;
    while (isdigit(s[i])) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
        i++;
    }
    if (s[i] == 'e' || s[i] == 'E') i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;
    while (isdigit(s[i])) {
        exp = exp * 10.0 + (s[i] - '0');
        i++;
    }

    while (exp-- > 0) {
        if (expsign < 0) power *= 10;
        else power /= 10;
    }

    return sign * val / power;
}
