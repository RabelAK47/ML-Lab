#include "bits/stdc++.h"
using namespace std;

double ans = 0.0;
int each[100][100], usr1=-1, usr2=-1;

int main()
{
    int user, movie;
    cin >> user >> movie;

    for(int i = 0; i < user; i++)
    {
        for( int j = 0; j < movie; j++)
        {
            cin >> each[i][j];
        }
    }

    for(int i = 0; i < user; i++)
    {
        for(int x = i+1; x < user; x++)
        {
            double sum1 = 0, sum2 = 0, sum3 = 0;

            for(int j = 0; j < movie; j++)
            {

                int a = each[i][j];
                int b = each[x][j];

                sum1 += a*b;
                sum2 += a*a;
                sum3 += b*b;

            }

            double temp = sum1/ (sqrt(sum2) * sqrt(sum3));

            if( temp > ans)
            {
                ans = temp;
                usr1 = i;
                usr2 = x;
            }
        }
    }

    cout << "(" << usr1 << "," << usr2 << ") = " << ans << endl;

}

/*
4 7
4 0 0 5 1 0 0
5 5 4 0 0 0 0
0 0 0 2 4 3 0
0 3 0 0 0 0 3
*/

