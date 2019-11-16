#include<iostream>
#include<string.h>
int trans(int s,char c);
using namespace std;
int main(){
	int cs = 0;
	int fs = 3;
	string s;
	int i=0;

	cout<<"Input any string : ";
	cin >> s;
	
	while(s[i]!= NULL)
	{
		cs = trans(cs,s[i]);
		i++;
	}
	if(cs==fs)
	{
		cout<<"valid string"<<endl;
	}
	else{
		cout<<"invalid string"<<endl;
	}
	
}
int trans(int cs ,char c)
{
	int TT[4][2] = {{1,0},
					{1,2},
					{1,3},
					{1,0}};
	
	//yha rows to cs ke hisab se select hoti rhe gi or column hm TT ke hisab se select krege notebook me likha hua he kese
	if(c=='a')
	{
		return TT[cs][0];
	}
	else if(c=='b')
	{
	return TT[cs][1];
	}
	else
	{
		return -1;
	}
}

