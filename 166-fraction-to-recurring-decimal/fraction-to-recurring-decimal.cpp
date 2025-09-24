class Solution {
public:
    string fractionToDecimal(int pay, int payda) {
        
       if(pay == 0) return "0";

    string res;

    if ((pay < 0) ^ (payda < 0)) res += "-";

    long long n = abs((long long)pay);
    long long d = abs((long long)payda);

    res += to_string(n / d);
    long long rem = n % d;
    if(rem == 0) return res;

    res += ".";

    vector<long long> kalan;          
    unordered_map<long long, int> pos; 

    while(rem != 0) {
        if(pos.count(rem)) {
           
            res.insert(pos[rem], "(");
            res += ")";
            break;
        }

        pos[rem] = res.size(); 
        rem *= 10;
        res += to_string(rem / d);
        rem %= d;
    }

    return res;
    }
};