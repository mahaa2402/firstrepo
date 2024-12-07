#include <iostream>
#include <fstream>
#include <cstdio> // For freopen

using namespace std;

int main() {
    // Redirect cin to read from "input.txt"
    freopen("input.txt", "r", stdin);

    // Redirect cout to write to "output.txt"
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b; // Input is read from "input.txt"

    cout << "Sum: " << a + b << endl; // Output is written to "output.txt"

    return 0;
}
