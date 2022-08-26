#include "loop_link_node.h"

bool loop_link_node::init(LinkList*& L)
{
    L = new LinkNode;
    if (!L)return false;

    L->next = L;
    L->data = -1;
    return true;
}

bool loop_link_node::insert_font(LinkList*& L, LinkNode* node)
{
    return false;
}

bool loop_link_node::push(LinkList*& L, LinkNode* node)
{
    LinkNode* last = nullptr;
    if (!L || !node)return false;
    last = L;
    while (last->next != L)last = last->next;
    node->next = L;
    last->next = node;
    return true;
}

bool loop_link_node::insert(LinkList*& L, int pos, int& e)
{
    return false;
}

bool loop_link_node::Joseph(LinkList*& L, int interval)
{
    //�ڴ�ͷ����ѭ������ L �У�ÿ�� interval �����ѭ��ɾ���ڵ�
    LinkList* now;
    int j = 0, i = 0;
    int times = 0, num = 0;
    LinkList* pre = L;
    if (!L || pre->next == L) {
        cout << "����Ϊ��!" << endl;
        return false;
    }
    if (interval < 1) {
        cout << "������̭�����С�� 1!" << endl;
        return false;
    }
    do {
        i += interval;
        while (pre->next) //���ҵ� i ����㣬p ָ��ý�����һ���ڵ�
        {
            if (pre->next != L) j++;
            if (j >= i) break;
            pre = pre->next;
        }
        times++;

        if (!(pre->next)||(j>i))//�� i>n �� i<1 ʱ��ɾ��λ�ò�����
            return false;
        now = pre->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷſռ�
        num = now->data;

        if (times == 5) cout << "�� 5 ����Ȧ�ı���ǣ�" << num << endl;
        printf("cur: %d last: %d next:%d\n", now->data, pre->data,
            now->next->data);

        pre->next = now->next; //�ı�ɾ�����ǰ������ָ����
        delete now; //�ͷű�ɾ�����Ŀռ�
        print(L);
    } while (L->next != L);//����Ϊ�գ���������
    cout << "���һ����Ȧ�ı���ǣ�" << num << endl;
    return true;
}

bool loop_link_node::get_elem(LinkList*& L, int pos, int& e)
{
    return false;
}

bool loop_link_node::find_elem(LinkList*& L, int e)
{
    return false;
}

void loop_link_node::print(LinkList*& L)
{
    LinkList* head = L;
    while (head->next != L)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "->-1\n";
}

void loop_link_node::destory(LinkList*& L)
{
}
