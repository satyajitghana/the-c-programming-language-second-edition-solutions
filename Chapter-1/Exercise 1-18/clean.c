#include<stdio.h>
#define MAXSIZE 1024

int _getline(char line[], int maxsize);
void concat(char where[], char what[]);

int main() {
char line[MAXSIZE];
char lines[MAXSIZE]={""};
int len;
while ( (len=_getline(line,MAXSIZE)) > 0 ) {
  /*To remove trailing carriage returns*/
  if (len > 1) {
  //printf("%s",line);
  concat(lines,line);
  }
}
  printf("\nFormatted Output: \n%s",lines);
}

int _getline(char l[], int max) {
  int c,i=0,FLAG=0;
  while ((i<max-1) && (c=getchar())!=EOF && c!='\n') {

    /*To remove trailing spaces*/
    if(c==' ') FLAG=1;
    else if (FLAG==1) {l[i]=' '; l[++i]=c; i++; FLAG=0;}
    else { l[i]=c; i++; }
    }
  if (c=='\n') {l[i]=c; i++;}
  l[i]='\0';
  return i;
}

void concat(char para[], char line[]) {
  int i=0;
  while (para[i]!='\0') i++;
  int j=0;
  while (line[j]!='\0') {
    para[i]=line[j];
    i++; j++;
  }
  //para[i]='\0';
}
