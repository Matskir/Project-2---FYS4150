#include <iostream>
#include <armadillo>
#include <cmath>
#include <stdexcept>
#include <math.h>

//Create tridiagonal matrix from scalar a and d
arma::mat create_tridiagonal(int n, double a, double d){
  arma::vec a_vec = arma::vec(n-1,arma::fill::ones)*a;
  arma::vec d_vec = arma::vec(n,arma::fill::ones)*d;

  arma::mat temp_A1 = arma::mat(n,n);
  arma::mat temp_A2 = arma::mat(n,n);
  arma::mat temp_A3 = arma::mat(n,n);

  temp_A1 = arma::diagmat(d_vec,0);
  temp_A2 = arma::diagmat(a_vec,1);
  temp_A3 = arma::diagmat(a_vec,-1);

  arma::mat A = temp_A1+temp_A2+temp_A3;
  return A;
}

arma::vec analytical_eigenvals(int n, double a, double d){
  arma::vec eigenvalues = arma::vec(n);
  for (int i = 1; i <= n; i++){
    double c = cos(i*M_PI/(n+1));
    eigenvalues[i-1] = d + 2*a*c;
  }
  return eigenvalues;
}

double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  int n = A.n_rows;

  k = 0;
  l = 1;

  if (n==0 || n==1){
    throw std::runtime_error("A is NOT a matrix!");
  }

  double maxval = A(0,1);
  for (int i=0; i<n; i++){
    for (int j=0; j<i; j++){
      if (i != j && fabs(maxval) < fabs(A(i,j))){
        maxval = A(i,j);
        k = i; l = j;
      }
    }
  }
  return maxval;
}

void update_matrix(arma::mat& A, arma::mat& R, int& k, int& l){
  int n = A.n_rows;

  double tau = (A(l,l)-A(k,k))/(2*A(k,l));
  double t;

  if (tau > 0){
    t = -tau + sqrt(1+tau*tau);
  }
  else if (tau == 0){
    t = 1.0;
  }
  else{
    t = -tau - sqrt(1+tau*tau);
  }

  double c = 1/(sqrt(1+t*t));
  double s = c*t;

  double ak = A(k,k)*c*c - 2*A(k,l)*c*s + A(l,l)*s*s;
  double al = A(l,l)*c*c + 2*A(k,l)*c*s + A(k,k)*s*s;

  A(k,k) = ak;
  A(l,l) = al;
  A(k,l) = 0;
  A(l,k) = 0;

  for (int i=0; i<n; i++){
    if (i != k && i != l){
      double aik = A(i,k)*c - A(i,l)*s;
      A(i,l) = A(i,l)*c + A(i,k)*s;
      A(l,i) = A(i,l);
      A(i,k) = aik;
      A(k,i) = A(i,k);
    }
  }

  for (int i=0; i<n; i++){
    double new_rik = R(i,k)*c - R(i,l)*s;
    double new_ril = R(i,l)*c + R(i,k)*s;

    R(i,k) = new_rik;
    R(i,l) = new_ril;
  }

}
