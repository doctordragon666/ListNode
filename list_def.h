#ifndef _LIST_DEF_H
#define _LIST_DEF_H

#include <iostream> 
using namespace std;

typedef struct _LinkNode {
	struct _LinkNode* next;
	int data;
}LinkNode, LinkList;

typedef struct _DoubleNode {
	struct _DoubleNode* next;
	struct _DoubleNode* prev;
	int data;
}DoubleNode, DoubleList;

#endif // !_LIST_DEF_H