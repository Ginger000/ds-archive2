/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
      while (getline(wordsFile, word)) {
        string temp = word;
        sort(temp.begin(),temp.end());
        dict[temp].push_back(word);
      }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for(string word : words){
      string temp = word;
      sort(temp.begin(),temp.end());
      dict[temp].push_back(word);
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    // return vector<string>();
    string temp = word;
    sort(temp.begin(),temp.end());
    using AnagramDictIter = std::map<std::string, std::vector<std::string>>::const_iterator;
    AnagramDictIter it = dict.find(temp);
    if(it == dict.end()){
      return vector<string>();
    } else{
      return it->second;
    }
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    // return vector<vector<string>>();
    vector<vector<string>> all;
    for(std::pair<string, vector<string>> d : dict){
    vector<string> temp = d.second;
      if(temp.size() <= 1){
        continue;
      }
      all.push_back(temp);
    }
    return all;
}
