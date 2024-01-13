/*
Insertion Sort for Singly Linked List
Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 
11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.

*/


class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
    
     Node* dummy= new Node(-1);
        while(head){
            Node* next = head->next;
            Node*temp = dummy;
            while(temp->next && temp->next->data <head->data){
                temp= temp->next;
            }
            head->next=temp->next;
            temp->next=head;
            head= next;
        }
        return dummy->next;
        
    }
    
};