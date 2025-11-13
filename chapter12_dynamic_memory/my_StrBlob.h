#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <iostream>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

#include "my_StrBlob.h"

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    void push_back(const std::string &t) { data->emplace_back(t); };
    void pop_back();
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

    StrBlobPtr begin() const;
    StrBlobPtr end() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

inline StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
inline StrBlob::StrBlob(std::initializer_list<std::string> li) :
    data(std::make_shared<std::vector<std::string>>(li)) {}

inline void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i > data->size())
        throw std::out_of_range(msg);
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back()");
    data->pop_back();
}

inline std::string& StrBlob::front()
{
    check(0, "front()");
    return data->front();
}

inline const std::string& StrBlob::front() const
{
    check(0, "front()");
    return data->front();
}

inline std::string& StrBlob::back()
{
    check(0, "back()");
    return data->back();
}
inline const std::string& StrBlob::back() const
{
    check(0, "back()");
    return data->back();
}

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

    std::string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>>
        check(size_t, const std::string&) const;
};

inline std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

inline std::string& StrBlobPtr::deref() const
{
    auto sptr = check(curr, "deref()");
    return (*sptr)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
    --curr;
    check(curr, "decrement past front");
    return *this;
}

inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
    return StrBlobPtr(*this, data->size());
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

#endif //MY_STRBLOB_H
