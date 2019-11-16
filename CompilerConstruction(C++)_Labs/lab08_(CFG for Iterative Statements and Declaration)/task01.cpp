#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool list1(string str);
bool dec(string str[]);
bool keywords( string str );
bool identifier(string str);

int main(){
	string str[3];
	int a=2;
	int b=3;
	a=b=4;
	cout<<a<<b;
	
	cout<<"enter elements of array:"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>str[i];
	}
	
	if(dec(str))
		cout<<"valid";
	else
	 	cout<<"invalid";
	
	return 0;
}

bool dec(string str[])
{
	int i=0;
	bool flag=false;
	
	string ss=str[i];
	if(keywords(ss))
	{
		i++;
		ss=str[i];
		if(identifier(ss))
		{
			i++;
			ss=str[i];
			if(list1(ss))
				flag= true;
		}
	}
	return flag;
}

bool list1(string str)
{
	if(str==";")
		return true;
	else 
		return false;
}

bool keywords( string str )
{
	string key_dt[6] = {  "int","float","char","string","bool","double" };

	for (int i = 0; i<6; i++)
	{
		if(key_dt[i] == str)
		{
			return true;
		}
	}
	
	return false;
}

//********************************"IDENTIFIER" *********************************	
bool identifier(string str)
{
	int cs=0, fs=1;
		
	int arr[3][3] = {{1, 1, 2}, 
					{1, 1, 1}, 
					{2, 2, 2}};
	
	for(int i=0; i<str.length();i++)
	{	
		if(str[i] == '_')
			cs= arr[cs][0];
		
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
			cs= arr[cs][1];
			
		else if(str[i]>='0' && str[i]<='9')
			cs= arr[cs][2];
		
		else{ 
			cs= 2;
			break;
		}			
	}
			
	if(cs==fs)
		return true;
	else
		return false;
}



