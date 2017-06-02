/*Vertical Histogram*/
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
  //find the maximum height
  int m=-1;
  for(int k=0;k<SIZE;k++) {
    if(count[k]>m) {m=count[k];}
  }
  //print the Histogram
  for (int i=m;i>0;i--) {
    for (int j=0;j<SIZE;j++) {
      //print # only if the count is greater than the i
      if (count[j]!=0) {
      if(count[j]>=i) printf("#");
      else printf(" ");}
    }
    printf("\n");
  }
  for (int j=0;j<SIZE;j++) {
    if (count[j]!=0)
    printf("%d",j);
  }
  printf("\n");
}
