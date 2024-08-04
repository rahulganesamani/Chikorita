/*
21. Merge Two Sorted Lists
Easy
19.1K
1.8K
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

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

    void insertAtEnd( ListNode*& head, int value ) {
        ListNode* newNode = new ListNode;
        newNode->val = value;
        newNode->next = NULL;
        if ( head == NULL ) {
            head = newNode;
        }
        else {
            ListNode* current = head;
            while ( current->next != NULL ) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if ( list1 == NULL || list2 == NULL ) {
            if ( list1 != NULL ) {
                return list1;
            }
            else if ( list2 != NULL ) {
                return list2;
            }
            else {
                return list1;
            }
        }

        ListNode* result = NULL;
        ListNode* l1_ptr = list1;
        ListNode* l2_ptr = list2;
        while ( l1_ptr != NULL && l2_ptr != NULL ) {
            if ( l1_ptr->val <= l2_ptr->val ) {
                insertAtEnd( result, l1_ptr->val );
                l1_ptr = l1_ptr->next;
            }
            else {
                insertAtEnd( result, l2_ptr->val );
                l2_ptr = l2_ptr->next;
            }
        }
        while ( l1_ptr != NULL ) {
            insertAtEnd( result, l1_ptr->val );
            l1_ptr = l1_ptr->next;
        }
        while ( l2_ptr != NULL ) {
            insertAtEnd( result, l2_ptr->val );
            l2_ptr = l2_ptr->next;
        }
        return result;
    }
};
