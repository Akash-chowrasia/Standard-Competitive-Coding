
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 300].
//     -100 <= Node.val <= 100
//     The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next)return head;
        ListNode* newNode = new ListNode(0), *temp = newNode, *temp1 = head, *temp2 = NULL;
        while(temp1)
        {
            int i = 1;
            temp2 = temp1->next;
            while(temp2 and temp2->val == temp1->val)
            {
                i++;
                temp2 = temp2->next;
            }
            if(i == 1)
            {
                temp->next = temp1;
                temp = temp->next;
            }
            temp1 = temp2;
        }
        temp->next = NULL;
        return newNode->next;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,3,3,4,4,5};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* ans = ob1.deleteDuplicates(l1);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }