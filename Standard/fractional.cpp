#include<bits/stdc++.h> 
using namespace std; 
void swap_pair(double& a, double& b, int& i1, int& i2) { 
    double temp = a; 
    a = b; 
    b = temp; 
    int tmp = i1; 
    i1 = i2; 
    i2 = tmp; 
} 
void quickSort(vector<double>& ratio, vector<int>& index, int low, int high) { 
    if (low < high) { 
        double pivot = ratio[low]; 
        int i = low + 1, j = high; 
 
        while (i <= j) { 
            while (i <= high && ratio[i] >= pivot) i++; 
            while (j >= low && ratio[j] < pivot) j--; 
            if (i < j) swap_pair(ratio[i], ratio[j], index[i], index[j]); 
        } 
        swap_pair(ratio[low], ratio[j], index[low], index[j]); 
 
        quickSort(ratio, index, low, j - 1); 
        quickSort(ratio, index, j + 1, high); 
    } 
} 
int main() { 
    int n; 
    cout << "Enter number of items: "; 
    cin >> n; 
    vector<int> val(n), wt(n); 
    cout << "Enter Profit Values: "; 
    for (int i = 0; i < n; i++) cin >> val[i]; 
    cout << "Enter weights: "; 
    for (int i = 0; i < n; i++) cin >> wt[i]; 
    int capacity; 
    cout << "Enter knapsack capacity: "; 
    cin >> capacity; 
    vector<double> ratio(n); 
    vector<int> index(n); 
    for (int i = 0; i < n; i++) { 
        ratio[i] = (double)val[i] / wt[i]; 
        index[i] = i; 
    } 
    quickSort(ratio, index, 0, n - 1);  
    vector<double> taken(n, 0.0); 
    vector<double> profit(n, 0.0); 
    double total_value = 0; 
    for (int k = 0; k < n; k++) { 
        int i = index[k]; 
        if (capacity >= wt[i]) { 
            capacity -= wt[i]; 
            taken[i] = wt[i]; 
            profit[i] = val[i]; 
            total_value += val[i]; 
        } else { 
            taken[i] = capacity; 
            profit[i] = ((double)val[i] / wt[i]) * capacity; 
            total_value += profit[i]; 
            break;         } } 
 
   
    cout << "\n--- Knapsack Selection Summary ---\n";
cout << "Item  Value  Weight  Ratio   Taken   Profit\n";

for (int i = 0; i < n; i++) {

    cout << i + 1 << "     ";          // item number
    cout << val[i] << "     ";         // item value
    cout << wt[i] << "      ";         // item weight

    // ----- Print Ratio -----
    double ratio_value = (double)val[i] / wt[i];  
    cout << fixed << setprecision(2) << ratio_value << "   ";

    // ----- Print Weight Taken -----
    cout << fixed << setprecision(2) << taken[i] << "    ";

    // ----- Print Profit From Item -----
    cout << fixed << setprecision(2) << profit[i] << "\n";
}

// ---- Print Total Profit ----
cout << "\nTotal value in knapsack = " 
     << fixed << setprecision(2) << total_value << "\n";

 
    return 0; 
}