bool prime[MAX];
int pr[MAX];//素数
int eluer[MAX];//欧拉函数
int mu[MAX];//莫比乌斯函数
int tot;
void init(){
    mem(prime,0);tot=0;
    eluer[1]=1,mu[0]=0,mu[1]=1;
    for(int i=2;i<MAX;i++){
        if(!prime[i]){
            pr[tot++]=i;
            eluer[i]=i-1;
            mu[i]=-1;
        }
        for(int j=0;j<tot&&pr[j]*i<MAX;j++){
            prime[pr[j]*i]=1;
            if(i%pr[j]==0){
                eluer[pr[j]*i]=eluer[i]*pr[j];
                mu[pr[j]*i]=0;
                break;
            }
            else{
                eluer[pr[j]*i]=eluer[i]*eluer[pr[j]];
                mu[pr[j]*i]=-mu[i];
            }
        }
    }
}
