#include <bits/stdc++.h>
using namespace std;
class questions {
    map<string, string> mp;
    int asked_que_ptr;
    vector<string> some_questions_to_be_asked;

public:
    questions() {
        asked_que_ptr = 0;
        mp["hi"] = "hello";
        mp["How are you"] = "I am fine, What about you?";
        mp["What's your name?"] = "My name is Wed. What's your name";
        mp["What's your age?"] = "I was created on march 2022 by Yash Rajput";
        mp["what's the timing of hospital?"] = "Morning 10am to Evening 6pm";
        some_questions_to_be_asked.push_back("What's your name?");
        some_questions_to_be_asked.push_back("What's your father's name?");
        some_questions_to_be_asked.push_back("What's your mother's name?");
        some_questions_to_be_asked.push_back("What's your problem?");
    }
    string accuracy(string question) {
        int accuracy = 0;
        string ans = "Sorry! unable to understand\n";
        map<char, int> mp_of_question;
        for (auto i : question) {
            mp_of_question[i]++;
        }
        for (auto i : mp) {
            int temp_accuracy = 0;
            map<char, int> map_of_question_in_dataset;
            for (auto k : i.first) {
                map_of_question_in_dataset[k]++;
            }
            for (char c = 'a'; c <= 'z'; c++) {
                temp_accuracy += min(map_of_question_in_dataset[c], mp_of_question[c]);
            }
            if (temp_accuracy > accuracy) {
                accuracy = temp_accuracy;
                ans = i.second;
            }
        }
        return ans;
    }
    void AskMeAnything() {
        cout << "Hey!!\n";
        cout << "What's your doubt\n";
        string question;
        cin.ignore();
        getline(cin, question);
        string ans = accuracy(question);
        cout << ans << '\n';
    }
    void addAnswer() {
        while (asked_que_ptr < some_questions_to_be_asked.size()) {
            cout << "If you want to stop please enter -1\n";
            cout << some_questions_to_be_asked[asked_que_ptr];
            string ans;
            cin.ignore();
            getline(cin, ans);
            if (ans == "-1") {
                break;
            }
            mp[some_questions_to_be_asked[asked_que_ptr]] = ans;
            asked_que_ptr++;
        }
    }
    void addManually() {
        cout << "Enter your Question\n";
        string que;
        cin.ignore();
        getline(cin, que);
        cout << "Enter your answer\n";
        cin >> mp[que];
    }
};
int main() {
    cout << "Welcome to OPERA HOSPITAL\n";
    cout << "Hi!! how can i help you?\n";
    questions obj;
    while (1) {
        cout << "\n1 Ask me a question\n";
        cout << "2 Want to give some answer\n";
        cout << "3 want to add some answer manually\n";
        cout << "0 Exit\n";
        int c;
        cin >> c;
        if (c == 0) {
            cout << "Hope you like our service if you are not satisfied than talk to our customer care '1800 256 452'\n";
            cout << "Thank you :)\n";
            break;
        } else if (c == 1) {
            obj.AskMeAnything();
        } else if (c == 2) {
            obj.addAnswer();
        } else if (c == 3) {
            obj.addManually();
        } else {
            cout << "Wrong choice :(\n";
            cout << "Please try again\n";
        }
    }
}