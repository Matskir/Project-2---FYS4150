#include "new_proj2.hpp"

int main(){
  int n = 10;
  double n_float = 10;
  double h = 1/n_float;

  double a = -1/(h*h);
  double d = 2/(h*h);

  arma::mat A = create_tridiagonal(n,a,d);
  arma::mat R = arma::mat(n,n,arma::fill::eye);

  arma::vec eigvals;
  arma::mat eigvecs;
  arma::eig_sym(eigvals, eigvecs,A);

  int k;
  int l;
  double maxval = max_offdiag_symmetric(A,k,l);

  double tol = 1e-8;

  int numb = 0;
  while (fabs(A(k,l))>tol){
    update_matrix(A,R,k,l);
    maxval = max_offdiag_symmetric(A,k,l);
    numb = numb + 1;
  }

  arma::vec jacobi_eigvals = arma::vec(n);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (i==j){
        jacobi_eigvals(i) = A(i,j);
      }
    }
  }

  A.save("A_matrix.bin");
  R.save("R_matrix.bin");

  eigvals.save("An_eigvals.bin");
  eigvecs.save("An_eigvecs.bin");

  std::cout << "Number of transformations: " << numb << "\n" << "\n";
  std::cout << "Numerically determined eigenvalues:" << "\n";
  std::cout << jacobi_eigvals << "\n" << "\n";
  std::cout << "Eigenvalues from Armadillo" << "\n";
  std::cout << eigvals << "\n" << "\n";
  std::cout << "Numerically determined eigenvectors:" << "\n";
  std::cout << R << "\n" << "\n";
  std::cout << "Eigenvectors from Armadillo" << "\n";
  std::cout << eigvecs << "\n" << "\n";

  return 0;
}
