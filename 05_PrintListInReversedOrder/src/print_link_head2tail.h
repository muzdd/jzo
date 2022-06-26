#ifndef _PRINT_LINK_H
#define _PRINT_LINK_H
#include <stdio.h>
#include "list.h"

class PrintLink
{
public:
   PrintLink();
   virtual ~PrintLink();
   void PrintListReversingly_Iteratively(ListNode* pHead);
   void PrintListReversingly_Recursively(ListNode* pHead);
};
#endif //VALID_H
