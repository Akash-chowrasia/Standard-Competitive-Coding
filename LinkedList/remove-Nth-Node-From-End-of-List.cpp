// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Follow up: Could you do this in one pass?

 

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:

// Input: head = [1], n = 1
// Output: []

// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

 

// Constraints:

//     The number of nodes in the list is sz.
//     1 <= sz <= 30
//     0 <= Node.val <= 100
//     1 <= n <= sz



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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        ListNode *t1=head;
        int count=0;

        while(t1){
            t1=t1->next;
            count++;
        }

        count -= n;
        if(!count)
            return head->next;
        t1=head;

        while(--count)
            t1=t1->next;
        t1->next=t1->next->next;
        return head;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,3,4,5};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* ans = ob1.removeNthFromEnd(l1,2);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }