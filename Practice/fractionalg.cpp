#include <bits/stdc++.h>
using namespace std;

void swap_pair(double &a, double &b, int &p, int &q)
{
  double temp = a;
  a = b;
  b = temp;
  int tmp = p;
  p = q;
  q = tmp;
}

void quick_sort(vector<double> &ratio, vector<int> &index, int low, int high)
{

  if (low < high)
  {
    double pivot = ratio[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
      while (i <= high && ratio[i] >= pivot)
        i++;
      while (j >= 0 && ratio[j] < pivot)
        j--;
      if (i < j)
      {
        swap_pair(ratio[i], ratio[j], index[i], index[j]);
        i++;
        j--;
      }
    }
    swap_pair(ratio[low], ratio[j], index[low], index[j]);
    quick_sort(ratio, index, low, j - 1);
    quick_sort(ratio, index, j + 1, high);
  }
}

int main()
{
  cout << "Enter the number of items:" << endl;
  int n;
  cin >> n;
  vector<int> wt(n, 0);
  vector<int> val(n, 0);
  cout << "=======Enter the weight values======" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter the weight of item " << (i + 1) << ":";
    cin >> wt[i];
  }
  cout << "=======Enter the Profit values======" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter the Profit of item " << (i + 1) << ":";
    cin >> val[i];
  }
  int capacity;
  cout << "Enter the knapsack capacity:" << endl;
  cin >> capacity;
  vector<double> ratio(n, 0.0);
  vector<int> index(n, 0);
  for (int i = 0; i < n; i++)
  {
    ratio[i] = (double)val[i] / wt[i];
    index[i] = i;
  }
  double total_value = 0.0;
  vector<int> taken(n, 0);
  vector<double> profit(n, 0.0);
  quick_sort(ratio, index, 0, n - 1);
  for (int k = 0; k < n; k++)
  {
    int i = index[k];
    if (capacity >= wt[i])
    {
      capacity -= wt[i];
      taken[i] += wt[i];
      profit[i] += val[i];
      total_value += profit[i];
    }
    else
    {

      taken[i] += capacity;
      profit[i] += ((double)val[i] / wt[i]) * capacity;

      total_value += profit[i];
      break;
    }
  }
cout << "===========Knapsack Table==========\n";
cout << left << setw(8) << "Item"
     << setw(10) << "Weight"
     << setw(10) << "Value"
     << setw(10) << "Profit"
     << setw(15) << "WeightTaken"
     << setw(10) << "Ratio" << endl;

for (int i = 0; i < n; i++)
{
    cout << left << setw(8) << i + 1
         << setw(10) << wt[i]
         << setw(10) << val[i]
         << setw(10) << fixed << setprecision(2) << profit[i]
         << setw(15) << taken[i]
         << setw(10) << fixed << setprecision(2) << ((double)val[i] / wt[i])
         << endl;
}

  cout << "Total Profit Value: " << fixed << setprecision(2) << total_value << endl;
  return 0;
}