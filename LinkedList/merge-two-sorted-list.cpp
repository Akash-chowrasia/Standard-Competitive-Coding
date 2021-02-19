// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

// Example 1:

// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: l1 = [], l2 = []
// Output: []

// Example 3:

// Input: l1 = [], l2 = [0]
// Output: [0]

 

// Constraints:

//     The number of nodes in both lists is in the range [0, 50].
//     -100 <= Node.val <= 100
//     Both l1 and l2 are sorted in non-decreasing order.

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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * list1 = l1, *list2 = l2, *newhead = new ListNode(0), *node = newhead;
        while(list1 || list2){
            if(list1 and list2){

                if(list1->val<=list2->val){
                    node->next = list1;
                    list1 = list1->next;
                    node = node->next;
                }

                else{
                    node->next = list2;
                    list2 = list2->next;
                    node = node->next;
                }

            }

            else if(list1 and !list2){
                node->next = list1;
                list1 = list1->next;
                node = node->next;
            }

            else{
                node->next = list2;
                list2 = list2->next;
                node = node->next;
            }

        }
        node->next = NULL;
        return newhead->next;
        
    }
};

int main(){
    ListMaker ob;
    Solution ob1;
    vector<int> a1 = {1,2,4};
    vector<int> a2 = {1,3,4};
    ListNode* l1 = ob.CreateList(a1);
    ListNode* l2 = ob.CreateList(a2);
    ListNode* ans = ob1.mergeTwoLists(l1,l2);
    ob.PrintList(ans);
    cout << "\n";
    return 0;
  }