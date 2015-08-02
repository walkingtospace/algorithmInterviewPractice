/**
 * https://leetcode.com/problems/add-two-numbers/
 * 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * questions
 * 1. Are those numbers the same number of digits? -> no  
 * 2. the number of digits of the sum can be different?! -> yes. e.g., 1+999 = 1000
 * 
 * insights
 * 1. the key point is how to handle the carry
 * 2. 
 * 
 * edge cases
 * 1. 206 + 0 or 00?
 * 2. 0 + 0 = 0.
 * 3. In case there are multiple carries
 * 
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        int cnt = 0;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL) {
            int sum = 0;
            
            if(l1 != NULL && l2 != NULL) {
                sum = l1->val + l2->val + carry;
                
                l1 = l1->next;
                l2 = l2->next;
                
            } else if(l1 != NULL){ // one of 11 and l2 is null
                sum = l1->val + carry;
                
                l1 = l1->next;
            } else if(l2 != NULL) {
                sum = l2->val + carry;
                
                l2 = l2->next;
            }
            
            carry = 0;
            
            if(sum >= 10) {
                carry = 1;
                sum %= 10;
            }
                
            res->next = new ListNode(sum);
            res = res->next;
        }
        
        if(carry == 1) {
            ListNode *item = new ListNode(carry);
            res->next = item;
        }
        
        return head->next;
    }
};
