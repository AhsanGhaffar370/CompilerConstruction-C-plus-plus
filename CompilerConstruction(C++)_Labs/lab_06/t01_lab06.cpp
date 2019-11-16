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

	string str,str1,temp,temp2;

	while(getline(input,str)){
		
		str1+=str;
		
		for(int i=0;i<str.length();i++){
			
			if(str[i]=='/' && str[i+1]=='/' ){
				
				for(int j=i; j<str.length();j++)	
					i++;
			}
			else
				temp+=str[i];
		}
	}
	
	int i=0;
	while(i<temp.length()){
		
		if(temp[i]=='/' && temp[i+1]=='*' ){
				
			for(int j=i; j<temp.length();j++){
				
				if(temp[i]=='*' && temp[i+1]=='/'){
					i++;
					break;
				}
				i++;
			}
		}
		else
			temp2+=temp[i];
		i++;
	}
			
	input.close();
	
	cout << "Original String:\n\n"<<str1<<endl;
	cout<<"\n\n\nAfter Removal of Comments:\n\n"<<temp2<<endl;
	
	return 0;
}
