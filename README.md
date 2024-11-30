# 链表实现

这是一个链表实现的项目，包含了单向链表、双向链表和循环链表三种结构的实现，以及相关的操作函数。
该项目已经弃用，现在直接归档，作为数据结构实现的一种方式，2024年11月30日

## 代码结构

- `single_link_node.h`：单向链表相关的头文件
- `loop_link_node.h`：循环链表相关的头文件
- `bidirect_link_node.h`：双向链表相关的头文件
- `single_link_node.cpp`：单向链表相关的函数实现
- `loop_link_node.cpp`：循环链表相关的函数实现
- `bidirect_link_node.cpp`：双向链表相关的函数实现
- `main.cpp`：主函数以及测试用例

## 单向链表

### 数据结构

```c++
typedef struct LNode
{
    int data; // 数据域
    struct LNode* next; // 指针域
}LinkNode, * LinkList;
```

### 支持的操作

- 初始化链表 `init(LinkList& L)`
- 判断链表是否为空 `is_empty(LinkList L)`
- 在链表尾部插入元素 `push(LinkList& L, LinkNode* node)`
- 获取链表中指定位置的元素 `get_elem(LinkList L, int i, int& e)`
- 查找链表中指定元素的位置 `find_elem(LinkList L, int e)`
- 在链表中指定位置插入元素 `insert(LinkList& L, int i, int e)`
- 删除链表中指定位置的元素 `delete_elem(LinkList& L, int i)`
- 销毁链表 `destory(LinkList& L)`
- 打印链表 `print(LinkList L)`

## 循环链表

### 数据结构

```c++
typedef struct LNode
{
    int data; // 数据域
    struct LNode* next; // 指针域
}LinkNode, * LinkList;
```

### 支持的操作

- 初始化循环链表 `init(LinkList& L)`
- 判断循环链表是否为空 `is_empty(LinkList L)`
- 在循环链表尾部插入元素 `push(LinkList& L, LinkNode* node)`
- 约瑟夫问题求解 `Joseph(LinkList& L, int k)`
- 销毁循环链表 `destory(LinkList& L)`
- 打印循环链表 `print(LinkList L)`

## 双向链表

### 数据结构

```c++
typedef struct DLNode
{
    int data; // 数据域
    struct DLNode* prev; // 前驱指针
    struct DLNode* next; // 后继指针
}DoubleNode, * DoubleList;
```

### 支持的操作

- 初始化双向链表 `init(DoubleList* L)`
- 判断双向链表是否为空 `is_empty(DoubleList* L)`
- 在双向链表尾部插入元素 `push(DoubleList* L, DoubleNode* node)`
- 获取双向链表中指定位置的元素 `get_elem(DoubleList* L, int i, int& e)`
- 查找双向链表中指定元素的位置 `find_elem(DoubleList* L, int e)`
- 在双向链表中指定位置插入元素 `insert(DoubleList* L, int i, int e)`
- 删除双向链表中指定位置的元素 `delete_elem(DoubleList* L, int i)`
- 销毁双向链表 `destory(DoubleList* L)`
- 打印双向链表 `print(DoubleList* L)`

## 测试用例

在 `main.cpp` 文件中提供了测试用例，分别对单向链表、循环链表和双向链表进行了测试。

## 其他说明

- 本项目使用 C++ 语言编写。
- 本项目中提供了可供参考的实现方式，如果您有更好的实现方式可以进行替换。
- 本项目中提供的算法并不一定是最优解，仅供学习和参考使用。
