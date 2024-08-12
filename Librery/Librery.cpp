#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <memory>
#include <typeinfo>

using namespace std;

class Book {
    
public:    
    string Name ;
    string Author; 
    int Amount ; 
    
    Book(string name , string author, int amount){ 
        if(amount == -1){
            cout << "ERROR! invalid price"<<endl; 
            return;
        }
        
        Name = name; 
        Amount = amount;
        Author = author; 
    };
    
   

}; 
class Journal{
public:    
    string Name ;
    string ISSN; 
    int Amount ; 

    Journal(string name , string issn, int amount){ 
        if(amount == -1){
            cout << "ERROR! invalid price"<<endl; 
            return;
        }

       
        
        Name = name; 
        Amount = amount;
        ISSN = issn; 
    };

};
class Newspaper{
public:
    string Name ;
    string Author; 
    int Amount ; 

    Newspaper(string name , string author, int amount){ 
        if(amount == -1){
            cout << "ERROR! invalid price"<<endl; 
            return;
        }
        
        Name = name; 
        Amount = amount;
        Author = author; 
    };

};


class Library {
public:
    int AccountBalance ; 
    vector<Book> BookList ;

    

    bool SellBook(string name , string author){
        for (int i = 0; i < BookList.size();i++){
            if (BookList[i].Name == name || BookList[i].Author == author){
                this->AccountBalance += BookList[i].Amount ;
                BookList.erase(BookList.begin() + i);
                
                cout <<"SUCCESS! "<< name << " by " <<author << " sold" << endl ; 
                return 1;
            }     
        }
        
        return 0 ; 
    }

    void DepositMoney(int amount){
        this->AccountBalance += amount; 
        cout << "SUCCESS! deposited "<< amount <<" into the account" << endl; 
        
    }

    void DisplayAccountBalance(){
        cout << "Account Balance: " << AccountBalance << endl ; 
        return ;  
    }

    
};

class UniversityLibrary : public Library { 
public:

    vector<Journal> JournalList;  
    void AddBook(Book book) {
        
        this->AccountBalance -= book.Amount ; 
        if (AccountBalance < 0){
            cout << "ERROR! insufficient balance" << endl;  
            this->AccountBalance += book.Amount ; 
            return;  
        }
        BookList.push_back(book); 
        cout << "SUCCESS! "<<  book.Name << " by " << book.Author<< " added to the university library"<< endl;
        
        
        
    }

    void AddJournal(Journal journal){
        if (journal.ISSN.length() != 8){
            cout << "ERROR! invalid ISSN" << endl; 
            return;  
        }

        this->AccountBalance -= journal.Amount ; 
        if (AccountBalance < 0){
            cout << "ERROR! insufficient balance" << endl;  
            this->AccountBalance += journal.Amount ; 
            return;  
        }
        JournalList.push_back(journal); 
        cout << "SUCCESS! "<<  journal.Name << ", " << journal.ISSN << " added to the university library"<< endl;
    }

    bool SellJournal(string JournalName , string ISSN ,vector<Journal>& JournalList){
        
        for (int i = 0; i < JournalList.size();i++){
            if (JournalList[i].Name == JournalName && JournalList[i].ISSN == ISSN){
                this->AccountBalance += JournalList[i].Amount ;
                JournalList.erase(JournalList.begin() + i);
                
                cout <<"SUCCESS! "<< JournalName << ", " <<ISSN << " sold" << endl ; 
                return true ;
            }    
             
        }
        return false ; 
        
    }

    void DisplayBooks() {
        if (BookList.size() == 0 || JournalList.size() == 0){
            cout << "ERROR! no items available in storage " << endl ; 
            return ; 
        }
    

   
    const int titleWidth = 30;
    const int TypeWidth = 20 ; 
    const int authorWidth = 30;
    const int priceWidth = 20;

    
    cout << right << setw(titleWidth) << "Title"
         << setw(TypeWidth) << "Type"
         << setw(authorWidth) << "Author/ISSN" 
         << setw(priceWidth) << "Price" 
         << left << endl;

    cout << setfill('-') << setw(titleWidth + TypeWidth + authorWidth + priceWidth) << "" << setfill(' ') << endl;

    for (int i = 0; i < BookList.size(); i++) {
        cout << right << setw(titleWidth) << BookList[i].Name
             << setw(TypeWidth) << "Book"  
             << setw(authorWidth) << BookList[i].Author
             << setw(priceWidth) << fixed << setprecision(2) << BookList[i].Amount
             << left <<endl;
        }
    for (int i = 0; i < JournalList.size(); i++){
        cout << right << setw(titleWidth) << JournalList[i].Name
             << setw(TypeWidth) << "Journal"   
             << setw(authorWidth) << JournalList[i].ISSN
             << setw(priceWidth) << fixed << setprecision(2) << JournalList[i].Amount
             << left <<endl;
        }
    };
   

};

class PublicLibrary: public Library{
public:

    vector<Newspaper> newspaperList; 
    void AddBook(Book book) {
        
        this->AccountBalance -= book.Amount ; 
        if (AccountBalance < 0){
            cout << "ERROR! insufficient balance" << endl;  
            this->AccountBalance += book.Amount ; 
            return;  
        }
        BookList.push_back(book); 
        cout << "SUCCESS! "<<  book.Name << " by " << book.Author<< " added to the public library"<< endl;
        
        
        
    }  

    void Addnewspaper(Newspaper newspaper){
        

        AccountBalance -= newspaper.Amount ; 
        if (AccountBalance < 0){
            cout << "ERROR! insufficient balance" << endl;  
            AccountBalance += newspaper.Amount ; 
            return;  
        }
        newspaperList.push_back(newspaper); 
        cout << "SUCCESS! "<<  newspaper.Name << " by " << newspaper.Author << " added to the public library"<< endl;
    }

    bool SellNewspaper(string name, string author, vector<Newspaper>& newspaperList) {
    for (int i = 0; i < newspaperList.size(); i++) {
        if (newspaperList[i].Name == name && newspaperList[i].Author == author) {
            this->AccountBalance += newspaperList[i].Amount;
            newspaperList.erase(newspaperList.begin() + i);

            cout << "SUCCESS! " << name << " by " << author << " sold" << endl;
            return true;
        }
    }

    return false;
}


    void DisplayBooks() {
        if (BookList.size() == 0 && newspaperList.size() == 0){
            cout << "ERROR! no items available in storage" << endl ; 
            return ;
        }
    

   
    const int titleWidth = 30;
    const int TypeWidth = 20 ; 
    const int authorWidth = 30;
    const int priceWidth = 20;

    
    cout << right << setw(titleWidth) << "Title"
         << setw(TypeWidth) << "Type"
         << setw(authorWidth) << "Author/Publisher" 
         << setw(priceWidth) << "Price" 
         << left << endl;

    cout << setfill('-') << setw(titleWidth + TypeWidth + authorWidth + priceWidth) << "" << setfill(' ') << endl;

    for (int i = 0; i < BookList.size(); i++) {
        cout << right << setw(titleWidth) << BookList[i].Name
             << setw(TypeWidth) << "Book"  
             << setw(authorWidth) << BookList[i].Author
             << setw(priceWidth) << fixed << setprecision(2) << BookList[i].Amount
             << left <<endl;
        }
    for (int i = 0; i < newspaperList.size(); i++){
        cout << right << setw(titleWidth) << newspaperList[i].Name
             << setw(TypeWidth) << "Newspaper"   
             << setw(authorWidth) << newspaperList[i].Author
             << setw(priceWidth) << fixed << setprecision(2) << newspaperList[i].Amount
             << left <<endl;
        }
    };
   



};
int stringToInt(const string& str) {
    
    try {  
        int num = stoi(str);
        return num; 
    }catch (const invalid_argument& e) {
       
        return -1;
    }

    
    
} ;



int main(){
    UniversityLibrary newUniversityLibrary; 
    PublicLibrary newPublicLibrary;
    int balance1;
    int balance2;

    // getline(cin, balance1);
    // getline(cin, balance2);
    cin >> balance1;
    cin >> balance2;

    newPublicLibrary.AccountBalance = balance2;
    newUniversityLibrary.AccountBalance = balance1;

    int n ; 
    cin >> n ; 
    

    cin.ignore();
    for ( int i = 0; i < n ; ++i ) { 
        string name;
        string author;
        string amount ;
        
        // cin.ignore(); 
        getline(cin,name);
         
        getline(cin,author);
        
        getline(cin,amount); 
        

        Book book(name , author , stringToInt(amount));
        
        
        newPublicLibrary.BookList.push_back(book);
        newUniversityLibrary.BookList.push_back(book);
        
    }

    int m ; 
    cin >> m ;  
    cin.ignore();
    for ( int i = 0; i < m ;i++ ) { 
        string name , issn ;
        string amount ;

         
        getline(cin,name);
         
        getline(cin,issn);
        
        getline(cin,amount);

        

        Journal journal(name, issn , stringToInt(amount));
        newUniversityLibrary.JournalList.push_back(journal); 
    }
    
    int f ;  
    cin >> f ; 
    cin.ignore(); 
    for (int i = 0; i < f ;i++){
        string name , author;
        string amount ;
        
        getline(cin,name);
         
        getline(cin,author);
        
        getline(cin,amount);

        Newspaper newspaper(name, author, stringToInt(amount)); 
        newPublicLibrary.newspaperList.push_back(newspaper); 
 
    }
 

 
      
    
    while (true){
        
        int menu ; 
        cin >> menu ;
    
        
        
        
        if (menu ==3){
            break;
        }

        if (menu == 1){
            
            while (true){
                
                int a ;
                cin >> a ; 
                    
                
                
                if (a ==1){
                    string name , author;
                    string amount ;

                    cin.ignore(); 
                    getline(cin,name);
                    getline(cin,author);
                    getline(cin,amount);
                    if(name.empty() || author.empty() || amount.empty()){
                        cout << "ERROR! missing information" << endl;
                        break;
                    }
                    int Amount = stringToInt(amount) ; 

                    if(Amount == -1){
                        cout << "ERROR! invalid price"<<endl; 
                        break;
                    }

                    Book book(name , author , stringToInt(amount));
                    newUniversityLibrary.AddBook(book);
                }

                if(a==2){
                    string name , issn ;
                    string amount ;

                    cin.ignore(); 
                    getline(cin,name);
                    getline(cin,issn);
                    getline(cin,amount);
                    if(name.empty() || issn.empty() || amount.empty()){
                        cout << "ERROR! missing information" << endl;
                        break ;
                    }
                    int Amount = stringToInt(amount) ; 

                    if(Amount == -1){
                        cout << "ERROR! invalid price"<<endl; 
                        break;
                    }

                    Journal journal(name, issn , stringToInt(amount));
                    newUniversityLibrary.AddJournal(journal);
                }

                if (a==3){
                    string name , issn ;
                    string amount ;

                    cin.ignore(); 
                    getline(cin,name);
                    getline(cin,issn);
                    string author = issn ;
                    

                    
                        
                        if(newUniversityLibrary.SellBook(name  , author)==0 && newUniversityLibrary.SellJournal(name , author, newUniversityLibrary.JournalList)==0){
                            cout << "ERROR! item not found"<< endl;
                        };
                    
                    
                }

                if (a==4){
                    newUniversityLibrary.DisplayBooks();
                }

                if (a==5){
                    cin.ignore();
                    int amount ; 
                    cin >> amount ; 
                    newUniversityLibrary.DepositMoney(amount);
                }

                if (a==6){
                    newUniversityLibrary.DisplayAccountBalance();
                    }

                if (a==7){break;}

                if (a==8){abort();}

            }
        }
        if (menu == 2)
        {   
            while (true){
                
                int a ;
                    /* code */
                cin >> a ; 
                
                if (a==1){
                    string name , author;
                    string amount ;

                    cin.ignore(); 
                    getline(cin,name);
                    getline(cin,author);
                    getline(cin,amount);
                    if(name.empty() || author.empty() || amount.empty()){
                        cout << "ERROR! missing information" << endl;
                        break ;
                    }
                    int Amount = stringToInt(amount) ; 

                    if(Amount == -1){
                        cout << "ERROR! invalid price"<<endl; 
                        break;
                    }


                    Book book(name , author , stringToInt(amount));
                    newPublicLibrary.AddBook(book);
                }
                else if(a==2){
                    string name , author ;
                    string amount ;

                    cin.ignore(); 
                    getline(cin,name);
                    getline(cin,author);
                    getline(cin,amount);

                    if(name.empty() || author.empty() || amount.empty()){
                        cout << "ERROR! missing information" << endl;
                        break;
                    }
                    int Amount = stringToInt(amount) ; 

                    if(Amount == -1){
                        cout << "ERROR! invalid price"<<endl; 
                        break;
                    }
                    Newspaper newspaper(name, author, stringToInt(amount));
                    newPublicLibrary.Addnewspaper(newspaper);
                }
                else if(a==3){
                    string name , author ;
                    string amount ;

                    cin.ignore(); 
                    getline(cin,name);
                    getline(cin,author);
                    

                    

                    if (newPublicLibrary.SellBook(name , author)==0 && newPublicLibrary.SellNewspaper(name , author , newPublicLibrary.newspaperList)==0){
                        cout << "ERROR! item not found"<< endl;
                    }
                    
                    
                }

                else if (a==4){
                    newPublicLibrary.DisplayBooks();
                }

                else if (a==5){
                    int amount ; 
                    cin >> amount ; 
                    newPublicLibrary.DepositMoney(amount);
                }

                if (a==6){
                    newPublicLibrary.DisplayAccountBalance() ;
                    }

                
                if (a==7){break;}

                if (a==8){abort();}
            }
        }
        
        
        // newPublicLibrary.DisplayBooks();
        // newUniversityLibrary.DisplayBooks();
        


    }
    
    return 0;
}