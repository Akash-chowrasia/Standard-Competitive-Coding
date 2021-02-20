// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:

// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:

// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

 

// Constraints:

//     The number of the nodes in the list is in the range [0, 104].
//     -105 <= Node.val <= 105
//     pos is -1 or a valid index in the linked-list.

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

    void LoopMaker(ListNode* head, int loop_at){
        if(loop_at == -1)return;
        ListNode* loopNode = NULL;
        ListNode *temp = head;
        while(temp->next){
            loop_at--;
            if(loop_at == -1){
                loopNode = temp;
            }
            temp = temp->next;
        }
        temp->next = loopNode;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return false;
        vector<ListNode*> a;
        ListNode *temp = head;
        while(temp->next){
            a.push_back(temp);
            temp = temp->next;
            for(int i=0; i<a.size();i++){
                if(a[i]==temp)return true;
            }
        }
        return false;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,3,3,4,4,5};
    int loop_at = 2;
    ListNode* l1 = ob.CreateList(a1);
    ob.LoopMaker(l1, loop_at);
    bool ans = ob1.hasCycle(l1);
    cout << ans;
    cout << "\n";
    return 0;
  }