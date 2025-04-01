
import java.util.Scanner;

class Point {
    private double x;
    private double y;
    
    public Point() {
        this(0f, 0f);
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Point(Point p) {
        this.x = p.x;
        this.y = p.y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }
    
    public double distance(Point p) {
        return Math.sqrt(Math.pow(this.x - p.x, 2) + Math.pow(this.y - p.y, 2));
    }
    
    public double distance(Point p1, Point p2) {
        return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
    }
    
    @Override
    public String toString() {
        return x + " " + y;
    }
}
public class J04008 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Point p1 = new Point(sc.nextDouble(), sc.nextDouble());
            Point p2 = new Point(sc.nextDouble(), sc.nextDouble());
            Point p3 = new Point(sc.nextDouble(), sc.nextDouble());
            double c1 = p1.distance(p2);
            double c2 = p1.distance(p3);
            double c3 = p2.distance(p3);
            double cv = c1 + c2 + c3;
            if (c1 + c2 <= c3 || c1 + c3 <= c2 || c2 + c3 <= c1) {
                System.out.println("INVALID");
            }
            else {
                System.out.printf("%.3f", cv);
            }
        }
    }
}
