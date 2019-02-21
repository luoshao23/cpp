#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void word_transform(ifstream &map_file, ifstream &input)
{
    map<string, string> buildMap(ifstream &map_file);
    const string &transform(const string &s, const map<string, string> &mp);

    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while(stream >> word){
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;

    }

}

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key, value;
    while(map_file >> key && getline(map_file, value)){
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string & transform(const string &s, const map<string, string> &mp)
{
    auto map_it = mp.find(s);
    if (map_it != mp.cend())
        return map_it->second;
    else
        return s;
}

int main()
{
    ifstream map_file("/Users/shouzeluo/Desktop/cpp_playground/ch11_ass_container/map.txt");
    ifstream input_file("/Users/shouzeluo/Desktop/cpp_playground/ch11_ass_container/trans.txt");
    word_transform(map_file, input_file);
}