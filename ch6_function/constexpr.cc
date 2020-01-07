int main(){
	constexpr int new_num(int i);
	new_num(3);
	return 0;
}

constexpr int new_num(int i){
	return i * i;
}
