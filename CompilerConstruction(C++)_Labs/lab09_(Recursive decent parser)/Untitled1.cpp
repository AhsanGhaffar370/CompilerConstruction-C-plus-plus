#include<iostream>
#include<string>
using namespace std;
bool E();
bool E1();
bool T();
bool T1();
bool F();

string s[] = {"ID","+","ID"};
int i=0;
bool E(){
	if(T())
	{
		if(E1())
		{
			return true;
		}
		else
			return false;
	}
	else
		 return false;
}

bool E1(){
	if(s[i]=="+")
	{
		
		if(T())
		{
			if(E1())
				return true;
			else
				return false;
		}

	}
	else
		return false;
}

bool T(){
	if(F())
	{
		if(T1())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool T1(){
	if(s[i]=="*")
	{
		if(F())
		{
			if(T1())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool F(){
	if(s[i]=="ID")
	{
		i++;
		return true;
	}
		
	else
		return false;
}

int main()
{
	
	if(E())
	{
		cout<<"invalid"<<endl;
	}
	else
		cout<<"parsing successfull"<<endl;	
}
