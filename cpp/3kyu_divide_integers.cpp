//https://www.codewars.com/kata/58dea43ff98a7e2124000169/train/cpp

#include <string>
#include <utility>
#include <iostream>

using namespace std;

pair<string, string> divide_strings(const string& a, const string& b) {
    auto sub = [](string x, string y) {
        string r; int carry = 0;
        while (x.size() < y.size()) x = '0' + x;
        while (y.size() < x.size()) y = '0' + y;
        for (int i = x.size() - 1; i >= 0; --i) {
            int d = x[i] - y[i] - carry;
            if (d < 0) d += 10, carry = 1; else carry = 0;
            r.insert(r.begin(), d + '0');
        }
        r.erase(0, r.find_first_not_of('0'));
        return r.empty() ? "0" : r;
    };
    auto mul = [](string x, int d) {
        string r; int c = 0;
        for (int i = x.size() - 1; i >= 0; --i) {
            int p = (x[i] - '0') * d + c;
            r.insert(r.begin(), p % 10 + '0');
            c = p / 10;
        }
        if (c) r.insert(r.begin(), c + '0');
        return r;
    };
    string q, rem;
    for (char c : a) {
        rem += c;
        rem.erase(0, rem.find_first_not_of('0'));
        if (rem.empty()) rem = "0";
        int d = 0;
        for (int i = 9; i >= 0; --i)
            if (mul(b, i).size() < rem.size() || (mul(b, i).size() == rem.size() && mul(b, i) <= rem)) {
                d = i; break;
            }
        q += d + '0';
        if (d > 0) rem = sub(rem, mul(b, d));
    }
    q.erase(0, q.find_first_not_of('0'));
    return {q.empty() ? "0" : q, rem};
}


int main() {
    auto [q, r] = divide_strings("123456789123456789123456789", "123456789");
    cout << "Quotient: " << q << endl;
    cout << "Remainder: " << r << endl;
    return 0;
}
