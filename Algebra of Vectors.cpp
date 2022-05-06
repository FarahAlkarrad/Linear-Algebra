/*
	Author: farah alkarrad

	Textbook: Schaum's Outline of Linear Algebra,by Seymour Lipschutz and Marc Lipson,
			 5th Edition, McGraw-Hill,2013

	Title: chapter 1 - Vectors
		Dot Product, length vector, distance, angle, cross products, parrallel


*/

#include <bits/stdc++.h>
using namespace std;
int Dot_Product(int a[],int b[],int space){
    int mult=0, result=0;
    for(int i=0;i<space;i++){
        mult = a[i] * b[i];
        result = result + mult;
    }
    return result;
}

double Length_Vector(int a[], int space){
    int power=0; double length=0;
    for(int i=0;i<space;i++){
        power += pow(a[i],2);
    }
    length = sqrt(power);
    return length;
}

double Distance(int a[], int b[], int space){
    int sub=0, power=0; double distance=0;
    for(int i=0;i<space;i++){
        sub = a[i] - b[i];
        power += pow(sub,2);
    }
    distance = sqrt(power);
    return distance;
}

double Angle(int a[], int b[], int space){
    int mult_vector=0; double mult_length=0, angle=0;
    mult_vector = Dot_Product(a , b , space);
    mult_length = Length_Vector(a, space) * Length_Vector(b, space);
    angle = mult_vector / mult_length;
    return angle;
}

void Cross_Products(int a[], int b[], int space){
    int result_i, result_j, result_k;
    result_i=((a[1]*b[2])-(a[2]*b[1]));
    result_j=((a[2]*b[0])-(a[0]*b[2]));
    result_k=((a[0]*b[1])-(a[1]*b[0]));
    cout<<"        AxB = ("<<result_i<<","<<result_j<<","<<result_k<<")"<<endl;
}

string Parallel(int a[], int b[], int space){
    //Two vectors a and b are parallel if their cross product is zero, i.e., axb=(0,0,0).
    string check;
    if(((a[1]*b[2])-(a[2]*b[1])) == 0 && ((a[2]*b[0])-(a[0]*b[2])) == 0 && ((a[0]*b[1])-(a[1]*b[0])) == 0)
        return " The vector (A) is parallel to vector (B).";
    return " The vector (A) isn't parallel to vector (B).";
}

int main(){
    int num, space;
    cout<<"Enter a number of space\t";
    cin>>space;
    int a[space], b[space];
    cout<<"\n Enter the elements of (A) vector\t";
    for(int i=0;i<space;i++){
        cin>>a[i];
    }
    cout<<" The length ||A|| = "<<Length_Vector( a, space)<<endl;
    cout<<"--------------------------------------------------"<<endl;

    cout<<"\n Enter the elements of (B) vector\t";
    for(int i=0;i<space;i++){
        cin>>b[i];
    }
    cout<<" The length ||B|| = "<<Length_Vector( b, space)<<endl;
    cout<<"--------------------------------------------------"<<endl;

    cout<<"        A.B = "<< Dot_Product(a,b,space)<< endl;
    Cross_Products(a,b,space);
    cout<<"     d(A,B) = "<<Distance(a,b,space)<<endl;
    cout<<" cos(Angle) = "<<Angle(a,b,space)<<endl;
    cout<<Parallel(a,b,space)<<endl;

    return 0;
}
