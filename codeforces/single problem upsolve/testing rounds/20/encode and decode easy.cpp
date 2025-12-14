#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() 
{
    int amount, temp;
    string run, out, str;
    cin >> run;
    if(run == "first")
    {
        cin >> amount;
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &temp);
            temp--;
            out.push_back(temp + 'a');
        }
        cout << out;
    }
    else
    {
        cin >> str;
        printf("%d\n", str.size());
        for(char c : str)
        {
            printf("%d ", c - 'a' + 1);
        }
    }
}
