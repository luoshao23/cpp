#include <memory>
#include "Query.h"
// #include "textQuery.h"

inline
std::ostream& operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

inline
Query::Query(const std::string &s): q(new WordQuery(s)) {}

inline
Query operator~(const Query &q){
    return std::shared_ptr<QueryBase>(new NotQuery(q));
}

inline
Query operator&(const Query &lhs, const Query &rhs){
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

inline
Query operator|(const Query &lhs, const Query &rhs){
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult
OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines =
        std::make_shared<std::set<line_no > >(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines =
        std::make_shared<std::set<line_no > >();
    std::set_intersection(right.begin(), right.end(),
                          left.begin(), left.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
NotQuery::eval(const TextQuery &text) const
{
    auto res = query.eval(text);
    auto ret_lines =
        std::make_shared<std::set<line_no > >();
    auto beg = res.begin(), end = res.end();
    auto sz = res.get_file()->size();
    for (size_t n = 0; n != sz; ++n){
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end )
            ++beg;
    }

    return QueryResult(rep(), ret_lines, res.get_file());
}
