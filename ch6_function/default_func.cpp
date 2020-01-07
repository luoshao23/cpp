int main(){
	int func(int i, int j = 3);
	func(2);
}

int func(int i, int j = 3){
	return i + j;
}
