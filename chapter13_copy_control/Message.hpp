#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = "") : content(str) {}
    // 拷贝控制, 同时修改对应的 folder
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    // 移动构造函数, set 插入可能 throw bad_alloc 所以没有 noexcept
    // 意味着 vector<Message> 的 push_back 操作使用拷贝构造
    Message(Message &&m);
    Message &operator=(Message &&rhs);

    void save(Folder &);
    void remove(Folder &);

private:
    std::string content;
    std::set<Folder *> folders;
    // 辅助函数, 遍历 folder 添加/删去
    void add_to_Floders(const Message &);
    void remove_from_Floders();
    void addFldr(Folder *f) { folders.insert(f); };
    void remFldr(Folder *f) { folders.erase(f); }

    // 移动构造函数需要更新每一个 folder, 辅助函数
    void move_Folders(Message *m);
};

#endif