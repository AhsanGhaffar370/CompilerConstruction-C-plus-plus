#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct token{
	string cp;
};	

int main(){

	ifstream infile;

	string str,str1,t1;
	int s,a=0,b=0;
	
	//To read the number of lines from file we open a file twice:
	infile.open("lab.txt");

	//Check for error
	if(infile.fail()){
		cerr<<"Error in opening file"<<endl;
		exit(1);
	}
	
	while(!infile.eof()){
		infile>>str;
		s++;
		cout<<"numbers:  "<<s<<endl;
	}	str.clear();
	infile.close();
	
	token tok[s];
	
	infile.open("lab.txt");

	while(getline(infile,str)){
		
		str1+=str;

		for(int i=0;i<str1.length();i++)
		{
			if(i==0) continue;
				
			if(str1[i]==',' && b==0)		( tok[a].cp=t1  );
			
			else   							( t1+=str1[i]   );
			
			if(str[i]==','){
				b++;
				t1.clear();
			}
		}
		b=0;
		a++;
		str1.clear();
		t1.clear();
	}
	infile.close();
	
	cout<<"     CP         \n"<<endl;
	for(int i=0;i<a;i++){	
		cout<<i<<":  "<<tok[i].cp<<endl;
	}
	
	return 0;
}
