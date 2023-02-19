/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
     private:
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
     void insertAtTail(struct Node* &head,struct Node* &tail,int val){
        Node*temp=new Node(val);
        if(head==NULL) //when list is empty
        {
            head=temp;
            tail=temp;
            return ;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        
    }
    struct Node*add(struct Node* frist,struct Node*second){
        int carry=0;
        Node* ansHead=NULL;
        Node*ansTail=NULL;
        
        while(frist!=NULL && second!=NULL){
            int sum=carry+frist->data + second->data;
            int digit=sum%10;
            // Node* temp=new Node(digit);
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            frist=frist->next;
            second=second->next;
            
        }
        while(frist!=NULL){ //when second list is sort
            int sum=carry+frist->data;
            int digit=sum%10;
            // Node* temp=new Node(digit);
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            frist=frist->next;
        }
        while(second!=NULL){  //when frist is sort
            int sum=carry+second->data;
            int digit=sum%10;
            // Node* temp=new Node(digit);
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            second=second->next;
        }
        while(carry!=0){
            int sum=carry;
             int digit=sum%10;
            // Node* temp=new Node(digit);
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            
            
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node*second)
    {
        // code here
        //step-1 reverse the both linked list 
        first = reverse(first);
        second = reverse(second);
        
        //step-2 add both linked list
      Node* ans = add(first, second);
        
        //step-3 reverse the ans
        ans=reverse(ans);
        
        return ans;
        
        
    }
};
