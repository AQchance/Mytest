#include <string>
#include <iostream>

using namespace std;

void LSD(string *a, int N)
{
    int w = a[0].size();
    int R = 256;
    string *aux = new string[N];
    int *count = new int[R + 1];

    for (int k = w - 1; k >= 0; k++)
    {
        for (int i = 0; i < R + 1; i++)
        {
            count[i] = 0;
        }

        for (int i = 0; i < N; i++)
        {
            count[a[i][k] + 1]++;
        }

        for (int i = 0; i < R; i++)
        {
            count[i + 1] += count[i];
        }

        for(int i =0;i<N;i++){
            aux[count[a[i][k]++]]=a[i];
        }
        for(int i =0;i<N;i++){
            a[i]=aux[i];
        }
    }
}

int main()
{
    
}