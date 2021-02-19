
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
#include<queue>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head, *newnode = new ListNode(0), *node = newnode;
        queue<ListNode*> q1;
        queue<ListNode*> q2;
        bool flag = false;
        while(temp){
            if(!flag){
                q1.push(temp);
            }
            if(flag){
                q2.push(temp);
            }
            flag = !flag;
            temp = temp->next;
        }
        flag = false;
        while(!q1.empty() || !q2.empty()){
            if(!flag && !q2.empty()){
                node->next = q2.front();
                node = node->next;
                q2.pop();
            }
            if(flag && !q1.empty()){
                node->next = q1.front();
                node = node->next;
                q1.pop();
            }
            flag = !flag;
        }
        node->next = NULL;
        return newnode->next;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,3,4,5};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* ans = ob1.swapPairs(l1);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }