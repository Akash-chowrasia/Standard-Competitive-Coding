// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 500].
//     -100 <= Node.val <= 100
//     0 <= k <= 2 * 109


// Given a linked list, swap every two adjacent nodes and return its head.

 

// Example 1:

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:

// Input: head = []
// Output: []

// Example 3:

// Input: head = [1]
// Output: [1]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 100].
//     0 <= Node.val <= 100

 
// Follow up: Can you solve the problem without modifying the values in the list's nodes? (i.e., Only nodes themselves may be changed.)

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k)return head;
        ListNode *temp = head,*t=NULL;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(k%len==0)return head;
        temp = head;
        k = len - k%len-1;
        while(k--){
            temp = temp->next;
        }
        t = temp->next;
        temp->next = NULL;
        temp = t;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return t;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,3,4,5};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* ans = ob1.rotateRight(l1,2);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }