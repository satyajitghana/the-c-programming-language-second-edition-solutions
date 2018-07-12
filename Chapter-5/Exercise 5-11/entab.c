#include<stdio.h>
#define MAXSIZE 1024

#define ds(s) printf(#s " : %s\n", s); /* debug string      */
#define dc(c) printf(#c " : %c\n", c); /* debug character   */
#define di(d) printf(#d " : %d\n", d); /* debug integer     */

int _getline(char line[], int maxline);
double atof(char *s);

int main(int argc, char **argv) {
    int tabSpace = 5;
    int start = -1;
    char *name = *argv;
    int len;
    char line[MAXSIZE];
    //char clean[MAXSIZE]={""};
    int c;
    while (--argc > 0) {
            //dc(c);
            switch(c = **++argv) {
                case '+':
                    //ds(*argv+1);
                    tabSpace = (int) atof(*argv+1);
                    break;
                case '-':
                    //ds(*argv+1);
                    start = (int) atof(*argv+1);
                    break;
                default :
                    printf("%s: illegal option %c\n", name, c);
                    argc = -1;
                    break;
            }
        //printf("%s\n", *++argv);
    }
    //printf(" #%d# ", argc);
    /* di(tabstop);
    di(start); */
    if (argc != 0) {
        printf("Usage : %s -m +n\n", name);
        return 0;
    }

    while ( (len=_getline(line,MAXSIZE)) > 0) { 
        char clean[MAXSIZE]={""};
        int i = 0, count, j = 0;
        if (len > 1)
            while (i < start && line[i] != '\0') {
                clean[j++] = line[i++];
                //++i;
            }

            while(line[i] != '\0') {
                count = 0;
                if (line[i] == ' ') {
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
        printf("%s",clean);
    }
    //printf("\nYour cleansed output: \n%s",clean);
}

int _getline(char l[], int max) {
	int c,i=0;
	while(i<max-1 && (c=getchar())!=EOF && c!='\n') l[i++]=c;
	if(c=='\n') l[i++]=c;
	l[i]='\0';
	return i;
}
