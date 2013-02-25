// ·´ĞòÊä³öÁ´±í
// http://t.jobdu.com/thread-98629-1-1.html

#include <stdio.h>
#include <stdlib.h>

typedef struct _LNode{
    int key;
    struct _LNode* next;
} LNode;

LNode* initLinker(int n)
{
    int i;
    LNode *head, *node;
    head = (LNode*)malloc(sizeof(LNode));
    head->key = 1;
    head->next = NULL;
    for (i = n; i > 1; i--)
    {
        node = (LNode*)malloc(sizeof(LNode));
        node->key = i;
        node->next = head->next;
        head->next = node;
    }

    return head;
}

void printLinker(LNode* node)
{
    while (node)
    {
        printf("%d ", node->key);
        node = node->next;
    }
    printf("\n");
}

void invertPrint(LNode* node)
{
    if (node)
    {
        invertPrint(node->next);
        printf("%d ", node->key);
    }
}

LNode* invertLinker(LNode* head)
{
    LNode *pre, *cur, *temp;
    pre = head;
    cur = pre->next;
    pre->next = NULL;
    while (cur)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

int main()
{
    LNode* head;
    head = initLinker(20);
    printf("Original Linker:\n");
    printLinker(head);

    printf("[recursive] Invert the Linker:\n");
    invertPrint(head);
    printf("\n");

    printf("[change the linker] Invert the Linker:\n");
    head = invertLinker(head);
    printLinker(head);

    return 0;
}
