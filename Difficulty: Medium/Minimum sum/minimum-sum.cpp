class Solution {
  public:
    string addStrings(const string &a, const string &b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        stringstream ss;
    
        while (i >= 0 || j >= 0 || carry) {
            int digitA = i >= 0 ? a[i--] - '0' : 0;
            int digitB = j >= 0 ? b[j--] - '0' : 0;
            int sum = digitA + digitB + carry;
            ss << char((sum % 10) + '0');
            carry = sum / 10;
        }
    
        string result = ss.str();
        reverse(result.begin(), result.end());

        int k = 0;
        while (k < result.size() - 1 && result[k] == '0') k++;
        return result.substr(k);
    }
    
    string minSum(vector<int> &arr) {
        int freq[10] = {0};
        for (int digit : arr) ++freq[digit];
    
        string num1, num2;
        num1.reserve(arr.size() / 2 + 1);
        num2.reserve(arr.size() / 2 + 1);
    
        bool toggle = true;
        for (int d = 0; d <= 9; ++d) {
            while (freq[d]--) {
                if (toggle)
                    num1.push_back('0' + d);
                else
                    num2.push_back('0' + d);
                toggle = !toggle;
            }
        }
    
        return addStrings(num1, num2);
    }
};