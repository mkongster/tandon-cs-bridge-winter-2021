/*
Ming Kong
Tandon Bridge Winter 2021
Homework 12
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Money {
    public:
        friend Money operator +(const Money& lhs, const Money& rhs);
        
        friend Money operator -(const Money& lhs, const Money& rhs);
        
        friend ostream& operator <<(ostream& os, const Money& money);

        Money(double money);

        Money();

        double getAmount() const;

    private:
        double amount;
};

class Check {
    public:
        Check(int check_num, double amount, bool cashed);

        int getCheckNum() const;

        bool getCashed() const;

        Money getMoney() const;

        void display();

        friend ostream& operator <<(ostream& ons, const Check& check);

    private:
        int check_num;
        double amount;
        bool cashed;
        Money money;

};

void readBalances(Money& old_balance, Money& new_balance);

void readDeposits(vector<Money>& deposits);

Money checksCashed(vector<Check>& checks);

void readChecks(vector<Check>& checks);

Money totalDeposits(vector<Money>& deposits);

bool checkCompare(const Check& lhs, const Check& rhs);

void displayCashedChecks(vector<Check>& checks);

void displayNonCashedChecks(vector<Check>& checks);



int main() {
    cout << "Old School Checkbook" << endl;
    Money old_balance, new_balance;
    vector<Money> deposits;
    vector<Check> checks;

    readBalances(old_balance, new_balance);
    readDeposits(deposits);
    readChecks(checks);
    Money cash_depo = totalDeposits(deposits);
    Money cash_check = checksCashed(checks);
    cout << endl;
    cout << "Your new balance: " << cash_depo + cash_check << endl;
    cout << "Difference from your current bank balance" << (cash_depo + cash_check) - new_balance << endl;
    cout << endl;
    sort(checks.begin(), checks.end(), checkCompare);
    cout << endl;
    displayCashedChecks(checks);
    cout << endl;
    displayNonCashedChecks(checks);

    return 0;
}


Money::Money(double money) : amount(money) {

}

Money::Money() {
    amount = 0;
}

Money operator +(const Money& lhs, const Money& rhs) {
    double amount = lhs.getAmount() + rhs.getAmount();
    return Money(amount);
}

Money operator -(const Money& lhs, const Money& rhs) {
    double amount = lhs.getAmount() - rhs.getAmount();
    return Money(amount);
}

ostream& operator <<(ostream& ons, const Money& money) {
    ons << "$" << money.getAmount();
    return ons;
}

double Money::getAmount() const {
    return amount;
}

Check::Check(int check, double amt, bool cash) : check_num(check), amount(amt), cashed(cash) {
    money = Money(amt);
}

int Check::getCheckNum() const {
    return check_num;
}

bool Check::getCashed() const {
    return cashed;
}

Money Check::getMoney() const {
    return money;
}

ostream& operator <<(ostream& os, const Check& check) {
    string c;
    if (check.getCashed()) {
        c = "CASHED";
    } else {
        c = "NOT CASHED";
    }

    os << check.getCheckNum() << "\t";
    os << check.getMoney(); 
    os << "\t" << c;
    return os;
}

void readBalances(Money& old_balance, Money& new_balance) {
    double old_bal, new_bal;
    cout << "Please enter your old balance: $";
    cin >> old_bal;
    cout << "Please enter your new balance: $";
    cin >> new_bal;
    old_balance = Money(old_bal);
    new_balance = Money(new_bal);

    
}

void readDeposits(vector<Money>& deposits) {
    double num;
    cout << "Please enter your deposit amounts, use -1 to finish depositing: ";
    cin >> num;
    while(num != -1) {
        deposits.push_back(num);
        cin >> num;
    }
}

Money checksCashed(vector<Check>& checks) {
    Money amount = 0;
    for (int i = 0; i < checks.size(); i++) {
        if (checks[i].getCashed()) {
            amount = amount + checks[i].getMoney().getAmount();
        }
    }
    cout << "Total value of checks cashed: " << amount << endl;
    return amount;
}

void readChecks(vector<Check>& checks) {
    cout << "Please enter your checks in the following format:" << endl;
    cout << "(Check Number, Amount, Cashed(Y/N, y/n))." << endl;
    cout << "Enter -1 when done entering checks." << endl;
    cin.ignore();
    string line;
    getline(cin, line);

    while (line != "-1") {
        int index = 0;

        int check_num = stoi(line.substr(0, line.find(' ')));
        index = line.find(' ', index + 1);
        double amount = stod(line.substr(index + 1, line.find(' ', index + 1) - index));
        char c = line.back();
        bool cashed = false;
        if (c == 'Y' || c == 'y') {
            cashed = true;
        } 

        Check temp = Check(check_num, amount, cashed);
        checks.push_back(temp);
        getline(cin, line);
    }
    
}

Money totalDeposits(vector<Money>& deposits) {
    Money amount = Money();
    for (int i = 0; i < deposits.size(); i++) {
        amount = amount + deposits[i].getAmount();
    }
    cout << "Total amount of deposits: " << amount << endl;
    return amount;
}

bool checkCompare(const Check& lhs, const Check& rhs) {
    return lhs.getCheckNum() < rhs.getCheckNum();
}

void displayCashedChecks(vector<Check>& checks) {
    cout << "List of cashed checks:" << endl;
    cout << "Check ID\t" << "Amount\t" << "Status" << endl;
    for (int i = 0; i < checks.size(); i++) {
        if (checks[i].getCashed()) {
            cout << checks[i] << endl;
        }
    }
}

void displayNonCashedChecks(vector<Check>& checks) {
    cout << "List of non cashed checks:" << endl;
    cout << "Check ID\t" << "Amount\t" << "Status" << endl;
    for (int i = 0; i < checks.size(); i++) {
        if (!checks[i].getCashed()) {
            cout << checks[i] << endl;
        }
    }
}