#include "ListNode.h"

ListNode * SolveB(int n){
    /* your code starts here */
    
    int firstEle;
    cin>>firstEle;
    ListNode *head= new ListNode(firstEle);
    if (n==1){
        return head;
    }
    int secondEle;
    cin>>secondEle;
    ListNode *even= new ListNode(secondEle);
    ListNode *odd= head;
    ListNode *evenFirst=even;
    
    for (int i=2;i<n;i++){
        int temp;
        cin>>temp;
        ListNode *newnode= new ListNode(temp);
        if (i%2==0){
            odd->next=newnode;
            odd=newnode;  //attach to odd
        }
        else{
            even->next=newnode;//attach to even
            even=newnode;
        }
    }
    odd->next=evenFirst;
    
    return head;
}
