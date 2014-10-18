//
//  main.c
//  Heat_Index
//
//  Created by Kate Polyakova on 10/18/14.
//  Copyright (c) 2014 Kate Polyakova. All rights reserved.
//

#include <stdio.h>
#include <math.h>

float calc_HI (int T, int RH);

int main()

{   //T=84, RH=55
    calc_HI (84, 55);
    
    //T=100, RH=10
    calc_HI (100, 10);
    
    //T=86, RH=90
    calc_HI (86, 90);
    
    //T=81, RH=25
    calc_HI (81, 25);
    
    return 0;
}
    float calc_HI (int T, int RH)

{   float HI;
    float ADJ;
    float Result;
    
    HI = -42.379 + 2.04901523*T + 10.14333127*RH - 0.22475541*T*RH - 0.00683783*T*T - 0.05481717*RH*RH + 0.00122874*T*T*RH + 0.00085282*T*RH*RH - 0.00000199*T*T*RH*RH;
    
    if (HI<80)
    {
        HI = 0.5 * (T + 61.0 + (T-68.0)*1.2 + (RH*0.094));
        Result = HI;
    }
    else
    
    {
        if ((RH < 13) && (80 <= T <= 112))
    
    {   ADJ = ((13.0-RH)/4.0)*sqrt((17.0-fabs(T-95.0))/17.0);
        Result = HI - ADJ;
    }
        
    else if ((RH>85) && (80<=T<=87))
        
        {   ADJ = ((RH-85.0)/10.0) * ((87.0-T)/5.0);
            Result = HI + ADJ;
        }
                    
    else
            {
                Result = HI;
            }
           }
    
    printf ("HI = %f\n\tT = %d\n\tRH = %d\n", Result,T,RH);
    
return Result;}












