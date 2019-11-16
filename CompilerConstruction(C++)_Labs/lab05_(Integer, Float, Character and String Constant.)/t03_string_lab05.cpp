
#include<iostream>
using namespace std;
int trans(int cs, char str);
int main(){
	
	int cs=0, fs=4;
	string str="\"ah\\\"san\"";

	
	cout<<"string : "<<str<<endl;
	
	for(int i=0;i<str.length();i++)
	{	
		cs=trans(cs,str[i]);
		cout<<"cs["<<str[i]<<"]"<<cs<<endl;
	
	}
			
	if(cs==fs)
		cout<<"\nvalid string\n"<<endl;
	else
		cout<<"\ninvalid string\n"<<endl;

}

int trans(int cs, char str)
{
	int arr[6][3]={ {1,5,5},
					{4,1,2},
					{3,1,2},
					{4,3,2},
					{5,5,5},
					{5,5,5} };
					 
	if(str == '"')
		return arr[cs][0];
	
	else if(str!='"' && str!='\\' || str==' ')
		return arr[cs][1];
	
	else if(str == '\\')
		return arr[cs][2];
	
	else
		return 5;
}
