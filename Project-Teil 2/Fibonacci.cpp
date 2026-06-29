//============================================================================
// Name        : Fibonacci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

int fibonacci(int n)
{
	if (n==0) return 0;
	if (n==1) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main() {

	std::cout<<"Fibonacci-Zahlen von 0 bis 25: "<<"\n";
	for (int i=0;i<=25;i++){
		std::cout<<"f("<<i<<") = "<<fibonacci(i)<<"\n";
	}

	return 0;
}
