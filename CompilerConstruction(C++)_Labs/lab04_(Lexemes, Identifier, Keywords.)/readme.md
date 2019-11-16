# Lexemes, Identifier, Keywords.
#### **Objective(s) : Upon completion of these tasks, we will be able to learn how to.**

1.	**Define Lexemes and Tokens.**
    A lexical analyzer reads characters from the input and groups them into "token objects." A sequence of input characters that comprises a single token is called a lexeme. A valid lexeme should be one of the basic components of language.  
    Basic Components of Language:
    Each language has following basic components,
    1.	Identifiers
    2.	Keywords
    3.	Constants
    4.	Punctuators
    5.	Operators

2.	**Identify rules for Identifier and keywords.**
    Rules for writing an identifier
    1.	A valid identifier can have letters (both uppercase and lowercase letters), digits and underscores.
    2.	The first letter of an identifier should be either a letter or an underscore. 
    3.	There is no rule on length of an identifier. 

3.	**Generate RE and DFA of Identifier.**
    letter(letter | digit | _)*
    letter: (A-Z) or (a-z),  digit: 0, 1, 2, ….. , 9

4.	**Split text in words on the basis of white spaces.**

5.	**Validate Identifier and Keywords of Language.**
    *Keywords are the reserved words of language which is specified for a predefine function. A keyword of a language must follow the rule of identifier of that language.
