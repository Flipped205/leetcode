#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode
{
    int val;
    struct ListNode *next;
    
}LISTNODE;
struct ListNode*  newListNode(int val);
int addListNode(struct ListNode *listNode,int val);
void PrintListNode(struct ListNode *listNode);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node,*p,*q,*tmp;
    int tmpVal = 0;
    node = newListNode(0);
    tmp = node;
    for(p = l1->next,q = l2->next;p!=NULL && q!=NULL;p=p->next,q=q->next)
    {
        tmpVal /=10;
        if(p!=NULL)
            tmpVal +=p->val;
        if(q!=NULL)
            tmpVal +=q->val;

        tmp->next = newListNode(tmpVal%10);
        tmp = tmp->next;
    }
    return node;
}

struct ListNode*  newListNode(int val)
{
    struct ListNode *node;
    node = (LISTNODE *)malloc(sizeof(LISTNODE));
    if(NULL == node)
        return NULL;
    node->val = val;
    node->next = NULL;
    return node;
}


int addListNode(struct ListNode *listNode,int val)
{
    struct ListNode *newNode =NULL;
    if(listNode == NULL)
        return 0;

    newNode = newListNode(0);
    if(newNode == NULL)
        return 0;
    newNode->next = NULL;
    newNode->val = val;

    newNode->next = listNode->next;
    listNode->next = newNode;
    return 1;
}


void PrintListNode(struct ListNode *listNode)
{
    struct ListNode *p;
    if(listNode == NULL)
        return ;
    for(p= listNode->next;p!=NULL;p=p->next){
        printf("%d", p->val);
        if(p->next)
            printf("->");
    }
    printf("\n");
}

void main(void)
{
    struct ListNode *l1;
    struct ListNode *l2;
    struct ListNode *l3;
    l1 = newListNode(0);
    addListNode(l1,3);
    addListNode(l1,4);
    addListNode(l1,2);
    PrintListNode(l1);

    l2 = newListNode(0);
    addListNode(l2,4);
    addListNode(l2,6);
    addListNode(l2,5);
    PrintListNode(l2);
    l3 = addTwoNumbers(l1,l2);
    PrintListNode(l3);
}