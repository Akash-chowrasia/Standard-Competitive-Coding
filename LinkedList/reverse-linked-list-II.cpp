
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

 

// Constraints:

//     The number of nodes in the list is n.
//     1 <= n <= 500
//     -500 <= Node.val <= 500
//     1 <= left <= right <= n


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
    int i=0;
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n)return head;
        ListNode *start=NULL,*end=NULL,*prev=NULL,*fin,*temp,*t;
        temp = head;
        int i=1;
        while(i<m){
            i++;
            prev = temp;
            temp = temp->next;
        }
        t = temp;
        while(i<=n){
            i++;
            start = temp->next;
            temp->next = end;
            end = temp;
            temp = start;    
        }
        if(prev){
            fin = prev->next;
            prev->next = end;
            fin->next = temp;
            return head;
        }
        t->next = temp;
        return end;
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,3,3,4,4,5};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* ans = ob1.reverseBetween(l1,2,4);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }