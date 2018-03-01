const int INF = 1e9 + 7;
#include <bits/stdc++.h>
#define in freopen("input.txt", "r", stdin)
#define out freopen ("output.txt", "w", stdout)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define ll long long
#define sc second
#define fr first
#define sws cin.sync_with_stdio(false);
using namespace std;
int main () {
     sws;
    //in;out;
   ll k,d,t;
    cin >> k >> d >> t;
    ll per;
    if (k%d==0){
            cout << t;
            return 0;
    }
    else {
        per = (k/d)*d +d;
    }
      ll cooking = per +k;
      ll num = (2*t)/cooking;
      ll carry = 2*t - num*cooking;
      long long ans;
      if (carry > 2*k)   {
        ans = num*per + carry - k ;
         cout << ans ;
         return 0;
      }
      else {
        ans = num*per;
        if (carry%2){
            ans+=carry/2;
            cout << ans << ".5";
        }
        else {
                ans+=carry/2;
            cout << ans;
        }
      }
                     return 0;
}
