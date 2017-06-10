/*Remove tabs and relpace with spaces, tab stops are a thing :p*/
#include<stdio.h>
#define MAXSIZE 1024

int _getline(char line[], int maxsize);

int main() {
  /*assuming tab size is of 5 characters*/
int tabSize=5;
char line[MAXSIZE];
while (_getline(line,MAXSIZE) > 0) {
  for(int i=0;line[i]!='\0';i++) {
      if(line[i]=='\t') {
        /*calculate the tab stop*/
        for (int j=0;j<(tabSize-(i%tabSize));j++)
        //putchar('_');
        putchar(' ');
      }
      else putchar(line[i]);
    }
  }
}

int _getline(char l[],int max) {
  int c;
  int i=0;
  while(i<max-1 && (c=getchar())!=EOF && c!='\n') l[i++]=c;
  if (c=='\n') l[i++]=c;
  l[i]='\0';
  return i;
}
