/*
https://leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


생각해야할 케이스 : 두 number의 길이가 다를 경우, carry 처리
발생한 Errors: 1)list pointer 처리 미숙 2)while loop 종료 후 carry ==1 일때 처리 빠뜨림 3)자리수 다를때 in loop에서 처리 미숙 

line 43: num = (num) % 10; 을 (num+carry)로 해둬서 carry를 두번 더하는 실수를 범했는데
이를 못찾아서 1시간 소비... 자책으로 끝낼수도있으나, 사실 근본 원인은 알고보면 의사코드를 제대로 정리하지 않고
코드를 컴파일러로 디버깅해가며 이라인 저라인 고쳐갔기 때문에 전체 code flow를 머리속에 제대로 정립하지 못했기 때문.

절대, 그냥 1라인 "실수"로 잘못 코딩한게 아니라 코딩습관의 문제가 그대로 드러난 것. 반성.

*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* ptr_l1 = l1;
        ListNode* ptr_l2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry = 0;
        int num = 0;
           
        while(1) {
            if(ptr_l1 != NULL && ptr_l2 == NULL) {
                num = ptr_l1->val + carry;
                
                ptr_l1 = ptr_l1->next;
            } else if(ptr_l1 == NULL && ptr_l2 != NULL){
                num = ptr_l2->val + carry;
                
                ptr_l2 = ptr_l2->next;
            } else if(ptr_l1 != NULL && ptr_l2 != NULL) {   
                num = ptr_l1->val + ptr_l2->val + carry;
                
                ptr_l1 = ptr_l1->next;
                ptr_l2 = ptr_l2->next;
            }
            
            if(num >= 10) {
                num = (num) % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            
            cur->val = num;
            
            if(ptr_l1 == NULL && ptr_l2 == NULL) {
                if(carry == 1) {
                    ListNode* node = new ListNode(carry);
                    cur->next = node;
                } else {
                    cur = NULL;
                }
        
                break;
            } else {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }//end while
        
        
        return head;
    }
};

