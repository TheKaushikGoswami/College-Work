/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* reverseList(ListNode* head) {

            if(head==NULL){
                return head;
            }

            ListNode* imd = NULL;
            ListNode* root = head;

            while(root!=NULL){
                ListNode* ptr = root->next;
                root->next = imd;
                imd = root;
                root = ptr;
            }

            return imd;
            
        }
    };