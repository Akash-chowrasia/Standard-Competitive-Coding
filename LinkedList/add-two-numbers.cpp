// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their
// nodes contains a single digit. Add the two numbers and return the sum
// as a linked list.

// You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

#include<iostream>
#include<vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL and l2 == NULL) return NULL;
        else if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        int a = l1->val + l2->val;
        ListNode *p = new ListNode(a % 10);
        p->next = addTwoNumbers(l1->next,l2->next);
        if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
        return p;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {2,3,4};
    vector<int> a2 = {5,6,4};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* l2 = ob.CreateList(a2);
    ListNode* ans = ob1.addTwoNumbers(l1,l2);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }
