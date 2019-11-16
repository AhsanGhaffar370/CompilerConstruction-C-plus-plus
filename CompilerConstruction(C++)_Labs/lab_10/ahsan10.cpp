#include<iostream>
#include<string>
using namespace std;
void reduce();
int i=0;
string inp[]={"id","+","id","*","id","$"};
string stack[6];

void reduce(){
		cout<<"Value at Stack["<<i<<"] :        "<<stack[i];
	if(stack[i]=="id")
	{
		stack[i]="E";
		cout<<"   ---->   "<<stack[i];
	}
	
	if(i>1)
	{
		if(stack[i]=="E" && stack[i-1]=="+" && stack[i-2]=="E")
		{
			cout<<"\nReduced String:            "<<stack[i-2]<<"   "<<stack[i-1]<<"  "<<stack[i];
			
			stack[i-1]="";
			stack[i-2]="";
			
			
		//	i=i-2;
		}
		else if(stack[i]=="E" && stack[i-1]=="*" && stack[i-2]=="E")
		{
			cout<<"\nReduced String:            "<<stack[i-2]<<"   "<<stack[i-1]<<"  "<<stack[i];
			stack[i-1]="";
			stack[i-2]="";
		//	i=i-2;
		}
	}
	
	cout<<endl;
	i++;
}

int main(){
	
	while(inp[i]!="$")
	{
		stack[i]=inp[i];
		reduce();
	}
	i--;
	
	if(stack[i]=="E")
		cout<<"Successfully reduced:"<<endl;
		
	else
		cout<<"Unccessfully reduced:"<<endl;
		
	
	return 0;
}
