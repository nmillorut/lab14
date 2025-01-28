#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void inputMatrix(double P[][N]){
	for(int i=0;i<N;i++){
		cout<<"Row "<<i+1<<": ";
		for (int j=0; j<N; j++){
			cin>>P[i][j];
		}
	}
}

void findLocalMax(const double Q[][N],bool R[][N]){
	for(int i=0;i<N;i++){
		for (int j=0; j<N; j++){
			if(i==0 || j==0 || i==N-1 || j==N-1){
				R[i][j]=false;
			}else{
				if(Q[i][j]>=Q[i-1][j] && Q[i][j]>=Q[i+1][j] && Q[i][j]>=Q[i][j-1] && Q[i][j]>=Q[i][j+1]){
					R[i][j]=true;
				}else {
                    R[i][j] = false;
                }
			}
		}
	}
}

void showMatrix(const bool B[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}