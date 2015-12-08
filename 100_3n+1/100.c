#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  int i, j;
  int k;
  int max_result;
  int temp, index;

  while(scanf("%d %d", &i, &j)!=EOF){

    printf("%d %d ", i, j);
    if(i>j){
      temp = i;
      i = j;
      j = temp;
    }
    max_result = 0;

    for(k=i; k<=j; k++){
      temp = k;
      index = 1;
      while(temp!=1){
        if(temp&1)
          temp = temp*3 + 1;
        else
          temp /= 2;

        index++;
      }
      if(max_result < index)
        max_result = index;
    }

    printf("%d\n", max_result);
  }

  return 0;
}
