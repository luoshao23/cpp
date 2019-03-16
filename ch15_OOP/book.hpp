#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include <set>

class Quote {
public:
    Quote() = default;
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;
    Quote(const std::string &s, double p): id(s), price(p) { }
    virtual ~Quote() = default;
    std::string isbn() const { return id; }
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual void debug();
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
private:
    std::string id;
protected:
    double price = 0.0;
};

class DiscQuote : public Quote {
public:
    DiscQuote() = default;
    DiscQuote(const std::string &s, double p, std::size_t qty, double disc) :
        Quote(s, p), quantity(qty), discount(disc){};
    double net_price(std::size_t) const = 0;
    void debug() = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class BulkQuote : public DiscQuote {
public:
    std::pair<size_t, double> discount_policy() const { return {quantity, discount}; }
    using DiscQuote::DiscQuote;
    double net_price(std::size_t) const override;
    void debug() override;
    virtual BulkQuote *clone() const & override{ return new BulkQuote(*this); }
    virtual BulkQuote *clone() && override { return new BulkQuote(std::move(*this)); }
};

class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale)
        { items.insert(sale); }
    void add_item(const Quote& sale)
        { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote&& sale)
        { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
        items{compare};
};


// class BulkQuote : public Quote {
// public:
//     BulkQuote() = default;
//     BulkQuote(const std::string &s, double p, std::size_t qty, double disc) :
//         Quote(s, p), min_qty(qty), discount(disc) {};
//     double net_price(std::size_t) const override;
//     void debug() override final;
// private:
//     std::size_t min_qty = 0;
//     double discount = 0.0;
// };


#endif