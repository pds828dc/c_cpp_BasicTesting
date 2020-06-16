// Data structure test: linked list
#include <iostream>
using namespace std;

class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
private:
    // int data;
    // ListNode *next;
public:
    int data;
    ListNode *next;
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode *first;            // list的第一個node
    ListNode *end;              // list的最後一個node
public:
    LinkedList():first(0), end(0){};
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
   // void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
    ListNode *getHead();
};
void LinkedList::PrintList(){
    ListNode *Current = first;
    if(Current == 0)    {
        cout << "there is nothing here !!!\n";
    }
    while(Current!=0){
        cout << Current->data;
        if(Current->next!=0){
            cout << ",";
        }
        else{
            cout << endl;
        }
        Current = Current->next;
    }
}
void LinkedList::Push_back(int value){
    ListNode *NewNode = new ListNode(value);
    if(end == 0){/////////////////
        first = NewNode;
        end = NewNode;
    }
    else{
    end->next = NewNode;
    end = NewNode;  
    }
}
void LinkedList::Push_front(int value){
    ListNode *NewNode = new ListNode(value);
    if(first==0){/////////////////////
        first = NewNode;
        end = NewNode;
    }
    NewNode->next = first;
    first = NewNode;
}
void LinkedList::Delete(int target){
    ListNode *PreviousNode = 0;
    ListNode* CurrentNode = first;
    while(CurrentNode!=0&&CurrentNode->data!=target){   ////////////////////
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->next;
    }
    if(CurrentNode==0){
        cout << "There is no value == " << target << "!!" << endl;
    }
    else if(CurrentNode==first){
        first = CurrentNode->next;
        delete CurrentNode;
        CurrentNode = 0;
    }
    else{
        PreviousNode->next = CurrentNode->next;
        delete CurrentNode;
        CurrentNode = 0;
    }
}
void LinkedList::Reverse(){
    if(first == 0||first->next==0)
    {
        cout << "The number of node must be larger then two for reversing !!" << endl;
        return;
    }
    ListNode *CurrentNode = first;
    ListNode *Previous = 0;
    ListNode *Preceding = CurrentNode->next;
    end = first;
    while(Preceding!=0){
        CurrentNode->next = Previous;    ///////////////
        Previous = CurrentNode;
        CurrentNode = Preceding;
        Preceding = Preceding->next;
    }
    CurrentNode->next = Previous;
    first = CurrentNode;
}
ListNode* LinkedList::getHead(){
    return first;
}
