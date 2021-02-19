
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:

// Input: lists = []
// Output: []

// Example 3:

// Input: lists = [[]]
// Output: []

 

// Constraints:

//     k == lists.length
//     0 <= k <= 10^4
//     0 <= lists[i].length <= 500
//     -10^4 <= lists[i][j] <= 10^4
//     lists[i] is sorted in ascending order.
//     The sum of lists[i].length won't exceed 10^4.



#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class ListMaker{
    
    public:

    ListNode* CreateList(vector<int> &arr){
        ListNode* dummynode = new ListNode(0);
        ListNode* temp = dummynode;
        for(int i=0; i<arr.size(); i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummynode->next;
    }

    void PrintList(ListNode* head){
        ListNode* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }

};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> v;
        vector<int> v1;
        for(int i=0;i<lists.size();i++){
            ListNode *temp = lists[i];
            while(temp){
                v.push_back(temp);
                v1.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(v1.begin(),v1.end());
        ListNode *newhead = new ListNode(INT_MIN), *node = newhead;
        for(int i=0; i<v1.size();i++){
            ListNode *temp = newhead;
            int j=0;
            while(temp->val != v1[i]){
                temp = v[j++];
            }
            node->next = temp;
            node = node->next;
            v[j-1] = newhead;
        }
        node->next = NULL;
        return newhead->next;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,5};
    vector<int> a2 = {1,3,4};
    vector<int> a3 = {2,6};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* l2 = ob.CreateList(a2);
    ListNode* l3 = ob.CreateList(a3);
    vector<ListNode*> arr = {l1,l2,l3};
    ListNode* ans = ob1.mergeKLists(arr);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }