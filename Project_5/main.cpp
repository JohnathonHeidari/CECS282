#include <iostream>
#include <vector>
#include <map>
using namespace std;
// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 5 - goldRabbits: BigInt using vectors and maps)
// Due Date: (06/7/20)

//  BigInt needs to handle addition and subtraction,
//  constructor, copy constructor, assignment operator,
//  destructor, and other functions as n

class BigInt {
private:
    std::vector<char> v;
public:
    // constructors
    BigInt();
    BigInt(int);
    BigInt(string);
    ~BigInt();
    // copy constructor
    BigInt( const BigInt& );

    // assignment operator
    BigInt operator=( BigInt);
    bool operator==(int);
    //  BigInt needs to handle addition and subtraction,
    BigInt operator+(BigInt);
    BigInt operator++(int);
    bool operator <= (int);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);   // thank you (code reference: https://en.cppreference.com/w/cpp/language/operators)
    BigInt operator-(int);
    friend ostream & operator<<(ostream &, BigInt );

    // other method
    void print();
    string getNumber();



};
//int goldRabbits(int);
BigInt goldRabbits(BigInt);
void pause() {cout << "Press Enter to continue..."; getchar();}
int main() {
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(INT_MAX);
    cout << "B1:"<<B1<<"\nB2:"<<B2<<"\nMAX:"<<MAX<<endl;
    pause();
    cout << "\nB1:";
    B1.print();
    cout << endl;
    pause();

	for(BigInt i=0; i<=3000; i++)	// uncomment this
//    for(int i=0; i<=3000; i++)		// comment this out
    {
        cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
    }
	cout<<endl;
    pause();

    cout<< "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 =  goldRabbits(BigInt(3000));
    gR3000.print();

    pause();
}
BigInt goldRabbits(BigInt n) {
    static map<BigInt, BigInt> lookup;
    if (n == 0 || n == 1) {
        return BigInt(1);
    } else if (lookup.count(n)){
        return lookup.at(n);
    }
    else{
        lookup[n] = (goldRabbits(n - 1) + goldRabbits(n - 2));
        return lookup[n];
    }
}
BigInt::BigInt(int n) {
    while(n > 9){
        int digit = n%10;
        v.push_back(digit + '0');
        n = n/10;
    }
    v.push_back((n + '0'));
}

BigInt::BigInt(string n) {
    int temp;
    for(int i = n.size() - 1; n.size() > i; i--) {
        temp = (char) n[i];
        v.push_back(temp);
    }

}
BigInt::BigInt() {
    v.push_back('0');
}

BigInt::~BigInt() {
   v.clear();
}

BigInt::BigInt( BigInt const &otherBigInt) {
    v = otherBigInt.v;
}
// print out the whole vector, regardless if it capable of scientific notation
void BigInt::print() {
    string result;
    vector<char>::reverse_iterator rit;
    for(rit = v.rbegin(); rit != v.rend(); rit++)
        cout<< (char)*rit;
    cout<<endl;
}

ostream &operator<<(ostream & output, BigInt bigInt) {
    vector<char>::reverse_iterator rit;
    // scientific notation
    if(bigInt.v.size() > 12){
        int count = 0;
        for (rit = bigInt.v.rbegin(); rit != bigInt.v.rend(); rit++){
            if(count < 10){
                if(count == 0){
                    output << (char) *rit<<".";
                }
                else{
                    output << (char) *rit;
                }
            }
            count++;
        }
        output<<"e"<<bigInt.v.size();
    }
    // general
    else {
        for (rit = bigInt.v.rbegin(); rit != bigInt.v.rend(); rit++)
            output << (char) *rit;
    }
    return output;
}

BigInt BigInt::operator=(BigInt otherBigInt) {
    v = otherBigInt.v;
    return BigInt(*this);
}

bool operator<(const BigInt &lhs, const BigInt &rhs) {
    if(lhs.v.size() == rhs.v.size()){
        for(int i = 0; rhs.v.size() > i; i++){
            if(lhs.v[i] < rhs.v[i]){
                return true;
            }
        }
        return false;
    }
    else{
        return true;
    }
}

bool BigInt::operator<=( int n ) {
    // false ends
    BigInt right(n);
    if(v.size() == right.v.size()){
        for(int i = 0; right.v.size() > i; i++) {
            if(v[i] < right.v[i]){
                return true;
            }
        }
        return v == right.v;
    }
    else{
        return true;
    }
}

bool BigInt::operator==(int n) {
    BigInt right(n);
    if(v.size() == right.v.size()){
        for(int i = 0; right.v.size() > i; i++) {
            if(v[i] != right.v[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

BigInt BigInt::operator++(int n){
    n = 1;
    BigInt result,right((char(n)));
    char carry ='0';
    for (int i = 0; v.size() > i; i++) {
        result.v.push_back('0');
        right.v.push_back('0');
    }
    for (int i=0; i<v.size();i++)
    {
        int temp = (int)(v[i] - '0') + (int)(right.v[i] - '0') + int(carry - '0');
        if(temp >= 10){
            carry = '1';
            temp -= 10;
            v[i] =  char(temp + '0');
        }
        else if (temp < 10)
        {
            v[i] = char(temp + '0');
            carry = '0';
        }
    }
    if (carry == '1')
        v.push_back('1');
    return result;
}

BigInt BigInt::operator+(BigInt otherBigInt) {
    int difference = 0, big1size = v.size(), big2size = otherBigInt.v.size();
    char carry ='0';
    BigInt result,right(otherBigInt), left(*this);
    // left is bigger than right
    if (big1size > big2size) {
        for (int i = 1; big1size > i; i++) {
            result.v.push_back('0');
        }

        difference = big1size - big2size;
        for (int i = 0; difference > i; i++) {
            right.v.push_back('0');
        }
    }

    // right bigger than left
    else if (big1size < big2size || big1size == big2size) {
        for (int i = 1; big2size > i; i++) {
            result.v.push_back('0');
        }

        difference = big2size - big1size;
        for (int i = 0; difference > i; i++) {
            left.v.push_back('0');
        }
    }
    int largest = ( v.size() > otherBigInt.v.size()) ? v.size() :  otherBigInt.v.size();
    for (int i=0; i<largest;i++)
    {
        int temp = (int)(left.v[i] - '0') + (int)(right.v[i] - '0') + int(carry - '0');
        if(temp >= 10){
            carry = '1';
            temp -= 10;
            result.v[i] =  char(temp + '0');
        }
        else if (temp < 10)
        {
            result.v[i] = char(temp + '0');
            carry = '0';
        }
    }
    if (carry == '1')
        result.v.push_back('1');
    return result;
}

BigInt BigInt::operator-( int n ) {
    // 5(left) - 2(right)
    BigInt result,right(n), left(*this);
    int difference = 0, big1size = v.size(), big2size = right.v.size();
    // left is bigger than right
    if (big1size > big2size) {
        for (int i = 1; big1size > i; i++) {
            result.v.push_back('0');
        }

        difference = big1size - big2size;
        for (int i = 0; difference > i; i++) {
            right.v.push_back('0');
        }
    }
        // other bigger than the original or equal.
    else if (big1size < big2size) {
        for (int i = 1; big2size > i; i++) {
            result.v.push_back('0');
        }

        difference = big2size - big1size;
        for (int i = 0; difference > i; i++) {
            left.v.push_back('0');
        }
    }
    else{
        for (int i = 1; big2size > i; i++) {
            result.v.push_back('0');
        }
    }
    int largest = ( v.size() > right.v.size()) ? v.size() :  right.v.size();
    for (int i=0; i<largest;i++) {
        int val = 0;
        if (left.v[i] >= right.v[i]) {
            char temp = left.v[i] - right.v[i];
            result.v[i] = temp + '0';
        }
        else{
            if (left.v.at(i + 1) != 0 && left.v.size() != 1) {
                left.v.at(i + 1) = left.v.at(i + 1) - 1;
                val = int(left.v[i] - '0') + 10;
                result.v[i] = (val - int(right.v[i] - '0')) + '0';
                left.v.at(i) += 9;
            }
        }
    }

    for(int rit = result.v.size() - 1; rit != 0; rit--) {
        if (result.v.size() == 1) {
            break;
        } else if (result.v[rit] == '0') {
            result.v.erase(result.v.begin() + rit);
        } else {
            break;
        }
    }
    return result;
}

