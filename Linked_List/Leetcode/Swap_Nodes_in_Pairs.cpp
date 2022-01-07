
// https://leetcode.com/problems/swap-nodes-in-pairs/

//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

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
    ListNode* swapPairs(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        
        if(head== NULL || head->next == NULL){
            return head;
        }
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        ListNode* evens[100]={NULL};
        ListNode* odds[100]={NULL};
        
        int i=0;
        int j=0;
        
        while(temp1!=NULL){
          evens[i++] = temp1;  
            
          if(temp1 -> next != NULL){
          temp1 = temp1 -> next ->next;
          }
          else{
              temp1 = temp1 -> next;
          }
        }
        
        temp2 = temp2->next;
        
        while(temp2!=NULL){
          odds[j++] = temp2;  
            
          if(temp2 -> next != NULL){
          temp2 = temp2 -> next ->next;
          }
          else{
              temp2 = temp2 -> next;
          }
        }
        
        i=0;
        j=0;
        
        while (evens[i] != NULL && odds[j] != NULL){
            odds[j]->next = evens[i];
            j++;
            evens[i]->next = odds[j];
            i++;
        }
        if(evens[i] != NULL){
            evens[i-1]->next = evens[i];
        }
        
        return odds[0];
    }
};
