#ifndef FOLDER_HPP
#define FOLDER_HPP

#include <set>
#include "Message.hpp"

class Folder
{
    friend class Message;
    friend void swap(Message &lhs, Message &rhs);
private:
    std::set<Message *> msgs;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void save(Message &);
    void remove(Message &);

private:
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void add_to_Messages(const Folder&);// add this Folder to each Message
    void remove_from_Msgs();     // remove this Folder from each Message
};

#endif