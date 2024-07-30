
// For sorted linkedList

Node * removeDuplicates(Node *head)
{
    if(head==NULL){
        return NULL;

    }
    Node* curr =head;

    while(curr!=NULL){

        if(curr->next!=NULL && curr->data==curr->next->data){
            Node* next_next=curr->next->next;
            Node* nodeTODelete = curr->next;
            delete (nodeTODelete);
            curr->next=next_next;

        }

        else{
            curr=curr->next;

        }
    }

    return head;
}