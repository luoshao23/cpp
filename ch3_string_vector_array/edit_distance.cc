#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;

int Levenshtein_dist(const string &a, const string &b)
{
    auto len_a = a.size() + 1;
    auto len_b = b.size() + 1;
    vector<vector<int> > dist(len_a, vector<int>(len_b));

    for (size_t i = 0; i < len_a; ++i)
        dist[i][0] = i;

    for (size_t j = 0; j < len_b; ++j)
        dist[0][j] = j;

    for (size_t i = 1; i < len_a; ++i){
        for (size_t j = 1; j < len_b; ++j){
            dist[i][j] = min(dist[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1),
             min(dist[i - 1][j], dist[i][j - 1]) + 1);
        }
    }

    return dist[len_a - 1][len_b - 1];

}

int LCS_dist(const string &a, const string &b)
{
    auto len_a = a.size() + 1;
    auto len_b = b.size() + 1;
    vector<vector<int>> dist(len_a, vector<int>(len_b));

    for (size_t i = 0; i < len_a; ++i)
        dist[i][0] = i;

    for (size_t j = 0; j < len_b; ++j)
        dist[0][j] = j;

    for (size_t i = 1; i < len_a; ++i)
    {
        for (size_t j = 1; j < len_b; ++j)
        {
            dist[i][j] = min(dist[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 2),
                             min(dist[i - 1][j], dist[i][j - 1]) + 1);
        }
    }

    return dist[len_a - 1][len_b - 1];
}

int main()
{
    string a = "kitten";
    string b = "sitting";
    size_t const lena = a.size();
    size_t const lenb = b.size();

    cout << Levenshtein_dist(a, b) << endl;
    cout << LCS_dist(a, b) << endl;
}