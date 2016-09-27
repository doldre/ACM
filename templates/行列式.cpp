int sgn(double x)  
{  
    if(fabs(x)<eps) return 0;  
    if(x<0) return -1;  
    else return 1;  
}  
double b[MAXN][MAXN];  
double det(double a[][MAXN],int n)  
{  
    int i,j,k,sign=0;  
    double ret=1;  
    for(i=0;i<n;i++)  
        for(j=0;j<n;j++)  
            b[i][j]=a[i][j];  
    for(i=0;i<n;i++)  
    {  
        if(sgn(b[i][i])==0)  
        {  
            for(j=i+1;j<n;j++)  
                if(sgn(b[j][i])!=0)  
                    break;  
            if(j==n) return 0;  
            for(k=i;k<n;k++)  
                swap(b[i][k],b[j][k]);  
            sign++;  
        }  
        ret*=b[i][i];  
        for(k=i+1;k<n;k++)  
            b[i][k]/=b[i][i];  
        for(j=i+1;j<n;j++)  
            for(k=i+1;k<n;k++)  
                b[j][k]-=b[j][i]*b[i][k];  
    }  
    if(sign&1) ret=-ret;  
    return ret;  
} 
