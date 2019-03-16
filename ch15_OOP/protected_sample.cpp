class Base {
protected:
    int prot_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
    int j;
};

void clobber(Sneaky &s) { s.j = s.prot_mem = 0;}
// void clobber(Base &b) { b.prot_mem = 0;}

class Base2 {
public:
    void pub_mem2();
protected:
    int prot_mem2;
private:
    char priv_mem2;
};

struct PubDerv : public Base2 {
    int f() { return prot_mem2; }
    // char g() { return priv_mem2; }
};

struct PrivDerv : private Base2
{
    int f1() const { return prot_mem2; }
};

int main()
{
    PubDerv pd1;
    PrivDerv pd2;
    pd1.pub_mem2();
    // pd2.pub_mem2();
}