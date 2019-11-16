/*

PROGRAM BY
RUSHIKESH V. AGASHE TE(E&TC)
PROF.AMOL V NYAYANIT (MIT, PUNE)

In order to separate variables,constants and operators from an expression the following guideline shall be used.
Examples:

1) Operators: + * = – /

2) Variables: z, xa, b4, y^3, rb1

3) Constants: 3, 56, 903

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{

char expr[100],operators[20]; //Arrays for storing expression and operator
char variables[20][20]; // 2d array for storing variable or identifier
int constants[20],ascii[100]={0}; //for storing constants, ascii values of expression
int cnt,i,number=0; //cnt to store string length
int j=-1,k=-1,l=-1,n=0; //counters for filling arrays
int pr[10]={0},m=0; //counters for printing identifier arrays

printf("\n———-LEXICAL ANALYZER ———-\n\n");

printf("Enter the String\n\n"); //Accepts expression from user
scanf ("%[^\n]%*c", expr); // “%[^\n]%*c” allows user to include spaces in entered string

cnt = strlen(expr);
printf("\nString length is: %d\n", cnt); //(OPTIONAL)To display string length

for (i = 0; i < cnt; ++i) //Loop to store ascii values in array ascii
{
ascii[i] = (int)expr[i];
}

for(i=0;i<cnt;++i)

{

if( isdigit(expr[i]) ) // Condition for current element to be digit
{
while(isdigit(expr[i])) //Run loop until successive elements are digits
{
number=10*number+ ascii[i] -'0'; // Needed to convert for eg. ‘3’ ‘4’ to 34
i++;
}
j++;
constants[j]=number;
number=0;
}

if( isalpha(expr[i]) ) //Condition for current element to be a variable
{
while( isalpha(expr[i]) || isdigit(expr[i]) || expr[i]=='_' ) //Run loop till next element is a letter or digit.
{
k++;
variables[m][k]=expr[i];
i++;
}
m++;
pr[n]=k;
n++;
k=-1;
}

if(expr[i]=='+'||expr[i]=='-'||expr[i]=='/'|| expr[i]=='*'|| expr[i]=='='|| expr[i]=='^') // Conditions to check for operators
{
l++;
operators[l]= expr[i];
}

}

//——————–Printing the Literals——————————-//
printf("\nThe literals are: \n\n");
for(i=0;i<=j;i++)
{
printf("\tlit%d\t%d \n",i+1,constants[i]);
}

//——————–Printing the Operators——————————-//
printf("\nThe operators are: \n\n");
for(i=0;i<=l;i++)
{
printf("\top%d\t%c\n",i+1,operators[i]);
}

//——————–Printing the Varibles——————————-//
printf("\nThe variables are: \n\n");
for(i=0;i<m;i++)
{
printf("\n\tid%d\t",i+1);
for(j=0;j<=pr[i];j++)
{
printf("%c",variables[i][j]);
}

}

printf("\n————– END OF LEXICAL ANALYZER ————\n\n");
}
