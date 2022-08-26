#include "single_link_node.h"
#include "loop_link_node.h"
//using namespace single_link_node;
using namespace loop_link_node;

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

int main()
{
	//test_single_link_node();
	test_loop_link_node();
	return 0;
}