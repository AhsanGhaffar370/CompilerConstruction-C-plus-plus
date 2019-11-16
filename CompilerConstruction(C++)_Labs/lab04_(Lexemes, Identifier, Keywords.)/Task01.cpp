#include<iostream>
#include<string>
using namespace std;

int main(){
	int s;
	cout << "Enter a string: ";
    cin >> s;
	
	cout<<"\n"<<s<<endl;
	
	string str="hello string name ";
    //cout << "Enter a string: ";
   // cin >> str;
    
    cout << "\nYou Entered: " << str << "\n\n";
	
	string temp;
	
	for(int i=0;i<str.length();i++)
	{
	
		if(str[i]!=' '){
			temp+=str[i];		
		}
		
		else{
			cout<<temp<<"\n\n";
			temp="";
		}
	}
	
	return 0;
}

