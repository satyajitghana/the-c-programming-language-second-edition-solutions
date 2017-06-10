/*Exercise to reverse a string line by line*/
#include<stdio.h>
#define MAXSIZE 1024

int _getline(char line[],int maxsize);
void reverse(char line[], int size);

int main() {
char line[MAXSIZE];
int len;
while ( (len=_getline(line,MAXSIZE)) > 0 ) {
  if (len > 1)  {
    /*reverse except the \n and \0 hence len-2*/
    reverse(line,len-2);
    printf("%s",line);
    }
  }
}

int _getline(char l[],int max) {
  int c;
  int i=0;
  while (i<max-1 && (c=getchar())!=EOF && c!='\n') {
      l[i]=c; i++;
    }
  if (c=='\n') {l[i]=c; i++;}
  l[i]='\0';
  return i;
}

/*swap without a temp, and call by reference*/
void swap(char *a, char *b) {
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
}

void reverse(char l[], int s) {
int i=0;
/*keep swapping i and size-i till you reach middle of string*/
while (i!=((s/2)+1)) {
  swap(&l[i],&l[s-i]); i++;
  }
}
