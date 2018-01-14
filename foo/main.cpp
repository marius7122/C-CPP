#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findArrayQuadruplet(vector<int> arr, int s)
{
  int n = arr.size();

  sort(arr.begin(),arr.end());

  int i,j,p,u;

  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
      p = 0;
      u = n-1;

      //updating the values for p and u for avoid overlapping
      while(p == i || p == j)
        p++;
      while(u == i || u == j)
        u--;

      int sum = s - (arr[i] + arr[j]);

      while(p < u && sum != arr[p] + arr[u])
      {
        //i must increment p for getting a bigger sum
        if(sum > arr[p] + arr[u])
          do
            p++;
            while(p == i || p == j);
        //i must decrement u for getting a smaller sum
        else
          do
            u--;
            while(u == i || u == j);
      }

      if(sum == arr[p] + arr[u] && p < u)
      {
        vector<int> sol = {arr[i],arr[j],arr[p],arr[u]};
        sort(sol.begin(),sol.end());
        return sol;
      }

    }

  vector<int> emptyArr;
  return emptyArr;
}

int main() {

  vector<int> v = {4,4,4,4};

  vector<int> sol = findArrayQuadruplet(v,16);

  for(int i = 0;i < sol.size(); i++)
    cout<<sol[i]<<' ';


  return 0;
}
