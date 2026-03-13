#include <iostream>
#include <unordered_map>

using namespace std;

class CurrencyConverter {

private:
    unordered_map<string,double> rates = {
        {"USD",1.0},
        {"INR",83.0},
        {"EUR",0.92},
        {"GBP",0.79}
    };

public:

    double convert(string from, string to, double amount){

        if(rates.find(from)==rates.end() || rates.find(to)==rates.end())
            throw invalid_argument("Unsupported currency");

        double usd = amount / rates[from];
        return usd * rates[to];
    }
};

int main(){

    CurrencyConverter converter;

    string from,to;
    double amount;

    cout << "From currency: ";
    cin >> from;

    cout << "To currency: ";
    cin >> to;

    cout << "Amount: ";
    cin >> amount;

    try{
        double result = converter.convert(from,to,amount);
        cout << "Converted amount: " << result << endl;
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
}