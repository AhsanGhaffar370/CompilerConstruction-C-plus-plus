#include<iostream>
using namespace std;
int trans(int cs, char str);
int main(){
	
	int cs=0, fs=1;
	string str, temp;
	
	cout<<"Input any string : ";
	cin >> str;
	
	int i=0;
	while(str[i]!=NULL)
	{	
		cs=trans(cs,str[i]);
		i++;
	}
			
	if(cs==fs)
		cout<<"\nvalid identifier\n"<<endl;
	else
		cout<<"\ninvalid identifier\n"<<endl;

}

int trans(int cs, char str){
	
	int arr[3][3]={ {1,1,2},
					{1,1,1},
					{2,2,2}  };

	//yha rows to cs ke hisab se select hoti rhe gi or column hm TT ke hisab se select krege notebook me likha hua he kese
	if(str=='_')
		return arr[cs][0];
	else if(str>='a' && str<='z' || str>='A' && str<='Z')
		return arr[cs][1];
	
	else if(str>='0' && str<='9')
		return arr[cs][2];

	else
		return -1;
}
