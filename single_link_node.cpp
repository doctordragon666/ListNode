#include "single_link_node.h"

bool single_link_node::insert_font(LinkList*& L, LinkNode* node)
{
	if (!L || !node)return false;

	node->next = L->next;
	L->next = node;

	return false;
}

bool single_link_node::push(LinkList*& L, LinkNode* node)
{
	if (!L || !node)return false;

	LinkNode* last = L;
	while (last->next)last = last->next;

	node->next = nullptr;
	last->next = node;
	return true;
}

bool single_link_node::insert(LinkList*& L, int pos, int& e)
{
	LinkList* last = L;
	int count = 1;
	while (last && count < pos - 1)
	{
		last = last->next;
		count++;
	}//定位到前一个位置
	if (!last || count > pos - 1)return false;

	LinkNode* s = new LinkNode;
	if (!s)return false;
	s->data = e;
	s->next = last->next;
	last->next = s;
	return true;
}

bool single_link_node::delete_elem(LinkList*& L, int pos)
{
	//在带头结点的单链表 L 中，删除第 i 个位置
	LinkList* p = L;
	int j = 0;
	while ((p->next) && (j < pos - 1)) //查找第 i-1 个结点，p 指向该结点
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || (j > pos - 1))//当 i>n 或 i<1 时，删除位置不合理
		return false;
	LinkList* q = p->next; //临时保存被删结点的地址以备释放空间

	p->next = q->next; //改变删除结点前驱结点的指针域
	delete q; //释放被删除结点的空间
	return true;
}

bool single_link_node::get_elem(LinkList*& L, int pos, int& e)
{
	LinkList* p = L->next;
	int count = 1;

	while (count < pos && p)
	{
		p = p->next;
		count++;
	}

	if (!p || count > pos)return false;

	e = p->data;
	return true;
}

bool single_link_node::find_elem(LinkList*& L, int e)
{
	LinkList* p = L->next;
	while (p && p->data != e)p = p->next;
	return p ? true : false;
}

void single_link_node::print(LinkList*& L)
{
	LinkList* p = L;
	p = p->next;//跳过头节点
	while (p)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "tail" << endl;
}

void single_link_node::destory(LinkList*& L)
{
	LinkList* p = L;
	cout << "销毁链表" << endl;

	while (p)
	{
		L = L->next;
		cout << "删除元素" << p->data << endl;
		delete p;
		p = L;
	}
}

bool single_link_node::init(LinkList*& L)
{
	L = new LinkNode;
	if (!L) return false;
	L->next = nullptr;
	return true;
	return false;
}