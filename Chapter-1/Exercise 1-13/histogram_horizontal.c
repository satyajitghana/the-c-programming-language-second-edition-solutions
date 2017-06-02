/*Horizontal Histogram*/
#include<stdio.h>
#define SIZE 15 //assuming max size of word is 15
int main() {
  int input,count[SIZE]={0},tmp=0;;
  //ctrl+d is the EOF key
  while ((input=getchar())!=EOF) {
    //keep counting till you you reach end of word then dump the
    //count into the array
    if(input!=' '&& input!='\n') ++tmp;
    else {++count[tmp]; tmp=0;}
  }
  for(int i=0;i<SIZE;i++) {
    //print only words which are >0
    if(count[i]!=0) {
      printf("%3d : ",i);
      for (int j=0;j<count[i];j++) printf("#");
      putchar('\n');
    }
  }
}
