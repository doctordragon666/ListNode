#pragma once
#include "list_def.h"

namespace bidirect_link_node
{
	bool init(DoubleList*& L);
	bool init(DoubleNode& head);

	bool insert_font(DoubleList*& L, DoubleNode* node);
	bool push(DoubleList*& L, DoubleNode* node);
	bool insert(DoubleList*& L, int pos, int& e);

	bool delete_elem(DoubleList*& L, int pos);

	bool get_elem(DoubleList*& L, int pos, int& e);
	bool find_elem(DoubleList*& L, int e);

	void print(DoubleList*& L);

	void destory(DoubleList*& L);
}