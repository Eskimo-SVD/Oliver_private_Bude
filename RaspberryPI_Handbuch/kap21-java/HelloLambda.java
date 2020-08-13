// Datei HelloLambda.java
import java.util.*;

public class HelloLambda {
  public static void main(String[] args) {
    List<String> lst = 
      Arrays.asList("Hello ", "Lambda-", "World!\n");
    lst.forEach( s->System.out.print(s) );
  }
}
                                                            