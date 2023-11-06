#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();

    // Create a 2D table to store the maximum values for different subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Include the current item and find the maximum value
                // by considering or not considering the item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Exclude the current item as its weight exceeds the capacity
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, weights, values);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
