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
 	cout<<"\nPlease Enter the value you want to search: ";
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
	  	cout<<"\n"<<n<<" was found at index"<<endl;
	  }
	  else{
	  	cout<<"\nThe value is not in the linked list"<<endl;
	  }
 }
 
 // Insert at last of the linked_list  function..............
 void insert_at_last(Node* p){
 	Node* temp = p;
 	    while(temp -> next != NULL){
 	    	temp = temp -> next;
		 }
		 int n;
		 cout<<"\nPlease Enter the value you want to insert: ";
		 cin >> n ;
		 Node* x = NULL;
		 	x = new Node();
		 	x -> data =n;
		 	x -> next = NULL;
		 	
		 	temp -> next =x;
		 	cout<<"\nInsert operation is done\n";
 }
 
 // Delete from last of the linked_list  function..............
    
    void delete_from_last(Node* p){
    	Node* temp = p;
    	
		while(temp -> next -> next != NULL){
			temp = temp -> next;
			
		}
		temp -> next = NULL;
		cout<<"\nDelete operation is done\n";
	}
int main(){
	int option;
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
      
	  
	  // options for user
	  cout<<"1-Print List"<<endl;
	  cout<<"2-Search a number in the list"<<endl;
	  cout<<"3-Insert value at the end of the list"<<endl;
	  cout<<"4-Delete value from the end of the list"<<endl;
	  cout<<"5-Exit"<<endl;
     while(true){
	 cout<<"\nEnter Number of option you want: ";
	 cin>> option;
	 if(option==1){
	 	show_list(head);
	 	cout<<"\n___________________________";
	 }
	 else if(option == 2){
	 	search_list(head);
	 	cout<<"\n___________________________";
	 }
	 else if(option == 3)
	 {
	 	insert_at_last(head);
	 	cout<<"\n___________________________";
	 }
	 else if(option == 4){
	 	delete_from_last(head);
	 	cout<<"\n___________________________";
	 }
	 else if(option == 5 ){
	 	return 0;
	 }
	 else{
	 	cout<< "\nWrong option";
	 }
}
	
	/*cout<<"\n";
	
	
	search_list(head);
	delete_from_last(head);
	show_list(head);
	search_list(head);
	*/
	
	
	
	
}
