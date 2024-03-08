#ifndef functions_h
#define functions_h

typedef struct rserved_slots
{
	char *arr ;
}slots;

typedef struct Node_type node;

struct Node_type{
    u32 ID;
    u8 name[50];
    u8 age;
    u8 gender[10];
    char *reserve;
    node *next;
    
};
void add_patient(u32 ID);
node* search_node( node *head, u32 data);
void admin_mode(void);
void user_mode(void);
node* edit_patient(node* head);
void reserve_slot(node*head,u32 ID,u8 n);
void view(node *head);
void cancel_res(node *head,u8 n);
void print(node *head);
#endif