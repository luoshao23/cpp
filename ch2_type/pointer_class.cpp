#include <iostream>
#include <string>

class myClass {
public:
	myClass() = default;
	myClass(int a): age(a) {}
	int getAge();
	void setAge(int);

private:
	int age;
	
};


int myClass::getAge() { return age; }
void myClass::setAge(int a) { age = a; }

int main() {
	myClass k;
	k.setAge(5);
	std::cout << k.getAge() << std::endl;
	// k.age = 3;
	myClass *pk = &k;

	std::cout << "pointer: " << pk->getAge() << std::endl;
	myClass &ik = *pk;

	std::cout << "ref: " << ik.getAge() << std::endl;
	myClass ll = myClass(23);
	std::cout << ll.getAge() << std::endl;

	return 0;

}
