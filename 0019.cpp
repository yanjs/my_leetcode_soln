/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int i;
        for(i=0;i<n;i++){
            curr = curr->next;
        }
        if(curr == NULL){
            return head->next;
        }
        //curr!=NULL, lcurr!=NULL
        ListNode* lcurr = head;
        while(true){
            curr = curr->next;
            if(curr == NULL){
                lcurr->next = lcurr->next->next;
                return head;
            }
            lcurr = lcurr->next;
        }
        return NULL;
    }
};
