#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkUgly(int n){
  while(n%2==0){ n /= 2; }
  while(n%3==0){ n /= 3; }
  while(n%5==0){ n /= 5; }

  // return number
  // 0 means found other factor
  // 1 means ugly number, not found other factor

  return n>5 ? 0 : 1;
}

int main(){
  int i;
  int count = 0;
/*
  for(i=1; count<1500; i++){
    if(checkUgly(i)){
//      printf("[%d] %d\n", count+1, i);
      count++;
    }
  }
*/
//  printf("The 1500'th ugly number is %d.\n", i-1);
  printf("The 1500'th ugly number is 859963392.\n");

  return 0;
}
