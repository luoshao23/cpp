#include "Message.hpp"
#include <iostream>


void Message::save(Folder &f)
{
    std::cout << "save " << this->object << " at " << f.name << std::endl;
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    std::cout << "Calling Message::remove: remove " << this->object << " from " << f.name << std::endl;
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f: m.folders) {
        std::cout << "add " << this->object << " to " << f->name << " ";
        f->addMsg(this);
    }

}

void Message::remove_from_Folders()
{
    for (auto f: folders) {
        std::cout << "remove " << this->object << " from " << f->name << " ";
        f->remMsg(this);
    }
    std::cout << "out" << std::endl;

}

Message::Message(const Message &m):
    object(m.object), contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    std::cout << "~Message" << std::endl;
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    object = rhs.object;
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    std::cout << "swap " << lhs.object << " " << rhs.object << std::endl;
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.object, rhs.object);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);

}


Folder::Folder(const Folder& f):
    name(f.name), msgs(f.msgs)
{ add_to_Messages(f); }

Folder& Folder::operator=(const Folder &f)
{
    remove_from_Messages();
    name = f.name;
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m: f.msgs) {
        std::cout << m->object << " saved at " << f.name << " ";
        m->save(const_cast<Folder&>(f));
    }
}

void Folder::remove_from_Messages()
{
    std::cout << "Calling Folder::remove_from_Messages: for [" << this->name << "] ";
    // for (auto m: msgs) {
    //     m->remove(const_cast<Folder&>(*this));
    // }
    while(!msgs.empty())
        (*msgs.begin())->remove(*this);
    std::cout << "Done!" << std::endl;
}

std::ostream& operator<<(std::ostream &os, Message &msg)
{
    os << msg.object << " " << msg.contents;
    return os;
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f: folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message& Message::operator=(Message &&rhs)
{
    std::cout << "rvalue move triggered!" << std::endl;
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

int main()
{
    Message b("MB", "nice to meet B");
    Message a("MA", "this is A");
    Message k;
    k = Message(b);

    Folder study("Fstudy");
    Folder casual("Fcasual");


    // a.save(study);
    b.save(casual);
    b.save(study);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    swap(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}