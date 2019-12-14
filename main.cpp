#include "Trit.h"
#define CATCH_CONFIG_MAIN
//#define CATCH_CONFIG_ALL_PARTS
#include "catch.hpp"
//srand(static_cast<unsigned int>(time(0)));


TEST_CASE("Testing") {
	
	SECTION("Constr") {

		Tritset set(100);
		REQUIRE(set.size() == 100);
		REQUIRE(set.capacity() == (100 / 4 / sizeof(uint) + 1) * 4 * sizeof(uint));
		for (size_t it = 0; it != set.capacity(); ++it)
			REQUIRE(set[it] == Unknown);		
	}

	SECTION("Get and Set") {

		Tritset set(15);
		REQUIRE(set.get_value(5) == Unknown);
		set.set_value(5, True);
		REQUIRE(set.get_value(5) == True);
	}
	
	SECTION("Cardinality") {

		Tritset set(100);
		for (size_t it = 0; it < set.size(); it += 2)
			set[it] = True;
		for (size_t it = 1; it < set.size(); it += 2)
			set[it] = False;

		REQUIRE(set.cardinality(True) == 50);
		REQUIRE(set.cardinality(False) == 50);
		REQUIRE(set.cardinality(Unknown) == 0);
	}
	
	SECTION("Trim") {

		Tritset set(80);
		fill_Tritset(set, True);
		for (size_t it = 52; it != set.size(); ++it)
			REQUIRE(set[it] == True);
		set.trim(51);
		REQUIRE(set[51] == True);
		for (size_t it = 52; it != set.size(); ++it)
			REQUIRE(set[it] == Unknown);
		REQUIRE(set.length() == 52);
	}

	SECTION("[], reference ()") {

		Tritset set(80);
		REQUIRE(set[14] == set.get_value(14));
		REQUIRE(set[14] == Trit(set[14]));
	}

	SECTION("&=") {

		Tritset setA(50); //U
		Tritset setB(60); //U
		setA &= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == Unknown);
		fill_Tritset(setA, True); // A - True
		setA &= setB; 
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == Unknown);
		fill_Tritset(setB, False); //B - False
		setA &= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == False);
		fill_Tritset(setB, True); //B - False
		setA &= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == False);
		REQUIRE(setA.size() == 50);
	}

	SECTION("|=") {

		Tritset setA(50);
		Tritset setB(60);
		setA |= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == Unknown);
		fill_Tritset(setB, False); //B - False
		setA |= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == Unknown);
		fill_Tritset(setB, True); //B - True
		setA |= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == True);
		fill_Tritset(setB, False); //B - False
		setA |= setB;
		for (size_t it = 0; it != setA.size(); ++it)
			REQUIRE(setA[it] == True);
		REQUIRE(setA.size() == 50);
	}

	SECTION("shrink") {

		Tritset set(100);
		fill_Tritset(set, True);
		REQUIRE(set.capacity() == 112);
		set.trim(50);
		set.shrink();
		REQUIRE(set.capacity() == 64);
		for (size_t it = 51; it != set.capacity(); ++it)
			REQUIRE(set[it] == Unknown);
	}

	system("pause");
}