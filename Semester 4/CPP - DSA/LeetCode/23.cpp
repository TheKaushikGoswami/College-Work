// Merge k sorted lists

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

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
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            if (lists.empty()) return NULL; // If the list is empty, return NULL

            priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap; // Min-heap to store the nodes

            // Push the head of each list into the min-heap
            for (ListNode* list : lists) {
                if (list) {
                    minHeap.push({list->val, list});
                }
            }

            ListNode* dummy = new ListNode(0); // Dummy node to simplify the process
            ListNode* current = dummy; // Pointer to build the merged list

            while (!minHeap.empty()) {
                pair<int, ListNode*> top = minHeap.top(); // Get the smallest node
                minHeap.pop(); // Remove it from the heap

                current->next = new ListNode(top.first); // Add it to the merged list
                current = current->next; // Move to the next position in the merged list

                if (top.second->next) { // If there are more nodes in the same list, push it into the heap
                    minHeap.push({top.second->next->val, top.second->next});
                }
            }

            return dummy->next; // Return the merged list starting from the first real node
        }
};

int main(){
    Solution s;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);

    vector<ListNode*> lists = {head1, head2, head3};

    ListNode* mergedHead = s.mergeKLists(lists);

    // Print the merged list
    while (mergedHead) {
        cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;

    return 0;
}