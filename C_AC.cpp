#include <iostream>
using namespace std;
 
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
// Function to get an integer input (simulating ini())
long long getInput() {
    long long x;
    cin >> x;
    return x;
}
 
// Function to print an integer (simulating ps())
void printSpace(long long x) {
    cout << x << " ";
}
 
// Function to print a newline (simulating pl())
void printNewline() {
    cout << "\n";
}
 
// Main function to solve the problem
void solve() {
    long long num1 = getInput();
    long long num2 = getInput();
    long long num3 = getInput();
    for (long long i = num1; i > num2; --i) printSpace(i);
    for (long long i = 1; i <= num2; ++i) printSpace(i);
    printNewline();
}
 
// Starting function
void start() {
    long long testCases = 1;
    testCases = getInput();
    while (testCases-- > 0) solve();
}
 
int main() {
    fastIO();
    start();
    return 0;
}
