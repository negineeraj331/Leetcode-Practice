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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode dummy(0, head);
        ListNode* prevGrp = & dummy;

        while(true){
            ListNode* kth = getKthNode(prevGrp, k);
            if(!kth) break;

            ListNode* nextGrp = kth->next;
            ListNode* prev = nextGrp;
            ListNode* curr = prevGrp->next;

            while(curr != nextGrp){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = prevGrp->next;
            prevGrp->next = kth;
            prevGrp = temp;
        }
        return dummy.next;
    }
    private:
        ListNode* getKthNode(ListNode* curr, int k){
            while(curr && k>0){
                curr=curr->next;
                k--;
            }
            return curr;
        }
};