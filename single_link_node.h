#pragma once
#include "list_def.h"
namespace single_link_node
{
	bool init(LinkList*& L);

	bool insert_font(LinkList*& L, LinkNode* node);
	bool push(LinkList*& L, LinkNode* node);
	bool insert(LinkList*& L, int pos, int& e);

	bool delete_elem(LinkList*& L, int pos);

	bool get_elem(LinkList*& L, int pos, int& e);
	bool find_elem(LinkList*& L, int e);

	void print(LinkList*& L);

	void destory(LinkList*& L);
}

