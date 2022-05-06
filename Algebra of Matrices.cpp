/*
    	Author: farah alkarrad

        Textbook: Schaum's Outline of Linear Algebra,by Seymour Lipschutz and Marc Lipson,
			 5th Edition, McGraw-Hill,2013

    	Title: chapter 2 - Algebra of matrices
			Power of matrices, inverse, add, mult matrices


*/

#include <bits/stdc++.h>
using namespace std;
void add(int a[][10], int b[][10],int n1,int n2,int m1,int m2){
    if(n1!=n2 && m1!=m2)
        cout<<"\nA + B = \n different order, error addition\n";
    else{
        cout<<"Enter number of matrix (A)\n";
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                cout<<"a"<<i<<j<<" : ";
                cin>>a[i][j];
            }
            cout<<endl;
        }
        cout<<"Enter number of matrix (B)\n";
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                cout<<"b"<<i<<j<<" : ";
                cin>>b[i][j];
            }
            cout<<endl;
        }
        cout<<"\nA + B = ";
        for(int i=0;i<n1;i++){
            cout<<"\n row "<<i<<" = ";
            for(int j=0;j<m1;j++){
                cout<< a[i][j] + b[i][j] << " ";
            }
        }
    }
    cout<<endl;
}

void mult(int a[][10], int b[][10],int n1,int n2,int m1,int m2){
    int mult[n1][m2];
    if(m1!=n2)
        cout<<"\nA * B = \n different order, error multiplication\n";
    else{
        cout<<"Enter number of matrix (A)\n";
        for(int i=0;i<n1;i++)
            for(int j=0;j<m1;j++){
                cout<<"a"<<i<<j<<" : ";
                cin>>a[i][j];
            }

        cout<<"\nEnter number of matrix (B)\n";
        for(int i=0;i<n2;i++)
            for(int j=0;j<m2;j++){
                cout<<"b"<<i<<j<<" : ";
                cin>>b[i][j];
            }

        for(int i = 0; i < n1; ++i)
            for(int j = 0; j < m2; ++j)
            {
                mult[i][j]=0;
            }

        for(int i=0;i<n1;i++)
            for(int j=0;j<m2;j++)
                for(int k=0;k<m1;k++){
                    mult[i][j] += a[i][k] * b[k][j];
                }


        cout<<"\nA * B = "<<endl;
        for(int i=0;i<n1;i++)
            for(int j=0;j<m2;j++){
                cout<<" "<<mult[i][j];
                if(j == m2-1)
                    cout<<endl;
            }

    }
}

void power(int a[][10],int n1,int m1,int p){
    int mult[n1][m1],b[n1][m1];
    cout<<"Enter number of matrix\n";
        for(int i=0;i<n1;i++)
            for(int j=0;j<m1;j++){
                cout<<"a"<<i<<j<<" : ";
                cin>>a[i][j];
            }

        for(int i = 0; i < n1; ++i)
            for(int j = 0; j < m1; ++j)
            {
                b[i][j] = a[i][j];
            }

        for(int w=0;w<p-1;w++){
            for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                    mult[i][j] = 0;
                for(int k=0;k<m1;k++){
                    mult[i][j] += b[i][k] * a[k][j];
                }
            }
            }

            for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                b[i][j] = mult[i][j];
            }
            }
        }
        for(int i = 0; i < n1; ++i){
            for(int j = 0; j < m1; ++j){
                cout <<" "<<mult[i][j];
            }
            cout<<endl;
        }
}

void inverse(){
    int x =0,y=0,a[2][2];
    cout<<"Enter number of matrix\n";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                cout<<"a"<<i<<j<<" : ";
                cin>>a[i][j];
            }
    y = (a[1][1]*a[0][0])-((a[0][1])*(a[1][0]));

    if(y<1){
        cout<<" Inverse matrix - not exist"<<endl;
        return;
    }

    x = 1 / y;
    int g = a[0][0];
    a[0][0] = a[1][1];
    a[1][1] = g;

    a[0][1] *= -1;
    a[1][0] *= -1;

    a[0][0] *= x;
    a[0][1] *= x;
    a[1][0] *= x;
    a[1][1] *= x;

    cout<<a[0][0]<<" "<<a[0][1]<<endl;
    cout<<a[1][0]<<" "<<a[1][1]<<endl;
}

int main(){
    int n1,n2,m1,m2,a[10][10],b[10][10],p,press;
    cout<<" Power of matrices\tPress 1"<<endl;
    cout<<" Inverse\t\tPress 2"<<endl;
    cout<<" Add and mult matrices\tPress 3"<<endl;
    cin>>press;

    if(press == 1){
        cout<<"Enter number of rows and columns for matrix:";
        cin>>n1>>m1;
        cout<<"Enter number of power:\t";
        cin>>p;
        power(a,n1,m1,p);
    }
    else if(press==2)
        inverse();
    else if(press==3){
        cout<<"Enter number of rows and columns for first matrix:\t";
        cin>>n1>>m1;
        cout<<"Enter number of rows and columns for second matrix:\t";
        cin>>n2>>m2;

        add(a,b,n1,n2,m1,m2);
        mult(a,b,n1,n2,m1,m2);
    }

    return 0;
}
