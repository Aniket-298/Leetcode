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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // unordered_map<ListNode*,int>m;
        vector<int>vec;
        ListNode* temp=head;
        int i=1;
        while(temp->next->next!=NULL){
            ListNode* prev=temp;
            if(prev->val< temp->next->val && temp->next->val > temp->next->next->val){
                vec.push_back(i);
            }
            else if(prev->val > temp->next->val && temp->next->val
             < temp->next->next->val){
                vec.push_back(i);
            }
            i++;
            temp=temp->next;
        }
        sort(vec.begin(),vec.end());
        int n=vec.size();
        if(vec.size()<2) return {-1,-1};
        int minDist=INT_MAX;
        int maxDist=vec[n-1]-vec[0];
        for(int i=0;i<vec.size()-1;i++){
            int j=i+1;
            minDist=min(vec[j]-vec[i],minDist);
        }
        return {minDist,maxDist};
    }
};