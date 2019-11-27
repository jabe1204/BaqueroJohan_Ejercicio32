#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Funcion(double sigma, double d, int nx, int nt, string name);

int main () 
{
	int Nx=30;								
	int Nt=450;
	double D = 1;
	double S=1;	 
	Funcion(S,D,Nx,Nt,"datos.dat");
	return 0;
}

void Funcion(double sigma, double d, int nx, int nt, string name)
{
    ofstream outfile;
    outfile.open(name);
    double dx = 2.0/nx;
	double dt= 1.0/nt;
	double C[nt][nx];
	
    for(int i=0; i<nt-1;i++)
    {
        for(int j =0; j<nx-1;j++)
        {
            if(i ==0 | j==0 | j==nx)
            {
                C[i][j]=0;
            }
            else
            {
                C[i+1][j] = C[i][j] + (d*dt/pow(dx,2))*(C[i][j+1] - 2*C[i][j] + C[i][j-1]) +sigma*dt;
            }
        }
    }
    
    for(int i = 0; i < nt-1; i++)
    {
		for(int j = 0; j < nx-1; j++)
        {
			outfile << C[i][j] << "\t";
		}
		outfile << endl;
	}		
    outfile.close();
}