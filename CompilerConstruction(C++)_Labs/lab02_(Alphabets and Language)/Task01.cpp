#include<iostream>
#include<string>
using namespace std;
int main(){
string str;
    int count=0;
    cout << "Enter a string: ";
    cin >> str;
    
    cout << "\nYou Entered: " << str << endl;
	
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='a')
			count++;
		
		else{
			count=0;
			break;
		}
	}
	
	if(count%2==0 && count>0)
		cout<<"\nYour string is valid";
	else
		cout<<"\nYour string is invalid";
	return 0;
}

