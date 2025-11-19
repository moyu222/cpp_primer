#include "Folder.hpp"
#include "Message.hpp"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Floders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Floders()
{
    for (auto f : folders)
        f->remMsg(this);
}

// 拷贝初始化成员, 我们可以通过定义 移动操作 来避免
Message::Message(const Message &m) : content(m.content), folders(m.folders)
{
    add_to_Floders(m);
}

Message::~Message()
{
    remove_from_Floders();
}

void Message::move_Folders(Message *m)
{
    // set 和 string 都有移动操作
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear(); // 确保销毁 m 是无害的
}

Message::Message(Message &&m) : content(std::move(m.content))
{
    move_Folders(&m);
}

Message &Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Floders();
        content = std::move(rhs.content);
        move_Folders(&rhs);
    }
    return *this;
}



Message &Message::operator=(const Message &rhs)
{
    remove_from_Floders();
    content = rhs.content;
    folders = rhs.folders;
    add_to_Floders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.content, rhs.content);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto &msg : msgs)
        msg->addFldr(this);
}

void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
    {
        (*msgs.begin())->remove(*this);
    }
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}


Folder &Folder::operator=(const Folder &f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_Msgs();
}

void Folder::save(Message &m)
{
    // add m and add this folder to m's set of Folders
    msgs.insert(&m);
    m.addFldr(this);
}

void Folder::remove(Message &m)
{
    // erase m from msgs and remove this folder from m
    msgs.erase(&m);
    m.remFldr(this);
}