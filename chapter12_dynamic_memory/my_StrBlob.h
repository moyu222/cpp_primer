#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <iostream>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
    StrBlob(std::vector<std::string> *p);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->emplace_back(t); }
    void pop_back();
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

inline StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
inline StrBlob::StrBlob(std::vector<std::string> *p) : data(p) {}
inline StrBlob::StrBlob(std::initializer_list<std::string> li) : data(std::make_shared<std::vector<std::string>>(li)) {}

inline void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
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
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    std::string& deref(int off) const;
    std::string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>> check(size_t, const std::string&) const;
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

inline std::string& StrBlobPtr::deref(int off) const
{
    auto sptr = check(curr + off, "deref()");
    return (*sptr)[curr + off];
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

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
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

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    const std::string& deref() const;
    ConstStrBlobPtr& incr();
    ConstStrBlobPtr& decr();
private:
    std::weak_ptr<const std::vector<std::string>> wptr;
    size_t curr;
    std::shared_ptr<const std::vector<std::string>> check(size_t, const std::string&) const;
};

inline std::shared_ptr<const std::vector<std::string>> ConstStrBlobPtr::check(size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

inline const std::string& ConstStrBlobPtr::deref() const
{
    auto sptr = check(curr, "deref()");
    return (*sptr)[curr];
}

inline ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end");
    ++curr;
    return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::decr()
{
    --curr;
    check(curr, "decrement past front");
    return *this;
}

inline ConstStrBlobPtr StrBlob::cbegin() const
{
    return ConstStrBlobPtr(*this);
}

inline ConstStrBlobPtr StrBlob::cend() const
{
    return ConstStrBlobPtr(*this, data->size());
}

#endif // MY_STRBLOB_H
