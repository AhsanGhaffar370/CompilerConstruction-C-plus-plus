# Language Specification, RE, NFA and DFA
#### **Objective(s) : Upon completion of these tasks, we will be able to learn how to.**

1.	**Define Language Specification**
    First step to design a compiler for any language is to identify the specification of that language. Language specification includes language name, targeted audience, paradigm of language, components of language, syntax of language components. Identify the keywords,identifier, constants, punctuators and operators of Language.  

2.	**Generate RE, NFA and DFA**
    *   **Regular Expression(RE):**
        A regular expression is a pattern that the regular expression engine attempts to match in input text. A pattern consists of one or more character literals, operators, or constructs. 
        Example:
        (aa)*
        (ab+ba)+
        (aa+bb)* + (ab+ba)*

    *   **Deterministic Finite Automata(DFA):**
        In DFA, for each input symbol, one can determine the state to which the machine will move. Hence, it is called Deterministic Automaton. As it has a finite number of states, the machine is called Deterministic Finite Machine or Deterministic Finite Automaton

    *   **Non-Deterministic Finite Automata(NFA):**
        In NDFA, for a particular input symbol, the machine can move to any combination of the states in the machine. In other words, the exact state to which the machine moves cannot be determined. Hence, it is called Non-deterministic Automaton. As it has finite number of states, the machine is called Non-deterministic Finite Machine or Non-deterministic Finite Automaton.
        

3.	**Implement DFA of any Language.**
    Implementaion is defined in code.
