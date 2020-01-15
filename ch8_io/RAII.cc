#include <iostream>
namespace detail {
template <typename F>
struct FinalAction {
	FinalAction(F f) : clean_{f} {}
	~FinalAction() { if (enabled_) clean_(); }
	void disable() { enabled_ = false; }
private:
	F clean_;
	bool enabled_{true};
};
}

template <typename F>
detail::FinalAction<F> finally(F f) {
	return detail::FinalAction<F>(f);
}

int main() {
	//int* a = new int;
	auto del_a = finally([] { /*delete a;*/ std::cout << "leaving, deleting!\n";});
	std::cout << "doing...\n";

}
