#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{ 
	string str1,s,temp,temp2;
	
	ifstream myfile;
	
	myfile.open("code.txt");
	int c;
	while(!myfile.eof())
	{  
		getline(myfile,s);
		if(s != " ")
			c++;
		temp=temp+s;
	}
	
	for(int i=0;i<temp.length();i++)
	{
		
		if(temp[i]=='/'&&temp[i+1]=='/')
		  {
			// Copy three characters of s1 (starting  
    		// from position 0) 
		 	//cout<<temp.substr(0,i-1)<<endl;
		}
		
		if(temp[i]=='}'||temp[i]=='{'||temp[i]=='('||temp[i]==')')
		{   
			temp2=temp[i];
			cout<<"(Brackets,"+temp2+")\n";
		}
		
		if(temp2=="int"||temp2=="double"||temp2=="float")
			cout<<"(DT,"+temp2+")\n";
		
		if(temp2=="main")
			cout<<"(main,"+temp2+")\n";
		
		if(temp[i]==' ')
			temp2="";
		
		else
			temp2+=temp[i];
	}	
	
	cout<<"\n\n\nOriginal String:\n\n "<<temp<<endl;
}
