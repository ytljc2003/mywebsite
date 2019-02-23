#include <stream>

template <typename T>
struct person{
int age;
char *name;
T something;
};

int main()
{
	person<int> x;
	x.something = 1;

	person<char *> y;
	y.something = "hoge";

	//Here add something
	std::out << "test cplusplus" << endl;
	return 0;
}
