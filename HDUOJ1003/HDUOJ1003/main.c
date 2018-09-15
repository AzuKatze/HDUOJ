//
//  main.c
//  HDUOJ1003
//
//  Created by Kakaro Gu on 2018/9/8.
//  Copyright © 2018年 Kakaro. All rights reserved.
//
#include <stdio.h>
int main(void) {
    int l;
    scanf("%d",&l);
    for(int line=0;line<l;line++)
    {
        int a=0;
        int sum = 0;
        int m=-1001;
        int start=1,end=1;
        int b=0,s=0,t=0;
        scanf("%d",&a);
        
        for(int i=1;i<=a;i++)
        {
            scanf("%d",&b);
            sum+=b;
            if(sum>m)
            {
                m=sum;
                start=s;
                end=t+s;
            }
            t++;
            if(sum<0)
            {
                sum=0;
                s+=t;
                t=0;
            }
            
        }
        
        printf("Case %d:\n",line+1);
        printf("%d %d %d\n",m,start+1,end+1);
        if(line!=l-1)
            printf("\n");
    }
    return 0;
}
