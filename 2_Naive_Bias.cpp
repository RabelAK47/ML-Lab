#include "bits/stdc++.h"
using namespace std;

string do_lower(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void display_prior_probability(int num_doc, int total_pos, int total_neg)
{
    cout << "==============Displaying Prior Probability=========\n";
    double pos = (double) total_pos / (double) num_doc;
    double neg = (double) total_neg / (double) num_doc;
    cout << "Prior Probability of Positive class " << pos << endl;
    cout << "Prior Probability of Negative class " << neg << endl;

    cout << endl;
    if(pos > neg)
        cout << "Test data in Positive class\n";
    else
        cout << "Test data in Negative class\n";
}

int main()
{
    int total_pos = 0;
    int total_neg = 0;
    int num_doc;
    cin >> num_doc;
    cin.ignore();

    vector <string> V, review;
    map <string, double> mp, mp2;

    set <string> St;
    for(int i = 0; i < num_doc; i++)
    {
        string temp, word;
        getline(cin, temp);
        V.push_back(temp);

        string rev;
        cin >> rev;
        cin.ignore();
        review.push_back(rev);

        if(rev == "Positive")
        {
            istringstream is(temp);
            while(is >> word)
            {
                word = do_lower(word);
                mp[word]++;
                total_pos++;
                St.insert(word);
            }
        }

        else if(rev == "Negative")
        {
            istringstream is(temp);
            while(is >> word)
            {
                word = do_lower(word);
                mp2[word]++;
                total_neg++;
                St.insert(word);
            }
        }
    }


    map <string, double> :: iterator it;
    cout << "=============Positive Reviews================\n";
    for(it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "=============Negative Reviews================\n";
    for(it = mp2.begin(); it != mp2.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "word\tPositive\tNegative\n";

    set <string> :: iterator its;
    for(its = St.begin(); its != St.end(); ++its)
    {
        cout << *its << "\t" << mp[*its] << "\t" << mp2[*its] << endl;
    }
    //cout << St.size() << endl;

    display_prior_probability(num_doc, total_pos, total_neg);

    string test, word;
    getline(cin, test);
    istringstream is(test);

//    cout << mp["buy"] << " " << total_pos << " " <<  St.size() << endl;
    while(is >> word)
    {
        cout << "P(" << word << ", Positive) = "  << setprecision(2) << ( mp[word] + 1) / (total_pos + St.size())  << endl;
    }
}

/*
5
Phone got crashed
Negative
Good Performance
Positive
Good Camera
Positive
Cheap in price
Positive
Battery drains fast
Negative
buy this phone
*/
