#include<bits/stdc++.h>

using namespace std;

void printPossibleWords(vector<string> &allWords) {
    for(int i = 0; i < allWords.size(); i++) {
        cout << allWords[i] << " ";
    }
}

void func1(vector<string> &allWords, string input){
    for(int i = 0; i < input.length(); i++) {
        vector<string> possibleWords;
        if(input[i] == '-')
            continue;
        for(int j = 0; j < allWords.size(); j++) {
            if(allWords[j][i] == input[i]){
                possibleWords.push_back(allWords[j]);
            }
        }
        allWords = possibleWords;
    }
}

void func2(vector<string> &allWords, string input) {
    
    for(int i = 0; i < input.length(); i++) {
        vector<string> possibleWords;
        for(int j = 0; j < allWords.size(); j++) {
            bool invalid = false;
            for(int k = 0; k < allWords[j].size(); k++) {
                if(input[i] == allWords[j][k]) {
                    invalid = true;
                    break;
                }
            }
            if(!invalid)
                possibleWords.push_back(allWords[j]);
            
        }
        allWords = possibleWords;
    }
    
}

void func3(vector<string> &allWords, string input) {
    vector<string> possibleWords;
    for(int i = 0; i < input.length(); i++) {
        for(int j = 0; j < allWords.size(); j++) {
            bool valid = false;
            for(int k = 0; k < allWords[j].size(); k++) {
                if(input[i] == allWords[j][k]) {
                    valid = true;
                    break;
                }
            }
            if(valid)
                possibleWords.push_back(allWords[j]);
        }
    }
    allWords = possibleWords;
}

int main() {
    fstream file;
    string fileName = "words.txt", word;
    vector<string> allWords, temp;
    file.open(fileName.c_str());
    while (file >> word) {
        allWords.push_back(word);
    }
    string input;
    bool loop = true;
    while(loop) {
        int n;
        cout << "1. Enter the word having all letters at their correct position" << endl;
        cout << "2. Enter the letters that are not there" << endl;
        cout << "3. Enter the letters that are there but not at their correct positions " << endl;
        cout << "4. Exit" << endl;
        cin >> n;
        switch(n) {
            case 1: 
            {
                string input;
                cout << "Enter the input: ";
                cin >> input;
                func1(allWords, input);
                printPossibleWords(allWords);
                break;
            }

            case 2: 
            {
                string input;
                cout << "Enter the letters that are not there: ";
                cin >> input;
                func2(allWords, input);
                printPossibleWords(allWords);
                break;
            }

            case 3: 
            {
                string input;
                cout << "Enter the letters that are there but not at their correct positions: ";
                cin >> input;
                func3(allWords, input);
                printPossibleWords(allWords);
                break;
            }

            case 4:
            loop = false;
            break;
        }

        cout << "\n\n";  
    }
}