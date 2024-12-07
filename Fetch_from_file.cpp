#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("Format_Source.txt");  // Open the input file for reading
    std::ofstream outputFile("new.txt");          // Open the output file for writing

    if (!inputFile || !outputFile) {
        std::cerr << "Error: Could not open file(s)." << std::endl;
        return 1;
    }

    std::string word = "boundary";
    std::string line;
    int count = 0;

    // Write lines containing the word "boundary" until 2 occurrences are found
    while (count <= 2 && std::getline(inputFile, line)) {
        if (line.find(word) != std::string::npos) {
            count++;
        }
        outputFile << line << '\n';
    }

    // Store all remaining lines to get the last two
    std::vector<std::string> remainingLines;
    while (std::getline(inputFile, line)) {
        remainingLines.push_back(line);
    }

    // Write the last two lines from the remaining lines
    int start = std::max(0, static_cast<int>(remainingLines.size()) - 2);
    for (int i = start; i < remainingLines.size(); i++) {
        outputFile << remainingLines[i] << '\n';
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Processing complete. Data saved to new.txt" << std::endl;
    return 0;
}
