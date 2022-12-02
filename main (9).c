/*******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct stack
{
    char ele;
    struct stack*next;

};
void push(int);
char pop();
int precedence(char);
void evaluate(char []);
void push1(int);
int pop1();
struct stack*top=NULL;
int stack1[20],top1=-1;
int main()
{
    char infix[20],postfix[20];
    int i=0,j=0;
    printf("enter infix expression :");
    scanf(" %s",infix);
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))  // is alphanumeric
        postfix[j++]=infix[i];
        else
        {
            if(top==NULL)
            push(infix[i]);
            else
            {
                while(top!=NULL && (precedence(top->ele)>=precedence(infix[i])))
                {
                postfix[j++]=pop(); //
                }
                push(infix[i]);

            }
        }

        ++i;

    }
    while (top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';
    printf("The postfix expression is :");
    printf(" %s",postfix);
    evaluate( postfix);
    return 0;
    
   
}
int precedence(char x)
{
    switch(x)
    {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default : return 0;


    }
}
void push (int x)
{
    int item;
    struct stack*temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->ele=x;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }


}

char pop ()
{
    struct stack*temp;
    char item;
    if(top==NULL)
    printf("EMPTY STACK");
    else if(top->next==NULL)
    {
        temp=top;
        item=top->ele;
        top=NULL;
        free(temp);

    }
    else
    {
        temp=top;
        item=top->ele;
        top=top->next;
        free(temp);

    }
    return item;
}
void evaluate(char postfix[])
{
    int i=0,num,n1,n2,n3;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            num=postfix[i] - 48;
            push1(num);
        }
        else
        {
            n1 = pop1();
            n2 = pop1();
            switch(postfix[i])
            {
                case '+': n3 = n2+n1 ;
                         push1(n3) ;
                         break;
                case '-': n3 = n2-n1;
                          push1(n3);
                          break;
                case '*': n3 = n2+n1 ;
                         push1(n3) ;
                         break;
                case '/': n3 = n2 / n1 ;
                          push1(n3) ;
                          break;
                case '^': n3 = pow(n2,n1);
                          push1(n3);
                          break;
               
                         
                         
            }
            
           
        }
        i++;
    }
    printf("\nThe evaluated expression %d",pop1());
    
}

void push1(int x)
{
    top1++;
    stack1[top1] = x;
}

int pop1()
{
    int e;
    e = stack1[top1];
    top1--;
    return e;
}
