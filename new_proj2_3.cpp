#include "new_proj2.hpp"

int main(){
  int n = 6;
  double n_float = 6;
  double h = 1/(n_float);
  double a = -1/(h*h);
  double d = 2/(h*h);

  arma::mat A = create_tridiagonal(n,a,d);
  arma::vec an_eigvals = analytical_eigenvals(n,a,d);

  arma::vec arm_eigvals;
  arma::mat arm_eigvecs;
  arma::eig_sym(arm_eigvals,arm_eigvecs,A);

  std::cout << "Analytically computed eigenvalues:\n";
  std::cout << an_eigvals << "\n";
  std::cout << "\n";
  std::cout << "Eigenvalues computed with Armadillo:\n";
  std::cout << arm_eigvals << "\n";
  return 0;
}
