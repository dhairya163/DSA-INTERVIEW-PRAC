// https://leetcode.com/problems/rotate-list/


//Given the head of a linked list, rotate the list to the right by k places.



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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        ListNode* start = head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        int rotation = k%count;
        
        if(rotation == 0){
            return head;
        }
        
        temp = head;
        
        int move = count - rotation ;
        
        ListNode* temp2;
        
        while(move--){
            temp2=temp;
            temp = temp->next;
        }
        
        temp2->next = NULL;
        
        head = temp;
         
        while(rotation>1){
            temp=temp->next;
            rotation--;
        }
        
        temp->next = start;
        
        return head;
    }
};
