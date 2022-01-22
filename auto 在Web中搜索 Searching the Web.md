### auto 在Web中搜索 Searching the Web

```c++
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
vector<string> data[110];
map<string, map<int, set<int> > > database;
// set_intersection（取集合交集）
// set_union（取集合并集）
// set_difference（取集合差集）
// set_symmetric_difference（取集合对称差集）
void str(string &s)
{
    for(auto &t:s)
    {
        if(isupper(t))
        {
            t = tolower(t);
        }
    }
}
void get(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; ; j++)
        {
            string s;
            getline(cin, s);
            if(s=="**********")
            {
                break;
            }
            data[i].push_back(s);
            for(auto &t:s)
            {
                if(!isalpha(t))
                {
                    t = ' ';
                }
            }
            stringstream ss;
            ss << s;
            while(ss >> s)
            {
                str(s);
                database[s][i].insert(j);
            }
        }
    }
}
void findA(const string &A, int n)
{
    if(database.count(A)==0)
    {
        cout << "Sorry, I found nothing." << endl;
    }
    else
    {
        bool flag = false;
        for(auto &t:database[A])
        {
            if(flag)
            {
                cout << "----------" << endl;
            }
            flag = true;
            for(int temp:t.second)
            {
                cout << data[t.first][temp] << endl;
            }
        }
    }
}
void AandB(const string &A, const string &B, int n)
{
    bool flag = false;
    bool firstpassage = true;
    if(database.count(A)!=0)
    {
        for(auto &t:database[A])
        {
            if(database.count(B)!=0&&database[B].count(t.first)!=0)
            {
                flag = true;
                if(!firstpassage)
                {
                    cout << "----------" << endl;
                }
                firstpassage = false;
                set<int> ans;
                set_union(database[A][t.first].begin(), database[A][t.first].end(), database[B][t.first].begin(), database[B][t.first].end(), inserter(ans, ans.begin()));
                for(auto temp:ans)
                {
                    cout << data[t.first][temp] << endl;
                }
            }
        }
    }
    if(!flag)
    {
        cout << "Sorry, I found nothing." << endl;
    }
}
void AorB(const string &A, const string &B, int n)
{
    map<int, set<int> > ans;
    if(database.count(A)!=0)
    {
        for(auto &t:database[A])
        {
            for(int temp:t.second)
            {
                ans[t.first].insert(temp);
            }
        }
    }
    if(database.count(B)!=0)
    {
        for(auto &t:database[B])
        {
            for(int temp:t.second)
            {
                ans[t.first].insert(temp);
            }
        }
    }
    if(ans.empty())
    {
        cout << "Sorry, I found nothing." << endl;
    }
    else
    {
        bool firstpassage = true;
        for(auto &t:ans)
        {
            if(!firstpassage)
            {
                cout << "----------" << endl;
            }
            firstpassage = false;
            for(auto temp:t.second)
            {
                cout << data[t.first][temp] << endl;
            }
        }
    }
}
void wA(const string &A, int n)
{
    set<int> all;
    for(int i=0; i<n; i++)
    {
        all.insert(i);
    }
    set<int> Apassage;
    if(database.count(A)!=0)
    {
        for(auto &t:database[A])
        {
            Apassage.insert(t.first);
        }
    }
    set<int> ans;
    set_difference(all.begin(), all.end(), Apassage.begin(), Apassage.end(), inserter(ans, ans.begin()));
    if(ans.empty())
    {
        cout << "Sorry, I found nothing." << endl;
    }
    else
    {
        bool firstpassage = true;
        for(auto &t:ans)
        {
            if(!firstpassage)
            {
                cout << "----------" << endl;
            }
            firstpassage = false;
            for(auto &temp:data[t])
            {
                cout << temp << endl;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    getchar();
    get(n);
    int m;
    cin >> m;
    getchar();
    while(m--)
    {
        string A, B, s;
        stringstream ss;
        getline(cin, s);
        ss << s;
        ss >> A;
        if(A=="NOT")
        {
            ss >> A;
            wA(A, n);
        }
        else if(ss >> s >> B)
        {
            if(s=="AND")
            {
                AandB(A, B, n);
            }
            else
            {
                AorB(A, B, n);
            }
        }
        else
        {
            findA(A, n);
        }
        cout << "==========" << endl;
    }
    return 0;
}
```

