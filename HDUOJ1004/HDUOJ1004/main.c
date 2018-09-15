//
//  main.c
//  HDUOJ1004
//
//  Created by Kakaro Gu on 2018/9/10.
//  Copyright © 2018年 Kakaro. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    int l;
    char c[1000][50];
    while(scanf("%d",&l)!=EOF&&l)
    {
        int sum=0,max=-1,answer=0;
        for(int i=0;i<l;i++)
            scanf("%s",c[i]);
        for(int i=0;i<l;i++)
        {
            sum=0;
            for(int j=i+1;j<l;j++)
            {
               
                if(strcmp(c[i],c[j])==0)
                {
                    sum++;
                }
                if(sum>max)
                {
                    max=sum;
                    answer=i;
                }
            }
        }
        printf("%s\n",c[answer]);
    }
    return 0;
}
