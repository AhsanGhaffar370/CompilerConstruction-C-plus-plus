#include<iostream>
#include<string.h>
using namespace std;

bool decl();
bool init();
bool list();
bool Const();

string str[] = {"DT","ID","=","ID",";"};
int i=0;

int main()
{
	cout<<"string =    ";
	for(int i=0;i<5;i++)
	{
		cout<<str[i]<<"  ";	
	}
	
	if(decl())
		cout<<"valid string";

	else
		cout<<"Invalid string\nsyntax error";
	
	return 0;
}

bool decl()
{
	bool flag=false;
	if(str[i]=="DT")
	{
		i++;
		
		if(str[i]=="ID")
		{
			i++;
			if(init())
			{
				i++;
				if(list())
					flag= true;
			}
		}
	}
	else 
		return flag;
}

bool init()
{
	bool flag=false;
	
	if(str[i] == "=")
	{
		i++;
		
		if(str[i]=="ID")
		{
			i++;
			if(init())
				flag= true;
	    }
	    else if(Const())
	    	flag= true;
	}
	else if(str[i]==" ")
		flag= true;
	
   else	
   		return flag;
	
}

bool list()
{
	bool flag=false;
	
	if(str[i]==";")
		flag= true;
	
	else if(str[i]==",")
	{
		i++;
		if(str[i]=="ID")
		{
			i++;
			if(init())
			{
				i++;
				if(list())
					flag= true;
			}
		}
	}
  	else	
  		return flag;
}

bool Const()
{
	bool flag=false;
	
	if(str[i]=="int")
		flag=true;
	
	else if(str[i]=="char")
		flag= true;
	
	else if(str[i]=="float")
		flag= true;
  	else	
  		return flag;
}

