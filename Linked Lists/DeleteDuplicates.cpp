// Leetcode. Remove Duplicates from Sorted List 
#include<iostream>

using namespace std;
// linked list definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// print linked list
void printListNode(ListNode* node) {
    ListNode* curr = node;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}
// solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* curr = dummy;
        
        // traverse the linked list 
        while ( curr != nullptr )
        {
            if((curr -> next != nullptr)&&( curr -> val == curr -> next ->val )) {
                curr -> next = curr -> next -> next;
            }
            curr = curr -> next;
        }
        
        // return the head
        return dummy -> next;
    }
};

int main() {
    // create list: 1 -> 2 -> 2 -> 3 -> 3
    ListNode* first  = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third  = new ListNode(2);
    ListNode* forth  = new ListNode(3);
    ListNode* fifth  = new ListNode(3);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout << "Original List:\n";
    printListNode(first);

    Solution s;
    ListNode* res = s.deleteDuplicates(first);

    cout << "Result :\n";
    printListNode(res);

    return 0;
}


