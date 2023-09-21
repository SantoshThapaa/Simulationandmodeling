#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
    int m,i,N=0,tmp,O[5]={0},E[5],d[4],j,l,k,t;
    float p[5]={0.001,0.504,0.036,0.432,0.027},tmpp,Xo,Xt=9.49;
    char class[5][20]={{"All same"},{"All Different"},{"Three of a kind"},{"One Pair"},{"Two Pairs"}};
    int X[1000];
    FILE *fp;
    fp=fopen("d:\\poker.txt","w");
    if(fp==NULL)
	{
		printf("\nFile could not be created.");
	}

    printf("Read any two seed values:- ");
    scanf("%d %d",&X[0],&X[1]);
    printf("Enter Modulus Operator:- ");
    scanf("%d",&m);
    for(i=2;i<1000;i++)
    {

      X[i]=(X[i-1]+X[i-2])%m;
      while(X[i]<1000)
        {
            X[i+1]=(X[i]+X[i-1])%m;
            X[i]=X[i+1];
        }
        N=N+1;

    }
    for(i=0;i<1000;i++)
    {
    	printf("%5d",X[i]);
        fprintf(fp,"%-5d",X[i]);
	}
	for(i=0;i<5;i++)
	{
		E[i]=1000*p[i];
	}
	for(i=0;i<1000;i++)
	{
		j=0;
		tmp=X[i];
		while(tmp!=0)
		{
			d[j]=tmp%10;
			tmp=tmp/10;
			j=j+1;
		}
		for(k=0;k<4;k++)
		{
			for(l=k+1;l<4;l++)
			{
				if(d[k]>d[l])
				{
					t=d[k];
					d[k]=d[l];
					d[l]=t;
				}
			}
		}
		if(d[0]==d[1]&&d[1]==d[2]&&d[2]==d[3])
			O[0]++;
		else if(d[0]!=d[1]&&d[1]!=d[2]&&d[2]!=d[3])
			O[1]++;
		else if(((d[0]==d[1])&&(d[1]==d[2]))||((d[1]==d[2])&&(d[2]==d[3])))
			O[2]++;
		else if ((d[0]==d[1])&&(d[2]==d[3]))
			O[4]++;
		else
			O[3]++;
	}
	printf("\n\nSN\tClass\t\tO[i]\tE[i]\t((O[i]-E[i])^2)/E[i]\n");
	fprintf(fp,"\n\nSN\tClass\t\tO[i]\tE[i]\t((O[i]-E[i])^2)/E[i]\n");
	for(i=0;i<5;i++)
	{
		tmpp=pow(O[i]-E[i],2);
		tmpp=tmpp/E[i];
		printf("%d\t%-15s\t%d\t%d\t\t%.2f\n",i+1,class[i],O[i],E[i],tmpp);
		fprintf(fp,"%d\t%-15s\t%d\t%d\t\t%.2f\n",i+1,class[i],O[i],E[i],tmpp);
		Xo=Xo+tmpp;
	}
	printf("\n\nXo=%.2f\t\tXt=%.2f",Xo,Xt);
	fprintf(fp,"\n\nXo=%.2f\t\tXt=%.2f",Xo,Xt);
	if(Xo<=Xt)
	{
		printf("\nGenerated numbers are Independent");
		fprintf(fp,"\nGenerated numbers are Independent");
	}

	else
	{
		printf("\nGenerated numbers are not Independent");
		fprintf(fp,"\nGenerated numbers are not Independent");
	}

    fclose(fp);
}

