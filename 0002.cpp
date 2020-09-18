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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val;
        int carry=0;
        size_t container;
        int i;
        int dig;
        size_t exp;
        int die=0;
        ListNode *newNode=new ListNode(0);
        ListNode *out=newNode;
        while(1){
            container=carry;
            exp=1;
            for(i=0;i<18;i++){
                container+=(l1->val+l2->val)*exp;
                exp*=10;
                if(l1->next&&l2->next){
                    l1=l1->next;
                    l2=l2->next;
                }else{
                    if(l1->next){
                        die=2;
                    }else if(l2->next){
                        die=1;
                    }else{
                        die=3;
                    }
                    i++;
                    break;
                }
            }
            while(i--){
                dig=container%10;
                newNode->next=new ListNode(dig);
                newNode=newNode->next;
                container/=10;
            }
            carry=container;
            switch(die){
                case 0:
                    break;
                case 1:
                    while(carry&&l2->next){
                        l2=l2->next;
                        val=l2->val;
                        newNode->next=new ListNode((val+1)%10);
                        carry=val==9?1:0;
                        newNode=newNode->next;
                    }
                    if(carry){
                        newNode->next=new ListNode(1);
                    }else{
                        newNode->next=l2->next;
                    }
                    return out->next;
                case 2:
                    while(carry&&l1->next){
                        l1=l1->next;
                        val=l1->val;
                        newNode->next=new ListNode((val+1)%10);
                        carry=val==9?1:0;
                        newNode=newNode->next;
                    }
                    if(carry){
                        newNode->next=new ListNode(1);
                    }else{
                        newNode->next=l1->next;
                    }
                    return out->next;
                case 3:
                    if(carry){
                        newNode->next=new ListNode(1);
                    }
                    return out->next;                    
            }
        }
    }
};

