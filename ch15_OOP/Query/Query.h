#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <memory>

#include "textQuery.h"

class QueryBase {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

class Query {
    // friend std::ostream &operator<<(std::ostream &, const Query &);
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery&t) const
                            { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<QueryBase> query): q(query) {}
    std::shared_ptr<QueryBase> q;
};

class WordQuery : public QueryBase {
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) {}
    QueryResult eval(const TextQuery &t) const
        { return t.query(query_word);}
    std::string rep() const { return query_word; }
    std::string query_word;
};

class NotQuery : public QueryBase
{
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) {}
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery : public QueryBase
{
protected:
    BinaryQuery(const Query &lhs, const Query &rhs, std::string s):
        lhs(lhs), rhs(rhs), op(s) {}
    std::string rep() const { return "(" + lhs.rep() + " "
                                        + op + " " + rhs.rep()
                                        + ")"; }
    Query lhs, rhs;
    std::string op;
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery &) const;
};

inline std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}

inline Query operator~(const Query &q)
{
    return std::shared_ptr<QueryBase>(new NotQuery(q));
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult
OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines =
        std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines =
        std::make_shared<std::set<line_no>>();
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
        std::make_shared<std::set<line_no>>();
    auto beg = res.begin(), end = res.end();
    auto sz = res.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }

    return QueryResult(rep(), ret_lines, res.get_file());
}

#endif