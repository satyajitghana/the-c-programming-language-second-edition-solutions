#include<stdio.h>
#define MAXSIZE 1024

int _getline(char line[], int maxSize);

int main() {
int tabSpace=5;
int len;
char line[MAXSIZE];
char clean[MAXSIZE]={""};
while ( (len=_getline(line,MAXSIZE)) > 0)
{ 
	int i=0,count,j=0;
	if (len > 1)
		while(line[i]!='\0') {
			count=0;
			if (line[i]==' ') {
				while(line[i]==' '){count++;i++;} 
				int tab=count/tabSpace;
				int space=count%tabSpace;
				for(int k=0;k<tab;k++) 
				//clean[j++]='\t';
				clean[j++]='*'; 
				for(int l=0;l<space;l++) 
				clean[j++]='-';
				}
			else clean[j++]=line[i++];
			}	
	}
printf("\nYour cleansed output: \n%s",clean);
}

int _getline(char l[], int max) {
	int c,i=0;
	while(i<max-1 && (c=getchar())!=EOF && c!='\n') l[i++]=c;
	if(c=='\n') l[i++]=c;
	l[i]='\0';
	return i;
}
