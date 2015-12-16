#include <stdio.h>
#include <stdlib.h>
#define true 1

FILE *fp;

char n_char[] = {
  '0',
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9'
};

void enterData(int x, int y){
  int i, j;
  char map[x][y];

  for(i=0; i<x; i++){
    scanf("%s", map[i]);
    getchar();
  }

  int count;
  int m, n;

  for(i=0; i<x; i++){
    for(j=0; j<y; j++){
      if(map[i][j]=='*'){
        continue;
      }else{
        count = 0;
        for(m=i-1; m<i+2; m++){
          for(n=j-1; n<j+2; n++){
            if(m==i && n==j)
              continue;
            if(m<0 || m>=x)
              continue;
            if(n<0 || n>=y)
              continue;

            if(map[m][n]=='*')
              count++;
          }
        }
        //        printf("(%d, %d) %d\n", i, j, count);
        map[i][j] = n_char[count];
      }
    }
  }

  for(i=0; i<x; i++){
    for(j=0; j<y; j++){
      printf("%c", map[i][j]);
      fprintf(fp, "%c", map[i][j]);
    }
    printf("\n");
    fprintf(fp, "\n");
  }
}

int main(){
  int x, y;
  int times = 0;

  fp = fopen("answer.txt", "w+");
  while(true){
    scanf("%d %d", &x, &y);
    getchar();

    if(x==0 && y==0)
      break;

    if(times!=0){
      printf("\n");
      fprintf(fp, "\n");
    }
    times++;


    printf("Field #%d:\n", times);
    fprintf(fp, "Field #%d:\n", times);


    if(x!=0 && y!=0)
      enterData(x, y);
  }

  fclose(fp);
  return 0;
}
