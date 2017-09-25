import java.util.*;
import java.io.*;

public class js {

    static double w;

    static double eval(double x) {
        return Math.sqrt( Math.pow(Math.sin(x + 2*w) - Math.sin(x + w), 2) + Math.pow(Math.cos(x + 2*w) - (Math.cos(x + w) + 1), 2) + x*x );
    }

    static double gss(double a, double b) {
        double r = (Math.sqrt(5)-1)/2;
        double x1 = b - r*(b-a), x2 = a + r*(b-a);
        double f1 = eval(x1), f2 = eval(x2);
        for (int i = 0; i < 2000; ++i) {
            if (f1 < f2) { //change to > to find maximum
                b = x2; x2 = x1; f2 = f1;
                x1 = b - r*(b-a); f1 = eval(x1);
            } else {
                a = x1; x1 = x2; f1 = f2;
                x2 = a + r*(b-a); f2 = eval(x2);
            }
        }
        return a;
    }

    public static void main(String... args) {
        Kattio io = new Kattio(System.in);

        w = io.getDouble();
        double res = Math.min(
                eval(gss(-2*Math.PI, -Math.PI)),
                eval(gss(-Math.PI, 0)));
        res = Math.min(res,
                eval(gss(0, Math.PI)));
        res = Math.min(res,
                eval(gss(Math.PI, 2*Math.PI)));
        io.printf("%.15f\n", res);
        io.flush();
    }

}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
