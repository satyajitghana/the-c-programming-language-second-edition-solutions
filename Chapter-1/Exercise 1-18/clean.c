#include<stdio.h>
#define MAXSIZE 1024

void _getline(char line[], int maxsize);

int main() {
char lines[MAXSIZE];
_getline(lines,MAXSIZE);
printf("\nFormatted Output: \n%s",lines);
}

void _getline(char l[], int max) {
  int c,i=0,FLAG=0;
  while ((i<max-1) && (c=getchar())!=EOF) {
    /*To remove empty lines*/
    if (c!='\n' && l[i]!='\n') {
    /*To remove trailing spaces*/
    if(c==' ') FLAG=1;
    else if (FLAG==1) {l[i]=' '; l[++i]=c; i++; FLAG=0;}
    else { l[i]=c; i++; }
    }
  }
  l[i]='\0';
}
