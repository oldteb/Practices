package lexer;
import java.io.*; import java.util.*; import symbols.*;
public class Lexer {
    String path;
    public static int line = 1;         //line��������ɨ��ĳ�������
    char peek = ' ';                    //peek������ǰ��һ���ַ�
    Hashtable words = new Hashtable();       //words�Ƿ��ű����������������ı������ؼ���
    FileReader fr;
    
    //word����Ϊ�ַ��������Ա�ʾ�������������ؼ���...��ͬ���µ�word.java��
    void reserve(Word w) { words.put(w.lexeme, w); }    

    public Lexer(String str) throws IOException{    //Lexer�Ĺ��캯������ʼ����ʱ���ڷ��ű�words�м���ؼ���
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
    
    
    //������һ���ַ�
    void readch() throws IOException { peek = (char)this.readNextChar(); }
   
    //�鿴��һ���ַ��Ƿ��������ַ���ƥ��...
    boolean readch(char c) throws IOException {
	      readch();
	      if( peek != c ) return false;
	      peek = ' ';
	      return true;
	   }
   //ÿ�ε��÷���һ��ʶ���Token
   public Token scan() throws IOException {
      for( ; ; readch() ) {
         if( peek == ' ' || peek == '\t'|| peek == '\r' ) continue;
         else if( peek == '\n' ) line = line + 1;
         else break;
      }
      //ʶ�������
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
      //ʶ������
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
      	//ʶ��������ؼ���
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
