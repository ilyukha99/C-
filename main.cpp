#include "Trit.h"

int main() {
	// just testing
	srand(static_cast<unsigned int>(time(0)));

	Tritset set1(70);
	set1.fill_Tritset_randomly();
	set1.print_tritset();
	Tritset set(51);
	set.fill_Tritset_randomly();
	set.print_tritset();

	Tritset set2(400);
	set2 = set1 & set;

	set2.print_tritset();

	std::cout << set2.capacity() << "\n";

	std::cout << set2.cardinality(Unknown) << "\n";

	set2.print_array();

	std::cout << set2.length() << "\n";

	set2.shrink();
	set2.print_tritset();

	set2 = ~set2;
	set2.print_tritset();

	std::cout << (set1 == set2) << "\n";
	std::cout << (set1 != set2) << "\n";
	std::cout << (set1 == set1) << "\n";

	system("pause");
	return 0;
}
