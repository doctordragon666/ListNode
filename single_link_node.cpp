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
	}//��λ��ǰһ��λ��
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
	//�ڴ�ͷ���ĵ����� L �У�ɾ���� i ��λ��
	LinkList* p = L;
	int j = 0;
	while ((p->next) && (j < pos - 1)) //���ҵ� i-1 ����㣬p ָ��ý��
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || (j > pos - 1))//�� i>n �� i<1 ʱ��ɾ��λ�ò�����
		return false;
	LinkList* q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷſռ�

	p->next = q->next; //�ı�ɾ�����ǰ������ָ����
	delete q; //�ͷű�ɾ�����Ŀռ�
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
	p = p->next;//����ͷ�ڵ�
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
	cout << "��������" << endl;

	while (p)
	{
		L = L->next;
		cout << "ɾ��Ԫ��" << p->data << endl;
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