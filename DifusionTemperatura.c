#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inicializar(float t_rectangulo, float t_placa, float T[100][100]);
void datos(FILE *out, float T[100][100]);
float mean_t(float T[100][100]);
void FijasCaso1(float v, float alpha, float T[100][100]);
void FijasCaso2(float v, float alpha, float T[100][100]);
//solo realice el analisis con condiciones de frontera fijas pues no entendi bien el funcionamiento de las otras dos
int main()
{
	float v = 0.1; //no se pudo dejar el dado en el enunciado pues no se observan grandes cambios
	float dx = 1.0;
	float dt = 0.2;
	float alpha = dt/(dx*dx);	

	//guardar txt de caso 1 condiciones de frontera fijas	
	int i,j;

	float Temp[100][100];
       	inicializar(100.0, 50.0, Temp);
       
	FILE *fijasCaso1_t0 = fopen("fijasCaso1_t0.txt", "w+");	
	FILE *fijasCaso1_t2500 = fopen("fijasCaso1_t2500.txt", "w+");
	FILE *fijasCaso1_t100 = fopen("fijasCaso1_t100.txt", "w+");
	FILE *fijasCaso1_mean = fopen("fijasCaso1_mean.txt", "w+");

	datos(fijasCaso1_t0, Temp);
	fclose(fijasCaso1_t0);
	
	fprintf(fijasCaso1_mean, "%f %f \n", 0.0, mean_t(Temp)); 
	
	for(i=0; i<(2500/dt);i++)
	{	
		FijasCaso1(v, alpha, Temp);
		
		if(i==(100/dt-1))
		{	
			datos(fijasCaso1_t100, Temp);
		}

		if(i==(2500/dt-1))
		{
			datos(fijasCaso1_t2500, Temp);
		}

		fprintf(fijasCaso1_mean, "%f %f \n", dt*(i+1), mean_t(Temp));	
	}

	fclose(fijasCaso1_t100);
	fclose(fijasCaso1_t2500);
	fclose(fijasCaso1_mean);


	
	//guardar txt de caso 1 condiciones de frontera fijas	

       	inicializar(100.0, 50.0, Temp);
       
	FILE *fijasCaso2_t0 = fopen("fijasCaso2_t0.txt", "w+");	
	FILE *fijasCaso2_t2500 = fopen("fijasCaso2_t2500.txt", "w+");
	FILE *fijasCaso2_t100 = fopen("fijasCaso2_t100.txt", "w+");
	FILE *fijasCaso2_mean = fopen("fijasCaso2_mean.txt", "w+");

	datos(fijasCaso2_t0, Temp);
	fclose(fijasCaso2_t0);
	
	fprintf(fijasCaso2_mean, "%f %f \n", 0.0, mean_t(Temp));
		
	for(i=0; i<(2500/dt);i++)
	{	
		FijasCaso2(v, alpha, Temp);
		
		if(i==(100/dt-1))
		{	
			datos(fijasCaso2_t100, Temp);
		}

		if(i==(2500/dt-1))
		{
			datos(fijasCaso2_t2500, Temp);
		}

		fprintf(fijasCaso2_mean, "%f %f \n", dt*(i+1), mean_t(Temp));	
	}

	fclose(fijasCaso2_t100);
	fclose(fijasCaso2_t2500);
	fclose(fijasCaso2_mean);

	return 0;
        
}

void inicializar(float t_rectangulo, float t_placa, float T[100][100])
{
	int i,j;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			if(i>=20 && i<40 && j>=45 && j<55)
			{
				T[i][j] = t_rectangulo;
			}
			else
			{
				T[i][j] = t_placa;
			}		
		}
	}

}

void datos(FILE *out, float T[100][100])
{
	int i,j;

	for(i=0; i<100; i++)
	{
		for(j=0; j<100; j++)
		{
			fprintf(out, "%f \n", T[i][j]);
		}
	}

}


float mean_t(float T[100][100])
{
	int i,j;
        float mean;
	mean = 0.0;
                                	
	for(i=0; i<100; i++)
	{
		for(j=0; j<100; j++)
		{                                       
			mean+=T[i][j];
		}
	}
	
	return (float)(mean/(100.0*100.0));
	
}

void FijasCaso1(float v, float alpha, float T[100][100])
{	
	int i,j;

	float T_past[100][100];
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			T_past[i][j] = T[i][j];
		}
	}

	for(i=1; i<99; i++)
	{
		for(j=1; j<99; j++)
		{
			T[i][j]= v*alpha*(T_past[i+1][j]+T_past[i-1][j]+T_past[i][j+1]+T_past[i][j-1]-4*T_past[i][j])+T_past[i][j];
		}
		
	}

}

void FijasCaso2(float v, float alpha, float T[100][100])
{
	
	int i,j;                                        
        float T_past[100][100];
        for(i=0;i<100;i++)
        {
        	for(j=0;j<100;j++)
        	{
        		T_past[i][j] = T[i][j];
		}
	}

	for(i=1; i<99; i++)
       	{
        	for(j=1; j<99; j++)
       		{
			if(!(i>=20 && i<40 && j>=45 && j<55))
			{
	    			T[i][j]= v*alpha*(T_past[i+1][j]+T_past[i-1][j]+T_past[i][j+1]+T_past[i][j-1]-4*T_past[i][j])+T_past[i][j];
			}
		}
	}

}


