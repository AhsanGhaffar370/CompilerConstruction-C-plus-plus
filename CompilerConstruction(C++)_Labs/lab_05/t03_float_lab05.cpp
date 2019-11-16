#include<iostream>
using namespace std;
int trans(int cs, char str);
int main(){
	
	int cs,fs=3;
	
	string str;

	cout<<"enter any float number:";
	cin>>str;
		
	int i=0;
	while(str[i]!=NULL){
		
		cs=trans(cs,str[i]);
		cout<<"\ncurrent state ["<<cs<<"]"<<endl;
		i++;
	}
	
	if(cs==fs)
		cout<<"valid float"<<endl;
	else
		cout<<"invalid float"<<endl;
}

int trans(int cs, char str){

	int arr[5][4]={{1,1,1,2},
				   {4,4,1,2},
				   {4,4,3,4},
				   {4,4,3,4},
				   {4,4,4,4} };
	
	if(str == '+')
		return arr[cs][0];
	
	else if(str == '-')
		return arr[cs][1];
		
	else if(str>='0' && str<='9')
		return arr[cs][2];
	
	else if(str == '.')
		return arr[cs][3];

	else  //once the string gone into dead state which is 3 then we dent need to check further more itterations:
		return 4;
}
