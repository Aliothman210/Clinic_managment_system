#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "functions.h"
#include <string.h>
node* head;

u8 listlength=0;
slots res[5]={
		"1- 2pm to 2:30pm",
		"2- 2:30pm to 3pm",
		"3- 3pm to 3:30pm",
		"4- 3:30pm to 4pm",
		"5- 4:30pm to 5pm"
	};

void admin_mode(void){
	u16 uPass;
	u8 a;
	node *search,*new;
	u8 flag =0;
	u8 i,n;
	u32 ID;
	u8 name[50];
	u8 age;
	u8 gender[10];
	printf("***********___________ Admin Mode ___________***********\n\n");
	printf("Please enter the password: ");
	
	for( i=0;i<3;i++){
		scanf("%i",&uPass);
		if(uPass == 1234)
			break;
		else if(i<2){
			printf("try again:");
		}
		else{
			return;
		}	
	}
	
	printf("Welcome to admin mode\n\n");
	
   
	while(flag==0){
	printf("Press 1 to Add new patient record\nPress 2 to edit patient record\nPress 3 to reserve a slot with the doctor\nPress 4 to Cancel reservation\nPress 5 to view all the patients records\nPress 9 to exit\n");
	scanf("%i",&a);
		
	
	switch (a){
		case 1:
		printf("Please enter the patient ID: ");
		scanf("%i",&ID);
		search= search_node(head,ID);
		if(search==NULL){
			
			add_patient(ID);
			
		}
		else{
			printf("This ID already exists\n");
		}
			printf("_____________**********************************_____________\n");
		break;
		case 2:
		printf("Please enter the patient ID to edit: ");
		scanf("%i",&ID);
		search= search_node(head,ID);
		if(search!=NULL){
			new =edit_patient(search);
			printf("Patient record updated\n");
		}
		else{
			printf("ID was not found\n");
		}
			printf("_____________**********************************_____________\n");
		break;
		case 3:
		printf("The available slots are:\n");
		for(u8 i =0;i<5;i++){
		printf("%s\n",res[i].arr);
	    }
		printf("Please enter the patient ID:");
		scanf("%i",&ID);
		
		search = search_node(head,ID);
		if(search!=NULL){
			printf("Please enter the desired slot:");
			scanf("%i",&n);
			reserve_slot(search,ID,n);
		}
		else{
			printf("Unvalid ID\n");
		}
		
			printf("_____________**********************************_____________\n");
		break;
		case 4:
		printf("Please Enter the ID you want to cancel its reserve: ");
		scanf("%i",&ID);
		search=search_node(head,ID);
		if(search!=NULL){
			printf("Please Enter the slot you want to cancel: \n");
			scanf("%i",&n);
			cancel_res(search,n);
		}
		else{
			printf("Unvalid ID\n");
		}
		
			printf("_____________**********************************_____________\n");
		break;
		case 5:
		print(head);
		printf("_____________**********************************_____________\n");

		break;
		case 9:
		printf("Thank you\n");
			printf("_____________**********************************_____________\n");
		flag=1;
		break;
		default:
		printf("Try again\n");
			printf("_____________**********************************_____________\n");
		break;
	}
	}
}
//______________________________________________________________________________________________________________
void user_mode(void){
	u8 t;
	u8 f=0;
	u32 ID;
	node* search;
	printf("***********___________ User Mode ___________***********\n\n");
	printf("Welcome to User Mode\n");
    
	while(f==0){
	printf("Press 1 to View Patient record\nPress 2 to View Today's reservations\nPress 9 to exit\n");
	scanf("%i",&t);
		switch(t){
			case 1:
			printf("Please enter the ptient ID:");
			scanf("%i",&ID);
			search = search_node(head,ID);
			if(search!=NULL){
				printf("Patient ID: %i\n",search -> ID);
				printf("Patient name: %s\n",search -> name);
				printf("Patient age: %i\n",search -> age);
				printf("Patient gender: %s\n",search -> gender);
			}
			else{
				printf("Patient ID was not found\n");
				
			}
			printf("_____________**********************************_____________\n");
			break;
			case 2:
			printf("Please enter the ptient ID:");
			scanf("%i",&ID);
			search = search_node(head,ID);
			if(search!=NULL){
				printf("Patient ID:%i\n",search->ID);
				printf("Patient slot:%s\n",search->reserve);
			}
			else{
				printf("Patient ID was not found\n");
				
			}
			printf("_____________**********************************_____________\n");
			break;
			case 9:
			printf("Thank You\n");
			printf("_____________**********************************_____________\n");
			f=1;
			break;
			default:
			printf("Try again\n");
			printf("_____________**********************************_____________\n");
			break;
		}
	}
	
}
//______________________________________________________________________________________________________________
void add_patient(u32 ID){
	
	if(listlength ==0){
		head =(node*) malloc(sizeof(node));
		head->ID=ID;
		printf("Please enter the patient name: ");
		scanf("%s",head->name);
		printf("Please enter the patient age: ");
		scanf("%i",&head->age);
		printf("Please enter the patient gender: ");
		scanf("%s",head->gender);
		
		head -> next =NULL;
		
	}
	else{
		
		node *last;
		
		node *new =(node*) malloc(sizeof(node));
		
		printf("Please enter the patient name: ");
			scanf("%s",new->name);
			printf("Please enter the patient age: ");
			scanf("%i",&new->age);
			printf("Please enter the patient gender: ");
			scanf("%s",new->gender);
		new -> ID =ID;
		
		new -> next =NULL;
		
		last =head;
		
		while(last -> next !=NULL){
			last= last -> next;
			
		}
		last -> next = new;
	}
	listlength ++;
}

//______________________________________________________________________________________________________________
node* search_node( node *temp, u32 data) {
	 
    node *current = temp;
    while (current != NULL) {
	  
    if (current->ID == data) {
		
      return current;
	  
    }
    current = current->next;
  }
   return NULL;
 }
//______________________________________________________________________________________________________________
node* edit_patient(node* head){
	
	node *current= head;
	
	printf("Please enter the patient new ID: ");
	scanf("%i",&current -> ID);
		
	printf("Please enter the patient new name: ");
	scanf("%s",current -> name);
	printf("Please enter the patient new age: ");
	scanf("%i",&current -> age);
	printf("Please enter the patient new gender: ");
	scanf("%s",current -> gender);
	
	return current;
}

void reserve_slot(node*head,u32 ID,u8 n){
	
	node* current = head;
	
	
  if (n < 1 || n > 5) {
    printf("The slot number is not valid.\n");
    return;
  }
  current -> reserve= res[n-1].arr;
  // Mark the slot as reserved
  res[n-1].arr = "";

  // Print a confirmation message
  printf("Slot number %d reserved for patient ID %d.\n", n, ID);
}

void cancel_res(node *head,u8 n){
	node* current = head;
	
	
  
  res[n-1].arr=current -> reserve;
  // Mark the slot as reserved
  current-> reserve = NULL;

  // Print a confirmation message
  printf("Slot number %d was canceled\n", n);
}
void print(node *head){
	
	if (listlength == 0){
		printf("the list is empty\n");

		}
	
	else{
		u16 i=1;
		
		node *last = head;
		printf("Patient (%i) ID : %i\n",i,last -> ID);
		printf("Patient (%i) name : %s\n",i,last -> name);
		printf("Patient (%i) age : %i\n",i,last -> age);
		printf("Patient (%i) ID : %s\n",i,last -> gender);
		printf("___________________________________________\n");
		while((last -> next) != NULL){
			i++;
			last =last -> next;
		printf("Patient (%i) ID : %i\n",i,last -> ID);
		printf("Patient (%i) name : %s\n",i,last -> name);
		printf("Patient (%i) age : %i\n",i,last -> age);
		printf("Patient (%i) ID : %s\n",i,last -> gender);
		printf("___________________________________________\n");
		}
	}	
	
}
