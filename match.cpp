#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAX_WORDS = 9;

void input_words(int n, std::string str[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент " << i << ":" << endl;
        cin >> str[i];
    }
}

void print_words(int n, std::string str[])
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
std::string match_words1(int n, std::string str1[], std::string str2[])
{
    std::string result;
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
std::string match_words2(int n, std::string str1[], std::string str2[])
{
    std::string result;
    std::map<std::string, bool> str2map;

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

int main()
{
    std::string str1[MAX_WORDS] = {};
    std::string str2[MAX_WORDS] = {};

    input_words(MAX_WORDS, str1);
    print_words(MAX_WORDS, str1);

    input_words(MAX_WORDS, str2);
    print_words(MAX_WORDS, str2);

    cout << "Результат 1: " << endl
         << match_words1(MAX_WORDS, str1, str2) << endl;

    cout << "Результат 2: " << endl
         << match_words2(MAX_WORDS, str1, str2) << endl;
    return 0;
}
