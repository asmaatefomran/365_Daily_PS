//Day 1    5/5/2026
//https://leetcode.com/problems/rotate-list/description/

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
        int size = 1;
        auto currNode = head;
        auto end = head;
        if (!head || !head->next) return head;
        while(currNode->next!=NULL){
            size++;
            currNode = currNode->next;
        }
        end = currNode;
        k%=size;

        if(k==0)return head;
        else{
            int i=1;
            currNode=head;
            while(i!=size-k){
                i++;
                currNode = currNode->next;
            }
            end->next = head;
            head = currNode->next;
            currNode->next = NULL;
            return head;
        }
        
    }
};
