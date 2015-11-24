#include <cmath>
// #include <iostream> // debug
#include <fstream>
#include <cstdlib>

using namespace std;

int fLength(const string& fname){
  ifstream file(fname.c_str(), ios::binary | ios::ate);
  return (int)(file.tellg()/8.0 + 1); // Rueckgabe der Dateilaenge
  // Teilen durch 8 fuer Bytelaenge, Aufrunden per +1 um alles abzudecken
}

void reading(double* const p, const int N, const string& fname){
  // Lesefunktion aus der Vorlesung - ohne Spaltensprung
  ifstream in(fname.c_str()); // create input file stream
  for (int i = 0; i < N; i++){
    in >> p[i];
    }
    in.close(); // close input file stream
}

void dreiMitt(double* const p, const int N, int Anz){
  double bu1,bu2 = p[0]; // Puffer
  
  for(int k = 0; k < Anz; k++){
    for(int i = 1; i < (N-1); i++){
      bu1 = p[i];
      p[i] = (bu2+p[i]+p[i+1])/3.0;
      bu2 = bu1;
    }
    // Randwert links
    p[0] = p[1];
    // Randwert rechts
    p[N-1] = p[0];
  }
}

void Fwrite(double* const p, const int N, string fname){
  ofstream out("filtered.txt");
  for(int i=0; i < N; i++){
    out << p[i] << endl;
  }
  out.close();
}


int main(){
  const string filename = "noisy.txt";
  const int N = fLength(filename); // bestimme die Dateilaenge von noisy.txt
  double p[N]; // Array fester Groesse, das spaeter die Werte sammelt
  
  // cout << N << endl; // debug
  
  reading(p, N, filename); // Datei einlesen und in p schreiben
  dreiMitt(p, N, 2); // fortlaufende Mittelwerte bestimmen und in p schreiben in 2facher Filterung
  
  // Dateiausgabe
  Fwrite(p, N, "filtered.txt"); // Ausgabe in filtered.txt
  
  return 0;
}