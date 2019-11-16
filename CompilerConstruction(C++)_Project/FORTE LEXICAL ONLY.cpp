#include<iostream>
#include<fstream>
#include<string>
using namespace std ;
bool operators(string str);
string operator_types(string str);
bool punctuators(string str) ;
int keywords( string str );
bool int_const(string str);
bool float_const(string str);	
bool identifier(string str);
bool str_const(string str);
bool chr_const(string str);
bool num(char s);

//********************************"MAIN" ********************************* 
int main()
{
	string str1,t1,gstr,s1,s2,s3;;
	
	int line=0;
	
	ifstream infile;
	infile.open("code1.txt");
	
	fstream file;
	file.open("a2.txt",ios::app);
	
	while(infile.fail()){
		cerr<<"Error in opening infile:"<<endl;
		exit(1);
	}
	
	while(file.fail()){
		cerr<<"Error in opening file:"<<endl;
		exit(1);
	}

	while(getline(infile,gstr))
	{
		str1+=gstr;
		line++;
		for(int i=0; i<=str1.length(); i++)
		{
			//Removing Single line Comments
			if(str1[i]=='#' && str1[i+1]=='#' )
			{		
				for(int j=i; j<str1.length();j++)	
					i++;
			}
			
			//Removing Multiple line Comments
			else if(str1[i]=='#' && str1[i+1]=='<' )
			{	
				bool flag1=false;
				for(int j=i; j<str1.length();j++)
				{	
					//Removing Multiple line Comments in single line
					if(str1[i]=='>' && str1[i+1]=='#'){
						flag1=true;
						line++;
						i+=2;
						break;
					}
					i++;
				}
				if(flag1==false)
				{
					//Removing Multiple line Comments in multiline
					str1.clear();
					while(getline(infile,gstr))
					{	
						bool flag2=false;
						str1+=gstr;
						for(int k=0;k<=str1.length();k++)
						{
							if(str1[k]=='>' && str1[k+1]=='#')
							{	
								flag2=true;
								line++;
								i=k+2;
								break;
							}
						}
						if(flag2==true)
							break;
			
						else {
							str1.clear();
							line++;
						}	
					}
				}
			}
			
			s1.clear();
			s2.clear();
			s3.clear();
			
			s1+=str1[i];
			s1+=str1[i+1];
			s2+=str1[i];

			if( !punctuators(s1) && !operators(s1) && !punctuators(s2) && !operators(s2) && str1[i]!='\n' && str1[i]!='\0' && 
				str1[i]!=' '&& str1[i]!='\'' &&  str1[i]!='~'  )
			{
				t1+=str1[i];
			}
			else
			{
//				//Float constant
				if(str1[i]=='.' && num(str1[i+1]))
				{
					string s4;
					for(int j=i;j<str1.length();j++)
					{
						t1+=str1[i];
						i++;
						s4=str1[i];
						if(str1[i]=='.' || str1[i]==' ' || str1[i]=='\0' || punctuators(s4) || operators(s4) )
						{
							i--;
							break;
						}
					}
				}

				if(t1.length()>=1)
				{
					bool flag=false;
					
					if(keywords(t1)==2 || keywords(t1)==1)
					{
						if(keywords(t1)==2){
							file<<"( DT, "<<t1<<" , "<<line<<" )"<<endl;
							
							cout<<"---------------------------------------"<<endl;	
							cout<<"( DT, "<<t1<<" , "<<line<<" )"<<endl;
							cout<<"---------------------------------------"<<endl;
						}
						else if(keywords(t1)==1){
							file<<"( "<<t1<<" , "<<t1<<" , "<<line<<" )"<<endl;
							
							cout<<"---------------------------------------"<<endl;	
							cout<<"( "<<t1<<" , "<<t1<<" , "<<line<<" )"<<endl;	
							cout<<"---------------------------------------"<<endl;
						}		
					}
					else if(int_const(t1)){
						file<<"( Int_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cout<<"---------------------------------------"<<endl;
						cout<<"( Int_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"---------------------------------------"<<endl;	
					}	
					else if(float_const(t1)){
						file<<"( Float_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cout<<"---------------------------------------"<<endl;
						cout<<"( Float_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"---------------------------------------"<<endl;	
					}	
					else if(identifier(t1)){
						file<<"( Identifier, "<<t1<<" , "<<line<<" )"<<endl;
						
						cout<<"---------------------------------------"<<endl;
						cout<<"( Identifier, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					else
						cout<<"A Lexical Error:  line_no["<<line<<"]    String_value:[  "<<t1<<"  ]"<<endl;
					
					t1.clear();
					
				}
				
				//storing and validating String constant
				if(str1[i]=='~')
				{
					bool flag=false;
					for(int j=i;j<str1.length();j++)
					{
						t1+=str1[i];
						i++;
						
						if(str1[i]=='~'  &&  str1[i-1]!='\\')
						{
							t1+=str1[i];
							flag=true;
							break;
						}
						else if(str1[i]=='~'  &&  str1[i-1]=='\\'  &&  str1[i-2]=='\\'  &&  str1[i-3]!='\\')
						{
							t1+=str1[i];
							flag=true;
							break;
						}
						else if(str1[i]=='~' && str1[i-1]=='\\' && str1[i-2]=='\\' && str1[i-3]=='\\' && str1[i-4]=='\\' && str1[i-5]!='\\')
						{
							t1+=str1[i];
							flag=true;
							break;
						}
					}
					
					if(flag ==true)
					{
						file<<"( String_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cout<<"---------------------------------------"<<endl;
						cout<<"( String_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"---------------------------------------"<<endl;
						flag=false;
						t1.clear();
					}	
					else 
						cout<<"S Lexical Error:  line_no["<<line<<"]    String_value:[  "<<t1<<"  ]"<<endl;
				}
				
				//storing character constant		
				if(str1[i]=='\'')
				{
					int tc=i+2;
					if(str1[i+1]=='\\')
						tc++;
					for(int j=i;j<str1.length();j++)
					{
						t1+=str1[i];
						
						if(j==tc)
							break;
						i++;
					}
					if(chr_const(t1))
					{
						file<<"( Char_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cout<<"---------------------------------------"<<endl;
						cout<<"( Char_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					else{
						cout<<"C Lexical Error:  line_no["<<line<<"]    String_value:[  "<<t1<<"  ]"<<endl;
					}
					t1.clear();
				}
			}
			
			//Operators and punctuators:
			if(s1=="||" || s1=="&&" || s1=="<="  || s1==">=" || s1=="!=" || s1=="==" || s1=="++"  || s1=="--" || s1=="+=" || s1=="-=" || s1=="<:" || s1==":>")
			{
				s3=s1;
				i++;
			}
			else if( !num(str1[i-1]) && (str1[i]=='+' || str1[i]=='-') && (num(str1[i+1]) || str1[i+1]=='.' ) )
				t1+="+";
			else 
				s3=s2;
				
			if(s3==".")
				s3="";

			if(operators(s3) || punctuators(s3))
			{
				if(operators(s3))
				{
					string opt=operator_types(s3);
					
					file<<"( "<<opt<<" , "<<s3<<" , "<<line<<" )"<<endl;
					
					cout<<"---------------------------------------"<<endl;
					cout<<"( "<<opt<<" , "<<s3<<" , "<<line<<" )"<<endl;
					cout<<"---------------------------------------"<<endl;
				}
				if(punctuators(s3) ==true)
				{
					file<<"( "<<s3<<" , "<<s3<<" , "<<line<<" )"<<endl;
					
					cout<<"---------------------------------------"<<endl;
					cout<<"( "<<s3<<" , "<<s3<<" , "<<line<<" )"<<endl;
					cout<<"---------------------------------------"<<endl;
				}
			}
		}
		str1.clear();
		t1.clear();
	}
	infile.close();
	file.close();
	return 0;
}

//************NUMBER*****************
bool num(char s)
{
	if(s>='0' && s<='9')
		return true;
	
	return false;
}


//********************************"OPERATORS" *********************************
bool operators(string str)
{
	bool flag=false;
	string opt[20] = { "+","-","*","/","%","^","++","--", "+=","-=","=",">","<","<=", ">=","!", "!=", "==" ,"&&","||"};
	
	for (int i = 0; i<20; i++)
	{
		if (opt[i]==str)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
string operator_types(string str)
{
	string relational_opt[7] = {  "==",">","<","<=", ">=","!", "!=" };

	for (int i = 0; i<7; i++)
	{	
		if (relational_opt[i] == str)
		{
			return "relational_opt";
		}
	}
	if (str == "=")
	{
		return "Assign_operator";
	}
	else if (str == "&&" || str=="||")
	{
		return "logical_opt";
	}
	else if (str == "+" || str=="-")
	{
		return "addsub_opt";
	}
	else if (str == "*" || str=="/")
	{
		return  "mul_div_opt";
	}
	else if (str == "%")
	{
		return "mode_opt";
	}
	else if (str == "^")
	{
		return "pow_opt";
	}
	else if (str == "++" || str=="--")
	{
		return "inc_dec_opt";
	}
	else if (str == "+=" || str=="-=")
	{
		return "inc_dec_assign_opt";
	}
	else 
		return "none";
}

//********************************"PUNCTUATORS" ********************************* 
bool punctuators(string str) 
{
	bool flag=false;
	string punc[12] = {"[", "]", "(", ")", "{", "}",";",".", ":",",","<:",":>"};
	
	for (int i=0; i<12; i++) {
		if (punc[i]==str) {
			flag = true;
			break;
		}
	}
	return flag;
}

//********************************"KEYWORDS" *********************************
int keywords( string str )
{
	string keywords[27] = {  "exclude","write","whilst","state","legal","true","false","otherwise", "do", "stag", "devoid", "execute", "elseward", 
							"this","cont","secret","stop","read","head","secured","deliver","global","fixed","return","for","if"	};
	
	string key_dt[6] = {  "cip","fract","lett","str","status","dup" };
	
	for (int i = 0; i<27; i++)
	{
		if (keywords[i]==str)
		{
			return 1;
		}
	}
	
	for (int i = 0; i<6; i++)
	{
		if(key_dt[i] == str)
		{
			return 2;
		}
	}
	
	return 0;
}

//********************************"INT CONSTANT" ********************************* 	
bool int_const(string str)
{
	int cs=0, fs=1;	
	int arr[4][3]={ {2,2,1},
					{3,3,1},
					{3,3,1},
					{3,3,3}  };
	
	for(int i=0; i<str.length();i++)
	{	
			//yha rows to cs ke hisab se select hoti rhe gi or column hm TT ke hisab se select krege notebook me likha hua he kese
		if(str[i] == '+')
			cs= arr[cs][0];
	
		else if(str[i] == '-')
			cs= arr[cs][1];
		
		else if(str[i]>='0' && str[i]<='9')
			cs= arr[cs][2];
	
		else{  //once the string gone into dead state which is 3 then we dent need to check further more itterations:
			cs= 3;
			break;
		}			
		
	}
			
	if(cs==fs)
		return true;
	else
		return false;
		
}

//********************************"FLOAT CONSTANT" ********************************* 	
bool float_const(string str)
{
	int cs=0,fs=3;
		
	int arr[5][4]={{1,1,1,2},
				   {4,4,1,2},
				   {4,4,3,4},
				   {4,4,3,4},
				   {4,4,4,4} };
				   
	for(int i=0; i<str.length();i++)
	{	
		//yha rows to cs ke hisab se select hoti rhe gi or column hm TT ke hisab se select krege notebook me likha hua he kese
		if(str[i] == '+')
			cs= arr[cs][0];
		
		else if(str[i] == '-')
			cs= arr[cs][1];
	
		else if(str[i]>='0' && str[i]<='9')
			cs= arr[cs][2];
		
		else if(str[i] == '.')
			cs= arr[cs][3];
	
		else{  //once the string gone into dead state which is 3 then we dent need to check further more itterations:
			cs= 4;
			break;
		}	
	}
			
	if(cs==fs)
		return true;
	else
		return false;
}

//********************************"Character CONSTANT" ********************************* 	
bool chr_const(string str)
{
	int cs=0, fs=4;	
	int arr[6][3]={ {1,5,5},
					{5,2,3},
					{3,3,3},
					{4,5,5},
					{5,5,5},
					{5,5,5}};
	
	for(int i=0;i<str.length();i++)
	{	
		if(str[i] == '\'')
			cs= arr[cs][0];
		
		else if(str[i] == '\\')
			cs= arr[cs][1];
		
		else if(str[i]!='\'' && str[i]!='\\' || str[i]==' ')
			cs= arr[cs][2];
	
		else{
			cs= 5;
			break;
		}		
	}
			
	if(cs==fs)
		return true;
	else
		return false;	
}


//********************************"IDENTIFIER" *********************************	
bool identifier(string str)
{
	int cs=0, fs=1;
		
	int arr[3][3] = {{1, 1, 2}, 
					{1, 1, 1}, 
					{2, 2, 2}};
	
	for(int i=0; i<str.length();i++)
	{	
			//yha rows to cs ke hisab se select hoti rhe gi or column hm TT ke hisab se select krege notebook me likha hua he kese
		if(str[i] == '_')
			cs= arr[cs][0];
		
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
			cs= arr[cs][1];
			
		else if(str[i]>='0' && str[i]<='9')
			cs= arr[cs][2];
		
		else{  //once the string gone into dead state which is 3 then we dent need to check further more itterations:
			cs= 2;
			break;
		}			
	}
			
	if(cs==fs)
		return true;
	else
		return false;
}
			
//			if(	str1[i]!='\n' && str1[i]!='\0' && str1[i]!=' '&& str1[i]!='\'' &&  str1[i]!='"' && str1[i]!='(' && str1[i]!=')' && 
//				str1[i]!='[' && str1[i]!=';' && str1[i]!=']' && str1[i]!='{' && str1[i]!='}' && str1[i]!=',' && str1[i]!='*' && 
//				str1[i]!='/' && str1[i]!='%' && str1[i]!='+' && str1[i]!='-' && str1[i]!='&' && str1[i]!='!' && str1[i]!='=' && 
//				str1[i]!='<' && str1[i]!='>'  && str1[i]!=':'  && str1[i]!='.' && s1!="||" && s1!="<:" && s1!=":>" && s1!="&&" && 
//				s1!="<=" && s1!=">=" && s1!="!=" && s1!="==" && s1!="++"  && s1!="--" && s1!="+=" && s1!="-=" )
