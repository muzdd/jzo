#include "print_link_head2tail.h"
#include <stack>

PrintLink::PrintLink(){ }

PrintLink::~PrintLink(){ }

void PrintLink::PrintListReversingly_Iteratively(ListNode* pHead){

    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;

    while(pNode!=nullptr){
        nodes.push(pNode);
        pNode=pNode->m_pNext;
    }

    while(!nodes.empty()){
        pNode=nodes.top();
        printf("%d\n",pNode->m_nValue);
        nodes.pop();
    }
}
