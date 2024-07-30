#include<bits/stdc++.h>
using namespace std;

vector<char> delimiters;

class StringCalculator{
private:
    bool isDelimiter(char c){
        for(int i=0;i<delimiters.size();++i){
            if(c == delimiters[i]) 
                return true;
        }
        return false;
    }

    int checkDelimiter(string numbers){
        if(numbers.size()>=3 && numbers[0] == '/' && numbers[1] == '/'){
            delimiters.push_back(numbers[2]);
            return 6;
        }
        return 0;
    }

public:
    int Add(string numbers){
        if(numbers == "") return 0;
        vector<int> Numbers;
        string cur = "";
       
        int start = checkDelimiter(numbers);
        for(int i=start;i<numbers.size();i++){
            if(isDelimiter(numbers[i])){
                if(cur == ""){
                    string error = "------> Invalid Input";
                    throw error;
                }
                int curint = stoi(cur);
                Numbers.push_back(curint);
                cur = "";
                continue;
            }
            if(numbers[i] >= '0' && numbers[i] <= '9') 
                cur += numbers[i];
            else{
                cout << "Invalid" << endl;
                return -1;
            }
        }
        if(cur != ""){
            int curint = stoi(cur);
            Numbers.push_back(curint);
            cur = "";
        }
        
        int ans = 0;
        for(int i=0;i<Numbers.size();++i)
            ans += Numbers[i];
        return ans;
    }
};

int main()
{
    delimiters.push_back(',');
    delimiters.push_back('\n');

    StringCalculator calculator;
    string input;

    while(cin >> input){
        if(input == "quit") break;
        int ans = calculator.Add(input);
        cout << "ans: " << ans << endl;
    }
}