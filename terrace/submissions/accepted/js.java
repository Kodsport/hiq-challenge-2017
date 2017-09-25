import java.util.*;
import java.io.*;

public class js {
    public static void main(String... args) {
        Kattio io = new Kattio(System.in);

        int limit = io.getInt(),
            events = io.getInt();
        int count = 0;
        int res = 0;
        for (int i = 0; i < events; i++) {
            String ev = io.getWord();
            int p = io.getInt();
            if (ev.equals("enter")) {
                if (count + p > limit) {
                    res++;
                } else {
                    count += p;
                }
            } else {
                count -= p;
            }
        }
        io.println(res);
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
