// CheckValidAnagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
* 242. Valid Anagram
* https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
*/
// input 1:- strInput   - Contains string1
// input 2: strAnagram  -- Contains anagram of string 1.
bool isAnagram(string strInput1, string strInput2)
{
    vector<int> charMap(26);
    if (strInput1.empty() && strInput2.empty())
        return true;
    if (strInput1.empty() || strInput2.empty())
        return false;
    if (strInput1.size() != strInput2.size())
        return false;

    for (int i = 0; i < strInput2.size(); i++)
    {
        int nVal = strInput1[i] - 'a';
        charMap[strInput1[i] - 'a']++;
        charMap[strInput2[i] - 'a']--;
    }

    for (int elem : charMap)
    {
        if (elem != 0)
        {
            return false;
        }
    }
    return true;

}

int main()
{
    if (isAnagram("anagram", "nagaram"))
    {
        cout << "nagaram is an anagram of anagram" << endl;
    }
    std::cout << "Hello World!\n";
}


