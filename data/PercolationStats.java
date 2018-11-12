import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    //trial times
    private int trialNum;
    //threshold P
    private double[] preP;
    public PercolationStats(int n,int trialNum) {
        if (n<1 || trialNum<1) throw new IllegalArgumentException("Illegal n or trialNum,please check");
        this.trialNum = trialNum;
        preP = new double[trialNum];
        for(int i=0;i<trialNum;i++) {
            Percolation p = new Percolation(n);
            while(!p.percolates()) {
                int row = StdRandom.uniform(n)+1;
                int col = StdRandom.uniform(n)+1;
                p.open(row,col);
                if (p.percolates()) break;
            }
            preP[i] = (double)p.numberOfOpenSites()/(n*n);
        }
    }

    // mean of p
    public double mean() {
        return StdStats.mean(preP);
    }

    // standard deviation
    public double stddev() {
        return StdStats.stddev(preP);
    }

    //confidence interval:low
    public double confidenceLo() {
        return mean()-1.96*stddev()/Math.sqrt(trialNum);
    }

    //confidence interval:high
    public double confidenceHi() {
        return mean()+1.96*stddev()/Math.sqrt(trialNum);
    }

    public static void main(String[] args) {
        int n =10,trialNum=1000;
        PercolationStats ps = new PercolationStats(n,trialNum);
        StdOut.println("grid size :" + n+"*"+n);
        StdOut.println("trial times :" + trialNum);
        StdOut.println("mean of p :"+ ps.mean());
        StdOut.println("standard deviation :"+ps.stddev());
        StdOut.println("confidence interval low :"+ps.confidenceLo());
        StdOut.println("confidence interval high :"+ps.confidenceHi());
    }


}
