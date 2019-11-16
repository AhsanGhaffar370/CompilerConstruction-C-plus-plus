#include <iostream>
#include<string>
using namespace std;
int Transition_func(int state, char ch)
{
    int TT[6][4] = { {1,5,5,5}, {5,2,5,4}, {3,5,5,5}, {5,5,5,5}, {2,5,2,2}, {5,5,5,5} };
    if (ch == '\'' && (state == 0 || state == 2))
    {
        return TT[state][0];
    }
    else if ((state!=4) &&( isalpha(ch) || isdigit(ch)))
    {
        return TT[state][1];
    }
    else if (ch=='\'' || ch=='\"' )
    {
        
        return TT[state][2];
    }
    else if( (state == 4 && (ch=='n' || ch=='t')))
    {
        return TT[state][2];    
    }
    else if(ch == '\\'){
        return TT[state][3];
    }
    else 
    {
        return 0;    
    }
}

int main()
{
    string input;
    int I_state = 0;
    int F_state = 3;
    int C_state = I_state;
    cout << "Enter any character for validation: \n";
    cin >> input;
    for(unsigned int i=0; i< input.length(); i++)
    {
        C_state = Transition_func(C_state, input[i]);
        
        if(C_state==5){
            break;
        }
    }
    if (C_state == F_state)
    {
        cout << "Valid Character "<<endl;
    }
    else
    {
        cout << "InValid Character "<<endl;
    }
}

