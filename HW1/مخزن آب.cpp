#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int most_volume(vector<int> height){
    int volume = 0 ;
    for (int i=0; i < height.size(); i++){
        for (int j=0; j < height.size(); j++){
            int new_volume = (j-i)*min(height[i], height[j]);
            volume = max(new_volume , volume);
        }
    }
    return volume;
}

int main() {
    string input;
    vector<int> numbers;

    
    getline(cin, input);

    istringstream iss(input);
    int num;
    while (iss >> num) {
        if (num < 0) {
            cout << "Error" << endl;
            return 1; 
        }
        numbers.push_back(num);
    }

   
    
    cout << most_volume(numbers)<<endl;

    return 0;
}
