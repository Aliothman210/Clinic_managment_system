#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "functions.h"



int main(){
	u16 x;
	u8 exit=0;

	printf("\n***********Welcome to CMS***********\n\n");
	while(exit ==0){
		
	
	printf("Press 1 for admin mode\nPress 2 for user mode\nFor exit press 9\n");
	scanf("%d",&x);
	switch (x){
		case 1:
		admin_mode();
		break;
		case 2:
		user_mode();
		break;
		case 9:
		exit =1;
		break;
		default:
		printf("Try again\n");
		break;
	}
	}
}