#ifndef _LIST_DEF_H
#define _LIST_DEF_H

#include <iostream> 
using namespace std;

typedef struct _LinkNode {
	struct _LinkNode* next;
	int data;
}LinkNode, LinkList;



#endif // !_LIST_DEF_H