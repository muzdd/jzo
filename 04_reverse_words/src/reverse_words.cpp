#include "reverse_words.h"
#include <string>

ReverseWord::ReverseWord(){ }

ReverseWord::~ReverseWord(){ }

char* ReverseWord::strrevw(char* s){
   int i=0;
   int j;
   int length=strlen(s);
   for(j=0;j<length;j++)
   {
       if(s[j]==' ')
       {
           for(int t=i;t<(j+i)/2;t++)
           {
               char temp=s[t];
               s[t]=s[j+i-t-1];
               s[j+i-t-1]=temp;
           }
           i=j+1;
           j=i;
       }
   }
   
   for(int t=i;t<(j+i)/2;t++)
   {
       char temp=s[t];
       s[t]=s[j+i-t-1];
       s[j+i-t-1]=temp;
   }
return s;
}

char* ReverseWord::reverse_string(char* s){
    
   if(NULL == s)
   {
      return s;
   }
   int len=strlen(s);
   for(int i=0;i<=len/2;i++)
   {   
      char t=s[i];
      s[i]=s[len-i-1];
      s[len-i-1]=t;
   } 

return s;
}
