import static java.lang.Character.isDigit;
import static java.lang.Character.isLetter;

public class states {
    static String Bemenet;
    static int stateindex;

    states(String s){
        Bemenet = s;
        stateindex = 0;}

    void read()   {stateindex++;}
    void backup() {stateindex--;}

    void state1()
    {
        System.out.println("kezdoallapot");
        if(stateindex == Bemenet.length()-1)
            return;
        read();
        if(isDigit(Bemenet.charAt(stateindex))){
            state4();}
        else if(isLetter(Bemenet.charAt(stateindex))){
            state2();}
        else{
            switch (Bemenet.charAt(stateindex)){
                case'{':{
                    state6();
                    break;}

                case'}':{
                    state19();
                    break;}

                case'(':{
                    state8();
                    break;}

                case'*':{
                    state19();
                    break;}

                case')':{
                    state19();
                    break;}

                case':':{
                    state12();
                    break;}

                case'=':{
                    state19();
                    break;}

                case'<':{
                    state14();
                    break;}

                case'>':{
                    state17();
                    break;}

                case' ':{
                    state1();
                    break;}

                case'$':{
                    state21();
                    break;}
                default:state19();
            }
        }
    }

    void state2()
    {
        System.out.println("azonosito");
        read();
        if(isDigit(Bemenet.charAt(stateindex))){
            state2();}

        else if(isLetter(Bemenet.charAt(stateindex))){
            state2();}

        else{
            state3();}
    }
    void state3()
    {System.out.println("azonosito vege");
        backup();
        state1();}

    void state4()
    {
        System.out.println("szam");
        read();
        if(isDigit(Bemenet.charAt(stateindex))){           //Ha szám
            state5();
        }
        else if(isLetter(Bemenet.charAt(stateindex))){     //Ha betű
            state4();
        }
        else
        {
            state5();
        }
    }
    void state5()
    {System.out.println("szam vege");
        backup();
        state1();}

    void state6()
    {
        System.out.println("komment");
        read();
        if(Bemenet.charAt(stateindex) == '}'){
            state7();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state6();
        }
    }
    void state7()
    {System.out.println("komment vege");
        state1();}

    void state8()
    {
        System.out.println("(");
        read();
        if(Bemenet.charAt(stateindex) == '*'){
            state9();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state20();
        }

    }
    void state9()
    {
        System.out.println("**");
        read();
        if(Bemenet.charAt(stateindex) == '*'){
            state10();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state9();
        }
    }
    void state10()
    {
        System.out.println("* (**)");
        read();
        if(Bemenet.charAt(stateindex) == '*'){
            state10();
        }
        else if(Bemenet.charAt(stateindex) == ':'){
            state11();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state9();
        }
    }
    void state11()
    {System.out.println("(**) komment vege");
        state1();}

    void state12()
    {
        System.out.println(":");
        read();
        if(Bemenet.charAt(stateindex) == '='){
            state13();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state20();
        }
    }
    void state13()
    {System.out.println(":=");
        state1();}

    void state14()
    {
        System.out.println("<");
        read();
        if(Bemenet.charAt(stateindex) == '='){
            state15();
        }
        else if(Bemenet.charAt(stateindex) == '>'){
            state16();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state20();
        }
    }
    void state15()
    {System.out.println("<=");
        state1();}

    void state16()
    {System.out.println("<>");
        state1();}

    void state17()
    {
        System.out.println(">");
        read();
        if(Bemenet.charAt(stateindex) == '='){
            state18();
        }
        else if (Bemenet.charAt(stateindex) == '$'){
            state19();
        }
        else{
            state20();
        }
    }
    void state18()
    {System.out.println("<=");
        state1();}

    void state19()
    {System.out.println("Hiba"+Bemenet.charAt(stateindex));
        state1();}

    void state20()
    {   backup();
        state1();}
    void state21()

    {System.out.println("Kész");}
}