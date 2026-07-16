#include<iostream>
#include<vector>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    vector<pair<char,int>> v;

    for(char ch : s)
    {
        if(ch >= 'a' && ch <= 'z')
        {
            v.push_back(make_pair(ch,0));
        }
        else
        {
            int pi = v.size() - 1;
            int count = v[pi].second * 10 + (ch - '0');
            v[pi].second = count;
        }
    }

    for(auto x : v)
    {
        char ch = x.first;
        int rpt = x.second;

        if(rpt == 0)
            rpt = 1;

        while(rpt--)
            cout << ch;
    }
}

int main()
{
    solve();
    return 0;
}