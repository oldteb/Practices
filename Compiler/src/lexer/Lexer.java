package lexer;
import java.io.*; import java.util.*; import symbols.*;
public class Lexer {
    String path;
    public static int line = 1;         //line用来计算扫描的程序行数
    char peek = ' ';                    //peek用来向前看一个字符
    Hashtable words = new Hashtable();       //words是符号表用来保存已声明的变量及关键字
    FileReader fr;
    
    //word类型为字符串，用以表示变量或运算符或关键字...在同包下的word.java中
    void reserve(Word w) { words.put(w.lexeme, w); }    

    public Lexer(String str) throws IOException{    //Lexer的构造函数，初始化的时候在符号表words中加入关键字
    	reserve( new Word("if",    Tag.IF)    );
    	reserve( new Word("else",  Tag.ELSE)  );
    	reserve( new Word("while", Tag.WHILE) );
		reserve( new Word("do",    Tag.DO)    );
		reserve( new Word("break", Tag.BREAK) );
		reserve( Word.True );  reserve( Word.False );
		reserve( Type.Int  );  reserve( Type.Char  );
		reserve( Type.Bool );  reserve( Type.Float );
		fr = new FileReader(str);
		//System.out.println((char)fr.read());
		//if(fr==null)
			//System.out.println("ERROR in FileReader()");
    }

    public int readNextChar()throws IOException{
    	//System.out.println("5");
    	//System.out.println((char)fr.read());
    	int i;
    	i=fr.read();
    	//System.out.println((char)i);
    	return i;
    }
    
    
    //读入下一个字符
    void readch() throws IOException { peek = (char)this.readNextChar(); }
   
    //查看下一个字符是否与输入字符相匹配...
    boolean readch(char c) throws IOException {
	      readch();
	      if( peek != c ) return false;
	      peek = ' ';
	      return true;
	   }
   //每次调用返回一个识别的Token
   public Token scan() throws IOException {
      for( ; ; readch() ) {
         if( peek == ' ' || peek == '\t'|| peek == '\r' ) continue;
         else if( peek == '\n' ) line = line + 1;
         else break;
      }
      //识别运算符
      switch( peek ) {
      case '&':
         if( readch('&') ) return Word.and;  else return new Token('&');
      case '|':
         if( readch('|') ) return Word.or;   else return new Token('|');
      case '=':
         if( readch('=') ) return Word.eq;   else return new Token('=');
      case '!':
         if( readch('=') ) return Word.ne;   else return new Token('!');
      case '<':
         if( readch('=') ) return Word.le;   else return new Token('<');
      case '>':
         if( readch('=') ) return Word.ge;   else return new Token('>');
      }
      //识别数字
      if( Character.isDigit(peek) ) {
         int v = 0;
         do {
            v = 10*v + Character.digit(peek, 10); readch();
         } while( Character.isDigit(peek) );
         if( peek != '.' ) return new Num(v);
         float x = v; float d = 10;
         for(;;) {
            readch();
            if( ! Character.isDigit(peek) ) break;
            x = x + Character.digit(peek, 10) / d; d = d*10;
         }
         return new Real(x);
      }
      	//识别变量及关键字
      if( Character.isLetter(peek) ) {
         StringBuffer b = new StringBuffer();
         do {
            b.append(peek); readch();
         } while( Character.isLetterOrDigit(peek) );
         String s = b.toString();
         Word w = (Word)words.get(s);
         if( w != null ) return w;
         w = new Word(s, Tag.ID);
         words.put(s, w);
         return w;
      } 
      Token tok = new Token(peek); peek = ' ';
      return tok;
   }
}
