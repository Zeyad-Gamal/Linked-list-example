#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* prev;
	int data ; 
	struct node* next; 
};

 
void print_list(struct node* head) {
	
	while(head != NULL )
	{
		printf("%d ", head->data) ;
		head = head->next ; 
	}
	
	printf("\n\n\n\n");
	
}


void reverse_print_list(struct node* head) 
{
	// Step 1
	// Move the pointer to the last node of the list
	while(head->next !=NULL) 
	{
		head = head->next ; 
	}
	
	// now 'head' -> Last Node
	
	
	// Step 2
	// Print the list in reverse 
	while(head!=NULL) {
		printf("%d ", head->data); // Print the data in the current node
		head = head->prev ; // Move the head 1 node before
	}
	
	
	// now 'head' -> NULL 
	
	
	printf("\n\n\n\n");
	
}


struct node* add_beg(struct node* head, int value) 
{
	
	// Step 1
	// Create a new node (a copy from the 'node' struct) and store it's address in the pointer 'temp'
	struct node* temp = malloc(sizeof(struct node)) ;

	// Step 2 
	// store data in the new node (which is stored in temp) 
	temp->data = value; 
	
	//  Step 3
	// Connect the new node (which is stored in temp) with the linked list 
	temp->prev = NULL ;
	temp->next = head ;	
	
	// Step 4
	// Connect the linked list's head to the new node 
	head->prev = temp ;
	
	
	// Step 5 ( Very important ) 
	// Change the address stored in head to the new start of the linked list (AKA the new node we created)
	head = temp ; 
	
	// Step 6 ( Very important ) 
	return head ;  
	
	
}


void add_end(struct node* head, int value) 
{
	// Step 1
	// Create a new node (a copy from the 'node' struct) and store it's address in the pointer 'temp'
	struct node* temp = malloc(sizeof(struct node)) ;
	
	
	// Step 2 
	// store data in the new node (which is stored in temp) 
	temp->data = value ;
	temp->next = NULL ;
	
	
	// Step 3
	// We need access to the last node of the linked list, so we use a while loop to make the
	// head pointer store the address of the last node by moving it on all the list
	while(head->next != NULL) {
		head = head -> next ;
	}
	
	
	// Step 4
	// We connect the last node in the list ( which now it's address is stored in the 'head' pointer ) to
	// the new node we created ( which it's address is stored in the 'temp' pointer 
	head->next = temp ; 
	temp->prev = head ; 
	
	
	// P.s: We don't need to return the head since this function only adds a new node to the END of the list 
	
}


void add_after_position(struct node* A, int value, int pos) 
{
	// Step 1
	// Create a new node (a copy from the 'node' struct) and store it's address in the pointer 'B'
	struct node* B = malloc(sizeof(struct node));
	
	// Step 2 
	// store data in the new node (which is stored in B) 
	B->data = value ; 
	
	
	// Step 3
	// Loop until the pos variable reaches 1 ( when we arrive at the position we want to insert after it )
	while(pos != 1) {
		A = A->next ; 
		pos-- ;
	}
	
	// now 'A' -> Node in position 'pos'
	
	
	
	// Step 4
	// Make a new pointer C which points at the Node after the position 'pos' 
	struct node* C = A->next ;
	
	
	
	// Step 5 
	// Connect the new node 'B' with  the nodes 'A' and 'C' 
	B->prev = A ;
	B->next = C ;
	
	// Step 6
	// Change the next of 'A' to make it 'B' instead of 'C'
	A->next = B ;


	// Step 7
	// Change the prev of 'B' to make it 'B' instead of 'A'
	C->prev = B ;
	
	
	// P.s : Order of steps 5,6,7 are very important
	
	
}


struct node* delete_first(struct node* head){
	
	node * temp= head;
	   head = head -> next;
	  head->prev=NULL;
	  
	  //delete the first node
	  free(temp);
	  temp=NULL;
	  //return the new start
	  return head;

}




int main() {
	
	struct node* head = (struct node*) malloc( sizeof(struct node) ) ;
	
	head->data = 10 ;
	head->next = NULL ;
	head->prev = NULL ;
	
	
	
	printf("List after the first node created :\n\n");
	print_list(head) ;
	
	
//	============================================================================


	struct node* ptr = malloc(sizeof(struct node)) ;
	
	ptr->data = 11 ;
	ptr->next = NULL ;
	
	ptr->prev = head; 
	
	head->next = ptr ; 
	
	
	printf("List after creating a second node: ");
	print_list(head) ;
	
	
//	============================================================================
	
	head = add_beg(head, 20); 
	
	printf("Linked List after add_beg() function being called:\n\n");
	print_list(head) ;
	
	
//	============================================================================
	
	add_end(head, 30) ;
	
	printf("Linked List after add_end() function being called:\n\n");
	print_list(head) ;
	
//	============================================================================
	
	
	
//	add_after_position(head, 40 , 2) ;
//	
//	printf("Linked List after add_after_position() function being called:\n\n");
//	print_list(head) ;
	
}
