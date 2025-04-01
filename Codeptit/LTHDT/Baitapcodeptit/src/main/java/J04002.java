
import java.util.Scanner;

class Rectange {
    private double w;
    private double h;
    private String color;

    public Rectange() {
        w = 1;
        h = 1;
    }
    
    public Rectange(double w, double h, String color) {
        this.w = w;
        this.h = h;
        this.color = Character.toUpperCase(color.charAt(0)) + color.substring(1).toLowerCase();
    }

    public double getW() {
        return w;
    }

    public void setW(double w) {
        this.w = w;
    }

    public double getH() {
        return h;
    }

    public void setH(double h) {
        this.h = h;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
    
    public double findArea() {
        return w * h;
    }
    
    public double findPerimeter() {
        return 2 * w + 2 * h;
    }
}
public class J04002 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Double x = sc.nextDouble();
        Double y = sc.nextDouble();
        String z = sc.next();
        if (x <= 0 || y <= 0) {
            System.out.println("INVALID");
        } 
        else {
            Rectange p = new Rectange(x, y, z);
            System.out.printf("%d %d %s", (int)p.findPerimeter(), (int)p.findArea(), p.getColor());
        }
    }
}
