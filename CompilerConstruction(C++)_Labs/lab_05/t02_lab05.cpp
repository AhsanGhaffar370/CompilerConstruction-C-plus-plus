#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	ifstream input;
	
	input.open("sample.txt");
	if(!input){
		cout<<"unable to open file"<<endl;
		exit(1);
	}
	
	string x;
	string sum;
	
	while(input >> x){
		sum+=x;
	}
	input.close();
	
	cout<<"****STRING:****\n"<<sum<<endl;
	
	string str=sum;
    
    cout << "\n\n****After Punctuator Separation:****\n\n";
	
	string temp,temp2, temp3;
	for(int i=0;i<str.length();i++)
	{
	
		if(str[i]!=';' && str[i]!='(' && str[i]!=')' && str[i]!='[' && str[i]!=']'  && str[i]!='{' && str[i]!='}' && str[i]!='.'  && str[i]!=',' && 
		   str[i]!='"' && str[i]!='+' && str[i]!='-'  && str[i]!='*' && str[i]!='/' && str[i]!='%' && str[i]!='&' && 
		   str[i]!='!' && str[i]!='|'  && str[i]!='=' && str[i]!='<' &&  str[i]!='>')
		{
			temp+=str[i];
		}
		
		else 
		{
			cout<<temp<<endl;
			temp2+=str[i];
			temp3+=str[i];
			temp3+=str[i+1];
			
			if(temp3=="||" || temp3=="&&" || temp3=="!=" || temp3=="==" || temp3=="<=" || temp3==">=")
			{
				cout<<temp3<<endl;
				i++;
			}
			else{
				cout<<temp2<<endl;
			}
			
			temp="";
			temp2="";
			temp3="";
		}
		

	}


}

