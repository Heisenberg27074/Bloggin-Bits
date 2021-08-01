#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool possible(lli *arr, lli C, lli mid, lli n)
{
    lli ans = 1, pos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {   
            ans++;
            pos = arr[i];
        }
        
    }
    return ans >= C;
}
lli solve(lli *arr, lli C, lli n)
{
    sort(arr, arr + n);
    lli ans = -1;
    if (C > n)
    {
        return -1;
    }
    lli low = 1, high = arr[n - 1] - arr[0];
    while (low <= high)
    {
        lli mid = (high - low) / 2 + low;
        if (possible(arr, C, mid, n))
        {
            ans = max(mid, ans);
            low = mid + 1;
        }else{
            high = mid - 1;
        }
        
    }
    return ans;
}

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli N, C;
        cin >> N >> C;
        lli arr[N] = {0};
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        lli ans = solve(arr, C, N);
        cout << ans << endl;
    }
    return 0;
}