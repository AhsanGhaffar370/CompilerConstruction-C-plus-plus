#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct token{
	string cp;
string vp;
	
	string lineno;
	
};token t[12];
int main()
{
	string line;
	string temp;
	int countline=0;
	ifstream readfile;
	int count=0;
	
 //	readfile.open("text.txt");
ifstream file("lab.txt");	
if (file.is_open()){
while (!file.eof()) {
getline(file,line);

for(int i=0;i<line.length();i++)
{
	

	if(line[i]=='(')
	{
		i++;
		while(line[i]!=',')
		{
			temp+=line[i];
			
			i++;
		}
		i++;
		t[count].cp=temp;
		cout<<temp;
		temp.clear();
	
		
		
		
			while(line[i]!=',')
		{
			temp+=line[i];
		
			i++;
		}	
		i++;
		t[count].vp=temp;
		cout<<temp;
		temp.clear();
	
		while(line[i]!=')')
		{
			temp+=line[i];
			
			i++;
		}
		t[count].lineno=temp;
	//	cout<<temp;
		temp.clear();
		count++;
			
	}
	

}



 }
}
else{
	cout<<"file is not open /n";
}
file.close();
cout<<endl;
for(int i=0;i<12;i++)
{
	cout<<t[i].cp<<"    "<<t[i].vp<<"    "<<t[i].lineno<<"     "<<endl;
}
}

