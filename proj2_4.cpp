#include "new_proj2.hpp"

int main(){
  arma::mat A = arma::mat(4,4);
  A.col(0) = arma::vec({1,0,0,0.5});
  A.col(1) = arma::vec({0,1,-0.7,0});
  A.col(2) = arma::vec({0,-0.7,1,0});
  A.col(3) = arma::vec({0.5,0,0,1});

  double maxval;
  int k;
  int l;

  maxval = max_offdiag_symmetric(A,k,l);
  std::cout << "Maximum value (in absolute value): " << maxval << "\n";

}
