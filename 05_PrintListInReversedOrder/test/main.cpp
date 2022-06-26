#include "print_link_head2tail.h"
#include <stdio.h>

void test(){
    ListNode* pNode1=CreateListNode(1);
    ListNode* pNode2=CreateListNode(2);
    ListNode* pNode3=CreateListNode(3);
    ListNode* pNode4=CreateListNode(4);
    ListNode* pNode5=CreateListNode(5);
    printf("pNode1:%d\n",*pNode1);
    printf("pNode2:%d\n",*pNode2);
    printf("pNode3:%d\n",*pNode3);
    printf("pNode4:%d\n",*pNode4);
    printf("pNode5:%d\n",*pNode5);
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    ConnectListNodes(pNode3,pNode4);
    ConnectListNodes(pNode4,pNode5);
    PrintLink pl;
    ListNode* pHead=pNode1;
    PrintList(pHead);
    pl.PrintListReversingly_Iteratively(pHead);
    DestroyList(pHead);
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

