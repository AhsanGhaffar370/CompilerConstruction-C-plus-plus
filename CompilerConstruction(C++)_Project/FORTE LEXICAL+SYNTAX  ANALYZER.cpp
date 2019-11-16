#include<iostream>
#include<fstream>
#include<string>
using namespace std ;
bool operators(string str);
string operator_types(string str);
bool punctuators(string str);
int keywords( string str );
bool int_const(string str);
bool float_const(string str);	
bool identifier(string str);
bool str_const(string str);
bool chr_const(string str);
bool num(char s);
  ///////////////////////////////////////////////////////////////////////
 ////////////////////Syntax checking functions//////////////////////////
///////////////////////////////////////////////////////////////////////

//MAIN PARSER
bool main1();
bool premain();
bool postmain();
bool body();
bool sst();
bool mst();
bool Return();

//DECLARATION PARSER
bool decl();
bool size();
bool id_int();
bool init();
bool a_init();
bool a_init_p();
bool value();
bool value1();
bool value2();
bool a_init2();
bool list();
bool list_p();
bool Const();

//CONDITION PARSER
bool OE();
bool OE_p();
bool AND();
bool AND_p();
bool RE();
bool RE_p();
bool E();
bool E_p();
bool T();
bool T_p();
bool F();
bool F_p();
bool MDM();

//FOR PARSER
bool whilst();
bool AI();
bool inc();
bool assign();
bool body2();

//IF ELSE PARSER
bool if_else();
bool op_else();

//FUNCTION PARSER
bool function();
bool type();
bool prmtrs();
bool m_prmtrs();

//FUNCTION SIGNATURE PARSER
bool func_sign();

//FUNCTION CALLING PARSER
bool func_call();
bool prmtrs2();
bool m_prmtrs2();

//STRUCTURES PARSER
bool Struct();

//GLOBAL DECLARATION PARSER
bool G_decl();

//DO WHILE PARSER
bool do_whilst();

//ASSIGNMENT PARSER
bool assignment();


int n=0,c=0;
string cp[300];

//********************************"MAIN" ********************************* 
int main(){
	string str1,t1,gstr,s1,s2,s3;
	int line=0;
	
	ifstream infile;
	infile.open("code1.txt");
	
	fstream file;
	//file.open("a2.txt",ios::app);
	file.open("a2.txt");
	
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
					if(keywords(t1)==2 || keywords(t1)==1){
						if(keywords(t1)==2){
							file<<"( DT, "<<t1<<" , "<<line<<" )"<<endl;
							cout<<"( DT, "<<t1<<" , "<<line<<" )"<<endl;
							
							cp[n]="DT";
						}
						else if(keywords(t1)==1){
							file<<"( "<<t1<<" , "<<t1<<" , "<<line<<" )"<<endl;
							cout<<"( "<<t1<<" , "<<t1<<" , "<<line<<" )"<<endl;	
							
							cp[n]=t1;
						}	
						n++;	
					}
					else if(int_const(t1)){
						file<<"( int_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"( int_const, "<<t1<<" , "<<line<<" )"<<endl;	
						
						cp[n]="int_const";
						n++;
					}	
					else if(float_const(t1)){
						file<<"( float_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"( float_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cp[n]="float_const";
						n++;
					}	
					else if(identifier(t1)){
						file<<"( ID, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"( ID, "<<t1<<" , "<<line<<" )"<<endl;
						
						cp[n]="ID";
						n++;
					}
					else
						cout<<"Other Lexical Error:  line_no["<<line<<"]  value:[  "<<t1<<"  ]"<<endl;
					
					t1.clear();	
				}
				
//				storing and validating String constant
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
						file<<"( string_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"( string_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cp[n]="string_const";
						n++;
						
						flag=false;
						t1.clear();
					}	
					else 
						cout<<"String Lexical Error:  line_no["<<line<<"]  value:[  "<<t1<<"  ]"<<endl;
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
						file<<"( char_const, "<<t1<<" , "<<line<<" )"<<endl;
						cout<<"( char_const, "<<t1<<" , "<<line<<" )"<<endl;
						
						cp[n]="char_const";
						n++;
					}
					else{
						cout<<"Char Lexical Error:  line_no["<<line<<"]  value:[  "<<t1<<"  ]"<<endl;
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
					cout<<"( "<<opt<<" , "<<s3<<" , "<<line<<" )"<<endl;
					
					cp[n]=opt;
				}
				if(punctuators(s3) ==true)
				{
					file<<"( "<<s3<<" , "<<s3<<" , "<<line<<" )"<<endl;
					cout<<"( "<<s3<<" , "<<s3<<" , "<<line<<" )"<<endl;
					
					cp[n]=s3;
				}
				n++;
			}
		}
		str1.clear();
		t1.clear();
	}
	cp[n]="$";
	infile.close();
	file.close();
	
	  ///////////////////////////////////////////////////////////////////////
	 ////////////////////SAVE Class Part Of Tokens//////////////////////////
	///////////////////////////////////////////////////////////////////////
	cout<<"\n\n\n***************************************"<<endl;
	cout<<"	   CLASS PART"<<endl;
	cout<<"***************************************"<<endl;	
	cout<<"string =    \n";
	for(int i=0;i<=n;i++){	
		cout<<i<<":  "<<cp[i]<<endl;
	}
	
	cout<<"\n\nPARSING COMPLETED"<<endl;
	if(main1())
		cout<<"\nvalid CODE";

	else
		cout<<"\nInvalid CODE\nsyntax error";
	
	return 0;
}

//************NUMBER*****************
bool num(char s){
	
	if(s>='0' && s<='9')
		return true;
	
	return false;
}

//********************************"OPERATORS" *********************************
bool operators(string str){
	
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

string operator_types(string str){
	
	string relational_opt[6] = {  "==",">","<","<=", ">=", "!=" };

	for (int i = 0; i<6; i++)
	{	
		if (relational_opt[i] == str)
		{
			return "relat_op";
		}
	}
	if (str == "=")
	{
		return "assign_op";
	}
//	else if (str == "&&" || str=="||")
//	{
//		return "logical_op";
//	}
	else if (str=="!")
	{
		return "not_op";
	}
	else if (str=="||")
	{
		return "or_op";
	}
	else if (str == "&&")
	{
		return "and_op";
	}
	else if (str == "+" || str=="-")
	{
		return "addsub_op";
	}
	else if (str == "*" || str=="/")
	{
		return  "muldiv_op";
	}
	else if (str == "%")
	{
		return "mode_op";
	}
	else if (str == "^")
	{
		return "pow_op";
	}
	else if (str == "++" || str=="--")
	{
		return "incdec_op";
	}
	else if (str == "+=" || str=="-=")
	{
		return "incdec_assign_op";
	}
	else 
		return "none";
}

//********************************"PUNCTUATORS" ********************************* 
bool punctuators(string str) {
	
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
int keywords( string str ){
	
	string keywords[28] = {  "struct","exclude","write","whilst","state","legal","true","false","otherwise", "do", "stag", "devoid", "execute", "elseward", 
							"this","cont","secret","stop","read","head","secured","deliver","global","fixed","return","for","if"	};
	
	string key_dt[6] = {  "cip","fract","lett","str","status","dup" };
	//string key_dt[6] = {  "int","float","char","string","bool","double" };
	
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
bool int_const(string str){
	
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
bool float_const(string str){
	
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
bool chr_const(string str){
	
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
bool identifier(string str){
	

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
			


//********************************"MAIN PARSER" *********************************			
bool main1()
{
	bool flag=false;
	
	if(premain())
	{
		c++;
		
		if(cp[c]=="global")
		{
			c++;
			
			if(cp[c]=="DT")
			{
				c++;
				if(cp[c]=="head")
				{
					c++;
					if(cp[c]=="(")
					{
						c++;
						if(cp[c]==")")
						{
							c++;
							if(cp[c]=="{")
							{
								c++;
								if(body())
								{
									c++;
									if(cp[c]=="}")
									{
										c++;
										if(postmain())
										{
											c++;
											if(cp[c]=="$")
											{
												flag=true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	
	return flag;	
}			

bool premain()
{
	bool flag=false;
	
	if(Struct())
	{
		c++;
		if(premain())
		{
			flag=true;
		}
	}
	else if(G_decl())
	{
		c++;
		if(premain())
		{
			flag=true;
		}
	}
	else if(function())
	{
		c++;
		if(premain())
		{
			flag=true;
		}
	}
	else if(func_sign())
	{
		c++;
		if(premain())
		{
			flag=true;
		}
	}
	else if(cp[c]=="global")                                          //follow ki value dlegi
	{
		c--;
		flag=true;
	}
	
	return flag;
	
}

bool postmain()
{
	bool flag=false;
	
	if(function())
	{
		c++;
		if(postmain())
		{
			flag=true;
		}
	}
	else if(cp[c]=="$")                                          //follow ki value dlegi
	{
		c--;
		flag=true;
	}
	
	return flag;
	
}
			
bool body()	
{
	bool flag=false;

	if(mst())
	{
		flag=true;
	}
	
	return flag;
}	
			
bool mst()	
{
	bool flag=false;
	
	if(sst())
	{
		c++;
		if(mst())
		{
			flag=true;
		}
	}
	else if(cp[c]=="}")                                          //follow ki value dlegi
	{
		c--;
		flag=true;
	}
				
	return flag;
}			

bool sst()
{
	bool flag=false;
	if(assignment())
	{
		flag=true;
	}
	else if(Return())
	{
		flag=true;
	}
	else if(decl())
	{
		flag=true;
	}
	else if(whilst())
	{
		flag=true;
	}
	else if(do_whilst())
	{
		flag=true;
	}
	else if(if_else())
	{	
		flag=true;
	}
	
			
	return flag;
}			

//********************************"RETURN PARSER" *********************************
bool Return()   												
{
	bool flag=false;
	
	if(cp[c]=="return")
	{
		c++;
		if(cp[c]=="int_const")
		{
			c++;
			if(cp[c]==";")
			{
				flag=true;
			}
		}	
	}	
			
	return flag;	
}
	
//********************************"DECLARATION PARSER" *********************************	
bool decl()
{
	bool flag=false;
	
	if(cp[c]=="DT")
	{
		c++;
		if(cp[c]=="ID")
		{
			c++;
			if(init())
			{
				c++;
				if(list())
				{
					flag= true;
				}
			}
			else if(cp[c] == "[")
			{
				c++;
				if(size())
				{
					c++;
					if(cp[c] == "]")
					{
						c++;
						if(a_init())
						{
							c++;
							if(list())
							{
								flag=true;
							}
						}
					}
				}
			}
		}
	}
	
	return flag;
}


bool size()
{
	bool flag=false;
	
	if(id_int())
	{
		c++;
		
		if(cp[c] =="]" )                                          //follow ki value dlegi
		{
			c--;
			flag=true;
		}
		else if(cp[c] == ",")
		{
			c++;
			if(id_int())
			{
				flag= true;
			}
		} 
	}
	else if(cp[c] == "]")                                          //follow ki value dlegi
	{
		c--;
		flag=true;
	}
	
	return flag;
}

bool id_int()
{
	bool flag=false;
	
	if(cp[c] == "ID")
	{
		flag= true;
	}
	else if(cp[c] == "int_const")
	{
		flag=true;
	}
	
	return flag;
}

bool init()
{
	bool flag=false;
	
	if(cp[c] == "assign_op")
	{
		c++;
		if(cp[c] == "ID")
		{
			c++;
			if(init())
			{
				flag=true;
			}
		}
		else if(Const())   
		{
			flag= true;
		}
		else if(E())
		{
			flag=true;
		}
	}
	else if(cp[c]== ";" || cp[c]== ",")                                            //follow ki value dlegi 
	{
		c--;
		flag= true;
	}		
   	return flag;
}

bool a_init()
{
	bool flag=false;
	
	if(cp[c] == "assign_op")
	{
		c++;
		if(cp[c] == "{")
		{
			c++;
			if(a_init_p())   
			{
				flag= true;
			}
		}
	}
	else if(cp[c]== ";" || cp[c]== ",")                                             //follow ki value dlegi
	{
		c--;
		flag= true;
	}
			
   return flag;
}

bool a_init_p()
{
	bool flag=false;
	
	if(value())
	{
		c++;
		if(cp[c] == "}")
		{
			flag= true;
		}
	}
	else if(a_init2())   
	{
		c++;
		if(cp[c] == "}")
		{
			flag= true;
		}
	}
			
   return flag;
}

bool value()
{
	bool flag=false;
	
	if(E())
	{
		c++;
		if(value1())
		{
			flag= true;
		}
	}
	else if(cp[c]== "}")                                             //follow ki value dlegi
	{
		c--;
		flag= true;
	}
			
   return flag;
}

bool value1()
{
	bool flag=false;
	
	if(cp[c]==",")
	{
		c++;
		if(E())
		{
			c++;
			if(value1())
			{
				flag= true;
			}
		}	
	}
	
	else if(cp[c]== "}")                                             //follow ki value dlegi
	{
		c--;
		flag= true;
	}
			
   return flag;
}

bool a_init2()
{
	bool flag=false;
	
	if(cp[c] == "{")
	{
		c++;
		if(value())
		{
			c++;
			if(cp[c] == "}") 
			{
				c++;
				if(value2()) 
				{
					flag= true;
				}
			}
		}
	}
	else if(cp[c]=="}" )                                             //follow ki value dlegi
	{
		c--;
		flag= true;
	}
			
   return flag;
}

bool value2()
{
	bool flag=false;
	
	if(cp[c] == ",")
	{
		c++;
		if(cp[c] == "{")
		{
			c++;
			if(value())
			{
				c++;
				if(cp[c] == "}") 
				{
					c++;
					if(value2()) 
					{
						flag= true;
					}
				}
			}
		}
	}
	
	else if(cp[c]== "}")                                           //follow ki value dlegi  
	{
		c--;
		flag= true;
	}
			
   return flag;
}

bool list()
{
	bool flag=false;
	
	if(cp[c]==";")
		flag= true;
	
	else if(cp[c]==",")
	{
		c++;
		if(cp[c]=="ID")
		{
			c++;
			if(list_p())
			{
				flag= true;
			}
		}
	}
  	
	return flag;
}

bool list_p()
{
	bool flag=false;
	
	if(init())
	{
		c++;
		if(list())
		{
			flag=true;
		}
	}
	
	else if(cp[c]=="[")
	{
		c++;
		if(size())
		{
			c++;
			if(cp[c]=="]")
			{
				c++;
				if(a_init())
				{
					c++;
					if(list())
					{
						flag=true;
					}
				}
			}
		}
	}
  	
	return flag;
}

bool Const()
{
	bool flag=false;
	
	if(cp[c]=="int_const")
		flag=true;
	
	else if(cp[c]=="char_const")
		flag= true;
	
	else if(cp[c]=="float_const")
		flag= true;
  	
	else if(cp[c]=="string_const")
		flag= true;
	
	return flag;
}			

//********************************"CONDITION STATEMENT USED IN WHILST/IF_ELSE/DO_WHILST:" *********************************
bool OE()
{
	bool flag=false;
	
	if(AND())
	{
		c++;
		if(OE_p())
		{
			flag=true;
		}
	}
  	
	return flag;
}

bool OE_p()
{
	bool flag=false;
	
	if(cp[c]=="or_op")
	{
		c++;
		if(AND())
		{
			c++;
			if(OE_p())
			{
				flag=true;
			}
		}
	}
  	else if(cp[c]== ")" || cp[c]== ";")                                          //follow ki value dlegi   
	{
		c--;
		flag= true;
	}
	
	return flag;
}

bool AND()
{
	bool flag=false;
	
	if(RE())
	{
		c++;
		if(AND_p())
		{
			flag=true;
		}
	}
  	
	return flag;
}

bool AND_p()
{
	bool flag=false;
	
	if(cp[c]=="and_op")
	{
		c++;
		if(RE())
		{
			c++;
			if(AND_p())
			{
				flag=true;
			}
		}
	}
  	else if(cp[c]== "or_op" || cp[c]== ")" || cp[c]== ";")                                          //follow ki value dlegi   
	{
		c--;
		flag= true;
	}
	
	return flag;
}

bool RE()
{
	bool flag=false;
	
	if(E())
	{
		c++;
		if(RE_p())
		{
			flag=true;
		}
	}
  	
	return flag;
}

bool RE_p()
{
	bool flag=false;
	
	if(cp[c]=="relat_op")
	{
		c++;
		if(E())
		{
			c++;
			if(RE_p())
			{
				flag=true;
			}
		}
	}
  	else if(cp[c]== "and_op" || cp[c]== "or_op" || cp[c]== ";" || cp[c]== ")")                                          //follow ki value dlegi   
	{
		c--;
		flag= true;
	}
	
	return flag;
}

bool E()
{
	bool flag=false;
	
	if(T())
	{
		c++;
		if(E_p())
		{
			flag=true;
		}
	}
  	
	return flag;
}

bool E_p()
{
	bool flag=false;
	
	if(cp[c]=="addsub_op")
	{
		c++;
		if(T())
		{
			c++;
			if(E_p())
			{
				flag=true;
			}
		}
	}
  	else if(cp[c]== "and_op" || cp[c]== "or_op" || cp[c]== ";" || cp[c]== ")" || cp[c]== "," || cp[c]== "}" || cp[c]== "relat_op")                                             //follow ki value dlegi
	{
		c--;
		flag= true;
	}
	
	return flag;
}

bool T()
{
	bool flag=false;
	
	if(F())
	{
		c++;
		if(T_p())
		{
			flag=true;
		}
	}
  	
	return flag;
}

bool T_p()
{
	bool flag=false;
	
	if(MDM())
	{
		c++;
		if(F())
		{
			c++;
			if(T_p())
			{
				flag=true;
			}
		}
	}
  	else if(cp[c]== "and_op" || cp[c]== "or_op" || cp[c]== ";" || cp[c]== ")" || cp[c]== "," || cp[c]== "}" || cp[c]== "relat_op" || cp[c]=="addsub_op" )                                           //follow ki value dlegi  
	{
		c--;
		flag= true;
	}
	
	return flag;
}

bool F()
{
	bool flag=false;
	
	if(cp[c]=="ID")
	{
		c++;
		if(F_p())
		{
			flag=true;
		}
	}
	
	else if(Const())
	{
		flag=true;
	}
	
	else if(cp[c]=="(")
	{
		c++;
		if(OE())
		{
			c++;
			if(cp[c]==")")
			{
				flag=true;
			}
		}
	}	
	
	else if(cp[c]=="incdec_op")
	{
		c++;
		if(cp[c]=="ID")
		{
			flag=true;
		}
	}
	
	else if(cp[c]=="not_op")
	{
		c++;
		if(F())
		{
			flag=true;
		}
	}
		   
   return flag;
}

bool F_p()
{
	bool flag=false;
	
	if(cp[c]=="(")
	{
		c++;
		if(prmtrs2())
		{
			c++;
			if(cp[c]==")")
			{
				flag=true;
			}
		}
	}	
	
	else if(cp[c]=="incdec_op")
	{
		flag=true;
	}
	
	else if(cp[c]== "muldiv_op" || cp[c]== "mode_op" ||cp[c]== "and_op" || cp[c]== "or_op" || cp[c]== ";" || cp[c]== ")" || cp[c]== "," || cp[c]== "}" || cp[c]== "relat_op")                                          //follow ki value dlegi
	{
		c--;
		flag=true;
	}
		   
   return flag;
}

bool MDM()
{
	bool flag=false;
	
	if(cp[c]=="muldiv_op")
	{	
		flag=true;
	}	
	
	else if(cp[c]=="mode_op")
	{
		flag=true;
	}
		   
   return flag;
}

//********************************"whilst LOOP PARSER" *********************************
bool whilst()
{
	bool flag=false;
	
	if(cp[c]=="whilst")
	{
		c++;
		if(cp[c] == "(")
		{
			c++;
			if(OE())
			{
				c++;
				if(AI())
				{
					c++;
					if(cp[c]==")")
					{
						c++;
						if(body2())
						{
							flag=true;
						}
					}
				}
			}
		}
	}
		   
   return flag;
}

bool AI()  //AI= Assignment AND INCREMENT_DECREMENT
{
	bool flag=false;
	
	if(cp[c]==";")
	{
		c++;
		if(inc())
			flag=true;
		
		else if(assign())
			flag=true;
	}
	
	else if(cp[c]==")")  
	{
		c--;
		flag=true;
	}                                        //follow ki value dlegi                                  
	
	return flag;
}


bool inc()
{
	bool flag=false;
	
	if(cp[c]=="ID")
	{
		c++;
		if(cp[c]=="incdec_op")
			flag=true;
	}
	
	else if(cp[c]=="incdec_op")
	{
		c++;
		if(cp[c]=="ID")
			flag=true;
	}

	return flag;
}

bool assign()
{
	bool flag=false;
	
	if(cp[c]=="ID")
	{
		c++;
		if(cp[c]=="incdec_assign_op")
		{   
			c++;
			if(id_int())
			{
				flag=true;
			}
		}
	}
	
	return flag;
}

bool body2()
{
	bool flag=false;
	
	if(cp[c]==";")
		flag=true;
	
	else if(sst())
		flag=true;
	
	else if(cp[c]=="{")
	{
		c++;
		if(mst())
		{
			c++;
			if(cp[c]=="}")
				flag=true;	
		}
	}
	
	return flag;
}

//********************************"IF ELSE PARSER" *********************************
bool if_else()
{
	bool flag=false;
	
	if(cp[c]=="if")
	{
		c++;
		if(cp[c]=="(")
		{
			c++;
			if(OE())
			{
				c++;
				if(cp[c]==")")
				{
					c++;
					if(body2())
					{
						c++;
						if(op_else())
							flag=true;
					}
				}
				
			}
		}
	}
	
	return flag;
}

bool op_else()
{
	bool flag=false;
	
	if(cp[c]=="otherwise")
	{
		c++;
		if(body2())
			flag=true;
		
	}
	else if(cp[c]== "}" || cp[c]== "DT" || cp[c]== "if" || cp[c]== "whilst" || cp[c]== "do" || cp[c]== "ID" || cp[c]== "return"  )                                       //follow ki value dlegi
	{
		c--;
		flag=true;
	}

	return flag;
}

//********************************"FUNCTION PARSER" *********************************
bool function()
{
	bool flag=false;
	
	if(type())
	{
		c++;
		if(cp[c]=="ID")
		{
			c++;
			if(cp[c]=="(")
			{
				c++;
				if(prmtrs())
				{
					c++;
					if(cp[c]==")")
					{
						c++;
						if(cp[c]=="{")
						{
							c++;
							if(body())
							{
								c++;
								if(cp[c]=="}")
								{
									flag=true;
									
								}
							}
						}
					}
				}
			}
		}
	}
	
	return flag;
}

bool type()
{
	bool flag=false;
	
	if(cp[c]=="devoid")
	{
		flag=true;
	}
	else if(cp[c]=="DT")                                        
	{
		flag=true;
	}

	return flag;
}
	
bool prmtrs()
{
	bool flag=false;
	
	if(cp[c]=="DT")
	{
		c++;
		if(cp[c]=="ID")
		{
			c++;
			if(m_prmtrs())
			{
				flag=true;	
			}
		}
	}
	if(cp[c]==")")                                          //follow ki value dlegi
	{
		c--;
		flag=true;	
	}
	
	return flag;
}

bool m_prmtrs()
{
	bool flag=false;
	if(cp[c]==",")
	{
		c++;
		if(cp[c]=="DT")
		{
			c++;
			if(cp[c]=="ID")
			{
				c++;
				if(m_prmtrs())
				{
					flag=true;	
				}
			}
		}
	}
	
	if(cp[c]==")")                                          //follow ki value dlegi
	{
		c--;
		flag=true;	
	}
	
	return flag;
}


//********************************"FUNCTION SIGNATURE PARSER" *********************************
bool func_sign()
{
	bool flag=false;
	
	if(type())
	{
		c++;
		if(cp[c]=="ID")
		{
			c++;
			if(cp[c]=="(")
			{
				c++;
				if(prmtrs())
				{
					c++;
					if(cp[c]==")")
					{
						c++;
						if(cp[c]==";")
						{
							flag=true;
						}
					}
				}
			}
		}
	}
	
	return flag;
}


//********************************"FUNCTION CALLING PARSER" *********************************
bool func_call()
{
	bool flag=false;

	if(cp[c]=="ID")
	{
		c++;
		if(cp[c]=="(")
		{
			c++;
			if(prmtrs2())
			{
				c++;
				if(cp[c]==")")
				{
					c++;
					if(cp[c]==";")
					{
						flag=true;		
					}
				}
			}
		}
	}
	
	return flag;
}
	
bool prmtrs2()
{
	bool flag=false;
	
	if(E())
	{
		c++;
		if(m_prmtrs2())
		{
			flag=true;	
		}
	}
	else if(cp[c]==")")                                          //follow ki value dlegi
	{
		c--;
		flag=true;	
	}
	
	return flag;
}

bool m_prmtrs2()
{
	bool flag=false;
	if(cp[c]==",")
	{
		c++;
		if(E())
		{
			c++;
			if(m_prmtrs2())
			{
				flag=true;	
			}
		}
	}
	
	else if(cp[c]==")")                                          //follow ki value dlegi
	{
		c--;
		flag=true;	
	}
	
	return flag;
}

//********************************"STRUCTURES PARSER" *********************************
bool Struct()
{
	bool flag=false;

	if(cp[c]=="struct")
	{
		c++;
		if(cp[c]=="ID")
		{
			c++;
			if(cp[c]=="{")
			{
				c++;
				if(decl())
				{
					c++;
					if(cp[c]=="}")
					{
						c++;
						if(cp[c]==";")
						{
							flag=true;		
						}
					}
				}
			}
		}
	}
	
	return flag;
}

//********************************"GLOBAL DECLARATION PARSER" *********************************
bool G_decl()
{
	bool flag=false;

	if(decl())
	{
		flag=true;
	}
	
	return flag;
}

//********************************"DO WHILE PARSER" *********************************
bool do_whilst()
{
	bool flag=false;

	if(cp[c]=="do")
	{
		c++;
		if(cp[c]=="{")
		{
			c++;
			if(body())
			{
				c++;
				if(cp[c]=="}")
				{
					c++;
					if(cp[c]=="whilst")
					{
						c++;
						if(cp[c]=="(")
						{
							c++;
							if(OE())
							{
								c++;
								if(cp[c]==")")
								{
									c++;
									if(cp[c]==";")
									{
										flag=true;		
									}		
								}
							}
						}
					}
					
				}
			}
		}
	}
	
	return flag;
}


//********************************"ASSIGNMENT PARSER" *********************************

bool assignment()
{
	bool flag=false;

	if(cp[c]=="ID")
	{
		c++;
		if(cp[c]=="assign_op")
		{
			c++;
			if(E())
			{
				c++;
				if(cp[c]==";")
				{
					flag=true;		
				}		
			}
		}
		else if(cp[c]=="(")
		{
			c++;
			if(prmtrs2())
			{
				c++;
				if(cp[c]==")")
				{
					c++;
					if(cp[c]==";")
					{
						flag=true;
					}
				}
			}
		}
	}
	
	return flag;
}

