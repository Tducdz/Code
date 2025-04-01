
import java.util.Scanner;

class GV {
    private String ma, hoten;
    private int lcb, bac, phucap, thunhap;
    
    public GV() {
        
    }

    public GV(String ma, String hoten, int lcb) {
        this.ma = ma;
        this.hoten = hoten;
        this.lcb = lcb;
        this.bac = Integer.parseInt(ma.substring(2));
        
        String chucvu = ma.substring(0, 2);
        if (chucvu.equals("HT")) {
            phucap = 2000000;
        }
        else {
            if (chucvu.equals("HP")) {
                phucap = 900000;
            }
            else {
                phucap = 500000;
            }
        }
        this.thunhap = lcb * bac + phucap;
    }

    public String getMa() {
        return ma;
    }

    public void setMa(String ma) {
        this.ma = ma;
    }

    public String getHoten() {
        return hoten;
    }

    public void setHoten(String hoten) {
        this.hoten = hoten;
    }

    public int getLcb() {
        return lcb;
    }

    public void setLcb(int lcb) {
        this.lcb = lcb;
    }
    
    @Override
    public String toString() {
        return ma + " " + hoten + " " + bac + " " + phucap + " " + thunhap;
    }
}
public class J04015 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        GV gv = new GV(sc.nextLine(), sc.nextLine(), sc.nextInt());
        System.out.println(gv);
    }
}
