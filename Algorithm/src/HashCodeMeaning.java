import java.util.ArrayList;
import java.util.Random;



public class HashCodeMeaning {
    public static void main(String[] args) {
        ArrayList list =  new ArrayList();
        int numberExist=0;
        Random rand = new Random();

        //֤��hashcode��ֵ�����ڴ��ַ
        for (int i = 0; i < 10000; i++) {
            //Integer n = new Integer(rand.nextInt(10000));
            Object obj = new Object();
            if (list.contains(obj.toString())) {
                System.out.println(obj.toString() +"  exists in the list. "+ i);
                numberExist++;
            }
            else {
                list.add(obj.toString());
            }
        }
        
        System.out.println("repetition number:"+numberExist);
        System.out.println("list size:"+list.size());
        
//        //֤���ڴ��ַ�ǲ�ͬ�ġ�
//        numberExist=0;
//        list.clear();
//        for (int i = 0; i < 10000; i++) {
//            Object obj=new Object();
//            if (list.contains(obj)) {
//                System.out.println(obj +"  exists in the list. "+ i);
//                numberExist++;
//            }
//            else {
//                list.add(obj);
//            }
//        }
        
//        System.out.println("repetition number:"+numberExist);
//        System.out.println("list size:"+list.size());
    }
}