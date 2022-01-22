/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        bool traversed=false;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// #1
// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
void printList(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

// #2
//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
void push(Node** ref, int new_data)
{
    Node* new_node=new Node(); 
    new_node->data = new_data;
    new_node->next=*ref;
    *ref=new_node;
}

// #2
//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
void append (Node* head, int new_data) {

    Node* new_node=new Node(); 
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (head == NULL) 
    { 
        head = new_node; 
        return; 
    } 
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// #2
//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
void insertAfter(Node* node,int val)
{
    Node* new_node=new Node();
    new_node->data=val;
    new_node->next=node->next;
    node->next=new_node;
}

// #3
// https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
void deleteNode(Node** head_ref, int key)
{
    Node* last=*head_ref;
    
    if(last->data==key)
    {
        *head_ref=last->next;
        delete last;
    }
    else
    {
        while(last->next!=NULL)
        {
           if(last->next->data==key)
           {
               Node* temp=last->next;
               last->next=last->next->next;
               delete temp;
               break;
           }
           last=last->next;
        }
    }
}

// #4
// https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
void deleteNode2(Node** head_ref, int position)
{
    int pos=0;
    Node* last=*head_ref;
    
    if(position==pos)
    {
        *head_ref=last->next;
        delete last;
    }
    else
    {
        while(last->next!=NULL)
        {
           if(pos==position-1)
           {
               Node* temp=last->next;
               last->next=last->next->next;
               delete temp;
               break;
           }
           last=last->next;
           pos++;
        }
    }
}

//#6
// https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
void deleteAll(Node** head_ref)
{
    Node* last=*head_ref;
    Node* temp=NULL;
    while(last!=NULL)
    {
        temp=last->next;
        delete last;
        last=temp;
    }
    *head_ref = NULL;
}

// 7
int getCount(Node* head)
{
    int count=0;
    Node* current=head;
    
    if(current==NULL)
        count=0;
    else
    {
        while(current!=NULL)
        {
            count++;
            current=current->next;
        }
    }
        
    return count;
}

// 8
bool search(Node *head, int x) 
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
            return true;
        temp=temp->next;
    }
    
    return false;
}

// 9
int GetNth(Node* head, int index)
{
    int data =0;
    int currentIndex=0;
    
    Node *temp=head;
    
    if(temp==NULL)
        return 0;
    
    while(temp!=NULL)
    {
        if(currentIndex==index)
            return temp->data;
        temp=temp->next;
        currentIndex++;
    }
    
    
    return data;
}

// 10
void printNthFromLast(Node *head, int index)
{
    int lenght=0;
    Node* current=head;
    while(current!=NULL)
    {
        lenght++;
        current=current->next;
    }
    
    int newIndex=lenght-index+1;
    
    int counter=1;
    current=head;
    while(current!=NULL)
    {
        if(counter==newIndex)
            cout<<"Element at index "<<index <<" from last is "<<current->data<<endl;
        current=current->next;
        counter++;
    }
    
}

// 11
void printMiddle(Node* head)
{
    Node* current=head;
    int lenght=0;
    while(current!=NULL)
    {
        lenght++;
        current=current->next;
    }
    
    lenght=lenght/2;
    
    current=head;
    int i=0;
    while(current!=NULL)
    {
        if(i==lenght)
            cout<<"Middle node value = "<<current->data<<endl;
        current=current->next;
        i++;
    }
}

// 12
int countKeys(Node* head, int key)
{
    Node *current=head;
    int numKey=0;
    
    while(current!=NULL)
    {
        if(current->data==key)
            numKey++;
        current=current->next;
    }
    
    return numKey;
}

// 13
bool detectAndRemoveLoop(Node *head)
{
    bool loop=false;
    Node *current=head;
    Node *prev=head;
    while(current!=NULL)
    {
        if(current->traversed)
        {
            loop=true;
            prev->next=NULL;
            break;
        }
            
        current->traversed=true;
        prev=current;
        current=current->next;
    }
    
    return loop;
}

// 14
int detectAndCountLoop(Node* head)
{
    int loopCount=0;
    Node *current=head;
    Node *base=NULL;
    bool isBaseSet=false;
    while(current!=NULL)
    {
        if(current->traversed)
        {
            if(base==current)
            {
                break;
            }
            loopCount++;
            if(!isBaseSet)
            {
                isBaseSet=true;
                base=current;
            }
            
        }
            
        current->traversed=true;
        current=current->next;
    }
    
    return loopCount;
}

// 15
bool isPalindrome(Node* head)
{
    bool isPalin=true;
    
    Node* current=head;
    
    vector<int> values;
    while(current!=NULL)
    {
        values.push_back(current->data);
        current=current->next;
    }
    
    for(int i=0;i<values.size()/2;i++)
    {
        if(values[i]!=values[values.size()-i-1])
            return false;
    }
    
    return isPalin;
}

// 16
void removeDuplicates(Node* head)
{
    Node* current=head;
    
    while(current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            if(current->next->next==NULL)
            {
                current->next=NULL;
                delete current->next;
            }
            else
            {
                Node* temp=current->next;
                current->next=current->next->next;
                delete temp;
            }
        }
        else
            current=current->next;
    }
}

// 17
void removeDuplicatesUnsorted(Node* head)
{
    Node* current=head;
    Node* prev=head;
    
    vector<int> list;
    
    while(current!=NULL)
    {
        if(std::find(list.begin(),list.end(),current->data)==list.end())
        {
            list.push_back(current->data);
            prev=current;
            current=current->next;
        }
        else
        {
            if(current->next==NULL)
            {
                prev->next=NULL;
                Node *temp=current;
                delete temp;
            }
            else
            {
                prev->next=current->next;
                Node *temp=current;
                current=current->next;
                delete temp;
            }
        }
            
    }
}

// 18
void swapNodes(Node* head,int x, int y)
{
    if(x==y)
        return;
        
    Node *currentx=head;
    Node* prevx=head;
    Node *currenty=head;
    Node* prevy=head;
    
    while(currentx!=NULL)
    {
        if(currentx->data==x)
            break;
            
        prevx=currentx;
        currentx=currentx->next;
    }
    
    while(currenty!=NULL)
    {
        if(currenty->data==y)
            break;
            
        prevy=currenty;
        currenty=currenty->next;
    }
    
    if(currenty==NULL)
        return;
    if(currentx==NULL)
        return;
    
    Node* tempcurrenty=currenty->next;
    prevx->next=currenty;
    prevy->next=currentx;
    currenty->next=currentx->next;
    currentx->next=tempcurrenty;
}

// 19
void pairwiseSwap(Node* head)
{
    if(head==NULL)
        return;
    if(head->next==NULL)
        return;
        
    Node* current=head;
    Node* prev=head;
    
    while(current->next!=NULL)
    {
        int data1=current->data;
        int data2=current->next->data;
        current->data=data2;
        current->next->data=data1;
        
        if(current->next->next!=NULL)
            current=current->next->next;
        else
            current=current->next;
    }
}

// 20
void moveToLast(Node** head)
{
    
    Node* last=*head;
    Node* onebeforelast=NULL;
    
    while(last->next!=NULL)
    {
        onebeforelast=last;
        last=last->next;
    }
    
    onebeforelast->next=NULL;
    last->next=*head;
    *head=last;
}

// 21
Node* intersectSorted(Node* head1, Node* head2)
{
    Node* current1=head1;
    
    
    if(head1==NULL || head2==NULL)
        return NULL;
        
    Node* res=new Node();
    Node* resLast=res;
    bool isFlag=true;
    while(current1!=NULL)
    {
        Node* current2=head2;
        while(current2!=NULL)
        {
            if(current1->data==current2->data)
            {
                if(isFlag)
                {
                    res->data=current1->data;
                    res->next=NULL;
                    isFlag=false;
                }
                else
                {
                    Node* newnode=new Node();
                    newnode->data=current1->data;
                    newnode->next=NULL;
                    resLast->next=newnode;
                    resLast=resLast->next;
                }
            }
            current2=current2->next;
        }
        current1=current1->next;
    }
    
    return res;
}

// 24
void segregateEvenOdd(Node** head_ref)
{
    Node *startOdd = NULL;
    Node* endOdd=NULL;
    Node *startEven = NULL;
    Node *endEven = NULL;
    Node *curr = *head_ref;
    
    while(curr!=NULL)
    {// 4 2 3 6 1
        if(curr->data%2!=0)
        {
            if(startOdd==NULL)
            {
                startOdd=curr;
                endOdd=startOdd;
            }
            else
            {
                endOdd->next=curr;
                endOdd=endOdd->next;
            }
        }
        else if(curr->data%2==0)
        {
            if(startEven==NULL)
            {
                startEven=curr;
                endEven=startEven;
            }
            else
            {
                endEven->next=curr;
                endEven=endEven->next;
            }
        }
        
        curr=curr->next;
    }
    
    endOdd->next=NULL;
    endEven->next=startOdd;
    *head_ref=startEven;
}

// 25
void reverseList(Node** head)
{
    Node* newfirst=*head;
    Node* afterLastNode=NULL;
    Node* lastNode=*head;
    
    while(lastNode->next!=NULL)
    {
        lastNode=lastNode->next;
    }
    // 1->2->3->4->5->null => 5->4->3->2->1->null
    // 17->15->8->12->10->5->4->1->7->6->NULL
    while(newfirst!=lastNode)
    {
        if(lastNode->next==NULL)
        {
            newfirst=newfirst->next;
            Node* temp=*head;
            temp->next=NULL;
            lastNode->next=temp;
            afterLastNode=temp;
        }
        else
        {
            newfirst=newfirst->next;
            Node* temp=*head;
            temp->next=afterLastNode;
            lastNode->next=temp;
            afterLastNode=temp;
        }
        *head=newfirst;
    } 
}

// 37
Node* addTwoLists(Node* head1, Node* head2)
{
    Node* res=NULL;
    vector<int> vec1;
    vector<int> vec2;
    int sum1=0,sum2=0;
    
    Node* current1=head1;
    Node* current2=head2;
    
    while(current1!=NULL)
    {
        vec1.push_back(current1->data);
        current1=current1->next;
    }
    
    while(current2!=NULL)
    {
        vec2.push_back(current2->data);
        current2=current2->next;
    }
    
    for(int i=0;i<vec1.size();i++)
    {
        sum1+=vec1[i]*pow(10,vec1.size()-i-1);
    }
    
    for(int i=0;i<vec2.size();i++)
    {
        sum2+=vec2[i]*pow(10,vec2.size()-i-1);
    }
    
    int total=sum1+sum2;
    
    while(total!=0)
    {
        int val=total%10;
        total=total/10;
        
        Node *temp=new Node();
        temp->data=val;
        temp->next=res;
        res=temp;
    }
    
    return res;
}

// 85
Node* mergeLists(Node* a, Node* b) {

    Node* res=new Node();
    
    if(a==NULL && b==NULL)
        return NULL;
        
    if(a->data <= b->data)
    {
        Node* newnode=new Node(); //(Node*)malloc(sizeof(Node));
        newnode->data=a->data;
        newnode->next=NULL;
        res=newnode;
        a=a->next;
    }
    else 
    {
        Node* newnode=new Node();
        newnode->data=b->data;
        newnode->next=NULL;
        res=newnode;
        b=b->next;
    }
    
    Node* current=res;
            
    while(a!=NULL && b!=NULL)
    {
        if(a->data <= b->data)
        {
            Node* newnode=new Node();
            newnode->data=a->data;
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
            a=a->next;
        }
        else {
                Node* newnode=new Node();
                newnode->data=b->data;
                newnode->next=NULL;
                current->next=newnode;
                current=current->next;
                b=b->next;
        }
    }
    
    while(a!=NULL)
    {
        Node* newnode=new Node();
        newnode->data=a->data;
        newnode->next=NULL;
        current->next=newnode;
        current=current->next;
        a=a->next;
    }
    
    while(b!=NULL)
    {
        Node* newnode=new Node();
        newnode->data=b->data;
        newnode->next=NULL;
        current->next=newnode;
        current=current->next;
        b=b->next;
    }
    
    return res;
}

int main()
{
    cout<<"Hello World"<<endl;
    //segregateEvenOdd 17->15->8->12->10->5->4->1->7->6->NULL
    /*Node* head1 = NULL;
    push(&head1, 6); 
    push(&head1, 7); 
    push(&head1, 1); 
    push(&head1, 4); 
    push(&head1, 5); 
    push(&head1, 10);
    push(&head1, 12);
    push(&head1, 8);
    push(&head1, 15);
    push(&head1, 17);
    printList(head1);
    reverseList(&head1);
    printList(head1);*/
    
    //intersectSorted
    // addTwoLists
    Node* head1 = NULL;
    push(&head1, 6); 
    push(&head1, 5); 
    push(&head1, 4); 
    push(&head1, 3); 
    push(&head1, 2); 
    push(&head1, 1); 
    Node* head2 = NULL;
    push(&head2, 8); 
    push(&head2, 6);  
    push(&head2, 4); 
    push(&head2, 2);
    printList(head1);
    //Node* intersect=intersectSorted(head1,head2);
    //printList(intersect);
    printList(head2);
    Node* added=addTwoLists(head1,head2);
    printList(added);
    
    /*
    //SWAP LINKS
    Node* headSwap = NULL;
    push(&headSwap, 17); 
    push(&headSwap, 16); 
    push(&headSwap, 15); 
    push(&headSwap, 14); 
    push(&headSwap, 13); 
    push(&headSwap, 12); 
    push(&headSwap, 11); 
    push(&headSwap, 10);   
    printList(headSwap);
    //swapNodes(headSwap,11,16);
    //pairwiseSwap(headSwap);
    moveToLast(&headSwap);
    printList(headSwap);
    */
    /*
    Node* head=new Node();
    Node* second=new Node();
    Node* tail=new Node();
    
    head->data=10;
    head->next=second;
    
    second->data=11;
    second->next=tail;
    
    tail->data=13;
    tail->next=NULL;
    
    //push(9);
    push(&head,9);
    //push(8);
    push(&head,8);
    printList(head);
    insertAfter(second,12);
    printList(head);
    //append(14);
    append(head,14);
    append(head,15);
    append(head,16);
    printList(head);
    deleteNode(&head,16);
    deleteNode2(&head,2);
    printList(head);
    //deleteAll(&head);
    //printList(head);
    cout<<getCount(head)<<endl;
    cout << "Element at index 3 is " << GetNth(head, 3)<<endl;
    printNthFromLast(head,4);
    printMiddle(head);
    deleteNode2(&head,2);
    printList(head);
    printMiddle(head);
    
    //REMOVE DUBLICATE SORTED
    Node* headDub = NULL; 
    push(&headDub, 20); 
    push(&headDub, 20); 
    push(&headDub, 15);
    push(&headDub, 13); 
    push(&headDub, 13); 
    push(&headDub, 11); 
    push(&headDub, 11); 
    push(&headDub, 11);                             
    
    printList(headDub); 
    removeDuplicates(headDub);      
    printList(headDub);   
    
    //REMOVE DUBLICATE UNSORTED
    // The constructed linked list is: 10->12->11->11->12->11->10
    struct Node* headDubUnsort = NULL;
    push(&headDubUnsort, 10); 
    push(&headDubUnsort, 11); 
    push(&headDubUnsort, 12); 
    push(&headDubUnsort, 11); 
    push(&headDubUnsort, 11); 
    push(&headDubUnsort, 12); 
    push(&headDubUnsort, 12); 
    push(&headDubUnsort, 12); 
    push(&headDubUnsort, 10);   
    printList(headDubUnsort);
    removeDuplicatesUnsorted(headDubUnsort);
    printList(headDubUnsort);
    
    cout<<"MERGED LIST"<<endl;
    //Merge two list
    Node* head1=new Node();
    Node* second1=new Node();
    Node* third1=new Node();
    head1->data=1;
    head1->next=second1;
    second1->data=2;
    second1->next=third1;
    third1->data=3;
    third1->next=NULL;
    
    Node* head2=new Node();
    Node* second2=new Node();
    head2->data=3;
    head2->next=second2;
    second2->data=4;
    second2->next=NULL;
    Node* merged=new Node();
    merged=mergeLists(head1,head2);
    printList(merged);
    
    cout<<"PALINDROME"<<endl;
    // Start with the empty list
    Node* headPal = NULL;
    char str[] = "1234321";
    int i;
 
    for(i = 0; str[i] != '\0'; i++)
    {
        push(&headPal, str[i]); 
    }
    printList(headPal);
    isPalindrome(headPal) ? cout << "Is Palindrome"
                 << "\n\n" : cout << "Not Palindrome"
                 << "\n\n";
    */
    
    
    return 0;
}
