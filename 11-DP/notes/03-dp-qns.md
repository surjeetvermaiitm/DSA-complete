#### Q1. Removing digits CSES

Link: https://cses.fi/problemset/task/1637

![1706594034887](image/03-dp-qns/1706594034887.png)

![1706594729949](image/03-dp-qns/1706594729949.png)

![1706594062129](image/03-dp-qns/1706594062129.png)

```CPP
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> get_digits(int n) {
    vector<int> result;
    while(n > 0) {
        if(n % 10 != 0) {
            // n%10 is the last digit
            result.push_back(n%10);
        }
        n = n / 10;
    }
    return result;
}

vector<int> dp;

int f(int n) {
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> d = get_digits(n);

    int result = INT_MAX;
    for(int i = 0; i < d.size(); i++) {
        result = min(result, f(n - d[i]));
    }
    return dp[n] = 1 + result;
}

int fbu(int num) {
    dp[0] = 0;
    for(int i = 1; i <= 9; i++) dp[i] = 1;
    for(int n = 10; n <= num; n++) {
        // n -> state
        // calc dp[n]
        vector<int> d = get_digits(n);
        int result = INT_MAX;
        for(int i = 0; i < d.size(); i++) {
            result = min(result, dp[n - d[i]]);
        }
        dp[n] = 1 + result;
    }
    return dp[num];
}

int main() {
    int n;
    cin>>n;
    dp.resize(1000005, -1);
    cout<<fbu(n)<<"\n";
    return 0;
}
```

#### Q2. Minimizing coins

Link: https://cses.fi/problemset/task/1634

![1706595049672](image/03-dp-qns/1706595049672.png)

- f(x) = 1+ min(f(x-c0),(x-c1),...f(x-cn-1)) where f(x) returns the min no of coins make x to 0

```CPP
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> coins;
vector<int> dp(1000006, -2);

int f(int x) {
    if(x == 0) return 0;
    if(dp[x] != -2) return dp[x];
    int result = INT_MAX;
    for(int i = 0; i < coins.size(); i++) {
        if(x - coins[i] < 0) continue;
        result = min(result, f(x - coins[i]));
    }
    if(result == INT_MAX) return dp[x] = INT_MAX;
    return dp[x] = 1 + result;
}

int main() {
    int n, x;
    cin>>n>>x;
    for(int i  = 0; i < n; i++) {
        int num;
        cin>>num;
        coins.push_back(num);
    }
    int ans = f(x);
    if(ans == INT_MAX) cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}
```

#### Qn 3. Dice combinations

Link:https://cses.fi/problemset/task/1633

- f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4)+f(n-5)+f(n-6)

```CPP
#include <iostream>
#include <vector>
#define mod 1000000007
#define ll long long int
using namespace std;
vector<ll> dp(1000005, -1);
ll f(int n) {
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll sum = 0;
    for(int i = 1; i <= 6; i++) {
        if(n - i < 0) break;
        sum = (sum % mod + f(n-i) % mod)%mod;
    }
    return dp[n] = sum%mod;
}


ll fbu(int n) {
    dp[0] = 1;

    for(int k = 1; k <= n; k++) {
        ll sum = 0;
        for(int i = 1; i <= 6; i++) {
            if(k - i < 0) break;
            sum = (sum % mod + dp[k-i] % mod)%mod;
        }
        dp[k] = sum%mod;
    }

    return dp[n];
}

int main() {
    int n;
    cin>>n;
    cout<<fbu(n)<<"\n";
    return 0;
}
```

#### Qn.4 Number of Dice rolls with target sum

Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

f(n,k,target)=no of ways to get target by die throw of n dices ok k faces

```CPP
#define ll long long int
#define mod 1000000007
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > dp;
    int f(int n, int k, int t) {
        if(n == 0 and t == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][t] != -1) return dp[n][t];
        int sum = 0;
        for(int v = 1; v <= k; v++) {
            if(t-v < 0) continue;
            sum = ((sum%mod) + f(n-1, k, t-v)%mod)%mod;
        }

        return dp[n][t] = sum%mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35, vector<int> (1005, -1));
        return f(n, k, target);
    }
};
```

#### Qn.5 Mcoins coins game (SPOJ)

Link: https://www.spoj.com/problems/MCOINS/#:~:text=MCOINS%20%2D%20Coins%20Game&text=They%20choose%20two%20different%20positive,L%20coins%20from%20the%20tower.
