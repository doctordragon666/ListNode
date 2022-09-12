#include "bidirect_link_node.h"
using namespace bidirect_link_node;

bool bidirect_link_node::init(DoubleList*& L)
{
	L = new DoubleNode;
	if (!L)return false;
	L->next = nullptr;
	L->prev = nullptr;
	L->data = -1;
	return true;
}

bool bidirect_link_node::insert_font(DoubleList*& L, DoubleNode* node)
{
	if (L->next == nullptr)
	{
		node->next = nullptr;
		node->prev = L;
		L->next = node;
	}
	else
	{
		L->next->prev = node;
		node->next = L->next;
		node->prev = L;
		L->next = node;
	}
	return true;
}

bool bidirect_link_node::push(DoubleList*& L, DoubleNode* node)
{
	if (!L || !node)return false;
	
	DoubleList* last = L;
	while (last->next) last = last->next;

	node->next = nullptr;
	last->next = node;
	node->prev = last;
	return false;
}

bool bidirect_link_node::insert(DoubleList*& L, int pos, int& e)
{
	if (!L || L->next)return false;
	if (pos < 1)return false;

	DoubleList* p = L;
	int count = 0;
	while (p && count < pos)
	{
		p = p->next;
		count++;
	}

	if (!p || pos != count)return false;

	cout << "p: " << p << endl;

	DoubleList* s = new DoubleNode;
	s->data = e;
	s->next = p;
	s->prev = p->prev;

	p->prev->next = s;
	p->prev = s;
}

void bidirect_link_node::print(DoubleList*& L)
{
}
