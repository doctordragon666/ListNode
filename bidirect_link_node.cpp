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

bool bidirect_link_node::init(DoubleNode& head)
{
	head.next = nullptr;
	head.prev = nullptr;
	head.data = -1;
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

bool bidirect_link_node::delete_elem(DoubleList*& L, int pos)
{
	if (!L || !L->next)return false;

	if (pos < 1)return false;//不能删除头节点

	DoubleList* p = L;
	int index = 0;

	while (p && index < pos)
	{
		p = p->next;
		index++;
	}

	if (!p)return false;//节点不存在

	p->prev->next = p->next;
	if (p->next)p->next->prev = p->prev;//末尾节点
	delete p;
	return true;
}

bool bidirect_link_node::get_elem(DoubleList*& L, int pos, int& e)
{
	if (!L || !L->next)return false;

	DoubleList* p = L->next;
	int index = 1;
	
	while (p&&index<pos)
	{
		p = p->next;
		index++;
	}

	if (!p || index > pos)return false;

	e = p->data;
	return true;
}

bool bidirect_link_node::find_elem(DoubleList*& L, int e)
{
	return false;
}

void bidirect_link_node::print(DoubleList*& L)
{
	if (!L)
	{
		cout << "链表为空" << endl;
		return;
	}
	DoubleList* p = L;

	cout << "\n顺序打印\n";
	while (p->next)
	{
		cout << p->next->data << "->";
		p = p->next;
	}

	cout << "\n逆向打印\n";
	while (p)
	{
		cout << p->data << "->";
		p = p->prev;
	}
	cout << "end\n";
}

void bidirect_link_node::destory(DoubleList*& L)
{
	DoubleList* p = L;
	cout << "销毁链表\n";

	while (p)
	{
		L = L->next;
		cout << "删除元素" << p->data << endl;
		delete p;
		p = L;
	}
}
