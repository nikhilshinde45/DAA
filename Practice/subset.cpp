#include <bits/stdc++.h>
using namespace std;

void printsubsetsum(int i, int n, int set[], vector<int> &subset, int targetsum)
{
  if (targetsum == 0)
  {
    cout << "[ ";
    for (int i = 0; i < subset.size(); i++)
    {
      cout << subset[i] << " ";
    }
    cout << "]" << endl;
    return;
  }
  if (i == n)
  {
    return;
  }
  printsubsetsum(i + 1, n, set, subset, targetsum);
  if (set[i] <= targetsum)
  {
    subset.push_back(set[i]);
    printsubsetsum(i + 1, n, set, subset, targetsum - set[i]);
    subset.pop_back();
  }
}

void menu()
{
  int ch;
  do
  {
    cout << "==========MENU==========" << endl;
    cout << "1.Enter the set and targetsum:" << endl;
    cout << "2.Exit" << endl;

    cout << "Enter your choice:";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
      int n;
      cout << "Enter the number of elements in the set:";
      cin >> n;
     
      int set[n];
      for (int i = 0; i < n; i++)
      {
        cout<<"Enter the element "<<(i+1)<<":";
        cin >> set[i];
      }
      int targetsum;
      cout << "Enter the targetsum:";
      cin >> targetsum;
      vector<int> subset;
      cout<<"===========The subsets are=========="<<endl;
      printsubsetsum(0, n, set, subset, targetsum);
      break;
    }

    case 2:
    {
      cout << "Exiting..." << endl;

      break;
    }
    default:
    {
      cout << "Enter the appropriate choice...." << endl;
    }
    }

  } while (ch != 2);
}
int main()
{
  menu();
  return 0;
}