package inter;

public class Seq extends Stmt {

   Stmt stmt1; Stmt stmt2;

   public Seq(Stmt s1, Stmt s2) { stmt1 = s1; stmt2 = s2; }

   public void gen(int b, int a) {
	   //System.out.println("Seq.gen()");
      if ( stmt1 == Stmt.Null ){
    	  //System.out.println("1");
    	  stmt2.gen(b, a);
    	  }
      else if ( stmt2 == Stmt.Null ) {
    	  //System.out.println("2");
    	  stmt1.gen(b, a);
      }
      else {
    	  //System.out.println("3");
         int label = newlabel();
         stmt1.gen(b,label);
         emitlabel(label);
         stmt2.gen(label,a);
      }
   }
}
