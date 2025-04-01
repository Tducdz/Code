
import java.util.Scanner;

class  PhanSo {
    private long tu;
    private long mau;

    public PhanSo() {
    }

    public PhanSo(long tu, long mau) {
        this.tu = tu;
        this.mau = mau;
    }

    public long getTu() {
        return tu;
    }

    public void setTu(long tu) {
        this.tu = tu;
    }

    public long getMau() {
        return mau;
    }

    public void setMau(long mau) {
        this.mau = mau;
    }
    
    public static long ucln(long a, long b) {
        if (b == 0) return a;
        return ucln(b, a % b);
    }
    
    public PhanSo rutgon() {
        long t = ucln(this.tu, this.mau);
        this.tu /= t;
        this.mau /= t;
        return this;
    }
    
    @Override
    public String toString() {
        return tu + "/" + mau;
    }
}
public class J04003 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        PhanSo p = new PhanSo(a, b);
        p.rutgon();
        System.out.println(p);
    }
}
