
#include<iostream>
using namespace std;
int trans(int cs, char str);
int main(){
	
	int cs=0, fs=1;
	string str;
	float a=.0;
	
	cout<<"Input any string : ";
	cin >> str;
	
	int i=0;
	while(str[i]!=NULL)
	{	
		cs=trans(cs,str[i]);
		cout<<"cs["<<i<<"]"<<cs<<endl;

		if(cs==3)    //once the string gone into dead state which is 3 then we dent need to check further more itterations:
			break; 
		i++;
	}
			
	if(cs==fs)
		cout<<"\nvalid identifier\n"<<endl;
	else
		cout<<"\ninvalid identifier\n"<<endl;

}

int trans(int cs, char str)
{
	int arr[3][3] = {{1, 1, 2}, 
					{1, 1, 1}, 
					{2, 2, 2}};
					 
	//yha rows to cs ke hisab se select hoti rhe gi or column hm TT ke hisab se select krege notebook me likha hua he kese
	if(str == '_')
		return arr[cs][0];
	
	else if ((str >= 'a' && str<= 'z') || (str >= 'A' && str <= 'Z')) 
		return arr[cs][1];
		
	else if(str>='0' && str<='9')
		return arr[cs][2];
	
	else //once the string gone into dead state which is 3 then we dent need to check further more itterations:
		return 2;
}
