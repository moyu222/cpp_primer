#include <string>
#include <memory>
#include <initializer_list>
#include <algorithm>

using namespace std;

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string> &sl);
    // 移动构造函数
    StrVec(StrVec &&s) noexcept;

    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);

    // 移动赋值运算
    StrVec &operator=(StrVec &&rhs) noexcept;

    ~StrVec();
    // 拷贝和移动的 push_back
    void push_back(const std::string &);
    void push_back(std::string &&);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    void reserve(size_t n);
    void resize(size_t n, std::string s);

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    static std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();
    void free();
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
};

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    // 处理自复制
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline StrVec::StrVec(initializer_list<string> &sl)
{
    auto data = alloc_n_copy(sl.begin(), sl.end());
    elements = data.first;
    first_free = cap = data.second;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

pair<string *, string *>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        // for (auto p = first_free; p != elements;)
        //     alloc.destroy(--p); // destory 前一个元素
        // alloc.deallocate(elements, cap - elements);
        for_each(elements, first_free,
                 [](std::string &s)
                 { alloc.destroy(&s); });
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

// void StrVec::reallocate()
// {
//     auto newcapacity = size() ? 2 * size() : 1;
//     auto newdata = alloc.allocate(newcapacity);
//     auto dest = newdata;
//     auto elem = elements;
//     for (size_t i = 0; i != size(); ++i)
//         alloc.construct(dest++, std::move(*elem++));
//     free();
//     elements = newdata;
//     first_free = dest;
//     cap = elements + newcapacity;
// }

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity())
        return;
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elem + newcapacity;
}

inline void StrVec::resize(size_t n, std::string s = std::string())
{
    // reserve(n);
    // if (n <= size())
    //     first_free = elements + n;
    // else
    // {
    //     for (size_t i = size(); i != n; ++i)
    //         alloc.construct(first_free++, s);
    // }
    // return;

    if (n > size())
        while (size() < n)
            push_back(s);
    else if (n < size())
        while (size() > n)
            alloc.destroy(--first_free);
}
