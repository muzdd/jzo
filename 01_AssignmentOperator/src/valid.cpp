#include "valid.h"

A::A(int n){
  value=n;
}

A::A(const A& other){
  value=other.value;
}

void A::Print(){
 printf("value:%d\n",value);
}
