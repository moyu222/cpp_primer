#include <vector>
#include <iostream>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
public:
    StrBlob();
    StrBlob(const initializer_list<string> il);
    StrBlob(vector<string> *p); // new vector 初始化

    StrBlob(const StrBlob &s);
    StrBlob &operator=(const StrBlob &rhs);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &s) { data->push_back(s); }
    void pop_back();

    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const; // 不要写 const StrBlobPtr begin() const;
    // 这样迭代器无法改变没有意义,  一般是如下
    // StrBlobPtr begin();              // 返回可修改迭代器
    // ConstStrBlobPtr_v begin() const;   // 返回只读迭代器

};

inline StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

inline StrBlob::StrBlob(std::vector<std::string> *p) : data(p) { }

inline StrBlob::StrBlob(std::initializer_list<std::string> li) :
    data(std::make_shared<std::vector<std::string>>(li)) {}

inline StrBlob::StrBlob(const StrBlob &s) : data(make_shared<vector<string>>(*s.data)) { }

inline StrBlob &StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}

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
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

    std::string& deref(int off) const;
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