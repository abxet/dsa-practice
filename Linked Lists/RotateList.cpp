// leetcode 61
// implement linked list
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

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // retrun if list is empty
         if (!head || !head->next || k == 0) return head;
        // create a curr node
        ListNode * curr = head;

        // move to last also find lenght
        int l = 1;
        while (curr -> next) {
            curr = curr -> next;
            l++;
        }

        // make ring 
        curr -> next = head;

        // adjust value of k 
        k %= l;
        if (k == 0) {
            curr->next = nullptr; // break the ring back
            return head;
        }

        // find the new last node
        int t = l - k - 1;

        // craete a last node
        ListNode * last = head;

        // move to new last 
        for (int i = 0; i < t; i++) {
            last = last -> next;
        }
        // create a start
        ListNode * start = last -> next;

        // break the ring
        last -> next = nullptr;

        return start;

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
    ListNode *fifth = new ListNode(5, nullptr);
    ListNode *forth = new ListNode(4, fifth);
    ListNode *third = new ListNode(3, forth);
    ListNode *second = new ListNode(2, third);
    ListNode *first = new ListNode(1, second);

    int k = 2;

    Solution s;

    cout << "\nInput: head = ";
    printListNode(first);
    cout << ", k = " << k;
    ListNode *res = s.rotateRight(first, k);
    cout << "\nOutput: ";
    printListNode(res);

    return 0;
}
