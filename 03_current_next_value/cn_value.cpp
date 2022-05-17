#include <stdio.h>
#include <math.h>

class A{
 public:
   int t2=INFINITY;
   int a_y(int x);
};

int aa(int x){
   int yy=20;
   yy=yy+x;
   return yy;
}

int A::a_y(int x){
  printf("t2=%d\n",t2);
  int a=aa(x);
  if(t2-a==0){
    printf("leon\n");
  }
  t2=a;
  printf("a=%d\n",a);
}

int main(){
  A a;
  for (int i=0;i<4;i++){
    a.a_y(i);
  }
  return 0;
}

