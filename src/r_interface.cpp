// r_interface.cpp
// (c) 2020 David Merrell
//

#include "block_rar_opt.h"
#include <string>
#include <iostream>
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
void block_rar_opt(int n_patients, int block_incr,
                   double error_cost, double block_cost,
                   std::string sqlite_fname,
                   float smoothing=1e-6) {
  
  std::cout << "about to initialize solver" << std::endl;
  BlockRAROpt solver = BlockRAROpt(n_patients, block_incr,
                                   float(error_cost), float(block_cost),
                                   smoothing);
  std::cout << "Initialized solver." << std::endl; 
  std::cout << "Solving." << std::endl;
  
  solver.solve();
  std::cout << "Solver completed." << std::endl;
  
  char* fname = new char[sqlite_fname.length() + 1];
  strcpy(fname, sqlite_fname.c_str());
  
  solver.to_sqlite(fname, 10);
  std::cout << "Saved to file: " << sqlite_fname << std::endl;
  
  delete[] fname;
}


