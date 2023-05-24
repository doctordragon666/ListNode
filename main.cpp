#include "single_link_node.h"
#include "loop_link_node.h"
#include "bidirect_link_node.h"
//using namespace single_link_node;
using namespace loop_link_node;
using namespace bidirect_link_node;

typedef struct {
	int fd;
	time_t timeout;
	DoubleNode node;
}ConnTimeout;

void test_single_link_node()
{
	//1.��ʼ������
	LinkList* head = nullptr;
	init(head);

	//2.��������
	for (int i = 0; i < 10; i++)
	{
		LinkNode* node = new LinkNode;
		node->data = i;
		node->next = nullptr;
		push(head, node);
	}
	print(head);

	//��ȡԪ��
	int num = -1;
	int pos = 10;
	if (get_elem(head, pos, num))
	{
		cout << "find num " << num << endl;
		insert(head, pos + 2, num);
	}
	print(head);

	//����Ԫ��
	int target = 8;
	if (find_elem(head, target))
	{
		cout << "exist " << target << endl;
	}

	//ɾ��Ԫ��
	single_link_node::delete_elem(head, 5);
	print(head);

	//��������
	destory(head);
}

void test_loop_link_node()
{
	LinkList* head = nullptr;
	init(head);
	print(head);

	for (int i = 0; i < 10; i++)
	{
		LinkNode* node = new LinkNode;
		node->data = i;
		node->next = nullptr;
		push(head, node);
	}

	print(head);

	Joseph(head, 5);
}

void test_bidirect_link_node()
{
	DoubleList* head = new DoubleList;
	init(head);
	print(head);

	for (int i = 0; i < 10; i++)
	{
		DoubleNode* node = new DoubleNode;
		node->data = i;
		node->next = nullptr;
		push(head, node);
	}

	print(head);

	//��ȡԪ��
	int num = -1;
	int pos = 10;
	if (get_elem(head, pos, num))
	{
		cout << "find num " << num << endl;
		insert(head, pos + 2, num);
	}
	print(head);

	//����Ԫ��
	int target = 8;
	if (find_elem(head, target))
	{
		cout << "exist " << target << endl;
	}

	//ɾ��Ԫ��
	delete_elem(head, 5);
	print(head);

	//��������
	destory(head);
}

bool DbListInsert_back(DoubleNode
	& L, DoubleNode
	& node) {
	DoubleNode* last = NULL;
	last = &L;
	while (last->next) last = last->next;
	node.next = NULL;
	last->next = &node;
	node.prev = last;
	return true;
}

int main()
{
	//test_single_link_node();
	test_loop_link_node();
	//test_bidirect_link_node();

	////1.����һ��������
	//ConnTimeout* c1 = new ConnTimeout;
	//c1->fd = -1;
	//init(c1->node);

	////2.��������
	//int n = 10;

	//ConnTimeout* temp = nullptr;
	//while (n > 0)
	//{
	//	temp = new ConnTimeout;
	//	temp->fd = rand() & 10;
	//	printf("s �ĵ�ַ:%p  node:%p\n", temp, &(temp->node));
	//	DbListInsert_back(c1->node, temp->node);
	//	n--;
	//}

	////3.�����������
	//DoubleNode* p = nullptr;
	//p = &(c1->node);
	//cout << "\n�������ӳ�ʱ�ڵ�\n";

	//while (p)
	//{
	//	int offset = offsetof(ConnTimeout, node);
	//	ConnTimeout* ct = ((ConnTimeout*)((size_t)p - offset));
	//	cout << ct->fd << "->";
	//	p = p->next;
	//}
	//cout << "end\n";

	////4.��������
	//p = &(c1->node);
	//cout << "\n�������ӳ�ʱ�ڵ�\n";

	//while (p)
	//{
	//	int offset = offsetof(ConnTimeout, node);
	//	ConnTimeout* ct = ((ConnTimeout*)((size_t)p - offset));
	//	printf("offset:%u ct: %p p:%p\n", offset, ct, p);
	//	cout << ct->fd << endl;
	//	p = p->next;
	//	delete ct;
	//}

	//system("pause");
	//return 0;
}