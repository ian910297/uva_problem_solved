#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define true 1

FILE *fp, *fpp;

int answer_index[] = {
9,
14,
14,
5,
7,
8,
6,
19,
7,
22,
12,
8,
4,
15,
14,
12,
23,
17,
28,
32,
12,
24,
34,
7,
20,
11,
12,
26,
37,
28,
2,
31,
23,
23,
25,
28,
27,
22,
28,
12,
22,
30,
51,
35,
50,
9,
48,
39,
14,
20,
22,
22,
30,
62,
22,
44,
53,
2,
55,
21,
50,
46,
3,
51,
23,
31,
54,
60,
81,
23,
6,
22,
45,
64,
75,
78,
3,
47,
12,
40,
44,
35,
29,
6,
12,
85,
23
};

int m_index[] = {
  40,
  1,
  7,
  15,
  5,
  82,
  8,
  27,
  82,
  23,
  16,
  34,
  5,
  13,
  9,
  18,
  99,
  31,
  19,
  24,
  18,
  20,
  8,
  34,
  56,
  90,
  18,
  11,
  24,
  46,
  37,
  17,
  45,
  45,
  127,
  11,
  115,
  56,
  46,
  124,
  35,
  59,
  87,
  10,
  5,
  161,
  42,
  83,
  169,
  7,
  56,
  67,
  59,
  107,
  133,
  71,
  142,
  48,
  47,
  7,
  15,
  63,
  41,
  19,
  13,
  27,
  149,
  188,
  48,
  133,
  364,
  31,
  359,
  47,
  274,
  65,
  41,
  58,
  16,
  11,
  145,
  27,
  56,
  245,
  16,
  65,
  289
};

int next_index(int appear[], int index, int n, int m){
  int i;
  int temp = 0;

  //  for(i=0; i<n; i++){
  //    printf(" %d", appear[i]);
  //  }
  //  printf("\n");
  //  getchar();

  if(index+1 == n)
    i=0;
  else
    i = index;


  for(temp=0; true; i++){

    if(appear[i]==0){
      temp++;
      if(temp==m)
        break;
    }
    //    printf("temp = %d, i = %d\n", temp, i);

    if(i+1 == n)
      i = 0;
  }

  return i;
}

int find_answer(int appear[], int n, int m){
  int i;
  int index = 0;
  int count = 0;
  int answer;

  while(true){
    if(count==n-1){
      for(i=0; i<n; i++){
        if(appear[i]==0)
          break;
      }
      answer = i;
      break;
    }else{
      appear[index] = 1;
    }

    count++;
    index = next_index(appear, index, n, m);
  }

  return answer+1;
}

int find_m(int appear[], int n, int m){
  int i;
  int index = 0;
  int count = 0;
  int temp;
  int answer;

  while(true){
    if(count==n-1){
      answer = 0;
      break;
    }else{
      appear[index] = 1;
      if(index==12 && count==n-2){
        answer = 1;
        break;
      }
//      printf("index = %d\n", index);
    }

    count++;
    index = next_index(appear, index, n, m);
    //    printf("count = %d, next index: %d\n", count, index);
    //    printf("appear:");
    //    for(i=0; i<n; i++)
    //      printf(" %d", appear[i]);
    //    printf("\n");
  }

  return answer;
}

void find_m_ctl(int n){
  int i;
  int appear[n];
  int temp;

  temp = 0;
  for(i=0; true; i++){
    memset(appear, 0, sizeof(int)*n);
    //    printf("%d: ", i+1);
    temp = find_m(appear, n, i+1);
    if(temp==1){
      printf("%d\n", i+1);
      fprintf(fp, "%d,\n", i+1);
      break;
    }
  }

  //  printf("%d\n", find_process(appear, 0, n));
}

void find_answer_ctl(int n){
  int i;
  int appear[n];
  int temp;

  memset(appear, 0, sizeof(int)*n);
  temp = find_answer(appear, n, m_index[n-13]);
  printf("answer = %d\n", temp);
  fprintf(fpp, "%d,\n", temp);
}

int main(int argc, char *argv[]){

  int n;

  while(true){
    scanf("%d", &n);
    if(n==0)
      break;
    printf("%d\n", answer_index[n-13]);
  }

  /*
   * Produce m and answer
   */
//  fp = fopen("m_variable.txt", "w+");
//  fpp = fopen("answer.txt", "w+");
//  for(n=13; n<100; n++){
////    find_m_ctl(n);
////    find_answer_ctl(n);
//  }
//  fclose(fp);
//  fclose(fpp);


  return 0;
}
