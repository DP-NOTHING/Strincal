#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include<bits/stdc++.h>
using namespace std;

unordered_set<char> delimiters; 

class StringCalculator{
private:
   
    bool isDelimiter(char c){
        return delimiters.find(c) != delimiters.end();
    }

    int checkDelimiter(string numbers){
        if(numbers.size() >= 3 && numbers[0] == '/' && numbers[1] == '/'){
            int index = 2;
            while(numbers[index] != '\n'){ // newline will be end of our custom delimiter declarations
                delimiters.insert(numbers[index]);
                index++;
            }
            return index + 1; // return the position after the delimiter declaration end
        }
        return 0;
    }

    vector<int> checkNegative(string numbers){
        string cur = "";
        vector<int> negNums;
        bool isNegative = false;
        int start = checkDelimiter(numbers); 
        for(int i = start; i < numbers.size(); ++i){
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
                if(i == start || isDelimiter(numbers[i-1])){
                    isNegative = true;
                } else {
                    string error = "------> Invalid Input";
                    throw error;
                }
                continue;
            }
            cur += numbers[i];
        }
        if(cur != ""){
            int cu = stoi(cur);
            if(isNegative) negNums.push_back(-cu);
        }
        return negNums;
    }

public:
    int Add(string numbers){
        if(numbers == "") return 0;
        vector<int> Numbers;
        string cur = "";
        try{
            vector<int> neg = checkNegative(numbers); 
            if(neg.size() != 0){
                string error = "----> error: Negative Nums : ";
                for(int i = 0; i < neg.size(); ++i){
                    error += to_string(neg[i]) + " ";
                }
                throw error;
            }
            int start = checkDelimiter(numbers); 
            for(int i = start; i < numbers.size(); i++){
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
            }
        
        }
        catch(string err){
            cout << err << endl;
            return -1;
        }
        int ans = 0;
        for(int i = 0; i < Numbers.size(); ++i)
            ans += Numbers[i];
        return ans;
    }
};

TEST_CASE("StringCalculator tests", "[StringCalculator]") {
    StringCalculator calculator;

    SECTION("Handles empty string") {
        REQUIRE(calculator.Add("") == 0);
    }

    SECTION("Handles single number") {
        REQUIRE(calculator.Add("4\n") == 4);
    }

    SECTION("Handles two numbers") {
        REQUIRE(calculator.Add("1,2") == 3);
    }
}

TEST_CASE("new line tests", "[StringCalculator]") {
    StringCalculator calculator;

    SECTION("Handles empty string") {
        REQUIRE(calculator.Add("") == 0);
    }

    SECTION("Handles two number") {
        REQUIRE(calculator.Add("4\n2") == 6);
    }

    SECTION("Handles multiple numbers") {
        REQUIRE(calculator.Add("1,2\n3,1\n1") == 8);
    }
    SECTION("Handles multiple numbers with different delimiter") {
        REQUIRE(calculator.Add("//:\n1:2\n3,1\n1") == 8);
    }
    SECTION("Handles multiple delimiter") {
        REQUIRE(calculator.Add("//:;\n1;2:3,4\n1\n1:2:1") == 15);
    }
    
}

int main(){
    delimiters.insert(','); 
    delimiters.insert('\n'); 
    int result = Catch::Session().run();

    if(result == 0){
        StringCalculator calculator;
        string input;
        char ch;

        cout << "To submit string for processing, press e and then press enter.\nTo quit the program enter q.\n";
        while (true) {
            ch = cin.get(); // read character by character. 
            //specially used to scan newline as char
            if (ch == 'e') { 
                if(input.back() == '\n'){
                    input.pop_back(); // remove last newline
                }
                int ans = calculator.Add(input);
                cout << "ans: " << ans << endl;
                input = ""; // reset input for next calculation
                cout << "Enter new string" << endl;
                cin >> ws; // clear whitespace for correct scanning of next string
                continue;
            }
            if(ch == 'q') return 0; 
            input += ch; 
        }
    }
    return 0;
}