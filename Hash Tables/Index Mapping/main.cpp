#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

// Can handle negative numbers
// hash[element][0] handles non-negative numbers
// hash[element][1] handles negative numbers
bool hashA[MAX+1][2];

bool search(int X)
{
    if(X >= 0)
    {
        if(hashA[X][0]==1)
            return true;
        else
            return false;
    }
    
    // For negative values take the absolute 
    // value of X 
    
    X = abs(X);
    if(hashA[X][1] == 1)
        return true;
    return false;
}

void insert(int a[], int n)
{
    for(int i=0; i< n; i++)
    {
        if(a[i] >= 0)
            hashA[a[i]][0] = 1;
        else
            hashA[abs(a[i])][1] = 1;
    }
}

int main()
{
    int A[] = {-5, 4, 2, -16, 3, 3};
    int n = sizeof(A)/sizeof(A[0]);
    insert(A,n);
    int X = -2;
    if(search(X) == true)
        cout<<"Present"<<endl;
    else
        cout<<"Not Present"<<endl;
    return 0;
}
