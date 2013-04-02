#include <stdio.h>
#include <math.h>

int main(void)
{
	int bitn,nn,n1,n2,l;
	int i;
	int jikken,jikkens;

	double r,v,fsr,sseido,zmax,dmax;

	printf("ビット数 n="); scanf("%d",&bitn);
	printf("電圧 VR="); scanf("%lf",&v);
	printf("抵抗 R[kΩ]="); scanf("%lf",&r);

	printf("実験番号 x-x : "); scanf("%d%d",&jikken,&jikkens);

	nn=1;
	for(i=0;i<bitn;i++)
		nn*=2;

	int b0[nn],b1[nn],b2[nn],b3[nn];
	double ia[nn],it[nn],z[nn],delta[nn];

	if( jikken==1 ){ //実験１
		for(i=0;i<nn;i++){
			b0[i]=(i/4)%2;
			b1[i]=(i/2)%2;
			b2[i]=i%2;
		}
		printf("測定値 I[mA] 入力\n");
		for(i=0;i<nn;i++){
			printf("%d%d%d : ",b0[i],b1[i],b2[i]);
			scanf("%lf",&ia[i]);
		}
		for(i=0;i<nn;i++){
			if( jikkens==1 )
				it[i]=(b0[i] + b1[i]/2.0 + b2[i]/4.0)*(v/r);
			else if( jikkens==2 )
				it[i]=(b0[i]/1.2 + b1[i]/2.0 + b2[i]/4.0)*(v/r);
			else
				it[i]=(b0[i] + b1[i]/2.0 + b2[i]/4.0/1.2)*(v/r);
		}
	}

	else if( jikken==2 ){ //実験２
		for(i=0;i<nn;i++){
			b0[i]=(i/8)%2;
			b1[i]=(i/4)%2;
			b2[i]=(i/2)%2;
			b3[i]=i%2;
		}
		printf("測定値 I[mA] 入力\n");
		for(i=0;i<nn;i++){
			printf("%d%d%d%d : ",b0[i],b1[i],b2[i],b3[i]);
			scanf("%lf",&ia[i]);
		}
		for(i=0;i<nn;i++){
			if( jikkens==1 )
				it[i]=(b0[i] + b1[i]/2.0 + b2[i]/4.0 + b3[i]/8.0)*(v/r);
			else if( jikkens==2 )
				it[i]=(b0[i]/1.1 + b1[i]/2.0 + b2[i]/4.0 + b3[i]/8.0)*(v/r);
			else
				it[i]=(b0[i] + b1[i]/2.0 + b2[i]/4.0 + b3[i]/8.0/1.1)*(v/r);
		}
	}

	else { //実験3
		for(i=0;i<nn;i++){
			b0[i]=(i/8)%2;
			b1[i]=(i/4)%2;
			b2[i]=(i/2)%2;
			b3[i]=i%2;
		}
		printf("測定値 I[mA] 入力\n");
		for(i=0;i<nn;i++){
			printf("%d%d%d%d : ",b0[i],b1[i],b2[i],b3[i]);
			scanf("%lf",&ia[i]);
		}
		for(i=0;i<nn;i++){
			if( jikkens==1 )
				it[i]=(b0[i] + b1[i]/2.0 + b2[i]/4.0 + b3[i]/8.0)*(v/(2*r));
			else if( jikkens==2 )
				it[i]=(b0[i]/1.1 + b1[i]/2.0 + b2[i]/4.0 + b3[i]/8.0)*(v/(2*r));
			else
				it[i]=(b0[i] + b1[i]/2.0 + b2[i]/4.0 + b3[i]/8.0/1.1)*(v/(2*r));
		}
	}

	n1=n2=1;
	for(i=0;i<bitn;i++){
		n1*=2;
		n2*=2;
	}
	n2/=2;
	l=v/(n2*r);
	fsr=l*n1;

	for(i=0;i<nn;i++){
		z[i]=fabs(ia[i]-it[i])/fsr;
		printf("%d%d%d = %f\n",b0[i],b1[i],b2[i],z[i]);
	}
	zmax=z[0];
	for(i=0;i<nn;i++){
		if( zmax<z[i] ) zmax=z[i];
	}
	printf("絶対精度 Max = %f\n",zmax);

	for(i=0;i<nn;i++){
		delta[i]=fabs(ia[i]-it[i]);
	}
	dmax=delta[0];
	for(i=1;i<nn;i++){
		if(dmax<delta[i]) {
			dmax=delta[i];
		}
	}
	sseido=dmax/ia[nn-1];
	printf("相対精度 = %f\n",sseido);


	return 0;
}



