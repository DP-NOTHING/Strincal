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
            return 5;
        }
        return 0;
    }
    vector<int>checkNegative(string numbers){
        string cur = "";
        vector<int> negNums;
        bool isNegative = false;
        int start = checkDelimiter(numbers);
        for(int i=start;i<numbers.size();++i){
            if(isDelimiter(numbers[i])){
                if(cur == ""){
                    string error = "------> Invalid Input";
                    throw error;
                }
                int cu = stoi(cur);
                if(isNegative) negNums.push_back(-cu);
                cur = "";
                isNegative = false;
                continue;
            }
            if(numbers[i] == '-'){
                if(i == start) 
                    isNegative = true;
                if((i-1)>=0 && isDelimiter(numbers[i-1])){
                    isNegative = true;
                }
                else{
                    string error = "------> Invalid Input";
                    throw error;
                }
                continue;
            }
            cur += numbers[i];
        }
        if(cur!=""){
            int cu = stoi(cur);
            if(isNegative) 
                negNums.push_back(-cu);
        }
        return negNums;
    }

public:
    int Add(string numbers)
    {
        if(numbers == "") return 0;
        vector<int> Numbers;
        string cur = "";
        try{
            vector<int>neg=checkNegative(numbers);
            if(neg.size()!=0){
                string error = "----> error: Negative Nums : ";
                for(int i=0;i<neg.size();++i){
                    error += to_string(neg[i]);
                    error += " ";
                }
                throw error;
            }
            int start = checkDelimiter(numbers);
            for(int i=start;i<numbers.size();i++){
                if(isDelimiter(numbers[i])){
                    if(cur == ""){
                        string error = "------> Invalid Input";
                        throw error;
                    }
                    int cu = stoi(cur);
                    Numbers.push_back(cu);
                    cur = "";
                    continue;
                }
                if(numbers[i] >= '0' && numbers[i] <= '9') 
                    cur += numbers[i];
                else{
                    string error = "------> Invalid Input";
                    throw error;
                }
            }
            if(cur != ""){
                int cu = stoi(cur);
                Numbers.push_back(cu);
                cur = "";
            }
        
        }
        catch(string err){
            cout<<err<<endl;
            return -1;
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
    char ch;

    while (true) {
        ch = cin.get();
        if (ch == 'e') { 
            if(input.back()=='\n'){
                input.pop_back();
            }
            int ans = calculator.Add(input);
            cout << "ans: " << ans << endl;
            input="";
            cin >> ws;
            continue;
        }
        if(ch=='q')return 0;
        input+=ch;
    }
    
}