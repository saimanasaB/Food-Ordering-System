#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
void welcome();
void createMenu();
void displayMenu();
void addCart(char username[20]);
void displayCart(char username[20]);
struct Item *searchItem(int );
void editItem();
void enqueueOrder(char username[20]);
void dequeueOrder();
void displayOrder();
void spacing(char name[50], float,int);
struct Item		
{
    char name[50];
    float rate;
    struct Item *next;
}*root;
struct FoodItem
{
    char username[20];
	int qty;
	float price;
	struct FoodItem *next;
	struct Item *item;
}*top=NULL;
struct Order
{
    float total;
    char username[20];
    struct Order *next;
}*rear,*front;
int main()
{
    int loginchoice, customerchoice, phone, adminchoice, editchoice, displaychoice, password;
	char username[20], adminid[20];
	welcome();
	system("cls");
    do
    {
    	system("cls");
    	printf("\n\t\t\t\t=======================================================");
		printf("\n\n\t\t\t\t\t\t\tLOGIN\n");
		printf("\n\t\t\t\t=======================================================");
		printf("\n\n\t\t\t\t\t\t\t1. User");
		printf("\n\n\t\t\t\t\t\t\t2. Admin");
		printf("\n\n\t\t\t\t\t\t\t3. Exit\n");
		printf("\n\t\t\t\t=======================================================");
		printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
		scanf("%d", &loginchoice);
	    switch(loginchoice)
	    {
	        case 1:
	        	system("cls");
				printf("\n\n\n\n\n\n\t\t\t\t\t\tEnter username : ");
				scanf("%s", &username);
				printf("\n\t\t\t\t\t\tEnter phone number : ");
				scanf("%d", &phone);
				do
				{
					system("cls");
				    printf("\n\t\t\t\t==========================================================");
					printf("\n\t\t\t\t\t\tWELCOME TO ZAISA RESTAURANT");
				    printf("\n\t\t\t\t==========================================================");
					printf("\n\n\t\t\t\t\t1. Order");
					printf("\n\n\t\t\t\t\t2. View Cart");
					printf("\n\n\t\t\t\t\t3. Proceed to Checkout");
					printf("\n\n\t\t\t\t\t4. Cancel");
					printf("\n\t\t\t\t==========================================================");
					printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
				    scanf("%d",&customerchoice);
					switch(customerchoice)
				    {
				        case 1: 
							addCart(username);
				            break;
				        case 2: 
							displayCart(username);
				            printf("\n\n\t\t\t\t\t  Press any button to return to previous screen");
				            getch();
				            break;
				        case 3: 
							enqueueOrder(username);
				            displayCart(username);
				            printf("\n\n\t\t\t\t\t\t  Order placed successfully ");
				            printf("\n\n\t\t\t\t\t  Press any button to return to main screen");
				            getch();
				            break;
				    }
				}while(customerchoice!=0 && customerchoice!=3 && customerchoice!=4);	
				break;		    
	        case 2:
	            system("cls");				
				printf("\n\n\n\n\n\n\t\t\t\t\t\tEnter admin id : ");
				scanf("%s", &adminid);
				printf("\n\t\t\t\t\t\tEnter password : ");
				scanf("%d", &password);
				if(strcmp(adminid,"zaisa")==0 && password==1234)
				{
					do
					{
						system("cls");
						printf("\n\t\t\t\t==========================================================");
						printf("\n\t\t\t\t\t\t\tADMIN PANEL");
					    printf("\n\t\t\t\t==========================================================");
						printf("\n\n\t\t\t\t\t\t1. Edit Menu");
						printf("\n\n\t\t\t\t\t\t2. Display Orders");
						printf("\n\n\t\t\t\t\t\t3. Log Out");
						printf("\n\t\t\t\t==========================================================");
						printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
					    scanf("%d",&adminchoice);
					    switch(adminchoice)
					    {
					    	case 1:
					    		do
                                {
                                    system("cls");
								    printf("\n\t\t\t\t==========================================================");
									printf("\n\t\t\t\t\t\t\tEDIT MENU");
									printf("\n\t\t\t\t==========================================================");
									printf("\n\n\t\t\t\t\t\t1. Add items");
									printf("\n\n\t\t\t\t\t\t2. Edit Items");
									printf("\n\n\t\t\t\t\t\t3. View Menu");
									printf("\n\n\t\t\t\t\t\t4. Back to Main Menu");
									printf("\n\t\t\t\t==========================================================");
									printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");  
									scanf("%d", &editchoice);         
								    switch(editchoice)
								    {
								    	case 1:
								    		createMenu();
								    		printf("\n\n\t\t\t\t\tPress any key to return to previous screen");
								    		getch();
								    		break;
								        case 2:
								            editItem();
								            break;
								        case 3:
								            system("cls");
								            displayMenu();
								            printf("\n\n\t\t\t\t\t  Press any button to return to previous screen");
								            getch();
								            break;
								    }
                                }while(editchoice!=4);
                                system("cls");
					    		break;
					    	case 2:
					    		do
                                {
                                    system("cls");
								    printf("\n\t\t\t\t==========================================================");
									printf("\n\t\t\t\t\t\t\tORDERS");
									printf("\n\t\t\t\t==========================================================");
									printf("\n\n\t\t\t\t\t\t1. Display Orders");
									printf("\n\n\t\t\t\t\t\t2. Serve Orders");
									printf("\n\n\t\t\t\t\t\t3. Back to Main Menu");
									printf("\n\t\t\t\t==========================================================");
									printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");                    
								    scanf("%d", &displaychoice);
								    switch(displaychoice)
								    {
								        case 1:
								        	system("cls");
								            displayOrder();
								            getch();
								            break;
										case 2:								    		
								            system("cls");
								            dequeueOrder();
								            getch();
								            break;
								    }
                                }while(displaychoice!=3);
					    		break;
						}						
					}while(adminchoice!=3);					
				}
				else
				{
					system("cls");
					printf("\n\n\n\t\t\t\t\tEnter valid admin id and password");
					printf("\n\n\t\tPress any key to main screen");
					getch();
				}
	            break;
	        case 3:
	            break;
		}
	}while(loginchoice!=3);	
}
void welcome()
{
	int i;
	char welcome[50]="WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]="FOOD ORDERING";
	char welcome4[50]=" SYSTEM";
	printf("\n\n\n\n\n\t\t\t\t\t      ");
	for(i=0;i<strlen(welcome);i++)		/*To print "WELCOME" and strlen(welcome)=7*/
	{
		printf(" %c",welcome[i]);
		Sleep(100);
	}
	printf("\n\n\t\t\t\t\t\t ");
	for(i=0;i<strlen(welcome2);i++)		/*To print "TO" and strlen(welcome2)=2*/
	{
		printf(" %c",welcome2[i]);
		Sleep(100);
	}
	printf("\n\n\t\t\t\t\t");
	for(i=0; i<strlen(welcome3) ;i++)		/*To print "FOOD ORDERING" and strlen(welcome3)=14*/
	{
		printf(" %c",welcome3[i]);
		Sleep(100);
	}
	printf("\n\n\t\t\t\t\t     ");
	for(i=0; i<strlen(welcome4) ;i++)		/*To print "SYSTEM" and strlen(welcome4)=10*/
	{
		printf(" %c",welcome4[i]);
		Sleep(100);
	}
	printf("\n\n\nPress enter to view menu... ");
	getch();
}
void createMenu()
{
	system("cls");
	char names[10];
	struct Item *temp, *newnode;
	int n,i;
	printf("Enter how many products you want to add ? ");
	scanf("%d", &n);	
    for(i=0;i<n;i++)
    {
        temp=(struct Item*)malloc(sizeof(struct Item));
		printf("\nEnter item : ");
		scanf("%s", &temp->name);
		printf("Enter rate : ");
		scanf("%f", &temp->rate);
		temp->next=NULL;
		if(root==NULL)
			root=temp;
		else
		{
			newnode=root;
			while(newnode->next!=NULL)
			{
				newnode=newnode->next;
			}
			newnode->next=temp;
		}
    }
}
void displayMenu()
{
    struct Item *temp;
    int i=1;
    temp = root;
    system("cls");
    printf("\n\t\t\t\t\t======================================================");
	printf("\n\t\t\t\t\t\t\t\tMENU\n\t\t\t\t\t");
	printf("======================================================");
    printf("\n\t______________________________________________________________________________________________________");
    printf("\n\tSr. No.\t\tName\t\t\t\t\t\t\t\t\t\tRate");
    printf("\n\t______________________________________________________________________________________________________");
    while(temp!=NULL)
    {
        Sleep(20);
        printf("\n\t%d\t\t%s",i++,temp->name);
        spacing(temp->name,temp->rate,83);
        printf("%0.2f", temp->rate);
        temp = temp->next;
    }
    printf("\n\t______________________________________________________________________________________________________");
}
void addCart(char username[20])
{
    int choice,quantity,x,flag=1;
    float rate,amount;
    struct FoodItem *newnode;
    again: system("cls");
    displayMenu();
    if(flag==0)
    {
        printf("\n\n\t\t\t\t\tPlease enter a valid choice\n");
    }
    else
    {
        printf("\n");
    }
    printf("\n\t\t\t\t\t0 -> Cancel\n\n\t\t\t\t\tEnter sr. no. of item : ");
    scanf("%d",&choice);
    if(choice!=0)
    {
        flag=1;
        newnode=(struct FoodItem*)malloc(sizeof(struct FoodItem));
        if (searchItem(choice)!=NULL)
        {
            newnode->item = searchItem(choice);
            system("cls");
            printf("\n\t\t\t\t\t======================================================");
			printf("\n\t\t\t\t\t\t\t\tORDER\n\t\t\t\t\t");
			printf("======================================================");
			printf("\n\n\t\t\t\t\t\tCurrently ordering: ");
            printf("%s",newnode->item->name);
            x = 0;
            while(username[x]!='\0')
            {
               newnode->username[x] = username[x];
               x++;
            }
            newnode->username[x]='\0';
            printf("\n\n\t\t\t\t\t\t\tQuantity : ");
            scanf("%d",&quantity);
            newnode->qty=quantity;
            rate=newnode -> item -> rate;
            amount=quantity*rate;
            newnode->price=amount;
            if(top==NULL)
            {
                newnode->next=NULL;
                top=newnode;
            }
            else
            {
                newnode->next=top;
                top=newnode;
            }
            displayCart(username);            
            printf("\n\n\t\t\t\t\t  Press any button to return to menu");
            getch();
        }
        else
        {
            flag=0;
            goto again;
        }
    }
}
void displayCart(char username[20])
{
    int i=1;
    float sum=0;
    struct FoodItem *temp;
    char str[50]="\0";
    temp=top;
    system("cls");
    printf("\n\t\t\t\t\t======================================================");
	printf("\n\t\t\t\t\t\t\t\tCART\n\t\t\t\t\t");
	printf("======================================================");
    printf("\n\t______________________________________________________________________________________________________");
    printf("\n\tSr. No.\t\tName\t\t\t\t\tQty\t\t\t\tPrice");
    printf("\n\t______________________________________________________________________________________________________");
    if(top==NULL)
        printf("\n\n\t\t\t\t\t\t\tCart is empty\n");
    else
    {
        while(temp!=NULL && !(strcmp(temp->username, username)))
        {
            Sleep(20);
            printf("\n\t%d\t\t%s",i++,temp->item->name);
            spacing(temp->item->name,temp->qty,42);
            printf("%d",temp->qty);
            spacing(str,temp->price,40);
            printf("%0.2f", temp->price);
            sum=sum+temp->price;
            temp=temp->next;
        }
         printf("\n\t______________________________________________________________________________________________________");
            printf("\n\tTOTAL");
            spacing("TOTAL",sum,95);
            printf("Rs. %0.2f",sum);
    }
    printf("\n\t______________________________________________________________________________________________________");
}
struct Item *searchItem(int n)
{
    int i=1,x;
    struct Item *temp;
    temp = root;
    while(temp!=NULL && i<n)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}
void editItem()
{
    char name[50];
    int choice,x,flag=1,n;
    float rate;
    struct Item *temp;
    again:
    system("cls");
    displayMenu();
    if(flag==0)
    {
        printf("\n\n\t\t\t\t\tPlease enter a valid choice\n");
    }
    else
    {
        printf("\n");
    }
    printf("\n\t\t\t\t\t0 -> Cancel\n\n\t\t\t\t\tEnter sr. no. of item : ");
    scanf("%d",&n);
    if(n!=0)
    {
        temp = searchItem(n);
        if(temp!=NULL)
        {
            flag=1;
            system("cls");
            printf("\n\t\t\t\t\t\tCurrently editing: ");
            printf("%s",temp->name);
            printf("\n\n\t\t\t\t\t\tWhich field do you want to edit?");
			printf("\n\n\t\t\t\t\t\t1. Name");
			printf("\n\t\t\t\t\t\t2. Rate");
			printf("\n\t\t\t\t\t\t0 -> Back");
			printf("\n\n\t\t\t\t\t\tEnter choice : ");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n\t\t\t\t\t\tEnter name :");
                scanf("%s", &name);
                x = 0;
                while(name[x]!='\0')
                {
                   temp -> name[x] = name[x];
                   x++;
                }
                temp->name[x]='\0';
            }
            else if(choice==2)
            {
                printf("\n\t\t\t\t\t\tEnter rate :");
                scanf("%f",&rate);
                temp -> rate = rate;
            }
            if(choice!=0)
            {
                goto again;
            }
        }
        else
        {
            flag=0;
            goto again;
        }
    }
}
void enqueueOrder(char username[20])
{
    int x;
    struct Order *newnode;
    struct FoodItem *temp;
    newnode = (struct Order *)malloc(sizeof(struct Order));
    newnode->total=0;
    strcpy(newnode->username,username);
    temp = top;
    while(temp!=NULL && !(strcmp(temp->username, username)))
    {
        newnode -> total += temp -> price;
        temp = temp->next;
    }
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeueOrder()
{
    struct Order *temp;
    char name[20];
        printf("\n\n\n\n\n\n\n\t\t\t\t");
    if(front==NULL)
    {
	    printf("_____________________________________________________\n\n");
	    printf("\t\t\t\t\t\tNO PENDING ORDERS.");
	    printf("\n\t\t\t\t_____________________________________________________");
	}
    else
    {
        temp=front;
        strcpy(name,temp->username);
	    printf("_________________________________________________________\n\n\t\t\t\t\t");
        printf("Hi %s ! your order is ready to collect!",name);
        printf("\n\t\t\t\t_________________________________________________________");
        front=front->next;
        free(temp);
    }
}
void displayOrder()
{
    struct Order *temp1;
    char str1[100]="Name: ";
    char str[2]="\0";
    struct FoodItem *temp2;
    temp1=front;
    printf("\n\t\t\t\t\t======================================================");
	printf("\n\t\t\t\t\t\t\t\tORDERS\n\t\t\t\t\t");
	printf("======================================================");
    while(temp1!=NULL)
    {
        Sleep(20);
        printf("\n\n\t\t\t\t\t\tName: %s",temp1->username);
        spacing(strcat(str1,temp1->username), temp1->total,20);
        printf(" Total: ");
        printf("%0.2f",temp1->total);
        printf("\n\t\t\t_____________________________________________________________________________");
    	printf("\n\t\t\tItem\t\t\t\t\tQty\t\t\t\tPrice");
    	printf("\n\t\t\t_____________________________________________________________________________");
        temp2 = top;
        while(temp2!=NULL)
        {
            if(!(strcmp(temp2->username, temp1->username)))
            {
                printf("\n\t\t\t%s",temp2->item->name);
                spacing(temp2->item->name,temp2->qty,42);
                printf("%d",temp2->qty);
                spacing(str,temp2->price,32);
                printf("%0.2f", temp2->price);
            }
            temp2=temp2->next;
        }
        printf("\n\t\t\t_____________________________________________________________________________\n\n");
        temp1=temp1->next;
    }
    if(front==NULL)
    {
        printf("\n\n\t\t\t_____________________________________________________________________________\n\n");
        printf("\n\t\t\t\t\t\t\tNo orders");
        printf("\n\n\t\t\t_____________________________________________________________________________\n\n");
    }
}
void spacing(char name[50], float price,int space)
{
    int x=0,intpart,i;
    while(name[x]!='\0')
    {
        space--;
        x++;
    }
    intpart = (int)price;
    while(intpart!=0)
    {
        space--;
        intpart /= 10;
    }
    for(i=1;i<=space;i++)
    {
        printf(" ");
    }
}
