#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip> // For formatting output

using namespace std;

int main() {
    // Open the input text file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input.txt file!" << endl;
        return 1;
    }

    // Open the output text file
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error: Could not open output.txt file!" << endl;
        return 1;
    }

    // Write a header to the output file
    outputFile << "Row | Die Index | LLC X | LLC Y\n";
    outputFile << "------------------------------------\n";

    string line;
    int rowNum = 1; // Track the row number

    // Read each line of the input file
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string value;

        double waferDiameter, dieWidth, dieHeight, shiftX, shiftY, refOffsetX, refOffsetY;

        try {
            // Parse comma-separated values
            getline(ss, value, ',');
            waferDiameter = stod(value);

            getline(ss, value, ',');
            dieWidth = stod(value);

            getline(ss, value, ',');
            dieHeight = stod(value);

            getline(ss, value, ',');
            shiftX = stod(value);

            getline(ss, value, ',');
            shiftY = stod(value);

            getline(ss, value, ',');
            refOffsetX = stod(value);

            getline(ss, value, ',');
            refOffsetY = stod(value);
        } catch (const invalid_argument &e) {
            cerr << "Error: Invalid data on line " << rowNum << ". Skipping this line." << endl;
            rowNum++;
            continue; // Skip this line and move to the next
        }

        // Compute wafer radius
        double radius = waferDiameter / 2.0;

        // Compute the number of dies along x and y directions
        int diesX = ceil(waferDiameter / dieWidth);
        int diesY = ceil(waferDiameter / dieHeight);

        // Process the grid of dies
        for (int i = -diesX; i <= diesX; ++i) {
            for (int j = -diesY; j <= diesY; ++j) {
                double llcX = i * dieWidth + shiftX + refOffsetX;
                double llcY = j * dieHeight + shiftY + refOffsetY;

                // Check if the die is within the wafer
                double centerX = llcX + dieWidth / 2.0;
                double centerY = llcY + dieHeight / 2.0;
                if (centerX * centerX + centerY * centerY <= radius * radius) {
                    // Write to the output file
                    outputFile << "Row " << rowNum << " | (" << i << "," << j << ") | "
                               << fixed << setprecision(4) << llcX << " | "
                               << fixed << setprecision(4) << llcY << "\n";
                }
            }
        }

        rowNum++; // Increment row number
    }

    inputFile.close();  // Close the input file
    outputFile.close(); // Close the output file

    cout << "Processing complete. Results saved in 'output.txt'." << endl;
    return 0;
}
