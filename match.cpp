#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

void input_words(int n, string str[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент " << i << ":" << endl;
        cin >> str[i];
    }
}

void print_words(int n, string str[])
{
    cout << "Введенные элементы:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (str[i].empty())
            break;
        cout << str[i] << " ";
    }
    cout << endl;
}

// Match words (nested loops) - O(n^2)
string match_words1(int n, string str1[], string str2[])
{
    string result;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (str1[i] == str2[j])
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
string match_words2(int n, string str1[], string str2[])
{
    string result;
    map<string, bool> str2map;
    
    for (int i = 0; i < n; i++)
    {
        str2map[str2[i]] = true;
    }
    
    for (int i = 0; i < n; i++)
    {
        result += str2map[str1[i]] ? '1' : '0';
    }
    return result;
}

int main(int argc, char** argv)
{
    const string help = "Usage: match <n> - number of words, integer > 0 \n";
    int max_words;

    if(argc != 2){
        cout << help;
        return 1;
    }

    istringstream(argv[1]) >> max_words;
    if(max_words < 1){
        cout << help;
        return 1;
    }

    string str1[max_words];
    string str2[max_words];
    
    input_words(max_words, str1);
    print_words(max_words, str1);
    
    input_words(max_words, str2);
    print_words(max_words, str2);
    
    cout << "Результат: " << endl
    << match_words2(max_words, str1, str2) << endl;
    return 0;
}

