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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* head0;
        //NULL
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        head0 = head;
        while(true){
            if(l1 == NULL){
                head->next = l2;
                return head0;
            }
            if(l2 == NULL){
                head->next = l1;
                return head0;
            }
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }else{
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
    }
};
