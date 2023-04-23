#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct CompareWords {
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main() {
    string inputFile = "input.txt";
    ifstream input_file(inputFile);
    if (!input_file.is_open()) {
        cerr << "Failed to open to file!" << endl;
        return 1;
    }
    string sentence;
    getline(input_file, sentence);
    input_file.close();
    string delimiters = " ,.!?";
    map<string, int> word_count;
    size_t start = 0, end = 0;

    while ((end = sentence.find_first_of(delimiters, start)) != string::npos) {
        string word = sentence.substr(start, end - start);
        for (char &c: word) c = ::tolower(c);
        if (!word.empty()) word_count[word]++;
        start = sentence.find_first_not_of(delimiters, end);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> sorted_words;
    for (const auto &entry: word_count) {
        sorted_words.push(entry);
    }
    while (!sorted_words.empty()) {
        pair<string, int> word_entry = sorted_words.top();
        cout << word_entry.first << " => " << word_entry.second << endl;
        sorted_words.pop();
    }

    return 0;
}