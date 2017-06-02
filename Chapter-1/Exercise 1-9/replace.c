#include<stdio.h>
int main() {
  int input,FLAG=0;
  while((input=getchar())!=EOF) {
    if(input==' ') FLAG=1;
    else if(FLAG==1) {putchar(' '); putchar(input); FLAG=0;}
    else putchar(input);

  }
}
