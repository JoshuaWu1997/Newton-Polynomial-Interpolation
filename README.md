# Newton-Polynomial-Interpolation
An optimisation of algorithms to calculate newton polynomial interpolation

![https://ece.uwaterloo.ca/~dwharder/NumericalAnalysis/05Interpolation/newton/](https://github.com/JoshuaWu1997/Newton-Polynomial-Interpolation/blob/master/p4.jpg)


1. coef.h: a defination of a tree (or graph) of newton coefficients (son-bro)
2. coef.cpp: an implementation of the coefficient tree
3. NEWTON.cpp: interface

The complexity of the nth interpolation is O(n). The device of such data structure theoretically reduces time consuming on C++ array indexing. The complexity of memory reference is approximately O(2n) instead of O(n(n-1)/2). Additionally, it is convenient for internal storage.

