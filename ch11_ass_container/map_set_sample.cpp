#include <map>
#include <set>
#include <iostream>

using namespace std;


int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"THE", "BUT", "AND", "OR", "AN", "A"};
    string word;
    while (cin >> word){
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;
    cout << "map_iter" << endl;
    for (auto map_it = word_count.begin(); map_it != word_count.end(); ++map_it)
            cout << map_it->first << ' ' << map_it->second << endl;
}