// cpp Test Data Structure: Linked List
#include"linked_list.h"

int main(){
    LinkedList LL;
    LL.PrintList();
    LL.Push_back(1);
    LL.PrintList();
    LL.Push_front(2);
    LL.PrintList();
    LL.Push_back(3);
    LL.PrintList();
    LL.Push_front(4);
    LL.PrintList();
    LL.Reverse();
    LL.PrintList();
    LL.Delete(2);
    LL.PrintList();
    LL.Delete(4);
    LL.PrintList();
    LL.Delete(3);
    LL.PrintList();
    LL.Delete(0);
    LL.PrintList();
    return 0;
}