#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

bool isValidSolution(const unordered_map<char, int>& letterToDigit, const vector<string>& words, const string& resultWord) {
    int result = 0;
    for (char ch : resultWord) {
        result = result * 10 + letterToDigit.at(ch);
    }

    int sum = 0;
    for (const string& word : words) {
        int value = 0;
        for (char ch : word) {
            value = value * 10 + letterToDigit.at(ch);
        }
        sum += value;
    }

    return sum == result;
}

bool solveCryptarithmetic(const vector<string>& words, const string& resultWord, vector<char>& letters, unordered_map<char, int>& letterToDigit, unordered_set<int>& usedDigits, size_t index = 0) {
    if (index == letters.size()) {
        return isValidSolution(letterToDigit, words, resultWord);
    }

    char currentLetter = letters[index];
    for (int digit = 0; digit <= 9; ++digit) {
        // Skip digit 0 for first letters
        bool isFirstLetter = false;
        for (const string& word : words) {
            if (word[0] == currentLetter) {
                isFirstLetter = true;
                break;
            }
        }
        if (resultWord[0] == currentLetter) {
            isFirstLetter = true;
        }

        if (isFirstLetter && digit == 0) {
            continue;
        }

        if (usedDigits.count(digit) == 0) {
            letterToDigit[currentLetter] = digit;
            usedDigits.insert(digit);

            if (solveCryptarithmetic(words, resultWord, letters, letterToDigit, usedDigits, index + 1)) {
                return true;
            }

            usedDigits.erase(digit);
        }
    }

    return false;
}
bool validateInput(const vector<string>& words, const string& resultWord) {
    // Check too many unique letters
    unordered_set<char> uniqueLetters;
    for (const string& word : words) {
        for (char ch : word) {
            uniqueLetters.insert(ch);
        }
    }
    for (char ch : resultWord) {
        uniqueLetters.insert(ch);
    }
    if (uniqueLetters.size() > 10) {
        cout << "Error: Too many unique letters in the puzzle." << endl;
        return false;
    }

    // Check length of result word
    size_t maxLength = 0;
    for (const string& word : words) {
        maxLength = max(maxLength, word.length());
    }
    if (resultWord.length() < maxLength || resultWord.length() > 2 * maxLength) {
        cout << "Error: The length of the result word does not match the expected length." << endl;
        return false;
    }

    // Check non-alphabetic characters
    for (const string& word : words) {
        for (char ch : word) {
            if (!isalpha(ch)) {
                cout << "Error: Non-alphabetic characters present in input." << endl;
                return false;
            }
        }
    }
    for (char ch : resultWord) {
        if (!isalpha(ch)) {
            cout << "Error: Non-alphabetic characters present in input." << endl;
            return false;
        }
    }

    // Check duplicate words
    vector<string> sortedWords = words;
    sort(sortedWords.begin(), sortedWords.end());
    if (unique(sortedWords.begin(), sortedWords.end()) != sortedWords.end()) {
        cout << "Error: Duplicate words found in input." << endl;
        return false;
    }
    // for (const string& word : words) {
    //     if (word.find(' ') != string::npos) {
    //         cout << "Error: Invalid input format." << endl;
    //         return false;
    //     }
    // }

    return true;
}
bool validateInput1(const string& inputLine) {
    if (inputLine.empty()) {
        
        return false;
    }

    // Check for multiple equal signs
    size_t equalCount = count(inputLine.begin(), inputLine.end(), '=');
    if (equalCount != 1) {
        
        return false;
    }

    // Check for consecutive operators or misplaced operators
    for (size_t i = 0; i < inputLine.length(); ++i) {
        if (inputLine[i] == '+' || inputLine[i] == '=') {
            // Check for consecutive operators
            if (i > 0 && (inputLine[i - 1] == '+' || inputLine[i - 1] == '=')) {
                
                return false;
            }
            // Check for operator at the start or end
            if (i == 0 || i == inputLine.length() - 1) {
                
                return false;
            }
        }
    }

    // Check for spaces without operators in between
    stringstream ss(inputLine);
    string segment;
    int count = 0;
    while (getline(ss, segment, '=')) {
        
        
        // Check segments around `=`
        stringstream ss2(segment);
        if (count != 0) {
            
            if ( segment.find("+") < segment.size() ) {
                
                return false; 
            }
            
            
            // Check for spaces within segments without '+' or '='
            for (int i = 0; i < segment.size(); i++) { 
                int found = segment.find(" ",i);
                
                if (found > segment.size() ||found == 0 || found == segment.size()-1) { 
                    continue; 
                }
                else {
                    
                    return false;
            }
            }
        }

        
        
        while (getline(ss2, segment, '+')) {
            // Check for empty segments
            string segment1 = segment;
            count = 1 ;  
            segment1.erase(remove_if(segment1.begin(), segment1.end(), ::isspace), segment1.end());
            if (segment1.empty()) {
                
                return false;
            }

            // Check for spaces within segments without '+' or '='
            for (int i = 0; i < segment.size(); i++) { 
                int found = segment.find(" ",i);
                if (found > segment.size() || found == 0 || found == segment.size()-1) { 
                    continue; 
                }
                else {
                    
                    return false;
            }
            }
        }
    }

    return true;
}

int main() {
    string inputLine;
    getline(cin, inputLine);
    if (!validateInput1(inputLine)) {
        cout << "Error: Invalid input format. " << endl;
        return 0;
    }

    // Remove spaces from inputLine
    inputLine.erase(remove_if(inputLine.begin(), inputLine.end(), ::isspace), inputLine.end());

    // Find positions of '='
    size_t posEqual = inputLine.find('=');

    if (posEqual == string::npos) {
        cout << "Error: Invalid input format. " << endl;
        return 0;
    }

    // Extract words and result word
    string equation = inputLine.substr(0, posEqual);
    string resultWord = inputLine.substr(posEqual + 1);
     
    // Split equation by '+'
    stringstream ss(equation);
    vector<string> words;
    string word;
    while (getline(ss, word, '+')) {
        words.push_back(word);
    }
    // for ( int i=0 ; i< words.size(); i++){
    //     cout<< words[i] << endl; 
    // }

    if (!validateInput(words, resultWord)) {
        
        return 1;
    }
    unordered_map<char, int> letterToDigit;
    unordered_set<int> usedDigits;
    vector<char> letters;

    for (const string& word : words) {
        for (char ch : word) {
            if (letterToDigit.count(ch) == 0) {
                letterToDigit[ch] = -1;
                letters.push_back(ch);
            }
        }
    }
    for (char ch : resultWord) {
        if (letterToDigit.count(ch) == 0) {
            letterToDigit[ch] = -1;
            letters.push_back(ch);
        }
    }

    if (solveCryptarithmetic(words, resultWord, letters, letterToDigit, usedDigits)) {
        cout << "Solution Found!" << endl;
        // for (const auto& entry : letterToDigit) {
        //     cout << entry.first << " = " << entry.second << endl;
        // }
    } else {
        cout << "Error: No solution exists for the given puzzle." << endl;
    }

    return 0;
}
