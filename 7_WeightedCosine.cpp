#include "bits/stdc++.h"
using namespace std;

int user, movie;
double each[1000][1000];

void scan_table()
{
    for(int i = 0; i < user; i++)
    {
        for(int j = 0; j < movie; j++)
        {
            cin >> each[i][j];
        }
    }
}

void update_weight()
{
    for(int i = 0; i < user; i++)
    {
        double sum = 0;
        int Count = 0;
        for(int j = 0; j < movie; j++)
        {
            if(each[i][j] > 0)
            {
                sum += each[i][j];
                Count++;
            }
        }

        for(int j = 0; j < movie; j++)
        {
            if(each[i][j] > 0)
                each[i][j] -= (double)(sum/Count);
        }
    }
}

int main()
{
    cin >> user >> movie;

    scan_table();
    update_weight();

    double user1, user2;
    double ans = 0;
    for(int i = 0; i < user; i++)
    {
        for(int x = i+1; x < user; x++)
        {
            double sum1 = 0, sum2 = 0, sum3 = 0;
            for(int j = 0; j < movie; j++)
            {
                double a = each[i][j];
                double b = each[x][j];
                sum1 += a*b;
                sum2 += a*a;
                sum3 += b*b;
            }

            double temp = sum1/(sqrt(sum2)*sqrt(sum3));
            if(temp > ans)
            {
                ans = temp;
                user1 = i;
                user2 = x;
            }
        }
    }

    cout << "Answer of Weighted Cosine\n";
    cout << user1 << ", " << user2 << " = " << ans << endl;;
}
/*
4 7
4 0 0 5 1 0 0
5 5 4 0 0 0 0
0 0 0 2 4 3 0
0 3 0 0 0 0 3
*/
