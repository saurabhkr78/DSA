/*inline fxn are the actual fxn 
All the functions defined inside class definition are by default inline, but you can also make any non-class function inline by using keyword inline with them.*/

inline void fun(int a) 
{ 
    return a++; 
}

/*Some Important points about Inline Functions
We must keep inline functions small, small inline functions have better efficiency.
Inline functions do increase efficiency, but we should not make all the functions inline. Because if we make large functions inline, it may lead to code bloat, and might affect the speed too.
Hence, it is advised to define large functions outside the class definition using scope resolution :: operator, because if we define such functions inside class definition, then they become inline automatically.
Inline functions are kept in the Symbol Table by the compiler, and all the call for such functions is taken care at compile time.*/

/*Limitations of Inline Functions
Large Inline functions cause Cache misses and affect performance negatively.
Compilation overhead of copying the function body everywhere in the code on compilation, which is negligible for small programs, but it makes a difference in large code bases.
Also, if we require address of the function in program, compiler cannot perform inlining on such functions. Because for providing address to a function, compiler will have to allocate storage to it. But inline functions doesn't get storage, they are kept in Symbol table.
*/
