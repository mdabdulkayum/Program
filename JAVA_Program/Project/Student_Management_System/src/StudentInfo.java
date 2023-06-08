public class StudentInfo extends Calculate{


    StudentInfo(){

    }

    public void input(){
            for(int i=0; i<10; i++){
                System.out.println("\tFor student "+(i+1)+": \n");
                System.out.print("\tEnter Roll: ");
                roll[i] = inputData.scan.nextInt();
                inputData.scan.nextLine();
                System.out.print("\tEnter Name: ");
                name[i] = inputData.scan.nextLine();
                System.out.print("\tEnter Department: ");
                dept[i] = inputData.scan.nextLine();

                System.out.println("\n\t\tEnter marks: \n");

                for(int j=0; j<3; j++){
                    System.out.print("\tCourse "+(j+1)+": ");
                    marks[i][j] = inputData.scan.nextInt();
                }
            }
            CalculateTotalMark();
    }

    public void DisplayAvg(){
        CalculateAvg();
        for(int i=0; i<10; i++){
            System.out.println("\n\tRoll: "+roll[i]);
            System.out.println("\n\tName: "+name[i]);
            System.out.println("\n\tDepartment: "+dept[i]);
            System.out.println("\n\tTotal Marks: "+Totalmarks[i]);
            System.out.println("\n\tAvarage marks: "+Avgmarks[i]);
        }
    }

    public void highMark(){
        int high=Totalmarks[0];

        for(int i=1; i<10; i++){
            if(high<Totalmarks[i]){
                high = Totalmarks[i];
            }
        }
        for(int i=0; i<10; i++){
            if(high==Totalmarks[i]){

                System.out.println("\n\tHighest mark:");
                System.out.println("\n\tRoll: "+roll[i]);
                System.out.println("\n\tNam  e: "+name[i]);
                System.out.println("\n\tDepartment: "+dept[i]);
                
                System.out.println("\n\n\tMarks: \n");
                for(int j=0; j<3; j++){
                    System.out.println("\tCourse "+(j+1)+": "+marks[i][j]);
                }
                System.out.println("\n\tTotal Marks: "+Totalmarks[i]);
            }
        }
    }

    public void Display(){
        for(int i=0; i<10; i++){
            System.out.println("\n\tRoll: "+roll[i]);
            System.out.println("\tName: "+name[i]);
            System.out.println("\tDepartment: "+dept[i]);
            
            System.out.println("\n\tMarks: \n");
            for(int j=0; j<3; j++){
                System.out.print("\tCourse "+(j+1)+": "+marks[i][j]+"\n");
            }
            System.out.println("\tTotal marks: "+Totalmarks[i]);
        }
    }

    public void sortByid(){
        int tempr, tempt;
        String tempn, tempd;
        int tempm[] = new int[3];
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                if(roll[i]>roll[j]){
                    tempr = roll[i];
                    roll[i] = roll[j];
                    roll[j] = tempr;

                    tempn = name[i];
                    name[i] = name[j];
                    name[j] = tempn;

                    tempd = dept[i];
                    dept[i] = dept[j];
                    dept[j] = tempd;

                    tempt = Totalmarks[i];
                    Totalmarks[i] = Totalmarks[j];
                    Totalmarks[j] = tempt;

                    for(int k=0; k<3; k++){
                        tempm[k] = marks[i][k];
                        marks[i][k] = marks[j][k];
                        marks[j][k] = tempm[k];
                    }
                }
            }
        }
        System.out.println("\n\tDisplay Student Information sort by roll: ");
        Display();
    }

    public void sortBymark(){
        int tempr, tempt;
        String tempn, tempd;
        int tempm[] = new int[3];
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                if(Totalmarks[i]>Totalmarks[j]){
                    tempt = Totalmarks[i];
                    Totalmarks[i] = Totalmarks[j];
                    Totalmarks[j] = tempt;

                    tempr = roll[i];
                    roll[i] = roll[j];
                    roll[j] = tempr;

                    tempn = name[i];
                    name[i] = name[j];
                    name[j] = tempn;

                    tempd = dept[i];
                    dept[i] = dept[j];
                    dept[j] = tempd;

                    for(int k=0; k<3; k++){
                        tempm[k] = marks[i][k];
                        marks[i][k] = marks[j][k];
                        marks[j][k] = tempm[k];
                    }
                }
            }
        }
        System.out.println("\n\tDisplay Student Information sort by total marks: ");
        Display();

    }

    public void grade(){
        if(Avgmarks[0]==0){
            CalculateAvg();
        }
        else{
            for(int i=0; i<10; i++){
                System.out.println("\n\tRoll: "+roll[i]);
                System.out.println("\tName: "+name[i]);
                System.out.println("\tDepartment: "+dept[i]);
                System.out.println("\tTotal Marks: "+Totalmarks[i]);
                System.out.println("\tAvarage Marks: "+Avgmarks[i]);
                if(Avgmarks[i]>=80 && Avgmarks[i]<=100){
                    grade[i] = "A+";
                }
                else if(Avgmarks[i]>=75 && Avgmarks[i]<=79){
                    grade[i] = "A";
                }
                else if(Avgmarks[i]>=70 && Avgmarks[i]<=74){
                    grade[i] = "A-";
                }
                else if(Avgmarks[i]>=65 && Avgmarks[i]<=69){
                    grade[i] = "B+";
                }
                else if(Avgmarks[i]>=60 && Avgmarks[i]<=64){
                    grade[i] = "B";
                }
                else if(Avgmarks[i]>=55 && Avgmarks[i]<=59){
                    grade[i] = "B-";
                }
                else if(Avgmarks[i]>=50 && Avgmarks[i]<=54){
                    grade[i] = "C+";
                }
                else if(Avgmarks[i]>=45 && Avgmarks[i]<=49){
                    grade[i] = "C";
                }
                else if(Avgmarks[i]>=40 && Avgmarks[i]<=44){
                    grade[i] = "D";
                }
                else if(Avgmarks[i]>=00 && Avgmarks[i]<=39){
                    grade[i] = "F";
                }
                else{
                    System.out.println("Marks out of range.");
                }
                System.out.println("\tGrade: "+grade[i]);
            }
        }
    }

    public void searchStudent(int id){
            for(int i=0; i<10; i++){
                if(id == roll[i]){
                    System.out.println("\n\tRoll: "+roll[i]);
                    System.out.println("\tName: "+name[i]);
                    System.out.println("\tDepartment: "+dept[i]);
                    System.out.println("\tTotal Marks: "+Totalmarks[i]);
                    System.out.println("\tAvarage Marks: "+Avgmarks[i]);
                    System.out.println("\tGrade: "+grade[i]);
                }
        }
    }

    public void faieldCourse(){
        String g=null;
        int count=0;
        for(int i=0; i<10; i++){
            count=0;
            for(int j=0; j<3; j++){
                if(marks[i][j]<40){
                    g = "F";
                    count++;
                }
            }
            if(g!=null){
                System.out.println("\n\tRoll: "+roll[i]);
                System.out.println("\tName: "+name[i]);
                System.out.println("\tDepartment: "+dept[i]);
                System.out.println("\tFaield in "+count+" course");
            }
            g=null;
        }
        if(count==0){
            System.out.println("\n\tNo one faield in any course");
        }

    }

    public void gradeAplus(){
        String g=null;
        int count=0;
        for(int i=0; i<10; i++){
            count=0;
            for(int j=0; j<3; j++){
                if(marks[i][j]>=80 && marks[i][j]<=100){
                    g = "A+";
                    count++;
                }
            }
            if(g!=null){
                System.out.println("\n\tRoll: "+roll[i]);
                System.out.println("\tName: "+name[i]);
                System.out.println("\tDepartment: "+dept[i]);
                System.out.println("\tGot A+ in "+count+" course");
            }
            g=null;
        }
        if(count==0){
            System.out.println("\n\tNo one get A+ in any course");
        }
    }
}