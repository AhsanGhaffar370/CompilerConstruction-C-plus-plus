#include<iostream>
#include<string>
using namespace std;
void reduce();
string inp[]={"id","+","id","*","id","$"};
string stack[6];
int i=0;

void reduce(){
	cout<<"Stack["<<i<<"] :"<<stack[i]<<endl;
	if(stack[i]=="id")
	{
		stack[i]="E";
		i++;
	}
	else if(i>2 && stack[i-1]=="E" && (stack[i-2]=="+" || stack[i-2]=="*") && stack[i-3]=="E")
	{
		cout<<"reduced:  "<<stack[i-1]<<"   "<<stack[i-2]<<"  "<<stack[i-3]<<endl;
		stack[i-1]='\0';
		stack[i-2]='\0';
	}
	else
	{
		i++;
	}
}

int main(){
	
//	for(int i=0;i<6;i++)
//		stack[i]==inp[i];
	
	while(inp[i]!="$")
	{
		stack[i]=inp[i];iuhg
		reduce();
	}
	i--;
	if(stack[i]=="E")
		cout<<"Successfully reduced:"<<endl;
		
	else
		cout<<"Unccessfully reduced:"<<endl;
		
	
	return 0;
}
