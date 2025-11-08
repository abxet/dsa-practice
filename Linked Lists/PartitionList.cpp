// leetcode 86
#include <iostream>
using namespace std;
// define linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(0);
        ListNode* larger = new ListNode(0);
        
        ListNode* small = smaller;
        ListNode* large = larger;

        while (head != nullptr) {
            if (head -> val < x) {
                small -> next = head;
                small = small -> next;
            } else {
                large -> next = head;
                large = large -> next;
            }
            head = head -> next;
        }

        small -> next = larger -> next;
        large -> next = nullptr;

        return smaller -> next;
    }
    
};

void printListNode(ListNode *node)
{
    ListNode *curr = node;
    cout << "[" << curr->val;
    curr = curr->next;
    while (curr != nullptr)
    {
        cout << ", " << curr->val;
        curr = curr->next;
    };
    cout << "]";
}

int main()
{
    ListNode *fifth = new ListNode(1, nullptr);
    ListNode *forth = new ListNode(2, fifth);
    ListNode *third = new ListNode(3, forth);
    ListNode *second = new ListNode(4, third);
    ListNode *first = new ListNode(5, second);

    int x = 2;

    Solution s;

    cout << "\nInput: head = ";
    printListNode(first);
    cout << ", x = " << x;
    ListNode *res = s.partition(first, x);
    cout << "\nOutput: ";
    printListNode(res);

    return 0;
}
