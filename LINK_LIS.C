#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct Link_List
{
	int  Data;
	struct Link_List *Next;
} *New_Node,*First,*Temp,*Dummy=NULL;

void Create(void);
void Display(void);
void Insert_First(void);
void Delete_First(void);
void Insert_Last(void);
void Delete_Last(void);
void Insert_Between(void);
void Delete_Specific(void);
void Search(void);
void Update(void);

int i=0,No_E=0;
int Search_Now=0,Flag=0;

void main()
{
	char Choice;

 clrscr();
	while(1)
		{
			window(1,1,80,25);
			textbackground(BLACK);
			clrscr();

			gotoxy(23,1); for(i=0; i<37; i++) printf("*");
			gotoxy(23,2); printf("*");
			gotoxy(38,2); printf("Choices              *");
			gotoxy(23,3); for(i=0; i<37; i++) printf("*");

			gotoxy(23,4);  printf("*   #   --->    Exit                *");
			gotoxy(23,5);  printf("*   0   --->    Create              *");
			gotoxy(23,6);  printf("*   1   --->    Display             *");
			gotoxy(23,7);  printf("*   2   --->    Insert First        *");
			gotoxy(23,8);  printf("*   3   --->    Delete First        *");
			gotoxy(23,9);  printf("*   4   --->    Insert Last      	  *");
			gotoxy(23,10); printf("*   5   --->    Delete Last         *");
			gotoxy(23,11); printf("*   6   --->    Insert between      *");
			gotoxy(23,12); printf("*   7   --->    Delete Specific     *");
			gotoxy(23,13); printf("*   8   --->    Search              *");
			gotoxy(23,14); printf("*   9   --->    Update Record       *");
			gotoxy(23,15); for(i=0; i<37; i++) printf("*");
			fflush(stdin);
			printf("\n Enter Your Choice:- ");
			Choice=getch();
			switch(Choice)
				{
					case '#': exit(0);
					case '0': Create();          getch(); break;
					case '1': Display();         getch(); break;
					case '2': Insert_First();    getch(); break;
					case '3': Delete_First();    getch(); break;
					case '4': Insert_Last();     getch(); break;
					case '5': Delete_Last();     getch(); break;
					case '6': Insert_Between();  getch(); break;
					case '7': Delete_Specific(); getch(); break;
					case '8': Search();          getch(); break;
					case '9': Update();          getch(); break;
					default : printf("\n\n\t\t     -> Error:- ");
								 printf("\n\n\t\t\t   Invailid Choice");
								 printf("\n\n\n\t\t\t Press Any Key......");
								 getch();
				}
		}
}

void Create(void)
{
	clrscr();

	printf("How Many Elements :- ");
	scanf("%d",&No_E);
	printf("\n");

	for(i=0; i<No_E; i++)
		{
			New_Node=(struct Link_List*)malloc(sizeof(struct Link_List*));
			fflush(stdin);
			printf("Enter Data :- ");
			scanf("%d",&New_Node->Data);

			New_Node->Next=NULL;

			if(First==NULL)
				{
					First=New_Node;
				}
			else
				{
					for(Temp=First; Temp->Next!=NULL; Temp=Temp->Next);

					Temp->Next=New_Node;
				}
		}
}

void Display(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	gotoxy(32,1); printf("List Of The Elements\n\n");

	for(Temp=First; Temp!=NULL; Temp=Temp->Next)
		{
			printf("%d -> ",Temp->Data);
		}
	printf("NULL");
}

void Insert_First(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	New_Node=(struct Link_List*)malloc(sizeof(struct Link_List*));
	fflush(stdin);
	printf("Enter New Element :- ");
	scanf("%d",&New_Node->Data);

	New_Node->Next=First;

	First=New_Node;
}

void Delete_First(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	if(First==NULL)
		{
			printf("\n\nLIST IS  EMPTY");
		}
	else
		{
			Temp=First;
			First=First->Next;
			free(Temp);
			printf("\n\nElement Is Delete");
		}
}

void Insert_Last(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	New_Node=(struct Link_List*)malloc(sizeof(struct Link_List*));
	fflush(stdin);
	printf("Enter New Element :- ");
	scanf("%d",&New_Node->Data);

	New_Node->Next=NULL;

	if(First==NULL)
		{
			First=New_Node;
		}
	else
		{
			for(Temp=First; Temp->Next!=NULL; Temp=Temp->Next);

			Temp->Next=New_Node;
		}
}

void Delete_Last(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	if(First==NULL)
		{
			printf("\nLIST IS EMPTY");
		}
	else if(First->Next==NULL)
		{
			free(First);
			First=NULL;
			printf("\n\nElement Is Deleted");
		}
	else
		{
			for(Temp=First; Temp->Next->Next!=NULL; Temp=Temp->Next);

			free(Temp->Next->Next);
			Temp->Next=NULL;
			printf("\n\nElement Is Deleted");
		}
}

void Insert_Between(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	Search();

	if(Flag==1)
		{
			New_Node=(struct Link_List*)malloc(sizeof(struct Link_List*));
			fflush(stdin);
			printf("\n\nEnter New Element :- ");
			scanf("%d",&New_Node->Data);

			New_Node->Next=Temp->Next;
			Temp->Next=New_Node;
		}
}

void Delete_Specific(void)
{
	int Delete_Now=0;

	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	if(First==NULL)
		{
			printf("LIST IS EMPTY");
			return;
		}
	fflush(stdin);
	printf("Which Data You Want To Delete:- ");
	scanf("%d",&Delete_Now);

	if(First->Data==Delete_Now)
		{
			Delete_First();
			return;
		}

	for(Temp=First; Temp!=NULL; Temp=Temp->Next)
		{
			if(Delete_Now==Temp->Next->Data)
				{
					printf("\nFound");
					Flag=1;
					Dummy=Temp->Next;
					Temp->Next=Dummy->Next;
					printf("\n\nElement Is Deleted");
					free(Dummy);
					return;
				}
		}

	if(Flag==0)
		{
			printf("\n\nNot Found");
		}
}

void Search(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	if(First==NULL)
		{
			printf("LIST IS EMPTY");
			return;
		}

	fflush(stdin);
	printf("What You Search:- ");
	scanf("%d",&Search_Now);

	for(Temp=First; Temp!=NULL; Temp=Temp->Next)
		{
			Flag=0;
			if(Search_Now==Temp->Data)
				{
					printf("\n\n%d Is Found",Temp->Data);
					Flag=1;
					return;
				}
		}
	if(Flag==0)
		{
			printf("\n\nNot Found");
		}
}

void Update(void)
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();

	Search(); // Here Search Function Is Calling

	if(Flag==1)
		{
			fflush(stdin);
			printf("\nEnter New Element:- ");
			scanf("%d",&Temp->Data);
			printf("\n\n\n Record Is Updated");
		}
}