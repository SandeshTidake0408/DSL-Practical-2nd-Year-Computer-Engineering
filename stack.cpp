#include <iostream>
#include <string>
using namespace std;

class stack
{
	int top;
	int size;
	char a[];

public:
	stack(int n)
	{
		top = -1;
		size = n;
		a[size];
	}

	bool is_empty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool is_full()
	{
		return top == size - 1;
	}

	void push(char val)
	{
		if (is_full())
		{
			cout << "Stack is Overflow" << endl;
		}
		else if (top == -1)
		{
			top = 0;
			a[top] = val;
		}
		else
		{
			top++;
			a[top] = val;
		}
	}

	int pop()
	{

		if (is_empty())
		{
			cout << "Stack Underflow" << endl;
			return -1;
		}

		else
		{
			int temp;
			temp = a[top];
			top--;
			return temp;
		}
	}
	void pallindrome(string ori)
	{
		string str = "";
		for (int i = top; i >= 0; i--)
			str = str + a[i];
		if (str == ori)
		{
			cout << "String is Pallindromic ...\n";
		}
		else
		{
			cout << "Not Pallindromic\n";
		}
	}
	void display()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << a[i];
		}
		cout << endl;
	}
};

int main()
{
	string str;

	cout << "Enter the string :" << endl;
	getline(cin, str);

	int len = str.size();
	char ch[len];
	stack s(len);
	for (int i = 0; i < len; i++)
	{
		ch[i] = str[i];
	}

	for (int i = 0; i < len; i++)
	{
		s.push(ch[i]);
	}
	s.pallindrome(str);
	cout << "Reversed String : ";
	s.display();

	return 0;
}
