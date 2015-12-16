#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_LEN 100000
#define true 1

int judge(int n, int *data){
  int i;
  int diff;
  int result = true;
  int appear[3000] = {0};

  for(i=0; i<n-1; i++){
    diff = data[i+1] - data[i];
    if(diff < 0) diff *= -1;

    if(appear[diff]==0 && diff<n) {
      appear[diff] = 1;
    }else {
      result = 0;
      break;
    }
  }

  return result;
}

void input(char *str){
  int n;
  char leave[MAX_LEN] = {'\0'};
  char tmp[MAX_LEN] = {'\0'};
  sscanf(str, "%d %[^\n]", &n, leave);

  int i;
  int data[n];
  for(i=0; i<n-1; i++){
    sscanf(leave, "%d %[^\n]", &data[i], tmp);

    memset(leave, '\0', sizeof(char)*MAX_LEN);
    memcpy(leave, tmp, sizeof(char)*MAX_LEN);
    memset(tmp, '\0', sizeof(char)*MAX_LEN);
  }
  sscanf(leave, "%d", &data[i]);

  judge(n, data)==true ? printf("Jolly\n") : printf("Not jolly\n");
}

int main(){
  char str[MAX_LEN] = {'\0'};
  while(scanf("%[^\n]", str)!=EOF) {
    getchar();
    input(str);
    memset(str, '\0', sizeof(char)*MAX_LEN);
  }

  return 0;
}
