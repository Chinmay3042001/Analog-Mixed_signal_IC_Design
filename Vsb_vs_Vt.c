#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double threshold_voltage(double substrate_voltage){
    
    double gamma,V_t0,phi_f,Vt;
    gamma = 0.82;
    V_t0 = 0.4;
    phi_f = 0.35;
    Vt = V_t0 + gamma*(sqrt(2*phi_f + substrate_voltage) - sqrt(2*phi_f));
    
    return Vt;
}

int main(){
    int simulation_resolution,i;
    double V_sb = 0.0;
    double step;
    double V_t;
    FILE *vt = fopen("vt_vs_vsb.txt","w");
    printf("Please enter the resolution you would like to run the simulation at");
    scanf("%d",&simulation_resolution);
    step = 5/(float)simulation_resolution;
    for(i = 0; i < simulation_resolution; i++){
        V_t = threshold_voltage(V_sb);
        V_sb += step;
        fprintf(vt,"%lf\t%lf\n",V_sb,V_t);
    } 
    fclose(vt);

    return 0;
}