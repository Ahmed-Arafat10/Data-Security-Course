#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    string Key;
    string Text;
    char Type;
    cout<<"Please Enter Key: ";
    cin>>Key;
    ll KeySz = Key.size();
    cout<<"Please Enter Text : ";
    cin.ignore();
    getline(cin,Text);
    cout<<"Please Enter (e) to encrypt, (d) to decrypt : ";
    cin>>Type;
    if(Type == 'e')
    {
        ll Spaces = 0;
        for(ll i =0; i<Text.size(); i++)
        {
            if(Text[i] == ' ') Spaces++;
        }
        ll TextSz =Text.size() - Spaces;
        ll Row = ceil(TextSz * 1.0 / KeySz);
        //Debug
        //cout<<"This row:"<<Row;
        char Grid[Row][KeySz];
        ll idx = 0;
        for(ll i = 0; i<Row; i++)
        {
            for(ll j = 0; j<KeySz; j++)
            {
                if(idx < Text.size())
                {
                    if(Text[idx] != ' ') Grid[i][j] = Text[idx], idx++;
                    else Grid[i][j] = Text[++idx], idx++;
                }
                else Grid[i][j] = 'z';
            }
        }
        //Debug
        for(ll i =0; i<Row; i++)
        {
            for(ll j = 0; j<KeySz; j++)
            {
                cout<<Grid[i][j]<<" ";
            }
            puts("");
        }
        map<ll,string> mp;
        for(ll i =0; i<Key.size(); i++)
        {
            string Temp = "";
            for(ll j = 0 ; j<Row; j++)
            {
                Temp += Grid[j][i];
            }
            mp[ Key[i] ] = Temp;
        }
        cout<<"CipherText Is: ";
        for(auto &it: mp) cout<< it.second;
    }
    else
    {
        map<ll,ll> mp;
        ll Row = Text.size() / KeySz;
        char Grid[Row][KeySz];
        for(ll i = 0; i<Key.size(); i++)
        {
            mp[ Key[i] - '0' ] = i;
        }
        //Debug
        //for(auto &it: mp)
        //{
        //    cout<< it.first <<"->"<<it.second<<"\n";
        //}
        ll R = 0;
        auto cur = mp.begin();
        for(ll i =0; i<Text.size(); i++)
        {
            if(R == Row) R = 0, cur++;
            ll refer = cur->second;
            Grid[R][refer] = Text[i];
            R++;
        }
        string PlainText;
        for(ll i =0; i<Row; i++)
        {
            for(ll j = 0; j<KeySz; j++)
            {
                cout<<Grid[i][j]<<" ";
                PlainText +=Grid[i][j];
            }
            puts("");
        }
        cout<<"PlainText Is: "<<PlainText;
    }
}
/*
I/P:
3412567
attack postponed until two am
e

O/P:
a t t a c k p
o s t p o n e
d u n t i l t
w o a m z z z
CipherText Is: ttnaaptmaodwtsuocoizknlzpetz
-----------
-----------
I/P:
83674215
fire on my order
e

O/P:
f i r e o n m y
o r d e r z z z
CipherText Is: mznziroryzrdeefo
-----------------
-----------------
I/P:
83674215
MRNSIRORYSRDEEFO
d

O/P:
F I R E O N M Y
O R D E R S R S
PlainText Is: FIREONMYORDERSRS
------------------
------------------
I/P:
58792
sizdettuxacyary
d

O/P:
d a t a s
e c u r i
t y x y z
PlainText Is: datasecurityxyz
*/
