Ques 1. Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Program code:
#include <iostream>
#include <unordered_map>
#include <string>

int firstUniqChar(const std::string& s) {
    std::unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++; character
    for (int i = 0; i < s.length(); ++i) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string s = "leetcode";

    int index = firstUniqChar(s);
    if (index != -1) {
        std::cout << "The first non-repeating character is at index " << index << std::endl;
    } else {
        std::cout << "There is no non-repeating character in the string." << std::endl;
    }

    return 0;
}
