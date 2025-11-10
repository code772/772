#include<iostream>

using namespace std;

class wellParenthesized 
{
	public:
		int max,top;
		char st[10];         //array declaration 
		char expression[20];        //expression declaration inside class

		wellParenthesized()
		{
			max=10;
			top=-1;
		}
		
	int IsEmpty();
	int IsFull();
	void push(char);
	char pop();
	
	void check(); 
	
	
};

int wellParenthesized::IsEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int wellParenthesized::IsFull()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}

void wellParenthesized::push(char e)
{
	if(!IsFull())
	{
		top++;
		st[top]=e;
	}
	else
		cout<<"stack is overflow";
}

char wellParenthesized::pop()
{
	char temp;
	
	if(!IsEmpty())
	{
		temp=st[top];
		top=top-1;
		return temp;
	}
	else
		return -1;
}

void wellParenthesized::check()
{
	int i=0;
	int f=0;
	char del,current;

	while(expression[i]!='\0')
	{
		current=expression[i];

		if(current=='(' || current=='[' || current=='{')
			push(current);

		if(current==')' || current==']' || current=='}')
		{
			del=pop();
			if((current==')' && del!='(') || (current==']' && del!='[') || (current=='}' && del!='{'))
			{
				f=1;
				break;
			}
		}
		i++;
	}

	if(f==0 && IsEmpty())
		cout<<"EXPRESSION IS WELL PARENTHESIZED\n";
	else
		cout<<"EXPRESSION IS NOT WELL PARENTHESIZED\n";
}

int main()
{
	wellParenthesized P1;
	char ch;

	do
	{
		// reset stack before checking new expression
		P1.top = -1;

		cout<<"\nEnter expression to check: ";
		cin>>P1.expression;

		P1.check();

		cout<<"\nDo you want to check another expression? (y/n): ";
		cin>>ch;

	}while(ch=='y' || ch=='Y');

	return 0;
}
