
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

#include<vector>
class Solution{
    private: //FIND MIDDLE
    Node* getmid(Node* head){
        Node*slow=head;
        Node* fast=head->next;
        while(fast!=NULL  && fast->next!=NULL){
            fast=fast->next->next;
            slow =slow->next;
        }
        return slow;
    }
    Node* reverse(Node* head){ //FIND REVERSE After middle
        Node* curr=head;
        Node*prev=NULL;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
       if(head->next==NULL){
           return true;
       }
       //step -1 :-find middle
       Node* middle=getmid(head);
       //step-2 :- find reverse
       Node* temp=middle->next;
       middle->next=reverse(temp);
       //step-3 :- check equal or not
       Node*head1=head;
       Node* head2=middle->next;
       while(head2!=NULL){
           if(head1->data!=head2->data){
               return false;
           }
           //step-4 :-repeat step-2
           head1=head1->next;
           head2=head2->next;
       }
       
       temp=middle->next;
       middle->next=reverse(temp);
       
       return true;
    }
       
       
};
