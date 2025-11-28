#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include "QueryResult.h"
#include <string>
#include <memory>
#include <iostream>

class Query_base
{
    friend class Query; // Query 可以调用 eval, rep
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() { }
private:
    // 凡是逻辑上只读的接口（如打印、查询、表示），都应该声明为 const 成员函数。
    // 只有 Query_base 和 他的 friend Query 可以调用 eval, rep
    // 但是 Query_base 是抽象基类, 就是说只能通过 Query 使用 eval rep
    // 虽然是 private 但是派生类继承了他们, 并且可以且必须实现覆盖, 不能调用
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query 
{
    // 运算符的语义是“根据已有的查询对象组合出一个新的查询”，而不是修改原来的查询对象
    // 运算符函数的参数几乎总是写成 const T&，因为它们只读、避免拷贝、还能绑定临时对象。
    // these operators need access to the shared_ptr constructor
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
private:
    std::shared_ptr<Query_base> q;
    Query(std::shared_ptr<Query_base> query) : q(query) { }
public:
    Query(const std::string &); // wordQuery
    // interface functions:
    QueryResult eval(const TextQuery &t) const
        { return q->eval(t); }
    std::string rep() const { return q->rep(); }   
};

inline
std::ostream &
operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery : public Query_base
{
    friend class Query; // Query use the WordQuery constructor
    std::string query_word;

    WordQuery(const std::string &s) : query_word(s) { }
    QueryResult eval(const TextQuery &t) const
        { return t.query(query_word); }
    std::string rep() const { return query_word; }
};

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }

    // concrete class: NotQuery defines all inherited pure virtual functions
	std::string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery : public Query_base
{
protected:
    Query lhs, rhs;
    std::string opSym;

    BinaryQuery(const Query &l, const Query &r, std::string s) : 
        lhs(l), rhs(r), opSym(s) { }
    
    // BinaryQuery does not define eval, so it is a abstrace class
    std::string rep() const { return "(" + lhs.rep() + " "
                                         + opSym + " "
                                         + rhs.rep() + ")";}
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) : 
        BinaryQuery(left, right, "&") { }
    // concrete class: inherits rep and define eval
    QueryResult eval(const TextQuery &) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right): 
                BinaryQuery(left, right, "|") { }

    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}


#endif