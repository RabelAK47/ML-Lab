#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;

int mat[1000][1000], trans[1000][1000], multi[1000][1000];
int row, col;

void scan_matrix()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void calculate_transpose()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }
}

void mat_multiply()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int sum = 0;
            for(int k = 0; k < col; k++)
            {
                sum += mat[i][k] * trans[k][j];
            }
            multi[i][j] = sum;
            sum = 0;
        }
    }
}

int main()
{
    cin >> row >> col;

    scan_matrix();
    calculate_transpose();
    mat_multiply();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << multi[i][j] << " ";
        }
        cout << endl;
    }
}
/*
2 2
1  2
4  5
*/
