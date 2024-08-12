#include "iostream"
#include "vector"
#include "string"

using namespace std; 


vector<int> peg_a;
vector<int> peg_b;      
vector<int> peg_c;

void print_vector(vector<int> vector ){
    cout << "[";
    for (size_t i = 0; i <vector.size(); ++i) {
        cout << vector[i];
        if (i != vector.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

}
void print_pegs(){
    cout << endl << "A :";
    print_vector(peg_a);
    cout << "B :";
    print_vector(peg_b);
    cout << "C :";
    print_vector(peg_c);
    cout<< "------------------------------------------------"  ;
}

void fill_vector(vector<int>& vector , int size ){
    for (int i = size; i > 0 ; i--) {
        vector.push_back(i);
    }
}
void move(vector<int>& from , vector<int>& to){
    to.push_back(from.back());
    from.pop_back();
    print_pegs();
    
}

void swap_vector(vector<int>& from , vector<int>& to , vector<int>& use , int num ){
    if (num == 1)
        move(from, to);
    else {
        swap_vector(from, use, to, num - 1);
        move(from, to);
        swap_vector(use, to, from, num - 1);
    } 
}

int main()
{   int number ;

    cout << "enter the number of discs" << endl;
    cin >> number; 

    fill_vector(peg_a , number); 
    swap_vector(peg_a , peg_b , peg_c , number);
    print_pegs();
    
    
    return 0 ;
}