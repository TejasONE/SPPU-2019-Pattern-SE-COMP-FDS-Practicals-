/*
Write C++ program for storing binary number using doubly linked lists. Write functions
a) To compute 1‘s and 2‘s complement
b) Add two binary numbers
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	long no;
	int name;
	struct node *next;
	struct node *prev;
}node;

int n,m;
node *create(int n);
int print(node *head);
void decToBinary(int m);

int main()
{
	node *head;

	cout<<"Enter no of seats: ";
	cin>>n;
	head = create(n);	
	print(head);
	return 0;
}



node *create(int n)
{
	int i;
	node *head,*p,*q;
	cout<<"Enter 1 element : ";
	head=new node;
	head->prev=NULL;
	cin>>head->name;
	head->next=NULL;
	p=head;
	m=p->name;
	decToBinary(m);
	cout<<"\n";
	for(i=1;i<n;i++)
	{
		p->next=new node;
		q=p->next;
		q->prev=p;
	        p=q;
		p->next=NULL;
		cout<<"Enter your "<<i+1<<" number : ";
		cin>>p->name;
		m=p->name;      
	        decToBinary(m);
	        cout<<"\n";
	}
	return head;
}

/*
n=0
n / 2 
store reminder in answer 
repeat above 2 steps while n != 0
reverse answer
*/
void decToBinary(int m)
{
        int binaryNum[100],binary[100];       
        int j, i = 0 ,k ,carry=1;

        while (m > 0) 
        {
                binaryNum[i] = m % 2;   //store in binaryNum
                m = m / 2;
                i++;
        }
        
        cout<<"Your binary num is : ";
        for ( j = i - 1; j >= 0; j--)   //rev print
        {
              
                cout<<binaryNum[j];
        }
        
        
        cout<<"\n1st compliment is : ";
        for (  j = i - 1; j >= 0; j--)
        {
                if(binaryNum[j]==0)
                        binaryNum[j]=1;
                else
                        binaryNum[j]=0;

                cout<<binaryNum[j];
        }
        
        
        cout<<"\n2's complint is : ";
        for (j =0; j <= i-1; j++)
        {
                if(binaryNum[j]==1 && carry==1)
                {        binary[j]=0;         }

                else if(binaryNum[j]==0 && carry==1)
                {
                        binary[j]=1;    //ulat
                        carry=0;
                }
                else
                        binary[j]=binaryNum[j];
                
                
        }
        for ( j = i - 1; j >= 0; j--)
        {
              
                cout<<binary[j];
        }
        cout<<"\n";
        
        
}



int print(node *head)
{
        cout<<"Your doubly linked list is :\n";
	while(head!=NULL)
	{
		cout<<head->name<<endl;
		head=head->next;
	}
	return 0;
}

