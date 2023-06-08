import java.util.Scanner;
public class Calculate {
    int course,  student;
    int roll[] = new int[10];
    String name[] = new String[10];
    String dept[] = new String[10];
    String grade[] = new String[10];
    int marks[][] = new int[10][3];
    int Totalmarks[] = new int[10];
    int Avgmarks[] = new int[10];


    public void CalculateTotalMark(){
        Totalmarks[0] = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<3; j++){
                Totalmarks[i]+=marks[i][j];
            }
        }
    }

    public void CalculateAvg(){
        for(int i=0; i<10; i++){
            Avgmarks[i]+=Totalmarks[i]/3;
        }
    }
}

class inputData{
    static Scanner scan = new Scanner(System.in);
}

