// implement linked list
#include <iostream>
using namespace std;
// define linked list
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

void printListNode (ListNode* node) {
    ListNode* curr = node;
    while (node != nullptr)
    {
        /* code */
        cout << curr -> val << endl;
        curr = curr -> next;
        
    }
    
}

int main () {
    ListNode* last = new ListNode(3);
    ListNode* mid = new ListNode(2, last);
    ListNode* first = new ListNode(1, mid);

    printListNode(first);
    return 0;
}
