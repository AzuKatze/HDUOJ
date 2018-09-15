//
//  main.c
//  HDUOJ1009
//
//  Created by Kakaro Gu on 2018/9/14.
//  Copyright © 2018年 Kakaro. All rights reserved.
//

#include <stdio.h>
/*void swap(double a,double b)
{
    double temp;
    temp=a;
    a=b;
    b=temp;
}*/

int main(void) {
    
    
    int sum,line;
    
    while(scanf("%d %d",&sum,&line)!=EOF&&sum+line!=-2)
    {
        double b[1001]={0};
        double a[1001][2]={0};
        double answer=0;
        double temp;
        for(int i=0;i<line;i++)
        {
            scanf("%lf %lf",&a[i][0],&a[i][1]);
        }
        for(int i=0;i<line;i++)
        {
            b[i]=a[i][0]/a[i][1];
            if(a[i][1]==0)
                b[i]=0;
        }
        for(int i=0;i<line-1;i++)
        {
            for(int j=0;j<line-i-1;j++)
            {
                if(b[j]<b[j+1])
                {
                    
                    temp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = temp;
                    temp = a[j][0];
                    a[j][0] = a[j + 1][0];
                    a[j + 1][0] = temp;
                    temp = a[j][1];
                    a[j][1] = a[j + 1][1];
                    a[j + 1][1] = temp;//swap(b[j],b[j+1]);
                   // swap(a[j][1],a[j+1][1]);
                   // swap(a[j][0],a[j+1][0]);
                }
            }
        }
        for(int i=0;i<line;i++)
        {
            if(sum>a[i][1])
            {
                answer+=a[i][1]*b[i];
                sum=sum-a[i][1];
                continue;
            }
            if(a[i][1]==0)
            {
                answer+=a[i][0];
                continue;
            }
            if(sum<=a[i][1]&&sum>0)
            {
                answer+=sum*b[i];
                sum=0;
                continue;
            
            }
        }
        printf("%.3lf\n",answer);
    }
    return 0;
}
//AC!!!
