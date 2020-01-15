#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>

class QueryResult
{
    using line_no = std::vector<std::string>::size_type;
    friend std::ostream &print(std::ostream &, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no > > p,
                std::shared_ptr<std::vector<std::string > > f):
               sought(s), lines(p), file(f) {}
    std::shared_ptr<std::vector<std::string > >  get_file() const { return file; }
    std::set<line_no>::const_iterator begin() const {
        return lines->cbegin();
    }
    std::set<line_no>::const_iterator end() const {
        return lines->cend();
    }

        private : std::string sought;
    std::shared_ptr<std::set<line_no > > lines;
    std::shared_ptr<std::vector<std::string > > file;
};

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    friend class QueryResult;
    TextQuery(std::ifstream &infile);
    QueryResult query(const std::string &s) const;

private:
    std::shared_ptr<std::vector<std::string >> content;
    std::map<std::string,
        std::shared_ptr<std::set<line_no >>> word_map;
};

TextQuery::TextQuery(std::ifstream &infile): content(new std::vector<std::string>)
{
    std::string line;
    int lineNo = 0;

    while (getline(infile, line)){
        // std::cout << line << "\n";
        content->push_back(line);
        std::istringstream sline(line);
        std::string word;
        while (sline >> word) {
            auto &lines = word_map[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(lineNo);
            // auto res = word_map.find(word);
            // if (res != word_map.end()){
            //     word_map[word].insert(lineNo);
            // } else {
            //     word_map.insert({word, std::set<int>{lineNo}});
            // }
        }
        ++lineNo;
    }
}

QueryResult TextQuery::query(const std::string &s) const
{
    static std::shared_ptr<std::set<line_no > > nodata(new std::set<line_no>);
    auto loc = word_map.find(s);
    if (loc == word_map.end())
        return QueryResult(s, nodata, content);
    else
        return QueryResult(s, loc->second, content);
    // auto res = word_map.find(s);
    // std::string output;
    // if (res == word_map.end()) {
    //     output = "No result!";
    // } else {
    //     for (auto& i : word_map[s])
    //         output += " " + std::to_string(i);
    // }

    // return output;
}

std::ostream &print(std::ostream &os, const QueryResult& qr){
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << "time(s)" << std::endl;
    for (auto num : *qr.lines)
        os << "(line " << num << ") "
        // << (*qr.file)[num] << std::endl;
        << *(qr.file->begin() + num) << std::endl;
    return os;
}
#endif
