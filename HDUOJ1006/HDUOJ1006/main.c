//
//  main.c
//  HDUOJ1006
//
//  Created by Kakaro Gu on 2018/9/12.
//  Copyright © 2018年 Kakaro. All rights reserved.
//

/*#include <stdio.h>

float ABS(float x){
    return x>0?x:-x;
}
int main(void) {
    int D;
    while(scanf("%d",&D)!=EOF&&D!=-1)
    {
        float s=0;
        float a=0;
        float b=0;
        float m=0,h=0;
        for(int t=0;t<43200;t++)
        {
            s+=0.6;
            m+=0.0100;
            h+=1/1200;
            if(s>=360)
                s=0;
            if(m>=360)
                m=0;
            if(ABS(s-m)>D&ABS(m-h)>D&ABS(s-h)>D)
            {
                a++;
            }
        }
        b=a/432.0;
        printf("%.3f\n",b);
    }
    return 0;
}
*/
#include<stdio.h>
double max(double a,double b,double c)
{
    return a>b?(a>c?a:c):(b>c?b:c);
}
double min(double a,double b,double c)
{
    return a>b?(b>c?c:b):(a>c?c:a);
}
int main(void)
{
    double sm=10./59,sh=120./719,mh=120./11;
    double D;
   
    
    while(scanf("%lf",&D)!=EOF&&D!=-1)
    {
        double Dsm,Dsh,Dmh,Ssm,Ssh,Smh,Esm,Esh,Emh;
        double happyStart,happyEnd;
         double a=0;
        Dsm=sm*360;
        Dsh=sh*360;
        Dmh=mh*360;
        Ssm=sm*D; Esm=Dsm-sm*D;
        Ssh=sh*D; Esh=Dsh-sh*D;
        Smh=mh*D; Emh=Dmh-mh*D;
        do{
            happyStart=max(Smh,Ssh,Ssm);
            happyEnd=min(Esm,Esh,Emh);
            if(happyEnd>happyStart)
                a+=happyEnd-happyStart;
            if(happyEnd==Esm)
            {
                Esm+=Dsm;
                Ssm+=Dsm;
            }
            if(happyEnd==Esh)
            {
                Esh+=Dsh;
                Ssh+=Dsh;
            }
            if(happyEnd==Emh)
            {
                Emh+=Dmh;
                Smh+=Dmh;
            }
        }while(happyStart<=43200&&happyEnd<=43200);
        printf("%.3lf\n",a/432.0);
    }
    
    return 0;
}
