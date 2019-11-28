#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void eq_onda(double C, int nx, int nt, string name);

double c = 0.5;
double tf = 6.0;
double L = 1;
double dt = 0.01;
double dx = 0.01;
double cp = dx/dt;
int Nx=L/dx;								
int Nt=tf/dt;

int main () 
{
    
    
	eq_onda(c,Nx,Nt,"datos.dat");
	return 0;
}

void eq_onda(double C, int nx, int nt, string name)
{
    ofstream outfile;
    outfile.open(name);
    
	double M[nt+1][nx+1];
	double x;
    double t;
    for(int i=0; i<nx;i++)
    {
        x=i*dx;
        M[0][i]=sin(M_PI*x/L);
    }
    
    for(int i = 0 ; i < nx; i++)
    {
        M[1][i]=M[0][i] + 0.5*pow(c/cp,2)*(M[0][i+1] +M[0][i-1]-2*M[0][i]);
	}
    
    t+=dt;
    
    while(t<tf)
    {
        for(int i=2 ;i < nx; i++)
        {
            for(int j = 0; j < nt; j++)
            {
                M[i][j] = M[i][j]=M[i][j] + 0.5*pow(c/cp,2)*(M[i][j+1] +M[i][j-1]-2*M[i][j]);
				M[i+1][j] = 2*M[i][j] - M[i][j-1] + pow(c/cp,2)*(M[i][j+1] +M[i][j-1]-2*M[i][j]);
            }  
        }
        t+=dt;
    }
    
    for(int i = 0; i<nx;i++)
    {
        for(int j = 0; j<nt;j++)
        {
            outfile<<M[i][j]<<"\t";
        }
        outfile<<endl;
    }
    outfile.close();
}
