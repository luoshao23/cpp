int main() {

	double i = 2.3;
	double j = 5;
	const double *pi = &i;
	i = 3.3;
//	*pi = 5;
	*pi = &j

	return 0;

}
