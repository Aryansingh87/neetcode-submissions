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

ListNode* merging(ListNode* l1 , ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(l1!=NULL && l2!=NULL){
    if(l1->val < l2->val){
  temp->next = l1;
  temp = temp->next;
  l1 = l1->next;
  
    }else{
        temp->next = l2;
        temp = temp->next;
        l2 = l2->next;
        

    }
    }
    if(l1 == NULL){
        temp->next = l2;
        return dummy->next;
    }
    temp->next = l1;
    return dummy->next;
}
   ListNode* mergelist(vector<ListNode*>& lists , int st , int end){
    if(st == end){
        return lists[st];
    }
    int mid = st + (end - st)/2;
    ListNode* l1 = mergelist(lists ,st , mid);
    ListNode* l2 = mergelist(lists , mid+1 , end);
    return merging(l1 , l2);
   }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        return mergelist(lists , 0 , lists.size()-1);
    }
};
