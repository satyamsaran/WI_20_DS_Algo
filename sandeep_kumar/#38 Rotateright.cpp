class Solution {
public:
    int size(ListNode* temp){
        int k=0;
        while(temp){
            k++;
            temp=temp->next;
        }
        return k;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        if(k%size(head)==0){
            return head;            
        }
        k=k%size(head);
        while(k--){
            ListNode *p=head,*q=head->next;
            while(q->next!=NULL){
                q=q->next;
                p=p->next;
            }
            ListNode *temp=new ListNode(q->val);
            p->next=NULL;
            temp->next=head;
            head=temp;
        }
        return head;
    }
};