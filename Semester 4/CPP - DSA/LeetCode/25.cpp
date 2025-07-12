// Reverse nodes in k-group

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            
            if (head == NULL || k == 1) return head; // Base case

            ListNode* dummy = new ListNode(0); // Dummy node to simplify the process
            dummy->next = head;
            ListNode* prevGroupEnd = dummy; // Pointer to the end of the previous group

            while (true) {
                ListNode* kthNode = prevGroupEnd; // Pointer to find the kth node
                for (int i = 0; i < k && kthNode != NULL; i++) {
                    kthNode = kthNode->next;
                }
                if (kthNode == NULL) break; // If there are less than k nodes left, break

                ListNode* groupStart = prevGroupEnd->next; // Start of the current group
                ListNode* groupEnd = kthNode->next; // End of the current group

                // Reverse the current group
                ListNode* prev = groupEnd;
                ListNode* curr = groupStart;
                while (curr != groupEnd) {
                    ListNode* nextTemp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextTemp;
                }

                // Connect the previous group's end to the current group's start
                prevGroupEnd->next = kthNode;
                // Connect the current group's start to the next group's end
                groupStart->next = groupEnd;

                // Move prevGroupEnd to the end of the reversed group
                prevGroupEnd = groupStart;
            }

            return dummy->next; // Return the new head of the list
        }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2;
    ListNode* result = s.reverseKGroup(head, k);

    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}