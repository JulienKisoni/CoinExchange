#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    map<string, double> bankNotes = {
        {"100$", 100.00},
        {"50$", 50.00},
        {"25$", 25.00},
        {"10$", 10.00},
        {"5$", 5.00},
    };
    map<string, double> coins = {
        {"2$", 2.00},
        {"1$", 1.00},
        {"25c", 0.25},
        {"10c", 0.10},
        {"5c", 0.05},
    };
    
    bool bankNoteDone = false;
    string* bankNote;
    bool coinDone = false;
    string* coin;
    
    do {
        cout << "Enter a banknote value (i.e. 100$, 50$, 20$, 10$ or 5$)" << endl;
        string inputBankNote;
        cin >> inputBankNote;
        
        if (bankNotes.find(inputBankNote) == bankNotes.end()) {
            cout << "Invalid banknote value !" << endl;
        } else {
            bankNoteDone = true;
            bankNote = &inputBankNote;
        }
    } while (!bankNoteDone);
    
    do {
        cout << "Enter a coin value (i.e. 2$, 10$, 25c, 10c or 5c)" << endl;
        string inputCoin;
        cin >> inputCoin;
        
        if (coins.find(inputCoin) == coins.end()) {
            cout << "Invalid coin value !" << endl;
        } else {
            coinDone = true;
            coin = &inputCoin;
        }
    } while (!coinDone);
    
    double bankNoteValue = bankNotes[*bankNote];
    double coinValue = coins[*coin];
    
    int numberOfCoins = static_cast<int>(bankNoteValue / coinValue);
    
    cout << "You will need " << numberOfCoins << " coins of " << *coin << " to exchange for " << *bankNote << endl;
    
    return 0;
}
