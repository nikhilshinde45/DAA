#include <bits/stdc++.h>
using namespace std;

// Function to print all subsets whose sum equals targetSum
void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset)
{
    // If we reached the end of the array and the targetSum is 0, print the subset
    if (targetSum == 0) {
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << "]" << endl;
        return;
    }

    if (i == n) {
        // Return if we have reached at the end of the array
        return;
    }

    // Not considering current element
    PrintSubsetSum(i + 1, n, set, targetSum, subset);

    // Considering the current element if it is less than or equal to the targetSum
    if (set[i] <= targetSum) {
        // Add current element to the subset
        subset.push_back(set[i]);

        // Recurse for the next elements, reducing the target sum
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);

        // Backtrack and remove the last element from the subset
        subset.pop_back();
    }
}

// Menu-driven function to get user input and find all subsets
void menu()
{
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enter a set and target sum" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                int n, targetSum;

                // Taking input for the set
                cout << "Enter the number of elements in the set: ";
                cin >> n;

                int set[n];
                cout << "Enter the elements of the set: ";
                for (int i = 0; i < n; i++) {
                    cin >> set[i];
                }

                // Taking input for the target sum
                cout << "Enter the target sum: ";
                cin >> targetSum;

                vector<int> subset; // to store the current subset
                cout << "The subsets with sum " << targetSum << " are: " << endl;
                PrintSubsetSum(0, n, set, targetSum, subset);

                break;
            }

            case 2:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 2);
}

int main()
{
    menu(); // Start the menu-driven program
    return 0;
}


// /Menu:
// 1. Enter a set and target sum
// 2. Exit
// Enter your choice: 1
// Enter the number of elements in the set: 7
// Enter the elements of the set: 5 7 10 12 15 18 20
// Enter the target sum: 35
// The subsets with sum 35 are: 
// [ 15 20 ]
// [ 7 10 18 ]
// [ 5 12 18 ]
// [ 5 10 20 ]
// Menu:
// 1. Enter a set and target sum
// 2. Exit
// Enter your choice: 1
// Enter the number of elements in the set: 5 10 12 13 15 18
// Enter the elements of the set: Enter the target sum: 30
// The subsets with sum 30 are: 
// [ 12 18 ]
// Menu:
// 1. Enter a set and target sum
// 2. Exit
// Enter your choice: 2
// Exiting program.
// administrator@administrator-OptiPlex-5060:~/Desktop/33255$