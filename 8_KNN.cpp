#include "bits/stdc++.h"
using namespace std;

struct myStruct
{
    int x, y;
    string cls;
    double distance;
};

double cal_distance(double x1, double y1, double x2, double y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool cmp(myStruct lhs, myStruct rhs)
{
    return lhs.distance < rhs.distance;
}

int main()
{
    struct myStruct data[1000];
    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> data[i].x >> data[i].y >> data[i].cls;
    }

    int test_x, test_y, K;
    cin >> test_x >> test_y;
    cin >> K;

    for(int i = 0; i < N; i++)
    {
        data[i].distance = cal_distance(test_x, data[i].x, test_y, data[i].y);
    }

    sort(data, data+N, cmp);

    map <string, int> Mp;
    map <string, int> :: iterator it;
    priority_queue <int> PQ;

    for(int i = 0; i < K; i++)
    {
        Mp[data[i].cls]++;
        PQ.push(Mp[data[i].cls]);
    }

    string test_class = "";
    for(it = Mp.begin(); it != Mp.end(); ++it)
    {
        if(it->second == PQ.top())
        {
            test_class = it->first;
            break;
        }
    }
    cout << "Test data will in " << test_class << " class" << endl;

}
/*
4
7 7 Bad
7 4 Bad
3 4 Good
1 4 Good
3 7
1
*/
