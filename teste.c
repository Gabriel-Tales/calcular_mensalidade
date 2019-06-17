#include <stdio.h>

struct test {
  int r[10];
};

void push_test(int t[]);

int main(void){
  register int i;
  struct test t;
  t.r[0] = 1;
  push_test(t.r);

  for (i=0; i<10; i++){
    printf("%d:%d\n",i,t.r[i]);
  }  

  return 0;
}

void push_test(int t[]){
  register int i;

  for (i=0; i<10; i++){
    t[i] = i*10;
  }

}

