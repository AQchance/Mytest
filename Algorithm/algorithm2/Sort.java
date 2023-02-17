public class Sort {
    public void IS(int[] a){
        //insertion sort；stable
        int n=a.length;
        for(int i=0;i<n;i++){
            for(int j=i;j>0&&a[j]<a[j-1];j--){
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    };
    private void merge(int[] aux,int a[],int lo,int mid,int hi){
        int i=lo,j=mid+1;
        for(int k=lo;k<=hi;k++)
            aux[k]=a[k];
        for(int k=lo;k<=hi;k++)
            if(i>mid) a[k]=aux[j++];
            else if(j>hi) a[k]=aux[i++];
            else if(aux[j]<aux[i]) a[k]=aux[j++];
            else a[k]=aux[i++];
    };
    private void msort(int[] aux,int[] a,int lo,int hi){
        if(hi<=lo) return;
        int mid=(lo+hi)/2;
        //System.out.print(lo+ " "+mid+" "+hi+" \n");
        msort(aux,a,lo,mid);
        msort(aux,a,mid+1,hi);
        merge(aux,a,lo,mid,hi);
    };
    public void TDM(int[] a){
        //top-down mergesort；stable
        int aux[]=new int[a.length];
        msort(aux,a,0,a.length-1);
    };
    public void BUM(int[] a){
        //bottom-up mergesort；stable
        int n=a.length;
        int aux[]=new int[a.length];
        for(int sz=1;sz<n;sz=sz+sz)
            for(int lo=0;lo<n-sz;lo+=sz+sz)
                merge(aux,a,lo,lo+sz-1,Math.min(lo+sz+sz-1,n-1));
    };
    private int partition(int[] a,int lo,int hi){
        int i=lo,j=hi+1,v=a[lo];
        while(true){
            while(a[++i]<v) if(i==hi) break;
            while(v<a[--j]);
            if(i>=j) break;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        int t=a[lo];
        a[lo]=a[j];
        a[j]=t;
        return j;
    };
    private void qsort(int[] a,int lo,int hi){
        if(hi<=lo) return;
        int j=partition(a,lo,hi);
        qsort(a,lo,j-1);
        qsort(a,j+1,hi);
    };
    public void RQ(int[] a){
        //random quicksort；not stable
        qsort(a,0,a.length-1);
    };
    private void q3sort(int[] a,int lo,int hi){
        if(hi<=lo) return;
        int lt=lo,i=lo+1,gt=hi;
        int v=a[lo];
        while(i<=gt){
            if(a[i]<v){
                int t=a[i];
                a[i]=a[lt];
                a[lt]=t;

                lt++;
                i++;
            }else if(a[i]>v){
                int t=a[i];
                a[i]=a[gt];
                a[gt]=t;

                gt--;
            }else{
                i++;
            }
        }
        q3sort(a,lo,lt-1);
        q3sort(a,gt+1,hi);
    };
    public void QD3P(int[] a){
        //Quicksort with Dijkstra 3-way Partition；not stable
        q3sort(a,0,a.length-1);
    };

    public void print(double[][] b){

        for(int i=0;i<5;i++){
            switch (i){
                case 0:System.out.print("IS   "); break;
                case 1:System.out.print("TDM  "); break;
                case 2:System.out.print("BUM  "); break;
                case 3:System.out.print("RQ   "); break;
                case 4:System.out.print("QD3P "); break;
            }
            for(int j=0;j<11;j++){
                System.out.printf("%.3f",b[i][j]);
                System.out.print("  ");
            }
            System.out.println("");
        }
    };
    public void print(int[] a){
            for(int j=0;j<a.length;j++){
                System.out.printf(a[j]+" ");
            }
            System.out.println("");
    };
    public void copy(int[] s,int[] d){
        for(int j=0;j<s.length;j++){
            d[j]=s[j];
        }
    };

}

