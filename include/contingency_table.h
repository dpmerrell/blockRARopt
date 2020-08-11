// contingency_table.h
// (c) 2020-08 David Merrell
//
// A simple struct definition for 2x2 contingency tables.

#include <string>

struct ContingencyTable {
    short unsigned int a0;
    short unsigned int a1;
    short unsigned int b0;
    short unsigned int b1;

    void pretty_print(){
        std::cout << a0 << "\t" << a1 << std::endl;
	std::cout << b0 << "\t" << b1 << std::endl;
    }

    bool operator==(const ContingencyTable& other) const {
	return (a0 == other.a0) && (a1 == other.a1) && (b0 == other.b0) && (b1 == other.b1);
    }
};


struct CTHash {

    std::size_t operator()(const ContingencyTable& t) const {
	return std::hash<std::string>{}(std::to_string(t.a0) 
			              + std::to_string(t.a1)
			              + std::to_string(t.b0)
			              + std::to_string(t.b1));
    }
};

