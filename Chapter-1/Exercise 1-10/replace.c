#include<stdio.h>
int main() {
    int input;
    while((input=getchar())!=EOF) {
      if(input== '\t' || input=='\b' || input=='\\') printf("\\\\");
      else putchar(input);
    }
}
