#include <vector>
using namespace std;

class nodefault {
	public:
		nodefault() = default;
		nodefault(int i): val(i) {}
	private:
		int val = 0;
};

int main(){
	vector<nodefault> no(10, nodefault(5));
}


