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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        int count = 0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }
      
        if(n == count){
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        
        int idxToDelete = count - n;
        temp = head;

        for(int i=1;i<idxToDelete;i++){
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};