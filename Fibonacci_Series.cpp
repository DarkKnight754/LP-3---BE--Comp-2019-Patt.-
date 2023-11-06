#include <iostream>
#include <stdio.h>

using namespace std;

void printfibonacci( int n)
{
    static int n1=0, n2=1, n3;
    if (n>0)
    {
        n3 = n1 + n2;
        n1 =n2;
        n2 = n3;
        cout<<n3<<" ";
        printfibonacci(n-1);
    }
}
int main()
{
    int n;
    cout<<"no. of elements :";
    cin>>n;
    cout<<"Fibonacci Series: ";    
    cout<<"0 "<<"1 ";  
    printfibonacci(n-2);    
    return 0;  
}
