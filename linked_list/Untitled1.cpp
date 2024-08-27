#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

    // Show List function................
 void show_list(Node* p){
 	Node* temp = p;
 	while(temp != NULL){
 		cout<<temp->data;
 		temp = temp->next;
	 }
 }
 
 // Search List function................
 
 void search_list(Node* p){
 	Node* temp = p;
 	int n;
 	cin >> n;
 	int index , t=0 , f=0;
 	 while(temp != NULL){
 	 	if(temp -> data == n){
 	 		
			  f=1;
 	 		index =t;
 	 		
		  }
		  temp = temp -> next;
		  t++;
	  }
	  if(f==1){
	  	cout<<n<<" was found at index"<<endl;
	  }
	  else{
	  	cout<<n<<" was not found at index"<<endl;
	  }
 }
 
 // Insert at last of the linked_list  function..............
 void insert_at_last(Node* p){
 	Node* temp = p;
 	    while(temp -> next != NULL){
 	    	temp = temp -> next;
		 }
		 int n;
		 cin >> n ;
		 Node* x = NULL;
		 	x = new Node();
		 	x -> data =n;
		 	x -> next = NULL;
		 	
		 	temp -> next =x;
 }
 
 // Delete from last of the linked_list  function..............
    
    void delete_from_last(Node* p){
    	Node* temp = p;
    	
		while(temp -> next -> next != NULL){
			temp = temp -> next;
			
		}
		temp -> next = NULL;
	}
int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	
	head = new Node();
	second = new Node();
	third = new Node();
	
	//Link...........
	
	head -> data = 1;
	head -> next = second;
	
	second -> data = 2;
	second -> next= third;
	
	third -> data = 3;
	third -> next = NULL;
	
	insert_at_last(head);
	show_list(head);
	
	cout<<"\n";
	search_list(head);
	delete_from_last(head);
	show_list(head);
	search_list(head);
	
	
	
	
}
