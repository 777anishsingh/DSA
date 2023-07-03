#include <bits/stdc++.h>
using namespace std;

// Q1. [ COIN CHANGE ] - You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any
// combination of the coins, return -1. You may assume that you have an infinite number of each kind of coin.

int solve(int coins[], int size, int amount, int currentCoin)
{
    // base case
    if (amount == 0)
        return 1;

    if (amount < 0)
        return 0;

    // use evry coins
    int ways = 0;
    for (int i = currentCoin; i < size; i++)
    {
        ways += solve(coins, size, amount - coins[i], i);
    }
    return ways;
}

// Q2 [ OPTIMAL GAME ANALYSIS ] - You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.Player 1 and player 2 take turns,
// with player 1 starting first.Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of
// the array(i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score.
// The game ends when there are no more elements in the array.

int optimalStrategy(int arr[], int i, int j)
{
    // base condition
    if (i > j)
        return 0;

    // Recursive condition
    int choice1 = arr[i] + min(optimalStrategy(arr, i + 2, j), optimalStrategy(arr, i + 1, j - 1));
    int choice2 = arr[j] + min(optimalStrategy(arr, i + 1, j - 1), optimalStrategy(arr, i, j - 2));

    int ans = max(choice1, choice2);
    return ans;
}

int main()
{
    int coins[] = {1, 2};
    int size = 3;
    int amount = 4;

    // cout << solve(coins, size, amount, 0);

    int arr[] = {20, 30, 2, 2, 2, 10};
    int i = 0, j = 5;

    cout << optimalStrategy(arr, i, j);

    return 0;
}