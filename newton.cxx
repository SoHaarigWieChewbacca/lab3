#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;


int main(){
  int N; 
  ofstream out("output2.dat");
  
  for(double Re=-2.0; Re<=2.0; Re+=0.1) {
    for(double Im=-2.0; Im<=2.0; Im+=0.1) {
      
      N = 0;
      complex<double> z_0 = complex<double>(Re, Im);
      complex<double> z = z_0;
      complex<double> z_n = z - (z*z*z - 1.0)/(3.0*z*z);
      
      while(norm(z_n - z) > 1E-8 && N < 400) {
	z = z_n;
	z_n = z - (z*z*z - 1.0)/(3.0*z*z);
	N++;
      }
      
      out << real(z_0) << "\t" << imag(z_0) << "\t" << N << endl;
    }
  }
  
  out.close();
  

  return 0;
}
















