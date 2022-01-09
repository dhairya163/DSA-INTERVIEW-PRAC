// https://leetcode.com/problems/linked-list-random-node/
  
/* Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the integer array nums.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be choosen.
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

// USED RESERVOIR SAMPLING 
//https://en.wikipedia.org/wiki/Reservoir_sampling

class Solution {
public:
    
    ListNode* heads = NULL;
    
    Solution(ListNode* heads) {
        this->heads = heads;
    }
    
    int getRandom() {
        ListNode* temp = heads;
        int result = temp->val;
        int i = 1;
        while(temp!=NULL){
            if(rand() % i == 0){
                result = temp->val;
            }
            temp=temp->next;
            i++;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
