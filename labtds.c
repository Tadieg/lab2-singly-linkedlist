#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	char data2[50];
	struct node *next;
}*head,*head2,*head3;
void createList(int n ,int s);
void traverseList();
void concate();
void insertNodeAtBeginning(char data2[50]);
void insertNodeAtMiddle(char data2[50],int position);
void insertNodeAtEnd(char data[50]);
void deleteFirstNode();
void deleteLastNode();
void deleteMiddleNode(int position);
void concatenate(struct node *a,struct node *b);
int searchRecursive(char key[50], struct node *curNode, int index);
int main(){
	int n,data,ch,position,s=0;
	char keyToSearch[50]; 
	int index;
	char data2[50];
	printf("enter the number of the nodes you want to create ");
	scanf("%d",&n);
	createList(n,s);
	printf("data int the list\n ");
	traverseList(s);
	label:
	printf("enter 1 for insert at the begginning: \n ");
	printf("enter 2 for insert at the end: \n ");
	printf("enter 3 for insert at the middle: \n ");
	printf("enter 4 for delete the first node :\n ");
	printf("enter 5 for delete the last node: \n ");
	printf("enter 6 for concatenate :\n ");
	printf("enter 7 for search data at any position: \n ");
	printf("enter 8 for delete at any postion\n ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("enter the data to insert at the beginning of the list ");
	        scanf("%s",&data2);
	        insertNodeAtBeginning(data2);
	        traverseList(s);
	        break;
	    case 2:
	    	printf("enter the data to insert at the at end of the list ");
	        scanf("%s",&data2);
	        insertNodeAtEnd(data2);
	        traverseList(s);
	        break;
	    case 3:
	     printf("nEnter data to insert at middle of the list: ");
         scanf("%s", &data2);
         printf("Enter the position to insert new node: " );
         scanf("%d", &position);
         insertNodeAtMiddle(data2, position);
         traverseList(s);
	        break;
	    case 4:
              deleteFirstNode();
              traverseList(s);
	        break;
	    case 5:
            deleteLastNode();
            printf("\nData in the list \n");
           traverseList(s=0);
	        break;
	    case 6:
            s=1;
            printf("enter the number of the nodes you want to create for the second list ");
			scanf("%d",&n);
			createList(n,s);
			traverseList(s);
			printf("data after concatenation\n");
			concatenate(head,head2);
			s=0;
			traverseList(s);
	        break;
	    case 7:
            printf("\nEnter element to search: ");
            scanf("%s", &keyToSearch);
            index = searchRecursive(keyToSearch, head, 0);
		    if (index >= 0)
		        printf("%s found in the list at position %d\n", keyToSearch, index + 1);
		    else
		        printf("%s not found in the list.\n", keyToSearch);
    
	        break;
	case 8:
		printf("\nEnter the node position you want to delete: ");
        scanf("%d", &position);
        deleteMiddleNode(position);
	    printf("\nData in the list \n");
        	traverseList(s=0);
		break;
		
	}
  goto label;
	return 0;
}
void createList(int n,int s){
	struct node *newnode,*temp,*newnode2,*temp2,*temp3;
	int data,i;
	char data2[50];
	if(s==0){
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		printf("you have no engough memory ");
		exit(0);
	}
	printf("enter the data of node 1:");
	scanf("%s",&data2);
	printf("the character you entered is=%s\n",data2);
	//head->data=data2;
	strcpy(head->data2,data2);
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++){
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("you have not enougn memory to enter the next node ");
		exit(0);
	}
		printf("enter the data of the node %d: ",i);
		scanf("%s",&data2);
     	strcpy(newnode->data2,data2);
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
}
}else{
	head2=(struct node *)malloc(sizeof(struct node));
	if(head2==NULL){
		printf("you have no engough memory ");
		exit(0);
	}
	printf("enter the data of node 1:");
	scanf("%s",&data2);
	printf("the character you entered is=%s\n",data2);
	strcpy(head2->data2,data2);
	head2->next=NULL;
	temp2=head2;
	for(i=2;i<=n;i++){
	newnode2=(struct node*)malloc(sizeof(struct node));
	if(newnode2==NULL){
		printf("you have not enougn memory to enter the next node ");
		exit(0);
	}
		printf("enter the data of the node %d: ",i);
		scanf("%s",&data2);
		strcpy(newnode2->data2,data2);
		newnode2->next=NULL;
		temp2->next=newnode2;
		temp2=temp2->next;
}
}
}
void traverseList(int s){
	struct node *temp,*temp2,*temp3;
	if(s==0){
	if(head==NULL){
		printf("list is empty ");
	}
	temp=head;
	while(temp!=NULL){
		printf("%s,",temp->data2);
		temp=temp->next;
	}
	printf("\n");
}else if(s==1){
	
if(head2==NULL){
		printf("list is empty ");
	}
	temp2=head2;
	while(temp2!=NULL){
		printf("%s,",temp2->data2);
		temp2=temp2->next;
	}
	printf("\n");
}else{
	if(head3==NULL){
		printf("list is empty ");
	
	}
	temp3=head3;
	while(temp3!=NULL){
		printf("%s,",temp3->data2);
		temp3=temp3->next;
	}
	printf("\n");	
}
	
}
void insertNodeAtBeginning(char data2[50])
{
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL){
	printf("you have no memory to enter ");
}else{
//newnode->data=data;
strcpy(newnode->data2,data2);
newnode->next=head;	
head=newnode;
printf("Entered successfully ");
}
}
void insertNodeAtEnd(char data2[50])
{
	//printf("we are in the lab");
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("unable to allocate memory");
	}else{
	    strcpy(newnode->data2,data2);
		newnode->next=NULL;
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
			}
		temp->next=newnode;
		printf("Data inserted at the end succussfully ");
	}
}
void insertNodeAtMiddle(char data2[50], int position)
{
    int i;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        strcpy(newnode->data2,data2);
        newnode->next = NULL;
        temp = head;
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            newnode->next = temp->next; 
            temp->next = newnode;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
void deleteFirstNode()
{
struct node *delete;
if(head==NULL){
	printf("Nothing to delete");
}else{
	delete=head;
	head=head->next;
	printf("data deleted successfully");
	free(delete);
}
}

int searchRecursive(char key[50], struct node *curNode, int index)
{
	char a[50];
    if (curNode==NULL){                
        return -1;
		}
    else if (strcmp(curNode->data2,key)==0) {
        return index;
        
		}
    else     {                     
        return searchRecursive(key, curNode->next, index + 1);
    }
}
void concatenate(struct node *a,struct node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        /* Traverse to the last node of the list */
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}



