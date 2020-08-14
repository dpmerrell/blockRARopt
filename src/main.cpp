// main.cpp
// (c) 2020-08 David Merrell
//
// Dynamic programming algorithm for 
// block RAR RCT design.
//

#include <iostream>
//#include "contingency_table.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>
#include "contingency_iterator.h"

std::string v_to_str(std::vector<float>& v){
    std::string result = "[";
    
    for (std::vector<float>::iterator it = v.begin(); it != v.end(); it++){
       result += std::to_string(*it);
       if (std::next(it) != v.end()){
           result += ", ";       
       }
    }
    result += "]";

    return result;
}	

int main(int argc, char* argv[]){

	std::cout << "Hello, world!" << std::endl;

	ContingencyTable my_table = {1,2,3,4};

	ContingencyTable other_table = {1,2,3,4};

        ContingencyTable different_table = {1,2,3,0};

	std::cout << "SHOULD BE TRUE:\t" << (my_table == other_table) << std::endl;
	std::cout << "SHOULD BE FALSE:\t" << (my_table == different_table) << std::endl;

	my_table.pretty_print();

	std::unordered_map<ContingencyTable, std::vector<float>, CTHash> my_map;

	my_map[my_table] = std::vector<float>(5, 3.14);
	my_map[different_table] = std::vector<float>(5, 2.7);
	
	std::cout << "SHOULD BE A VECTOR:\t" << v_to_str(my_map[my_table]) << std::endl;
	std::cout << "SHOULD BE A DIFFERENT VECTOR:\t" << v_to_str(my_map[different_table]) << std::endl;

        // std::cout << "SHOULD BE AN UNORDERED_MAP:\t" << my_map << std::endl;
	//
	my_table += other_table;

	my_table.pretty_print();


        //ContingencyIterator it = ContingencyIterator(2);
	//it.value().pretty_print();
        ////it.pretty_print();
        //it.advance();
	//it.value().pretty_print();
        //it.advance();
	//it.value().pretty_print();
        //it.advance();
	//it.value().pretty_print();
	ContingencyIterator it = ContingencyIterator(500);
	int k = 0;
	while(true){

	    //it.value().pretty_print();
	    k++; 

            if(it.not_finished()){
		//std::cout << "\n";
	        it.advance();
	    }else{
		break;
	    }	   

	}
	std::cout << k << " TABLES" << std::endl;
}


