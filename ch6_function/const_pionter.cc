int main()
{
	const int ci = 42;
	int i = ci;
	int * const p = &i;
	*p = 0;
	// p = 0;

	return 0;
}
