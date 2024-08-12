#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;


int calculateWordValue(const string& word) {
    int value = 0;
    for (size_t i = 0; i < word.length(); ++i) {
        char letter = toupper(word[i]); // convert to uppercase
        int letterValue = letter - 'A' + 1; // calculate letter value
        value += letterValue * (i + 1); // add to total value
    }
    return value;
}
bool replace(string word) {
    string reversedWord = word;
    reverse(word.begin(), word.end());
    if(calculateWordValue(word)>calculateWordValue(reversedWord)){
        return true; // 
    }
    return false; // 
}

int main(){
    int n; 
    cin >> n;
    vector<string> word(n);

    for(int i = 0; i < n ; ++i){
        cin >> word[i];
    }

    string txt;
    cin.ignore();
    getline(cin,txt);
    
    for(int i = 0; i < n ; i++){
        if(replace(word[i])){
            size_t found = txt.find(word[i]);
            if (found != string::npos) {
                string reversedWord = word[i];
                reverse(word[i].begin(), word[i].end()); 
                txt.replace(found, word[i].length(), word[i]);
                
           
        
            
            }
        }
    }
    cout << txt << endl;
    return 0;
}