import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
   // n*n grid
   private int n ; 
   //status of each site
   private boolean[] eachStatus ; 
   //number of open site
   private int openNum;
   //UF alg with virtual site
   private WeightedQuickUnionUF uf1;
   //UF alg with only top site due to backwash
   private WeightedQuickUnionUF uf2;

   // create n-by-n grid, with all sites blocked
   public Percolation(int n){   
    if(n<=0) throw new IllegalArgumentException("illegal value of n!");
    this.n = n;
    //plus two virtual site
    eachStatus = new boolean[(n+1)*(n+2)]; 

    //all sites are blocked
    for(int i=0; i< eachStatus.length;i++) eachStatus[i]=false;
    // grid with top site and bottom site
    uf1 = new WeightedQuickUnionUF((n+1)*(n+2));
    // grid with only bottom site
    uf2 = new WeightedQuickUnionUF((n+1)*(n+2));
   }

   //translate 2 dimentional coordinate to 1 dimentional pattern
   private int oneDimention(int row, int col){
    return row*(n+1)+col;
   }
   // open site (row, col) if it is not open already
   public void open(int row, int col){
    if(row<1 || row>n || col<1 || col>n) throw new IllegalArgumentException("illegal row or col!");
    if(!isOpen(row,col)) {
        eachStatus[oneDimention(row,col)]=true;
        openNum++;
        int temp1 = oneDimention(row,col);
        //if neighbor could be connected?
        if(row==1){
            uf1.union(0,temp1);
            uf2.union(0,temp1);
        }
        if(row==n) { 
            uf1.union((n+1)*(n+1),temp1);
        }
        int[] dx = {1,-1,0,0};
        int[] dy = {0,0,1,-1};
        for(int i=0; i<4;i++){
            int tempX = row+dx[i];
            int tempY = col+dy[i];
            int temp2 = oneDimention(tempX,tempY);
            if (eachStatus[temp2]){
                uf1.union(temp1,temp2);
                uf2.union(temp1,temp2);
             }
            }
    }
   }    

   //is site (row, col) open?
   public boolean isOpen(int row, int col){
       if(row<1 || row>n || col<1 || col>n) throw new IllegalArgumentException("illegal row or col!");
       return eachStatus[oneDimention(row,col)];
   }  

   //is site (row, col) full?
   public boolean isFull(int row, int col){
    if(row<1 || row>n || col<1 || col>n) throw new IllegalArgumentException("illegal row or col!");
    return uf2.connected(0,oneDimention(row,col));
   }

   // number of open sites
   public int numberOfOpenSites() {
    return openNum;
   }

   // does the system percolate?
   public boolean percolates() {
    return uf1.connected(0,(n+1)*(n+1));
   }

   // test client (optional)
   public static void main(String[] args) {
     Percolation p = new Percolation(3);
     p.open(1, 2);
     p.open(2, 2);
     p.open(3, 2);
     StdOut.println(p.isOpen(1,1));
     StdOut.println(p.percolates());
   }

}

