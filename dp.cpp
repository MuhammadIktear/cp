//knapsack recursive approach
#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int weight[], int value[], int W)

{

 if (n == 0 || W == 0)

 return 0;

 if (weight[n - 1] <= W)

 {

 // duita option

 // niye dekhbo, na niye dekhbo

 int op1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];

 int op2 = knapsack(n - 1, weight, value, W);

 return max(op1, op2);

 }

 else

 {

 // ekta option

 // na niyei dekhte hobe

 int op2 = knapsack(n - 1, weight, value, W);

 return op2;

 }

}

int main()

{

 int n;

 cin >> n;

 int weight[n], value[n];

 for (int i = 0; i < n; i++)

 {

 cin >> weight[i];

 }

 for (int i = 0; i < n; i++)

 {

 cin >> value[i];

 }

 int W;

 cin >> W;

 cout << knapsack(n, weight, value, W) << endl;

 return 0;

}


//subset sum top down
#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

bool subset_sum(int n, int a[], int s)

{

 if (n == 0)

 {

 if (s == 0)

 return true;

 else

 return false;

 }

 if (dp[n][s] != -1)

 return dp[n][s];

 if (a[n - 1] <= s)

 {

 bool op1 = subset_sum(n - 1, a, s - a[n - 1]);

 bool op2 = subset_sum(n - 1, a, s);

 return dp[n][s] = op1 || op2;

 }

 else

 {

 return dp[n][s] = subset_sum(n - 1, a, s);

 }

}

int main()

{

 int n;

 cin >> n;

 int a[n];

 for (int i = 0; i < n; i++)

 {

 cin >> a[i];

 }

 int s;

 cin >> s;

 for (int i = 0; i <= n; i++)

 {

 for (int j = 0; j <= s; j++)

 {

 dp[i][j] = -1;

 }

 }

 if (subset_sum(n, a, s))

 {

 cout << "YES" << endl;

 }

 else

 {

 cout << "NO" << endl;

 }

 return 0;

}

//count subset sum
#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int subset_sum(int n, int a[], int s)

{

 if (n == 0)

 {

 if (s == 0)

 return 1;

 else

 return 0;

 }

 if (dp[n][s] != -1)

 return dp[n][s];

 if (a[n - 1] <= s)

 {

 int op1 = subset_sum(n - 1, a, s - a[n - 1]);

 int op2 = subset_sum(n - 1, a, s);

 return dp[n][s] = op1 + op2;

 }

 else

 {

 return dp[n][s] = subset_sum(n - 1, a, s);

 }

}

int main()

{

 int n;

 cin >> n;

 int a[n];

 for (int i = 0; i < n; i++)

 {

 cin >> a[i];

 }

 int s;

 cin >> s;

 dp[0][0] = true;

 for (int i = 1; i <= s; i++)

 {

 dp[0][i] = 0;

 }

 for (int i = 1; i <= n; i++)

 {

 for (int j = 0; j <= s; j++)

 {

 if (a[i - 1] <= j)

 {

 dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];

 }

 else

 {

 dp[i][j] = dp[i - 1][j];

 }

 }

 }

 for (int i = 0; i <= n; i++)

 {

 for (int j = 0; j <= s; j++)

 {

 cout << dp[i][j] << " ";

 }

 cout << endl;

 }

 return 0;

}
//Equal sum partition
#include <bits/stdc++.h>

using namespace std;

int main()

{

 int n;

 cin >> n;

 int s = 0;

 int a[n];

 for (int i = 0; i < n; i++)

 {

 cin >> a[i];

 s += a[i];

 }

 if (s % 2 == 0)

 {

 int sum = s / 2;

 bool dp[n + 1][sum + 1];

 dp[0][0] = true;

 for (int i = 1; i <= sum; i++)

 dp[0][i] = false;

 for (int i = 1; i <= n; i++)

 {

 for (int j = 0; j <= sum; j++)

 {

 if (a[i - 1] <= j)

 {

 dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];

 }

 else

 {

 dp[i][j] = dp[i - 1][j];

 }

 }

 }

 if (dp[n][sum])

 cout << "YES" << endl;

 else

 cout << "NO" << endl;

 }

 else

 {

 cout << "NO" << endl;

 }

 return 0;

}

//coin change 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - w[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}

//coin change 2(unbound knapsack)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= s; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp[n][s] == INT_MAX - 1)
        cout << "Not Possible" << endl;
    else
        cout << dp[n][s] << endl;
    return 0;
}


