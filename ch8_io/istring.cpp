#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool vaild(string s)
{
    // for (auto si : s)
    //     if (isdigit(si))
    //         return 0;
    return 1;
}

string format(string s)
{
    // ostringstream ss;
    // for (int i = 0; i < s.length(); ++i)
    // {
    //     if (i == 3)
    //         ss << "-";
    //     ss << s[i];
    // }
    // return ss.str();
    string ss = "ce";
    return ss;
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    bool valid(string s);

    while (getline(cin, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            cout << entry.name << " "
                 << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
}
