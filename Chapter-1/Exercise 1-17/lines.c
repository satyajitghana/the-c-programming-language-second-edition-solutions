/*Print lines which are 80 characters or more, length including the '\n'*/
#include<stdio.h>
#define MAXLENGTH 1024

int _getline(char line[], int maxlength);

int main() {
  char line[MAXLENGTH];
  /*Array of strings to store a maximum of 15 lines with 80 characters
  or more*/
  char lines[15][MAXLENGTH]={};
  char length;
  int i=0;
  while ((length=_getline(line,MAXLENGTH))>0) { //printf("%d",length);
    if (length > 80) {
      for (int j=0;line[j]!='\0';j++)
        lines[i][j]=line[j];
        i++;
    }
  }
  for (int j=0;j<i;j++) {
    printf("\nThe line(s) with more than 80 characters are :\n%s",lines[j]);
  }
}

int _getline(char l[], int maxlength) {
  int c,i=0;
  while (i<(maxlength-1) && (c=getchar())!=EOF && c!='\n') {
    l[i]=c;
    i++;
  }
  if (c=='\n') {l[i]=c; i++;}
  l[i]='\0';
  return i;
}
