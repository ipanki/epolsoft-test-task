#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

vector<string> input_words(int n)
{
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string s;
        cout << "Введите элемент " << i << ":" << endl;
        cin >> s;
        if(cin.eof()){
            break;
        }
        words.push_back(s);
    }
    return words ;
}

void print_words(vector<string> words)
{
    cout << "Введенные элементы:" << words.size() << endl;
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;
}

// Match words (nested loops) - O(n^2)
string match_words1(vector<string> &words1, vector<string> &words2)
{
    string result;
    for (int i = 0; i < words1.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < words2.size(); j++)
        {
            if (words1[i] == words2[j])
            {
                found = true;
                break;
            }
        }
        result += found ? '1' : '0';
    }
    return result;
}

// Match words (using map) - O(2n)
string match_words2(vector<string> &words1, vector<string> &words2)
{
    string result;
    map<string, bool> str2map;
    
    for (int i = 0; i < words2.size(); i++)
    {
        str2map[words2[i]] = true;
    }
    
    for (int i = 0; i < words1.size(); i++)
    {
        result += str2map[words1[i]] ? '1' : '0';
    }
    return result;
}

int main(int argc, char** argv)
{
    const string help = "Usage: match <n> - number of words, integer > 0 \n";
    int n;

    if(argc != 2){
        cout << help;
        return 1;
    }

    istringstream(argv[1]) >> n;
    if(n < 1){
        cout << help;
        return 1;
    }

    vector<string> words1 = input_words(n);
    vector<string> words2 = input_words(n);
    
    print_words(words1);
    print_words(words2);
    
    cout << "Результат: " << endl << match_words2(words1, words2) << endl;
    return 0;
}

