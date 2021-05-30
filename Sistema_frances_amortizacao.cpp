#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

float calc_FVP(int *n, float *i){
	float resultado;
	*i /= 100;
	*n *= -1;
	resultado = (1 - pow((1 + *i),*n))/ *i;
	return resultado;
}


int main(){
	int num_par,aux1;
	num_par = aux1 = 0;
	float PV, juros, prest, FVP, total_prest,  IOF;
	PV = juros = prest= FVP = total_prest = IOF = 0.0;

	printf("Digite o valor do PV:\n");
	scanf("%f", &PV);
	setbuf(stdin, NULL);
	printf("Digite os juros:\n");
	scanf("%f", &juros);
	setbuf(stdin, NULL);
	printf("Digite o numero de parcelas:\n");
	scanf("%d", &num_par);
	setbuf(stdin, NULL);
	aux1 = num_par;
	
	FVP = calc_FVP(&num_par, &juros);
	printf("FVP = %.6f", FVP);
	
	prest = PV/FVP;
	printf("\nPrestacao = %.2f", prest);
	
	total_prest = prest * aux1;
	printf("\nTotal de prestacoes = %.2f", total_prest);
	
	IOF = total_prest*0.01;
	printf("\nIOF = %.2f", IOF);
	
	
	float saldo_dev[aux1+1], juros_valor[aux1], amort[aux1];
	saldo_dev[0] = PV;
	
	for(int i = 1; i <= aux1; i++){
		juros_valor[i] = saldo_dev[i-1]*juros;
		amort[i] = prest - juros_valor[i];
		saldo_dev[i]= saldo_dev[i-1] - amort[i];
		printf("\n\nPrestacao %d = R$ %.2f , Juros = R$ %.2f, Amortizacao = R$ %.2f, Saldo Devedor = R$ %.2f\n", i, prest, juros_valor[i], amort[i], saldo_dev[i]);	
	}
	
	getch();
}
