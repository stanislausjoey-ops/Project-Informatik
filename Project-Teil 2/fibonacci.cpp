//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 0;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i <= n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 0; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}

//2.2.3: Ja, da es gibt mehrere Call-stack und Rechnungen.
//2.2.4: Ab der 47-ten Fibonnaci-Zahl ist sie fur int Datentyp zu gross, also overflow (32 bit).
//int Wertbereich ist bis 2,147,483,647, und f(47) ist 2,971,215,073
