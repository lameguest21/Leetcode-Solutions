#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Recurrence{
    public:
    // Matrix multiplication
    vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
        int k = A.size();
        vector<vector<ll>> C(k, vector<ll>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                for(int x=0;x<k;x++){
                    C[i][j] += A[i][x]*B[x][i];
                }
            }
        }
        return C;
    }

    //Matrix Power
    vector<vector<ll>> matPower(vector<vector<ll>> A,int n){
        if(n==1) return A;
        if(n&1) return multiply(A,matPower(A,n-1));
        vector<vector<ll>> X = matPower(A,n/2);
        return multiply(X,X);
    }

    //Create transformation matrix
    //isExtra if D is available
    vector<vector<ll>> transMat(vector<ll> C,bool isExtra){
        int k = C.size();
        int size = k;
        if(isExtra) size++;
        vector<vector<ll>> T(size,vector<ll>(size));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i<k-1){
                    if(i+1==j) T[i][j]=1;
                    else T[i][j]=0;
                }else{
                    T[i][j]=C[k-i-1];
                }
            }
        }
        if(isExtra){
            T[k][k] = 1;
            T[k-1][k] = 1;
        }
        return T;
    }

    // Multiply two vecotr and get add result
    int mulMatVec(vector<int> &a, vector<int> &b){
        int k = a.size();
        int res=0;
        for(int i=0;i<k;i++) res+=a[i]*b[i];
        return res;
    }
};


int main() {
    cout<<"Hello World!";
}
