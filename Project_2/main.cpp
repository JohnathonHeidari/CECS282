#include <iostream>

using namespace std;
void creditCard(int, double);

int main()
{
    creditCard(5367, 0); // new account - zero balance
    creditCard(1198, -34.98); // dinner purchase
    creditCard(1198, -20.00); // went to see a movie.
    creditCard(1198, 15.89); // made the monthly minimum payment
    creditCard(7265, -1267.45); // bought a new laptop
    creditCard(7265, 1000.00); // made a paymnet
    creditCard(1959, -7956.34); // bought a new motorcycle
    cout << "Show all accounts and balances:\n";
    cout << "-------------------------------\n";
    creditCard(0,0); // print out everybody’s balance
    getchar();
}

#include <map>
void creditCard(int n, double b){
    static map<int,double> creditcard;
    if(creditcard.count(n)){
        creditcard[n] = creditcard.at(n) + b;
    } else if (n == 0 && b == 0.0){
        map<int, double>::iterator itr;
        for(itr = creditcard.begin(); itr != creditcard.end(); itr++) {
            cout << itr->first << ":$" << itr->second << endl;
        }
    }
    else{
        creditcard[n] = b;
    }
}