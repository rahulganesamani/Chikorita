/*
2. Add Two Numbers
Medium
27K
5.2K
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* result = NULL;
        int a, b, c, value;
        int carry = 0;
        while ( tmp1 != NULL || tmp2 != NULL ) {
            a = 0;
            b = 0;
            if( tmp1 == NULL ) {
                b = tmp2->val;
                tmp2 = tmp2->next;
            }
            else if( tmp2 == NULL ) {
                a = tmp1->val;
                tmp1 = tmp1->next;
            }
            else {
                a = tmp1->val;
                b = tmp2->val;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            value = ( a + b + carry ) % 10  ;
            carry = ( a + b + carry ) / 10;
            cout << value << " ";
            ListNode* newNode = new ListNode;
            newNode->val = value;
            newNode->next = NULL;
            if(result == NULL) {
                result = newNode;
            }
            else {
                ListNode* current = result;
                while( current->next != NULL ) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        if ( carry != 0 ) {
            ListNode* newNode = new ListNode;
            newNode->val = carry;
            newNode->next = NULL;
            ListNode* current = result;
            while( current->next != NULL ) {
                current = current->next;
            }
            current->next = newNode;
        }
        return result;
    }
};
