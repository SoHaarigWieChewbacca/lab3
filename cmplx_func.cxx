#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;

complex<double> calculate_tan(double phi_b);


int main(){

  int N = 100;
  complex<double> arr_a[N+1];
  complex<double> arr_b[N+1];
  
  
  double phi_a[N+1];
  double phi_b[N+1];
  complex<double> z_a;

  
  // Aufgabe a)
  for(int i=0; i<=N; i++) {
    phi_a[i] = i*2*M_PI/N;
    z_a = complex<double>(cos(phi_a[i]), sin(phi_a[i]));
    arr_a[i] = z_a;
  }
  
  ofstream out_a("output_a.dat");
  
  for(int i=0; i<=N; i++) {
    out_a << phi_a[i] << "\t" << real(arr_a[i]) << "\t" << imag(arr_a[i]) << "\t" << norm(arr_a[i]) << endl;
  }
  
  out_a.close();
  
  
  // Aufgabe b)
  for(int i=0; i<=N; i++) {
    phi_b[i] = i*2*M_PI/N - M_PI;
    arr_b[i] = calculate_tan(phi_b[i]);
  }
  
  ofstream out_b("output_b.dat");
  
  for(int i=0; i<=N; i++) {
    out_b << phi_b[i] << "\t" << real(arr_b[i]) << "\t" << imag(arr_b[i]) << "\t" << norm(arr_b[i]) << endl;
  }
  
  out_b.close();
  
  return 0;
}




complex<double> calculate_tan(double phi_b) {
  complex<double> c = complex<double>(1.0, 1.0);
  complex<double> z_b;
  z_b = tan(phi_b*c);
  
  return z_b;
}