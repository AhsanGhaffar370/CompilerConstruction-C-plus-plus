# Recursive decent parser
#### **Objective(s) : Upon completion of these tasks, we will be able to learn how to.**
1. **Implement recursive decent parser**
    Recursive descent is a simple parsing algorithm that is very easy to implement. It is a top-down parsing algorithm because it builds the parse tree from the top (the start symbol) down.
    The main limitation of recursive descent parsing (and all top-down parsing algorithms in general) is that they only work on grammars with certain properties. For example, if a grammar contains any left recursion, recursive descent parsing doesn't work.
    A recursive decent parsing program consists of a set of procedures, one for each non-terminal. Execution begins with the procedure for the start symbol which halts and announces success if its procedure body scans the entire input string.
    General Recursive descent may require backtracking that is it may require repeated scans over the input

