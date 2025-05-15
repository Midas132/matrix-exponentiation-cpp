#include <iostream>
using namespace std;

const int Q = 1e9+7;

const long long M = 101;
long long **A;
long long **B;
long long **W;
long long **K;

void mnozenie(int d, long long ** pA, long long ** pB, long long ** pC)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < d; k++)
            {
                K[i][j] += (pB[i][k]*pC[k][j])%Q;
                K[i][j]%=Q;
            }
        }
    }
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            pA[i][j] =K[i][j];
            K[i][j]=0;
        }
    }
}
void pot(long long n, int d)
{

    while(n>0)
    {
        if(n%2==1) mnozenie(d, W, W, A);

        mnozenie(d, A, A, A);
        n/=2;
    }
}

int main()
{
    long long k, n;
    cin >> k >> n;
    A = new long long * [M];
    B = new long long * [M];
    W = new long long * [M];
    K = new long long * [M];
    for(int i = 0; i < k; i++)
    {
        A[i] = new long long [k];
        B[i] = new long long [k];
        W[i] = new long long [k];
        K[i] = new long long [k];
        for(int j = 0; j < k; j++)
        {
            cin >> A[i][j];
            K[i][j]=0;
            B[i][j] = 0;
            if(i==j)
            {
                W[i][j] = 1;
            }else{
                W[i][j] = 0;
            }
        }
    }

    pot(n,k);

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << W[i][j]%Q<< ' ';
        }
        cout << '\n';
    }

}

/*
2 2
1 1
1 0
*/