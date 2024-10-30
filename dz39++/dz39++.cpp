//Завдання1
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//void copyFileLines(const string& inputFile, const string& outputFile) {
//    ifstream inFile(inputFile);
//    ofstream outFile(outputFile);
//
//    if (!inFile || !outFile) {
//        cerr << "File could not be opened" << endl;
//        return;
//    }
//
//    string line;
//    while (getline(inFile, line)) {
//        outFile << line << endl;
//    }
//
//    inFile.close();
//    outFile.close();
//}
//
//int main() {
//    string inputFile = "input.txt";
//    string outputFile = "output.txt";
//
//    copyFileLines(inputFile, outputFile);
//    cout << "Rows copied successfully" << endl;
//}

//Завдання 3
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void addDashesAfterLastNonSpaceLine(const string& inputFile, const string& outputFile) {
//    ifstream inFile(inputFile);
//    ofstream outFile(outputFile);
//
//    if (!inFile || !outFile) {
//        cerr << "File could not be opened" << endl;
//        return;
//    }
//
//    vector<string> lines;
//    string line;
//    int lastNonSpaceLineIndex = -1;
//
//    while (getline(inFile, line)) {
//        lines.push_back(line);
//        if (line.find(' ') == string::npos) {
//            lastNonSpaceLineIndex = lines.size() - 1;
//        }
//    }
//
//    for (size_t i = 0; i < lines.size(); i++) {
//        outFile << lines[i] << endl;
//        if (static_cast<int>(i) == lastNonSpaceLineIndex) {
//            outFile << "------------" << endl;
//        }
//    }
//
//    if (lastNonSpaceLineIndex == -1) {
//        outFile << "------------" << endl;
//    }
//
//    inFile.close();
//    outFile.close();
//}
//
//int main() {
//    string inputFile = "input.txt";
//    string outputFile = "output.txt";
//
//    addDashesAfterLastNonSpaceLine(inputFile, outputFile);
//    cout << "The operation was successful" << endl;
//}

//Завдання 5
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void generateFileStatistics(const string& textf, const string& textl) {
    ifstream inFile(textf);
    ofstream outFile(textl);

    if (!inFile || !outFile) {
        cerr << "File could not be opened." << endl;
        return;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string vowels = "aeiouyAEIOUY";
    string line;

    while (getline(inFile, line)) {
        lineCount++;
        for (char ch : line) {
            if (isalpha(ch)) {
                charCount++;
                if (vowels.find(ch) != string::npos) {
                    vowelCount++;
                }
                else {
                    consonantCount++;
                }
            }
            else if (isdigit(ch)) {
                charCount++;
                digitCount++;
            }
            else if (!isspace(ch)) {
                charCount++;
            }
        }
    }

    outFile << "Number of symbols: " << charCount << endl;
    outFile << "Number of rows: " << lineCount << endl;
    outFile << "The number of vowels: " << vowelCount << endl;
    outFile << "Number of consonant letters: " << consonantCount << endl;
    outFile << "The number of digits: " << digitCount << endl;

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "textf.txt";
    string outputFile = "textl.txt";

    generateFileStatistics(inputFile, outputFile);
    cout << "Statistics are saved in the file " << outputFile << endl;
}
