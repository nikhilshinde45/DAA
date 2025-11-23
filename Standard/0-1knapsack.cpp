
#include<iostream>
#include<vector>
using namespace std;

int maximum_profit(vector<int> &weight, vector<int> &profit, vector<int> &items, int n, int c)
{
    vector<vector<int>> table(n + 1, vector<int>(c + 1, 0));

    // DP tabulation approach
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (weight[i] <= j)
            {
                table[i][j] = max(table[i - 1][j], (profit[i] + table[i - 1][j - weight[i]]));
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    // Backtrack to get the selected items
    int i = n, j = c;
    while (i > 0 && j > 0)
    {
        if (table[i][j] != table[i - 1][j])
        {
            items.push_back(i);
            j = j - weight[i];
        }
        i--;
    }

    // TABLE:
    cout << "\nDP TABLE:\n";
    for (int j = 0; j <= c; j++){
        cout<<"\t"<<j;

    }
    cout << "\n";
    for(int i=0;i<=n;i++){
        cout<<"i="<<i<<"\t";
        for(int j=0;j<=c;j++){
            cout<<table[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return table[n][c];
}



int main()
{
    int n, c;
    cout << "Enter the numbers of items: ";
    cin >> n;

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> c;

    vector<int> weight(n + 1, 0), profit(n + 1, 0), items;

    cout << "Enter the Weight of item and corresponding profit:\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> profit[i];
    }

    int maxprofit = maximum_profit(weight, profit, items, n, c);
    cout << "\nThe Maximum Profit is: " << maxprofit << endl;

    cout << "The Selected items are as follows:\n";
    for (int i = 0; i < items.size(); i++)
    {
        int it = items[i];
        cout << "Item " << it + 1 << "\n";
    }

    return 0;
}

    