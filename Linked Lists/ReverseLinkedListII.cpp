#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode* node) {
    ListNode* curr = node;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // 1️. Move prev to the node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // 2️. Start reversal
        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        // 3️. Reverse the sublist [left, right]
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};

int main() {
    // create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* first  = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third  = new ListNode(3);
    ListNode* forth  = new ListNode(4);
    ListNode* fifth  = new ListNode(5);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout << "Original List:\n";
    printListNode(first);

    Solution s;
    ListNode* rev = s.reverseBetween(first, 2, 4);

    cout << "Reversed List (2 to 4):\n";
    printListNode(rev);

    return 0;
}
