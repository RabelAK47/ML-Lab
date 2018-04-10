#include "bits/stdc++.h"
using namespace std;

double prio_pos;
double prio_neg;

string do_lower(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void display_prior_probability(double num_doc, double total_pos, double total_neg)
{
    prio_pos = total_pos/num_doc;
    prio_neg = total_neg/num_doc;
    cout << "\nPrior Probabilities\n";
    cout << "P(Positive) = " << setprecision(2) <<  prio_pos << endl;
    cout << "P(Negative) = " << setprecision(2) << prio_neg << endl;
    cout << endl;
}

int main()
{
    double num_doc, total_pos = 0, total_neg = 0;
    double pos_word = 0, neg_word = 0;
    cin >> num_doc;
    cin.ignore();

    map <string, int> mpPos, mpNeg;
    set <string> St;

    for(int i = 0; i < num_doc; i++)
    {
        string line;
        getline(cin, line);
        line = do_lower(line);

        string rev;
        cin >> rev;
        cin.ignore();

        if(rev == "Positive")
        {
            total_pos++;
            istringstream is(line);
            string word;
            while(is >> word)
            {
                mpPos[word]++;
                pos_word++;
                St.insert(word);
            }
        }
        else if(rev == "Negative")
        {
            total_neg++;
            istringstream is(line);
            string word;
            while(is >> word)
            {
                mpNeg[word]++;
                neg_word++;
                St.insert(word);
            }
        }
    }

    string test_data;
    getline(cin, test_data);
    test_data = do_lower(test_data);

    display_prior_probability(num_doc, total_pos, total_neg);

    istringstream is(test_data);
    string word;
    cout << "Conditional Probability\n";

    double positive = prio_pos;
    double negative = prio_neg;
    while(is >> word)
    {
        double ans1 = (mpPos[word]+1)/(pos_word + St.size());
        double ans2 = (mpNeg[word]+1)/(neg_word + St.size());
        cout << word << "(Positive) " << setprecision(2) << ans1 << endl;
        cout << word << "(Negative) " << setprecision(2) << ans2 << endl;

        positive *= prio_pos;
        negative *= prio_neg;
    }
    cout << endl;

    if(positive >= negative)
        cout << "Test data is Positive Sentiment\n";
    else
        cout << "Test data is Negative Sentiment\n";
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
