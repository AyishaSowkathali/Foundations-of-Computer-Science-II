#include <iostream>
#include <fstream>
#include "CharStack.h"

using namespace std;

void GetFileName(ifstream &fin);
int isParenthesis(char p);
char getMatching(char c);
bool isMatching(char c1, char c2);

int main()
{
	ifstream fin;
	GetFileName(fin);
	CharStack cs;
	char ch;
	//read character from file
	while (fin >> ch)
	{
		if (isParenthesis(ch)==1)
		{
			cs.push(ch);
		}
		else if (isParenthesis(ch)==2)
		{
			if (cs.isEmpty()==false)
			{
                    char out = cs.peek();
				cs.pop();
				if (isMatching(out, ch) == false)
				{
					cout << "expected " << getMatching(out) << " but found " << ch << " : this is a wrong closing bracket" << endl;
					return 0;
                    }
               }
			else
			{
				cout << "there is a closing bracket but not an opening bracket" << endl;
					return 0;
			}
		}
	}
	fin.close();

	if (cs.isEmpty()==false)
	{
		cs.pop();
          char out = cs.peek();
		cout << "missing " << getMatching(out) << endl;
		return 0;
	}
	cout << "All parenthesis matched sussessfully." << endl;
	
	return 0;
}

char getMatching(char c)
{
	char b;
	if (c=='[')
	b = ']';
	if (c=='(')
	b = ')';
	if (c=='{')
	b = '}';
return b;
}

bool isMatching(char c1, char c2)
{
	return ((c1=='['&& c2==']')||(c1=='{'&& c2=='}')||(c1=='('&& c2==')'));
}

int isParenthesis(char p)
{
	if (p=='[' || p=='{' || p=='(')
		return 1;
	else if (p==']' || p=='}' || p==')')
		return 2;
	return 0;
}

void GetFileName(ifstream &fin)
{
	bool open = false;
	char filename[50];
	cout << "Enter file name to open: ";
	cin >> filename;
	fin.open(filename);
	while (open == false)
	{
		if(!fin)
		{
			cout << "ERROR: File does not exists. Try again." << endl;
			cout << "Enter file name to open: ";
			cin >> filename;
			fin.open(filename);
		}
		else
			open = true;
	}
}
