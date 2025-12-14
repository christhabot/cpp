#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int lettersToNumber(const string& col) 
{
    int result = 0;
    for (char c : col) {
        result = result * 26 + (c - 'A' + 1);
    }
    return result;
}

string numberToLetters(int num) 
{
    string result;
    while (num > 0) 
    {
        num--;
        result = char('A' + (num % 26)) + result;
        num /= 26;
    }
    return result;
}

int main() 
{
    int amountq, cont, a, b;
    bool second, stop;
    scanf("%d", &amountq);
    string str, temp, aa;
    while(amountq--)
    {
        cin >> str;
        cont = -1;
        for(int i = 0; i < str.size() && cont == -1; i++)
        {
            if(isdigit(str[i]))
            {
                cont = i;
            }
        }
        second = true;
        for(int i = cont; i < str.size(); i++)
        {
            if(!isdigit(str[i]))
            {
                second = false;
            }
        }
        if(!second)
        {
            stop = false;
            temp = "";
            for(int i = 1; i < str.size() && !stop; i++)
            {
                if(isdigit(str[i]))
                {
                    temp += str[i];
                }
                else
                {
                    stop = true;
                }
                cont = i;
            }
            a = stoi(temp);
            stop = false;
            temp = "";
            for(int i = cont+1; i < str.size() && !stop; i++)
            {
                temp += str[i];
            }
            b = stoi(temp);
            cout << numberToLetters(b) << a << "\n";
        }
        else
        {
            stop = false;
            temp = "";
            for(int i = 0; i < str.size() && !stop; i++)
            {
                if(!isdigit(str[i]))
                {
                    temp += str[i];
                }
                else
                {
                    stop = true;
                }
                cont = i;
            }
            aa = temp;
            stop = false;
            temp = "";
            for(int i = cont; i < str.size() && !stop; i++)
            {
                temp += str[i];
            }
            b = stoi(temp);
            cout << 'R' << b << 'C' << lettersToNumber(aa) << "\n";
        }
    }
}
