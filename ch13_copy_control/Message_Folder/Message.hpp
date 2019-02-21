#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include <iostream>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend std::ostream& operator<<(std::ostream&, Message&);
public:
    explicit Message(const std::string &obj = "", const std::string &cont = ""):
        object(obj), contents(cont) { std::cout << "create message: " << object << std::endl; }
    Message(const Message&);
    Message(Message &&m): object(std::move(m.object)), contents(std::move(m.contents)) { move_Folders(&m); }
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void move_Folders(Message*);

private:
    std::string object;
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder
{
    friend class Message;
    friend void swap(Message&, Message&);
public:
    Folder(std::string name): name(name) { std::cout << "create folder: " << name << std::endl; };
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void save(Message&);
    void remove(Message&);
private:
    std::string name;
    std::set<Message*> msgs;
    void add_to_Messages(const Folder&);  // add this Folder to each Message
    void remove_from_Messages();  // remove this Folder from each Message
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

#endif