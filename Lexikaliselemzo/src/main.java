public class main {
    public static void main(String[] args) {

        String Bemenet = "a(azon{komment}$";
        for (int i = 0; i < Bemenet.length(); i++)
        {System.out.println(Bemenet.charAt(i));}
        states fut = new states(Bemenet);
        fut.state1();
    }
}