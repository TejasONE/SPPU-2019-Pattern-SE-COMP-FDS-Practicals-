#include <iostream>
#include <string.h>
using namespace std;

class node
{
friend class list;
int prnno;
char name[30];
node *next;

public:
node(int d,char s[10])
{
prnno=d;
strcpy(name,s);
next=NULL;
}
};

class list
{
node *start;

public:
list()
{
start=NULL;
}

void display()
{
node *ptr;
ptr=start;
cout<<"\n info is : \n";
while(ptr!=NULL)
{
cout<<"\n"<<ptr->prnno;
cout<<"\t"<<ptr->name;
ptr=ptr->next;
}
}
void insertmember();
void createmember();
void insertpresident();
void insertsecretary();
void deletemember();
void delete1();
void deletesecretary();
void deletepresident();
void count();
void reverse(node *);
void reverse1()
{
reverse(start);
}
void concatinate(list,list);
};
void list::insertmember()
{
int prnno;
char name[30];
node *ptr,*temp;
cout<<"\n Enter PRN No. : ";
cin>>prnno;
cout<<"\n Enter Name : ";
cin>>name;
temp=new node(prnno,name);
if(start==NULL)
{
start=temp;
}
else
{
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}
}

void list::insertpresident()
{
int prnno;
char name[30];
node *temp;
cout<<"\n Enter PRN No. : ";
cin>>prnno;
cout<<"\n Enter Name : ";
cin>>name;
temp=new node(prnno,name);
temp->next=start;
start=temp;
}

void list::insertsecretary()
{
int prnno;
char name[30];
node *ptr,*temp;
cout<<"\n Enter PRN No. : ";
cin>>prnno;
cout<<"\n Enter Name : ";
cin>>name;
temp=new node(prnno,name);
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}

void list::createmember()
{
int ch;
char ans;
do
{
cout<<"\n choose : ";
cout<<"\n 1-Member\n 2-Secretary\n 3-President\n\nEnter your choice : ";
cin>>ch;

switch(ch)
{
case 1: insertmember();
break;
case 2: insertsecretary();
break;
case 3: insertpresident();
break;
default:cout<<"Invalid choice ! ";
break;
}
cout<<"\n Insert more ?(y/n) :  ";
cin>>ans;
}while(ans=='y');
}

void list::delete1()
{
int ch;
char ans;
do
{
cout<<"\n choose : ";
cout<<"\n 1-Member\n 2-Secretary\n 3-President\n\nEnter your choice : ";
cin>>ch;

switch(ch)
{
case 1:deletemember();
break;
case 2:deletesecretary();
break;
case 3:deletepresident();
break;
default:cout<<"Invalid choice ! ";
break;
}

cout<<"\n Delete more ?";
cin>>ans;
}while(ans=='y');
}

void list::deletesecretary()
{
node *ptr,*prev;
ptr=start;
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=NULL;
delete ptr;
cout<<"\n Deleted";
}

void list::deletepresident()
{
node *ptr;
ptr=start;
start=start->next;
delete ptr;
cout<<"\n Deleted";
}
void list::deletemember()

{
node *ptr,*prev;
int p;
cout<<"\n Enter PRN No. To Delete : ";
cin>>p;
ptr=start;
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
if(ptr->prnno==p)
break;
}
if(ptr->next==NULL)
{
cout<<"\n Data not found !";
}
else if(ptr->prnno==p)
{
prev->next=ptr->next;
ptr->next=NULL;
delete ptr;
cout<<"\n Deleted";
}
}

void list::concatinate(list s1,list s2)
{
node *ptr;
ptr=s1.start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=s2.start;
s1.display();
}

int main()
{
int ch;
char ans;
list sll1,sll2,s1,s2;
do
{
cout<<"\nChoice\n";
cout<<"\n1) Create member\n2) Display\n3) Delete member\n4) Concatenate\n\nEnter the choice: ";
cin>>ch;

switch(ch)
{
case 1: sll1.createmember();
	break;
case 2: sll1.display();
	break;
case 3: cout<<"\n Enter the nodes to be deleted in list : ";
	sll1.delete1();
break;

case 4: sll2.createmember();
	sll1.concatinate(sll1,sll2);
	break;
default: cout<<"\n invalid choice ! ";
	break;
}
cout<<"\n\n Do you want to continue ?(y/n) : ";
cin>>ans;
}while(ans=='y');
return 0;
}
