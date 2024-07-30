#include<iostream>
#include<string>
#include<vector>

using namespace std;

class StringCalculator {
public:
    int Add(string numbers) {
        if (numbers == "") return 0;
        vector<int> Numbers;
        string cur = "";
        try {
            for (int i = 0; i < numbers.size(); i++) {
                if (numbers[i] == ',') { 
                    if (cur != "") {
                        int curint = stoi(cur);
                        Numbers.push_back(curint);
                        cur = "";
                    }
                    continue;
                }
                if (numbers[i] >= '0' && numbers[i] <= '9') 
                    cur += numbers[i];
                else {
                    string error = "Invalid Input!";
                    throw error;
                }
            }
            if (cur != "") {
                int curint = stoi(cur);
                Numbers.push_back(curint);
            }
        } catch (string err) {
            cout << err << "\n";
            return -1;
        }
        int ans = 0;
        for (int i = 0; i < Numbers.size(); ++i)
            ans += Numbers[i];
        return ans;
    }
};

int main() {
    StringCalculator calculator;
    string input;

    while (cin >> input) {
        if (input == "quit") break;
        int ans = calculator.Add(input);
        cout << "ans: " << ans << "\n";
    }
}