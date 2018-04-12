#include "bits/stdc++.h"
using namespace std;

int num_doc;
vector <int> total_word_in_doc;
vector <string> all_doc;
vector <map<string,double> > MapDoc;
vector <map<string,double> > normalize_map;
vector <set<string> > distinct_word;
map <string, double> idf_word;


string do_lower(string word)
{
    for(int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);
    if(word[word.length()-1] == '.')
        word = word.substr(0, word.length()-1);
    return word;
}

void take_input()
{
    for(int i = 0; i < num_doc; i++)
    {
        string temp;
        getline(cin, temp);
        all_doc.push_back(temp);
    }
}

void do_mapping()
{
    for(int i = 0; i < num_doc; i++)
    {
        string temp = all_doc[i], word;
        istringstream is(temp);
        map <string, double> mp;
        int Count = 0;
        while(is >> word)
        {
            word = do_lower(word);
            mp[word]++;
            Count++;
        }
        MapDoc.push_back(mp);
        total_word_in_doc.push_back(Count);
    }
}

void display_term_frequency()
{
    int Count = 1;
    for(int i = 0; i < MapDoc.size(); i++)
    {
        map<string, double> mp = MapDoc[i];
        map<string,double> :: iterator it;
        cout << "\nTerm Frequency of Document: " << Count++ << endl;
        cout << "============================" << endl;
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            cout << it->first << " = " << it->second << endl;
        }
        cout << endl;
    }
}

void do_word_distinct()
{
    for(int i = 0; i < MapDoc.size(); i++)
    {
        map<string, double> mp = MapDoc[i];
        map<string,double> :: iterator it;
        set<string> St;
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            St.insert(it->first);
        }
        distinct_word.push_back(St);
    }
}

void do_normalize()
{
    for(int i = 0; i < MapDoc.size(); i++)
    {
        map<string, double> mp = MapDoc[i];
        map<string,double> :: iterator it;
        int num_word = total_word_in_doc[i];
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            mp[it->first] = it->second / num_word;
        }
        normalize_map.push_back(mp);
    }
}

void display_after_normalize()
{
    int Count = 1;
    for(int i = 0; i < normalize_map.size(); i++)
    {
        map<string, double> mp = normalize_map[i];
        map<string,double> :: iterator it;
        cout << "\nNormalized Document: " << Count++ << endl;
        cout << "============================" << endl;
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            cout << it->first << " = " << it->second << endl;
        }
        cout << endl;
    }
}

int number_of_document_having_term(string term)
{
    int Count = 0;
    for(int i = 0; i < num_doc; i++)
    {
        set <string> St = distinct_word[i];
        set <string> :: iterator it;
        for(it = St.begin(); it != St.end(); ++it)
        {
            if(*it == term)
                Count++;
        }
    }
    return Count;
}

void calculate_IDF()
{
    for(int i = 0; i < num_doc; i++)
    {
        map <string, double> mp = MapDoc[i];;
        map <string, double> :: iterator it;
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            string term = it->first;
            if(idf_word[term] == 0)
            {
                idf_word[term] = 1 + log ((double)num_doc / (double)number_of_document_having_term(term));
            }
        }
    }
}

void display_idf_terms()
{
    cout << "IDF OF ALL TERM" << endl;
    cout << "=================" << endl;
    map <string, double> :: iterator it;
    for(it = idf_word.begin(); it != idf_word.end(); ++it)
    {
        cout << "IDF {" << it->first << "} = " << it->second << endl;
    }
}

int main()
{
    cin >> num_doc;
    cin.ignore();

    take_input();

    do_mapping();

    display_term_frequency();

    do_word_distinct();

    do_normalize();

    display_after_normalize();

    calculate_IDF();

    display_idf_terms();
}
