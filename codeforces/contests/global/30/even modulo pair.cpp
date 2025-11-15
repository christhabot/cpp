#include <bits/stdc++.h>

using namespace std;

typedef long long ZQ;

bool fx_pair(const vector<ZQ>& VV, ZQ& AA, ZQ& BB)
{
    int SZ = VV.size();
    if (SZ < 2)
    {
        return false;
    }
    for (int I = 0; I < SZ - 1; I++)
    {
        ZQ MD = VV[I + 1] % VV[I];
        if (MD % 2 == 0)
        {
            AA = VV[I];
            BB = VV[I + 1];
            return true;
        }
    }

    for (int I = 0; I < SZ; I++)
    {
        for (int J = I + 1; J < SZ; J++)
        {
            ZQ MD = VV[J] % VV[I];
            if (MD % 2 == 0)
            {
                AA = VV[I];
                BB = VV[J];
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int TT;
    scanf("%d", &TT);
    for (int CS = 0; CS < TT; CS++)
    {
        int NN;
        scanf("%d", &NN);
        vector<ZQ> RR(NN);
        for (int I = 0; I < NN; I++)
        {
            scanf("%lld", &RR[I]);
        }
        vector<ZQ> OO, EE;
        for (auto XX : RR)
        {
            if (XX % 2 == 0)
            {
                EE.push_back(XX);
            }
            else
            {
                OO.push_back(XX);
            }
        }
        if (EE.size() >= 2)
        {
            printf("%lld %lld\n", EE[0], EE[1]);
            continue;
        }
        if (EE.size() == 0)
        {
            ZQ A1, B1;
            if (fx_pair(OO, A1, B1))
            {
                printf("%lld %lld\n", A1, B1);
            }
            else
            {
                printf("-1\n");
            }
            continue;
        }

        ZQ EV = EE[0];
        auto IT = lower_bound(OO.begin(), OO.end(), EV);
        int LC = IT - OO.begin();
        bool OK = false;
        for (int K = 0; K < LC; K++)
        {
            ZQ MD = EV % OO[K];
            if (MD % 2 == 0)
            {
                printf("%lld %lld\n", OO[K], EV);
                OK = true;
                break;
            }
        }
        if (!OK)
        {
            ZQ A2, B2;
            if (fx_pair(OO, A2, B2))
            {
                printf("%lld %lld\n", A2, B2);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}
