/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        odd->next = even->next;
        even->next = odd;
        head = even;
        while(odd->next != NULL){
            odd = odd->next;
            if(odd->next == NULL){
                return head;
            }
            even->next->next = odd->next;
            even = odd->next;
            odd->next = even->next;
            even->next = odd;
        }
        return head;
    }
};
