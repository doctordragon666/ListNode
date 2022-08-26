#pragma once
#include "list_def.h"
namespace loop_link_node
{
	bool init(LinkList*& L);

	bool insert_font(LinkList*& L, LinkNode* node);
	bool push(LinkList*& L, LinkNode* node);
	bool insert(LinkList*& L, int pos, int& e);

	bool Joseph(LinkList*& L, int interval);

	bool get_elem(LinkList*& L, int pos, int& e);
	bool find_elem(LinkList*& L, int e);

	void print(LinkList*& L);

	void destory(LinkList*& L);
}

