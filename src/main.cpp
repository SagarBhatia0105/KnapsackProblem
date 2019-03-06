#include <iostream>
#include <fstream>

using namespace std;

int max(int x, int y){
  if(x>y)

    return x;

  else

    return y;
}

int KnapSack(int W, int *values, int *weights, int n){

  int **K = new int*[n+1];

  for(int i = 0; i<n+1; i++){
    K[i] = new int[W+1];
  }

  for(int i = 0; i<=n; i++){
    for(int j = 0; j<=W; j++){
      if(i == 0 || j == 0){
        K[i][j] = 0;
      }
      else if(weights[i-1] <= j){
        K[i][j] = max(values[i-1] + K[i-1][j-weights[i-1]], K[i-1][j]);
      }
      else if(weights[i-1] > W){
        K[i][j] = K[i-1][j];
      }
      //cout<<"K= "<<K[i][j]<<endl;
    }
  }

  return K[n][W];
}

int main(int argc, char const *argv[]) {

  //no of items
  int n;
  //capacity of the knapsack
  int W;

  int *values;
  int *weights;

  values = new int[n];
  weights = new int[n];

  fstream input(argv[1]);

  input>>n;
  input>>W;

  for(int i = 0; i<n; i++){
    input>>values[i];
    input>>weights[i];
  }

  cout<<"Final value of the knapsack is "<<KnapSack(W, values, weights, n)<<endl;

  input.close();
  return 0;
}
