import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

public class Final{
    public static void main(String Args[]){
        try{
            Scanner input = new Scanner(System.in);
            File f = new File("name.txt");
            FileWriter fw = new FileWriter(f, false);
            fw.write("This is vaja class\n");
            fw.write("My name is Jubaer\n");
            fw.write(String.valueOf(12343));
            String arr = input.nextLine();
            fw.write(arr);
            fw.close();
        }
        catch(Exception e){
            System.out.println("File not found");
        }
        try{
            File f = new File ("name.txt");
            Scanner input = new Scanner(f);
            String str = "";
            int res = 0;
            char temp;
            while(input.hasNext()){
                 str = input.nextLine();
                for(int i = 0; i < str.length(); i++){
                    temp = str.charAt(i);
                    
                    if(temp != 0)
                        res++;
                }
                 System.out.println(str);
                }
            System.out.println(res);
            }
        catch (Exception ex){
            System.out.println("File not Found");
        }
        System.out.print(1);
        System.out.println(1);
    }
}
