#include "bits/stdc++.h"
using namespace std;

int N;
vector <int> v1, v2, fv1, fv2;

struct myStruct
{
    double x;
    double y;
}data[1000];


void cal_distance(double fx, double fy, double sx, double sy)
{
    for(int i = 0; i < N; i++)
    {
        double dis1 = sqrt( (fx-data[i].x) * (fx-data[i].x) + (fy-data[i].y) * (fy-data[i].y) );
        double dis2 = sqrt( (sx-data[i].x) * (sx-data[i].x) + (sy-data[i].y) * (sy-data[i].y) );

        if(dis1 < dis2)
            v1.push_back(i);
        else
            v2.push_back(i);
    }
}


int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> data[i].x >> data[i].y;
    int k = 2;

    double fx = data[2].x;
    double fy = data[2].y;

    double sx = data[5].x;
    double sy = data[5].y;

    cal_distance(fx, fy, sx, sy);

    while(v1.size() != fv1.size() || v2.size() != fv2.size())
    {
        cout << "Aise\n";
        fv1.clear();
        fv2.clear();

        fx = fy = 0;
        for(int i = 0; i < v1.size(); i++)
        {
            fv1.push_back(v1[i]);
            fx += data[v1[i]].x;
            fy += data[v1[i]].y;
        }

        sx = sy = 0;
        for(int i = 0; i < v2.size(); i++)
        {
            fv2.push_back(v2[i]);
            sx += data[v2[i]].x;
            sy += data[v2[i]].y;
        }

        fx /= (double) v1.size();
        fy /= (double) v1.size();

        sx /= (double) v2.size();
        sy /= (double) v2.size();

        v1.clear();
        v2.clear();
        cal_distance(fx, fy, sx, sy);
    }

    cout << "1st Cluster\n";
    for(int i = 0; i < fv1.size(); i++)
    {
        cout << fv1[i] << " ";
    }
    cout << endl;
    cout << "2nd Cluster\n";
    for(int i = 0; i < fv2.size(); i++)
    {
        cout << fv2[i] << " ";
    }
    cout << endl;
}

/*
6
1 1
2 2
1 2
2 4
5 5
4 3
*/
