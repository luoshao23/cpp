#include <iostream>

class ConstRef{
	public:
		ConstRef(int ii): i(ii), ci(ii), ri(i) {}
		void display(std::ostream&) const;
	private:
		int i;
		const int ci;
		int &ri;
};

void ConstRef::display(std::ostream &os) const {
	os << i << " " << ci << " " << ri;
}

int main(){
	ConstRef k(5);
	k.display(std::cout);

	return 0;
}
