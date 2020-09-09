#include <iostream>
#include <cmath>
#include "Hash.h"
using namespace std;

// Checks if number is prime
bool isPrime(int x)
{
    for(int i=2; i< x/2; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

// Finds the next prime number
int returnNextPrimeNumber(float val)
{
    int x = round(val);
    if(x==0 || x==1)
        return 3;
    
    while(true)
    {
        if(isPrime(x))
            return x;
        x++;
    };
}

int main()
{
    int A[] = {5, 3, 12, 8, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    
    // Find the size of hash table
    int m = returnNextPrimeNumber(1.3 * size);
    
    Hash h(m);
    
    for(int i=0; i<size; i++)
    {
        h.insertItem(A[i]);
    }
    
    h.displayHash();
    return 0;
}
