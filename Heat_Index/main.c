//
//  main.c
//  Heat_Index
//
//  Created by Kate Polyakova on 10/18/14.
//  Copyright (c) 2014 Kate Polyakova. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void calc_HI ();

    int T;
    int RH;

int main()

{   T=84;
    RH=55;
    calc_HI ();
    
    T=100;
    RH=10;
    calc_HI ();
    
    T=86;
    RH=90;
    calc_HI ();
    
    T=81;
    RH=25;
    calc_HI ();
    
    return 0;
}

    void calc_HI ()

{   float HI;
    float ADJ;
    
    HI = -42.379 + 2.04901523*T + 10.14333127*RH - 0.22475541*T*RH - 0.00683783*T*T - 0.05481717*RH*RH + 0.00122874*T*T*RH + 0.00085282*T*RH*RH - 0.00000199*T*T*RH*RH;
    
    if (HI<80)
    {
        HI = 0.5 * (T + 61.0 + (T-68.0)*1.2 + (RH*0.094));
        printf ("HI = %f\n", HI);
        printf ("\tT = %d\n\tRH = %d\n", T, RH);
        
    }
    else
    
    {
        if ((RH < 13) && (80 <= T <= 112))
    
    {   ADJ = ((13-RH)/4)*sqrt((17-fabs(T-95.0))/17);
        
        printf ("HI = %f\n", HI-ADJ);
        printf ("\tT = %d\n\tRH = %d\n", T, RH);    }
    
    
    else if ((RH>85) && (80<=T<=87))
        
        {   ADJ = ((RH-85)/10) * ((87-T)/5);
        
            printf ("HI = %f\n", HI+ADJ);
            printf ("\tT = %d\n\tRH = %d\n", T, RH);    }
                    
    else
            {   printf ("HI = %f\n", HI);
                printf ("\tT = %d\n\tRH = %d\n", T, RH); }
    }
                                          
}