#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amount;
    string temp, temp2;
    string run, out, str;
    string cur;
    char cc;
    bool started;
    cin >> run;
    if(run == "first")
    {
        cin >> amount;
        for(int i = 0; i < amount; i++)
        {
            temp.assign(10, '0');
            cin >> temp2;
            for (int j = 10 - temp2.size(); j < 10; j++) {
                temp[j] = temp2[j - (10 - temp2.size())];
            }
            for(char c : temp)
            {
                out.push_back((c - '0') + 'a');
            }
        }
        cout << out;
    }
    else
    {
        cin >> str;
        printf("%d\n", str.size()/10);
        for(int word = 0; word < str.size() / 10; word++)
        {
            started = false;
            cur = "";
            for(int i = 0; i < 10; i++)
            {
                cc = str[word*10+i];
                if(!started && cc == 'a')
                    continue;
                else
                {
                    started = true;
                    printf("%d", cc - 'a');
                }
            }
            printf(" ");
        }
    }
}