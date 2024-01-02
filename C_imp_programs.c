#include <stdio.h>
#include<limits.h>
#define SIZE 50

int main()
{
    int arr[SIZE],n,i,first,second;
    printf("enter the no of elements in an array : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter tha value of arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    first = second = INT_MAX;
    for(i=0; i<n; i++)
    {
        if(arr[i] < first)
        {
            second = first;
            first = arr[i];
        }
        //if arr[i] lies between first and second then update second */
        else if(arr[i] < second && arr[i] != first)
            second = arr[i];
        
    }
    printf("%d\n%d\n", first,second);
    return 0;
}
-------------------------------------------------------------
#include <stdio.h>
#include<string.h>

int main()
{
    char str[20]; 
    int n,i,j,k;
    printf("enter a string : ");
    scanf("%s",str);
    for(i=0; str[i]; i++)
        for(j=i+1; str[j]; j++)
            if(str[i] == str[j])
            {
                for(k=j; str[k]; k++)
                {
                    str[k] = str[k+1];
                }
                j--;
            }
    printf("After removing duplicates in string is %s", str);
    
    return 0;
}
-------------------------------------------------------------
#include <stdio.h>
#include<limits.h>
#define SIZE 50

int main()
{
    int arr[SIZE],n,i,j,k;
    printf("entrr the no of elements in an array : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter tha value of arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(arr[i] == arr[j])
            {
                for(k=j; k<n; k++)
                {
                    arr[k] = arr[k+1];
                }
                 // decrease the size of array after removing duplicate element  
                n--;
                // if the position of the elements is changes, don't increase the index j 
                j--;
            }
    printf("After removing duplicates in array\n");
    for(i=0; i<n; i++)
    {
        
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
--------------------------------------------------------------
#include <stdio.h>
#include<limits.h>
#define SIZE 50

int main()
{
    int arr[SIZE],n,i,j,k;
    printf("entrr the no of elements in an array : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter tha value of arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("After removing alternatives in array\n");
    for(i=0; i<n; i+=2)
    {
        printf("%d\t",arr[i]);
        
    }
    
    return 0;
}
-------------------------------------------------------------
#include <stdio.h>
#include<limits.h>
#define SIZE 50

int main()
{
    int arr[SIZE],n,i,first,second;
    printf("entrr the no of elements in an array : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter tha value of arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    first = second = INT_MIN;
    for(i=0; i<n; i++)
    {
        if(arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if( arr[i] > second && arr[i] != first)
            second = arr[i];
    }
    printf("first highest and second highest elements are %d and %d ",first,second);
    return 0;
}
-------------------------------------------------------------
//SWAP the matrix diagonals
enter the matrix row-wise(2x2):
1 2
3 4
o/p:

    2       1 
    4       3 

-----------------------------------
#include <stdio.h>
#define ROW 2
#define COL 2
int main(void)
{
    int mat[ROW][COL];
    int i,j,temp;
    printf("enter the matrix row-wise(%dx%d): \n",ROW,COL);
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
          scanf("%d",&mat[i][j]);
    }
    if(i == j)
    {
        for(i=0; i<ROW; i++)
        {
                temp = mat[i][i];
                mat[i][i] = mat[i][ROW-i-1];
                mat[i][ROW-i-1] = temp;
            
        }
        for(i=0; i<ROW; i++)
        {
          for(j=0; j<COL; j++)
             printf("%5d \t",mat[i][j]);
          printf("\n");
        }
    }
	else
		printf("matrix should be a square matrix\n");
    return 0;
}
-----------------------------------------------------------
//print the diagonal elements
enter the matrix row-wise(3x3):
1 2 3
4 5 6
7 8 9
o/p:

1       3
5       5
9       7

#include <stdio.h>
#define ROW 3
#define COL 3
int main(void)
{
    int mat[ROW][COL];
    int i,j,temp;
    printf("enter the matrix row-wise(%dx%d):\n",ROW,COL);
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
          scanf("%d",&mat[i][j]);
    }
    if(i == j)
    {
        for(i=0; i<ROW; i++) 
        {
             printf("%d\t%d\t",mat[i][i],mat[i][ROW-i-1]);
             printf("\n");
        }
    }
	else
		printf("matrix should be a square matrix\n");
    return 0;
}
----------------------------------------------------------
#include <stdio.h>
int main()
{
    int data,ldata,rdata,l,r;
    printf("enter the data : ");
    scanf("%d",&data);
    
    for(l=sizeof(int)*8-1; l>=0; l--)
        printf("%d",(data>>l)&1);
    printf("\n");
	
    for(l=sizeof(int)*8-1,r=0; l>r; l--,r++)
    {
        ldata = (data>>l)&1;
        rdata = (data>>r)&1;
        
       if(ldata != rdata)
        {
            data = data^(1<<l);
            data = data^(1<<r);
       }
    }
	
    for(l=sizeof(int)*8-1; l>=0; l--)
        printf("%d",(data>>l)&1);
    printf("\n");
    return 0;
}
==========================================================
//sum of diagonals of matrix:
enter the matrix row-wise(3x3):
1 2 3
4 5 6
0 2 9
o/p:
sum = 15
osum = 8
#include <stdio.h>
#define ROW 3
#define COL 3
int main(void)
{
    int mat[ROW][COL];
    int i,j,temp,sum =0,osum=0;
    printf("enter the matrix row-wise(%dx%d):\n",ROW,COL);
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        scanf("%d",&mat[i][j]);
    }
    if(i == j)
    {
        for(i=0; i<ROW; i++) 
        {
            sum = sum+mat[i][i];
            osum = osum+mat[i][ROW-i-1];
        }
        printf("sum = %d\n",sum);
        printf("osum = %d\n",osum);
    }
	else
		printf("matrix should be a square matrix\n");
    return 0;
}
-----------------------------------------------------------------------
//matirx is a diagonal matrix or not
enter the matrix row-wise(3x3):
1 0 0
0 1 0
0 0 1
Given Matrix is a diagonal Matrix.

#include <stdio.h>
#define ROW 3
#define COL 3
int main(void)
{
    int mat[ROW][COL];
    int i,j,index = 0;
    printf("enter the matrix row-wise(%dx%d):\n",ROW,COL);
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        scanf("%d",&mat[i][j]);
    }
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(i!=j && mat[i][j]!=0)
            {
                index=1;
                break;
            }
        }
    }
    if(index==1)
        printf("Given Matrix is not a diagonal Matrix.");
    else
        printf("Given Matrix is a diagonal Matrix.");
    
}
-------------------------------------------------------------------------
#include <stdio.h>
#define SIZE 10
char *User_strstr(char *a,char *b);
int main(void)
{
    char str1[20],str2[20],*ptr;
    printf("enter 2 strings: ");
    scanf("%s",str1);
    scanf("%s",str2);
    ptr = str1;
    if(ptr = User_strstr(ptr,str2))
        printf("found at index %d\n",ptr-str1);
    else
        printf("not found");
	return 0;
};
char *User_strstr(char *a,char *b)
{
    int i,j;
    for(i=0; a[i]; i++)
    {
        if(a[i] == b[0])
        {
            for(j=1; b[j]; j++)
                if(b[j]!=a[i+j])
                    break;
            if(b[j]=='\0')
                  return (a+i);
        }
    }
}
o/p:
enter 2 strings: HELLOSURENDRAREDDY
SURENDRA
found at index  5
=========================================================================

#include <stdio.h>
#define SIZE 100
int top = -1;
void push();
void pop();
void display();
int stack[SIZE];
int N,data;
int main()
{
    int choice;
    printf("enter the no of elements in the stack : ");
    scanf("%d",&N);
    printf(" =====Stack implementation using Array ==========\n");
    while(choice!=4)
    {  
        printf("\nenter your choice[1.push 2.pop 3.display]: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("wrong choice\n");
        return 0;
        }
    }
}
void push()
{
    printf("enter the data : ");
    scanf("%d",&data);
    if (top == N-1)
        printf("stack is overflow\n");
    else
        stack[++top] = data;
}
void pop()
{
      if(top == -1)
        printf("stack is underflow\n");
    data = stack[top];
     printf("%d\n",data);
    top --;
}
void display()
{
    int i;
    for(i = top;i>=0;i--)
        printf("%d\t",stack[i]);
}
===================================================
// C program to find the array element that appears only
// once

#include <stdio.h>
#define SIZE 10
int nonrepno(int arr[],int n);
int i,res;
int main(void)
{
    int arr[SIZE],n;
    printf("enter the no of elements in an arry: ");
    scanf("%d",&n);
    for(i=0; i< n; i++)
    {
        printf("enter the value of arr[%d] is : ",i);
        scanf("%d",&arr[i]);
    }
    printf("i am occuring once here : %d\n",nonrepno(arr,n));
    return 0;
}
int nonrepno(int arr[],int n)
{
    res = arr[0];
    for(i=1; i<n; i++)
        res = res ^ arr[i];
    return res;
}


========================================================
frequency of each character in a string
#include <stdio.h>
#include<string.h>
int count_occurance(char str[]);
int main()
{
    char str[30];
    printf("enter a string : ");
    scanf("%s",str);
    count_occurance(str);
    return 0;
}
int count_occurance(char str[])
{
    char ch;
    int i,j,count,n;
    n = strlen(str);
    for(i=0; i<n; i++)
    {
        if(str[i]!='\0')
        {
            ch = str[i];
            count = 0;
            for(j=0; j<n; j++)
                if(str[j] == ch)
                {
                    count++;
                    str[j] = 0;
                }
            printf("%c occurs %d times\n",ch,count);
        }
    }
}
o/p:
enter a string : surendra
s occurs 1 times
u occurs 1 times
r occurs 2 times
e occurs 1 times
n occurs 1 times
d occurs 1 times
a occurs 1 times
================================================================
//Adding Two Numbers using Linked Lists 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* start3 = NULL;
struct node* addatbeg(struct node *start, int num);
struct node* display(struct node *start);
struct node* convtolist(struct node *start,int n);
struct node* reverse(struct node* start);
struct node* addtwolists(struct node* start1,struct node* start2);
int main(void)
{
	int a,b;
	printf("enter two numbers:\n" );
	scanf("%d%d",&a,&b);
	
	printf("linked list representation of first number: \n");
	start1 = convtolist(start1,a);
	display(start1);
	
	printf("\nlinked list representation of second number: \n");
	start2 = convtolist(start2,b);
	display(start2);

	//reverse
	start1 = reverse(start1);
	printf("\nreverse the first linked list is : \n");
	display(start1);
	start2 = reverse(start2);
	printf("\nreverse the second linked list is : \n");
	display(start2);

	//add of two links
	printf("\naddition of two linked lists is : \n");
	start3 = addtwolists(start1,start2);
	display(start3);
	
	return 0;
}
struct node* addtwolists(struct node* start1,struct node* start2)
{
    struct node* ptr1 = start1;
    struct node* ptr2 = start2;
    struct node* start3 = NULL;
    int carry = 0,sum;
    while(ptr1 || ptr2)
    {
        sum = 0;
        if(ptr1)
            sum = sum + ptr1->data;
        if(ptr2)
            sum = sum + ptr2->data;

        sum = sum + carry;
        carry = sum/10;
        sum = sum%10;

        start3 = addatbeg(start3,sum);

        if(ptr1)
            ptr1 = ptr1->link;
        if(ptr2)
            ptr2 = ptr2->link;
    }
    if(carry)
        start3 = addatbeg(start3,carry);
    return start3;
}
struct node* convtolist(struct node* start, int n)
{
	while(n != 0)
	{
		start = addatbeg(start, n%10);
		n = n/10;
	}
	return start;
}
struct node* reverse(struct node* start)
{
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* ptr =start;
    while(ptr!= NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;

    return start;
}
struct node* addatbeg(struct node* start, int num)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	//temp->link = NULL;
	
	temp->link = start;
	start = temp;
	return start;
}
struct node* display(struct node* start)
{
	struct node *ptr;
	ptr = start;
	if(start == NULL)
		printf("List is Empty");
	else {
	    while(ptr->link != NULL)
	    {
		   printf("%d->",ptr->data);
		   ptr = ptr->link;
	    }
		printf("%d ",ptr->data);
	}
}
output:
enter two numbers:
123 456
linked list representation of first number: 
1 2 3 
linked list representation of second number: 
4 5 6 
reverse the first linked list is : 
3 2 1 
reverse the second linked list is : 
6 5 4 
addition of two linked lists is : 
5 7 9 
==================================================================================
Node* getIntesectionNode(Node* head1, Node* head2)
{
    while (head2) {
        Node* temp = head1;
        while (temp) {
            // if both Nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // intersection is not present between the lists
    return NULL;
}
----------------------------------------------------

