#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int count_cycle(int n, std::vector<int> &cache);

int max_cycle(int a, int b);

int main()
{

 int a, b;
 std::cin >> a >> b;

 std::cout << max_cycle(a, b);

 return 0;
}

int count_cycle(int n, std::vector<int> &cache)
{

 if (n == 1)
 {
  return 1;
 }

 if (cache[n] != 0)
 {
  return cache[n];
 }

 int count = 1;
 if (n % 2 == 0)
 {
  count += count_cycle(n / 2, cache);
 }
 else
 {
  count += count_cycle(3 * n + 1, cache);
 }
 cache.at(n) = count;
 return count;
}

int max_cycle(int a, int b)
{

 std::vector<int> cache;
 for (int i = 0; i <= 1000 * 1000; i++)
 {
  cache.push_back(0);
 }

 int max = 0;

 for (int i = a; i <= b; i++)
 {
  int curr = count_cycle(i, cache);
  if (curr > max)
  {
   max = curr;
  }
 }

 return max;
}
