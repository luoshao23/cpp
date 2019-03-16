class Base {
    friend class Pal;
protected:
    int prot_mem;
};

class Sneaky : public Base {
private:
    int j;
};

class Pal {
public:
    int f(Base b) { return b.prot_mem;}
    int f2(Sneaky s) { return s.j; }
    int f3(Sneaky s) { return s.prot_mem; }
};

// D2对Base的protected和private成员不具有特殊的访问能力
class D2 : public Pal {
public:
    int mem(Base b)
        { return b.prot_mem; }
};

