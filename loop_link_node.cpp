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
    //在带头结点的循环链表 L 中，每个 interval 个间隔循环删除节点
    LinkList* now;
    int j = 0, i = 0;
    int times = 0, num = 0;
    LinkList* pre = L;
    if (!L || pre->next == L) {
        cout << "链表为空!" << endl;
        return false;
    }
    if (interval < 1) {
        cout << "报数淘汰口令不能小于 1!" << endl;
        return false;
    }
    do {
        i += interval;
        while (pre->next) //查找第 i 个结点，p 指向该结点的上一个节点
        {
            if (pre->next != L) j++;
            if (j >= i) break;
            pre = pre->next;
        }
        times++;

        if (!(pre->next)||(j>i))//当 i>n 或 i<1 时，删除位置不合理
            return false;
        now = pre->next; //临时保存被删结点的地址以备释放空间
        num = now->data;

        if (times == 5) cout << "第 5 个出圈的编号是：" << num << endl;
        printf("cur: %d last: %d next:%d\n", now->data, pre->data,
            now->next->data);

        pre->next = now->next; //改变删除结点前驱结点的指针域
        delete now; //释放被删除结点的空间
        print(L);
    } while (L->next != L);//链表不为空，继续报数
    cout << "最后一个出圈的编号是：" << num << endl;
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
