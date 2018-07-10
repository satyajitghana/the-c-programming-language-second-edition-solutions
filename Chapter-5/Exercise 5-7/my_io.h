#ifndef MY_IO_H
#define MY_IO_H

int _getline(char str[], int limit);

int _readlines(char *lineptr[], int maxlines, char *linestore);
int readlines(char *lineptr[], int maxlines);

void writelines(char *lineptr[], int nlines);

#endif
