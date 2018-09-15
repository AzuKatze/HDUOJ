//
//  main.c
//  HDUOJ1005
//
//  Created by Kakaro Gu on 2018/9/11.
//  Copyright © 2018年 Kakaro. All rights reserved.
//

#include <stdio.h>

int main(void) {
    int a[3];
    int d[100];
    d[0]=1;
    d[1]=1;
    do
    {
        char b[2]={1,1};
        for(int i=0;i<3;i++)
            scanf("%d",&a[i]);
        for(int j=3;j<49;j++)//由于a[0],a[1]只有7*7=49种组合情况所以49轮之后必定循环
        {
            d[j]=(a[0]*b[1]+a[1]*b[0])%7;
            b[0]=b[1];
            b[1]=d[j];
        }
        if(a[0]||a[1]||a[2])
            printf("%d\n",d[a[2]%49]);
    }while(a[0]||a[1]||a[2]);
    return 0;
}
