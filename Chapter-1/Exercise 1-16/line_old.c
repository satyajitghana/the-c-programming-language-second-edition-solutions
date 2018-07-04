#include<stdio.h>
#define MAXSIZE 1023
/*assuming max length will be 1023*/

int _getline(char line[], int maxlength);
void copy(char from[],char to[]);

int main() {
char line[MAXSIZE];
int length;
char maxline[MAXSIZE];
int maxlength=0;
while ((length=_getline(line,MAXSIZE))>0) {
  if (length > maxlength) {
    maxlength=length;
    copy(line,maxline);
  }
}
printf("The largest line is : \n%s\n which is of %d length\n",maxline,maxlength);
return 0;
}

int _getline(char line[], int max) {
  int c;
  int i=0;
  while((c=getchar())!=EOF && c!='\n') {
    line[i]=c; i++;
  }
//  if (c=='\n') { line[i]=c; i++; }
  line[i]='\0';
//  printf("%s",line);
  return i;
}

void copy(char f[],char t[]) {
  int i=0;
  while ((t[i]=f[i])!='\0') ++i;
}
