#include "bits/stdc++.h"
using namespace std;

struct myStruct
{
    string outlook;
    string temperature;
    string humidity;
    string windy;
    string play;
};

int main()
{
    struct myStruct data[1000];
    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> data[i].outlook >> data[i].temperature >> data[i].humidity >> data[i].windy >> data[i].play;
    }

    map <string, int> Mp;
    map <string, int> :: iterator it;
    for(int i = 0; i < N; i++)
    {
        Mp[data[i].outlook]++;
    }

    double ans = 0;
    for(it = Mp.begin(); it != Mp.end(); ++it)
    {
        double yes = 0, no = 0;
        for(int i = 0; i < N; i++)
        {
            if(it->first == data[i].outlook)
            {
                if(data[i].play == "yes")
                    yes++;
                else
                    no++;
            }
        }

        double Count = (double) it->second;
        double pi = yes/Count;
        double qi = no/Count;

        if(pi > 0.0 && qi > 0.0)
            ans += (Count/(double)N) * (((-pi)*log2(pi)) + ((-qi)*log2(qi)));
        else if(pi > 0.0)
            ans += (Count/(double)N) * ((-pi)*log2(pi));
        else
            ans += (Count/(double)N) *  ((-qi)*log2(qi));
    }

    cout << "Entropy Base on Outlook " << ans << endl;
}
/*
14
R H H F no
R H H T no
O H H F yes
S M H F yes
S C N F yes
S C N T no
O C N T yes
R M H F no
R C N F yes
S M N F yes
R M N T yes
O M H T yes
O H N F yes
S M H T no
*/
