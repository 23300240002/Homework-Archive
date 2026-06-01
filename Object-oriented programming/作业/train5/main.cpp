#pragma warning(disable: 4786)
#include <iostream>
#include <string>
using namespace std;
template <class T>
struct ListNode {
      ListNode *prev;
      ListNode *next;
      T data;
    ListNode() : prev(NULL), next(NULL), data() {}
    ListNode(const T& val) : prev(NULL), next(NULL), data(val) {}
  };
// 简化迭代器
template <typename T>
class Iterator {
private:
    ListNode<T>* node;
public:
    Iterator(ListNode<T>* n = NULL) : node(n) {}

    T& operator*() { return node->data; }

    Iterator& operator++() {
        node = node->next;
        return *this;
    }
    Iterator& operator--() {
        node = node->prev;
        return *this;
    }

    bool operator!=(const Iterator& other) { return node != other.node; }
};

template <class T>
class myList{ // list 由于需要插入、删除，因此本质是双向链表
private:
    ListNode<T>* head; // 头结点
    // head->next 是第一个元素，head->prev 是最后一个元素
public:
    myList() { // 默认构造函数，创建空链表，头节点指向自己
        // 头节点实际没有意义，第一个元素应当从 head->next 开始
        head = new ListNode<T>(); // new 创建头结点
        head->next = head;
        head->prev = head;
    }

    ~myList() { // 析构函数，释放内存
        clear(); // 先清空链表
        delete head; // 再把头结点也端了
    }

    void clear() { // 清空链表
        // 从第一个元素开始遍历删除每个节点，直到回到头结点
        ListNode<T>* cur = head->next;
        while (cur != head) { // 当还没有回到头结点时
            ListNode<T>* next = cur->next;
            delete cur;
            cur = next;
        }
        // 最后把头结点的指针重新指向自己，形成空链表
        head->next = head;
        head->prev = head;
    }

    // 在链表末尾添加元素
    void push_back(const T& val) {
        // 创建一个新节点，数据为 val
        ListNode<T>* node = new ListNode<T>(val);
        node->prev = head->prev; // 前驱是当前最后一个节点
        node->next = head; // 后继是头结点
        head->prev->next = node; // 当前最后一个节点的 next 指向新节点
        head->prev = node; // 头结点的 prev 指向新节点
    }
    
    // 头节点不算元素，所以 begin() 从 head->next 开始
    // end() 就是 head
    Iterator<T> begin() { return Iterator<T>(head->next); }
    Iterator<T> end() { return Iterator<T>(head); }

    // 遍历链表并打印元素
    void print() {
        // 由于在定义内部，因此不再需要 T.begin()，直接 begin() 就行了
        for (Iterator<T> it = begin(); it != end(); ++it) {
            cout << " " << *it;
        }
    }

    void sort() { // 排序
        if (head->next == head || head->next->next == head) {
            return; // 已经不用排了
        }
        // 冒泡排序简单操作，反正不是数据结构课，效率不重要
        bool swapped = true; // 是否发生过交换
        while (swapped) { // 只要发生过交换就再来一轮，否则说明换无可换，已经排好了
            swapped = false;
            ListNode<T>* cur = head->next;
            while (cur->next != head) {
                if (cur->data > cur->next->data) { // 交换数据
                    T tmp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = tmp;
                    swapped = true;
                }
                cur = cur->next; // 继续推进
            }
        }
    }
};

int main( )
{
   myList <int> t1;
   myList <string> t2;
   t1.push_back( 20 );
   t1.push_back( 10 );
   t1.push_back( 30 );

   cout << "Before sorting: c1 =";
   t1.print();
   cout << endl;

   t1.sort( );
   cout << "After sorting c1 =";
   t1.print();
   cout << endl;

    t2.push_back( string("Tom") );
    t2.push_back( string("Jame") );
    t2.push_back( string("Alice") );

    cout << "Before sorting: c1 =";
    t2.print();
    cout << endl;

    t2.sort( );
    cout << "After sorting c1 =";
    t2.print();
    cout << endl;

    return 0;
}
