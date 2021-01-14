#include<iostream>
#include<iomanip>
using namespace std;

void filling(int (&mas)[20][20]){
  
  mas[0][0] = 1;
  for(int i = 0;i < 20;i++){
    for(int j = 0;j <= i;j++){
      if(i == j || j == 0) mas[i][j] = 1;
      else mas[i][j] = mas[i - 1][j - 1] + mas[i - 1][j];
    }
  }  
}

int kol(int &one,int &two,int &thr,int &thor){
  int sum = 5;
  
  if(one < 10) sum += 1;
  else if(one < 100) sum += 2;
  else if(one < 1000) sum += 3;
  
  if(two < 10) sum += 1;
  else if(two < 100) sum += 2;
  else if(two < 1000) sum += 3;
  
  if(thr < 10) sum += 1;
  else if(thr < 100) sum += 2;
  else if(thr < 1000) sum += 3;
  
  if(thor < 10) sum += 1;
  else if(thor < 100) sum += 2;
  else if(thor < 1000) sum += 3;
  else if(thor < 10000) sum += 4;
  
  return sum;
}

int main(){
  int Pascals_triangle[20][20];
    
  filling(Pascals_triangle);

  int white,black,red;
  
  cout << "Skilki znahoditsa: \n";
  
  cout << "WHITE: ";
  cin >> white;
  cout << "BLACK: ";
  cin >> black;
  cout << "RED: ";
  cin >> red;  
  
  cout << "\nSkilki sposobov: ";
  
  int sposobov;
  cin >> sposobov;
  
  int whiteU,blackU,redU;
  
  cout << "\nUslovie dla: \n";
  
  cout << "WHITE: ";
  cin >> whiteU;
  cout << "BLACK: ";
  cin >> blackU;
  cout << "RED: ";
  cin >> redU;
  
  cout << "\n\nTABLICHKA: ";
  
  cout << endl << " --------------------------------------------------" << endl << "|" << setw(5) << "W" << setw(5) << "|" << setw(5) << "B" << setw(5) << "|" << setw(5) << "R" << setw(5) << "|" ;
  cout << setw(10) << "K" << setw(11) << "|" ;
  
  int otvet = 0;
  
  for(int w = 0;w <= white;w++){
    for(int b = 0;b <= black;b++){
      for(int r = 0;r <= red;r++){
        if(w >= whiteU && b >= blackU && r >= redU && (w + b + r == sposobov)){
          cout << endl << " --------------------------------------------------" << endl << "|" << setw(5) << w << setw(5) << "|" << setw(5) << b << setw(5) << "|" << setw(5) << r << setw(5) << "|" ;
          int temp = Pascals_triangle[white][w] * Pascals_triangle[black][b] * Pascals_triangle[red][r];
          cout << setw(5) << Pascals_triangle[white][w] << "*" << Pascals_triangle[black][b] << "*" << Pascals_triangle[red][r] << " = " << temp << setw(17 - kol(Pascals_triangle[white][w],Pascals_triangle[black][b],Pascals_triangle[red][r],temp)) << "|";
          otvet += temp;
        }
      }
    }
  }
  
  cout << endl << " --------------------------------------------------" << endl;
  cout << "\n\nOTVET: " << otvet;
  return 0;
}
