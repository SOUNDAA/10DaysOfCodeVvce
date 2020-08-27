#include <bits/stdc++.h>
using namespace std;

int A[100005], B[100005], C[100005];

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int sumA = 0, sumB = 0, sumC = 0;
    
    for(int i=1; i<=a; i++)
    {
        cin >> A[i];
        sumA+= A[i];
    }
    
    for(int i=1; i<=b; i++)
    {
        cin >> B[i];
        sumB+= B[i];
    }
    
    for(int i=1; i<=c; i++)
    {
        cin >> C[i];
        sumC+= C[i];
    }
    
    a = 1, b = 1, c = 1;
    
    while(sumA!=sumB || sumB!=sumC || sumC!=sumA)
    {
        if(sumA>=sumC && sumA>=sumB)
        {
            sumA-= A[a];
            a++;
        }
        else if(sumB>=sumC && sumB>=sumA)
        {
            sumB-= B[b];
            b++;
        }
        else
        {
            sumC-= C[c];
            c++;
        }
    }
    
    cout << sumA << endl;

    return 0;
}