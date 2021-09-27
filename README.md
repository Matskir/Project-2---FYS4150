# Project-2---FYS4150

new_proj2.hpp is the main header file for this project and includes all needed functions, and is imported into every C++ program. 

new_proj2_3.cpp uses create_tridiagonal() to create a 6x6 matrix, then finding its eigenvalues using armadillo and compares them to the analytical eigenvalues. The program should be run in the following way:

g++ new_proj2_3.cpp -o new_proj2_3.exe -larmadillo

./new_proj2_3.exe


new_proj2_4.cpp uses max_offdiag_symmetric() to find the maximum off-diagonal element of an example matrix, and should be run in the following way:

g++ new_proj2_4.cpp -o new_proj2_4.exe -larmadillo

./new_proj2_4.exe

new_proj2_5.cpp implements the Jacobi rotation algorithm to solve our differential equation, and saves the A and R matrices, as well as the analytical eigenvalues and eigenvectors from armadillo. These .bin files are needed to run the Python script in proj2_7.py, but are also included in the repo. The program should be run in the following way:

g++ new_proj2_5.cpp -o new_proj2_5.exe -larmadillo

./new_proj2_5.exe

plot_data.py plots the data of the number of required transformations for different values of N, and should be run in the following way:

python plot_data.py

proj2_7.py plots the eigenvectors corresponding to the three lowest eigenvalues and compares them to the analytical eigenvalues, and should be run in the following way:
python proj2_7.py
