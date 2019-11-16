#include<iostream>
#include<string.h>
using namespace std;
int i = 0;
string w[]={"for","(","DT","ID","=","int",";","ID","relop","int",";","ID","indec",")",";"};
bool For();
bool AD();
bool decl();
bool con();
bool c();
bool AI();
bool id_cons();
bool inc();
bool assign();
bool body();
bool ml_st();
bool s_st();
bool Const();
bool init();
bool list();
 
 bool init()
{
//	int i = 0;
	
	if(w[i] == "=")
	{
		i++;
		
		if(w[i]=="ID")
		{
		 i++;
		if(init())
		{
			return true;
		}
	    }
	    
	    else if(Const())
	    {
	    	return true;
	    }
	}
	else if(w[i]==" ")
	{
		return true;
	}
	
   else	return false;
	
}

bool list()
{
//	int i = 0;
	if(w[i]==";")
	{
		return true;
	}
	else if(w[i]==",")
	{
		i++;
		if(w[i]=="ID")
		{
			i++;
			if(init())
			{
				i++;
				if(list())
				{
					return true;
				}
			}
		}
		
	}
	
  else	return false;
}

bool Const()
{
//	int i = 0 ;
	if(w[i]=="int")
	{
		return true;
	}
	
	else if(w[i]=="char")
	{
		return true;
	}
	else if(w[i]=="float")
	{
		return true;
	}
	
  else	return false;
}

 
bool decl()
{
	
	//int i = 0;
	if(w[i]=="DT")
	{
		i++;
		
		if(w[i]=="ID")
		{
			i++;
			if(init())
			{
				i++;
				if(list())
				{
					return true;
				}
			}
		}
	}
	
	else return false;
}

bool For()
{
	if(w[i]=="for")
	{
		i++;
		if(w[i] == "(")
		{
			i++;
			
			if(AD())
			{
				i++;
				if(con())
				{
					i++;
					if(w[i]==";")
					{
						i++;
						if(AI())
						{
							i++;
							if(w[i]==")")
							{
								i++;
								if(body())
								{
									return true;
								}
							}
							
						}
					}
				}
			}
		}
	}
   else	return false;
}



bool AD()
{
	if(decl())
	{
		return true;
		
	}
	else if(assign())
	{
		i++;
		if(w[i]==";")
		{
		
		return true;
	}
	
	
	}
	else if(w[i]==";")
	{
		return true;
	}
	else return false;
}

bool con()
{
	if(c())
	{
		return true;
	}
	else if(w[i]==" ")
	{
		return true;
	}
	
	else return false;
}
 bool c()
 {
 	if(id_cons())
 	{
 		i++;
 		if(w[i]=="relop")
 		{
 			i++;
 			if(id_cons())
 			{
 				return true;
 			}
 		}
 	}
 	else return false;
 }
 bool AI()
 {
 	if(inc())
 	{
 		return true;
 	}
 	else if(assign())
 	{
 		return true;
 	}
 	else if(w[i]==" ")
 	{
 		return true;
 	}
 	else return false;
 }
 
 bool id_cons()
 {
 	if(w[i]=="ID")
 	{
 		return true;
 		
 	}
 	else if(w[i]=="int")
 	{
 		return true;
 	}
 	else return false;
 }
 
 bool inc()
 {
 	if(w[i]=="ID")
 	{
 		i++;
 		if(w[i]=="indec")
 		{
 			return true;
 		}
 	}
 	else if(w[i]=="indec")
 	{
 		i++;
 		if(w[i]=="ID")
 		{
 			return true;
 		}
 	}
 	
 	else return false;
 }
 
 bool assign()
 {
 	if(w[i]=="ID")
 	{
 		i++;
 		if(w[i]=="asop")
 		{   
 		i++;
 			if(id_cons())
 			{
 				i++;
 				if(w[i]==";")
 				{
 					return true;
 				}
 			}
 		}
 	}
 	else return false;
 }
 
 bool body()
 {
 	if(w[i]==";")
 	{
 		return true;
 	}
 	else if(s_st())
 	{
 		return true;
 	}
 	else if(w[i]=="{")
 	{
 		i++;
 		if(ml_st())
 		{
 			i++;
 			if(w[i]=="}")
 			{
 				return true;
 			}
 		}
 	}
 	else return false;
 }
 
 bool ml_st()
 {
 	if(s_st())
 	{
 		i++;
 		if(ml_st())
 		{
 			return true;
 		}
 	}
 	else if(w[i]==" ")
 	{
 		return true;
 	}
 	else 
	 	return false;
 }
 
bool s_st()
{
	if(w[i]=="any single line commment")
	{
		return true;
	}
	else return false;
}
 
 int main()
 {
 	if(For())
 	{
 		cout<<"Valid";
 	}
 	else {
 		cout<<"invalid";
 	}
 }
