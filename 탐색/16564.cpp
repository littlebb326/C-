#include <iostream>
using namespace std;
typedef long long ll;
ll level[1000001];
ll n, k;
bool isLvPossible(ll target)
{
  ll temp_k = 0;
  for (int i = 1; i <= n; i++)
  {
    if (level[i] < target)
      temp_k += (target - level[i]);
  }

  if (temp_k <= k)
    return true;
  return false;
}
int main()
{
  ll start = 1;
  ll end = 1000000000;
  ll answer = 1;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    cin >> level[i];

  while (start <= end)
  {
    ll mid = (start + end) / 2;
    if (isLvPossible(mid))
    {
      answer = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }

  cout << answer;

  return 0;
}