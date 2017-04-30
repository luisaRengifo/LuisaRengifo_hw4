plots = fijasCaso1_t0.pdf fijasCaso1_t100.pdf fijasCaso1_t2500.pdf fijasCaso2_t0.pdf fijasCaso2_t100.pdf fijasCaso2_t2500.pdf PromedioFijasCaso1.pdf prom2PromedioFijasCaso2.pdf 

Resultados_hw4.tex $(plots): .txt
	python Plots_Temperatura.py
.txt: a.out
	./a.out
a.out: DifusionTemperatura.c
	cc DifusionTemperatura.c -lm



