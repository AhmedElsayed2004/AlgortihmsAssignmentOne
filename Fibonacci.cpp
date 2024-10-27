#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;


//Recursive Fibonacci Series
long long recFib(int n){
    if(n==0 or n ==1 ){
        return n;
    }else if(n==2){
        return 1;

    }
    else{
        return recFib(n-1)+ recFib(n-2);
    }
}
//Recursive dp Fibonacci Series
long long fib[N];
long long dpFib(int n){
    if(n==0 or n ==1 ){
        return fib[n]= n;
    }
    else if(n==2){
        return fib[n]= 1;
    }
    else if(!fib[n]){
        return fib[n]=recFib(n-1)+ recFib(n-2);
    }
    return fib[n];

}
//Itriative dp Fibonacci Series
long long IFib[N];
long long ItriativeFib(int n){
    IFib[1]=1;
    IFib[2]=1;
    int i = 3;
    for(;i<=n;i++){
        IFib[i]=IFib[i-1]+IFib[i-2];
    }
    return IFib[n];

}
const int MOD = 1e9+7;
const int k = 3;
vector<vector<int>> matrixMutliplication(vector<vector<int>> A,vector<vector<int>> B){
    vector<vector<int>> C (k,vector<int>(k));
    for(int i = 1 ; i<k ;i++){
        for(int j = 1 ; j<k ;j++){
            for(int q = 1 ; q<k ;q++){
                C[i][j] = (C[i][j] +A[i][q] * B[q][j])%MOD;
            }
        }

    }
    return C;
}
vector<vector<int>> matrixPower(vector<vector<int>> A,long long pow){
    if(pow == 1){
        return A;
    }
    if(pow&1){
        return matrixMutliplication(A,matrixPower(A,pow-1));
    }
    vector<vector<int>> X = matrixPower(A,pow/2);
    return matrixMutliplication(X,X);
    //T(n)=T(n/2)+1 =>o(logn);
}
long long Fibonacci(long long n){
    vector<vector<int>> T(k,vector<int>(k));
    T[1][1]=0;T[1][2]=1;
    T[2][1]=1;T[2][2]=1;
    if(n==1 or  n == 0 ){
        return n;
    }else{
        int answer{};
        T = matrixPower(T,n-1);
        for(int i =1 ; i<k ; i++){
           answer+= T[1][i];
        }
        return answer;
    }
}

//int main() {
//    cout<<"Recursive Fibonacci Series:\n";
//    cout<<recFib(0)<<"\n";
//    cout<<recFib(1)<<"\n";
//    cout<<recFib(2)<<"\n";
//    cout<<recFib(3)<<"\n";
//    cout<<recFib(4)<<"\n";
//    cout<<recFib(5)<<"\n";
//    cout<<"Recursive dp Fibonacci Series:\n";
//    cout<<dpFib(0)<<"\n";
//    cout<<dpFib(1)<<"\n";
//    cout<<dpFib(2)<<"\n";
//    cout<<dpFib(3)<<"\n";
//    cout<<dpFib(4)<<"\n";
//    cout<<dpFib(5)<<"\n";
//    cout<<"Iterative dp Fibonacci Series:\n";
//    cout<<ItriativeFib(0)<<"\n";
//    cout<<ItriativeFib(1)<<"\n";
//    cout<<ItriativeFib(2)<<"\n";
//    cout<<ItriativeFib(3)<<"\n";
//    cout<<ItriativeFib(4)<<"\n";
//    cout<<ItriativeFib(5)<<"\n";
//    cout<<"Matrix Fibonacci Series:\n";
//    cout<<Fibonacci(0)<<"\n";
//    cout<<Fibonacci(1)<<"\n";
//    cout<<Fibonacci(2)<<"\n";
//    cout<<Fibonacci(3)<<"\n";
//    cout<<Fibonacci(4)<<"\n";
//    cout<<Fibonacci(5)<<"\n";
//    cout<<Fibonacci(6)<<"\n";
//    cout<<Fibonacci(7)<<"\n";
//    cout<<Fibonacci(8)<<"\n";
//    cout<<Fibonacci(9)<<"\n";
//    cout<<Fibonacci(20)<<"\n";
//
//}
