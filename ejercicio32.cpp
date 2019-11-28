#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void eq_onda(double C, int nx, int nt, string name);

double tmax = 0.1;
double L = 1;
double T  =40;
double rho = 0.01;
double c = sqrt(T/rho);
double dt = 0.0001;
double dx = 0.01;
double cprima = dx/dt;
int Nx = L/dx;								
int Nt = tmax/dt;

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
    for(int i=0; i<=nx; i++)
    {
        /*Condiciones iniciales*/
        x=i*dx;
        M[0][i]=(1E-4)*sin(2*M_PI*x/L);
    }
    
    for(int i = 1 ; i < nx; i++)
    {
        /*Relleno del primer salto dt*/
        M[1][i]=M[0][i] + 0.5*((c*c)/(cprima*cprima))*(M[0][i+1] +M[0][i-1]-2*M[0][i]);
	}
    
        for(int i=1 ;i < nt; i++)
        {
            for(int j = 1; j < nx; j++)
            {
                M[i+1][j] = 2*M[i][j] - M[i-1][j] + ((c*c)/(cprima*cprima))*(M[i][j+1] +M[i][j-1]-2*M[i][j]);
            }  
        }
    
    /*Imprime los datos en un archivo .dat*/
    for(int i = 0; i<nt;i++)
    {
        for(int j = 0; j<nx;j++)
        {
            outfile<<M[i][j]<<"\t";
        }
        outfile<<endl;
    }
    outfile.close();
}
