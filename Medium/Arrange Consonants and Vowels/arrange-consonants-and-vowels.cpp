//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    
    bool vowel(char c){
        
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')    return true;
        
        return false;
    }
    struct Node* arrangeCV(Node* head) {
        // Code here
        Node* temp1 = NULL;
        Node* temp2 = NULL;
        Node* temp3 = NULL;
        
        if(vowel(head->data)){
            temp1 = head;
        }
        
        while(temp1 != NULL && temp1->next != NULL && vowel(temp1->next->data)){
            
            temp1 = temp1->next;
        }
        
        if(temp1 != NULL)   temp2 = temp1->next;
        else temp2 = head;
        
        while(temp2 != NULL){
            
            if(vowel(temp2->data)){
                
                if(temp1 == NULL){
                    
                    temp3->next = temp2->next;
                    temp2->next = head;
                    head = temp2;
                    temp1 = head;
                    temp2 = temp3->next;
                }
                else{
                    
                    temp3->next = temp2->next;
                    temp2->next = temp1->next;
                    temp1->next = temp2;
                    temp1 = temp2;
                    temp2 = temp3->next;
                }
            }
            
            else{
                
                temp3 = temp2;
                temp2 = temp2->next;
            }
        }
        
        return head;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends