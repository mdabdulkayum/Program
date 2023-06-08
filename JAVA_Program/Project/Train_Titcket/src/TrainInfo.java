import java.util.ArrayList;

public class TrainInfo {
    int a,b;
    ArrayList <String> TrainName = new ArrayList <String>();
    ArrayList <Integer> RoadNo = new ArrayList <Integer>();
    ArrayList <String> TrainTime = new ArrayList <String>();
    ArrayList <String> TrainDestination = new ArrayList <String>();

    int fAc_S[] = {786, 786, 680, 680, 1010, 1010, 640, 640, 1005, 1005};
    int fF_Seat[] = {705, 705, 620, 620, 920, 920, 690, 690, 910, 910};
    int fSnigdha[] = {650, 650, 570, 570, 840, 840, 530, 530, 840, 840};
    int fSovon[] = {550, 550, 470, 470, 740, 740, 430, 430, 730, 730};
    String aAc_S[][] = new String[10][25];
    String aF_Seat[][] = new String[10][40];
    String aSnigdha[][] = new String[10][40];
    String aSovon[][] = new String[10][50];

    public void trainDetailes(){
        TrainName.add(0,"Sonar Bangla Express");
        RoadNo.add(0,101);
        TrainDestination.add(0,"Dhaka To Chittagong");
        TrainTime.add(0,"06:30AM");
        TrainName.add(1,"Sonar Bangla Express");
        RoadNo.add(1,102);
        TrainDestination.add(1,"Chittagong To Dhaka");
        TrainTime.add(1,"04:30PM");

        TrainName.add(2,"Padma Express");
        RoadNo.add(2,103);
        TrainDestination.add(2,"Dhaka To Rajshahi");
        TrainTime.add(2,"05:30AM");
        TrainName.add(3,"Padma Express");
        RoadNo.add(3,104);
        TrainDestination.add(3,"Rajshahi To Dhaka");
        TrainTime.add(3,"04:30PM");

        TrainName.add(4,"Rangpur Express");
        RoadNo.add(4,105);
        TrainDestination.add(4,"Dhaka To Rangpur");
        TrainTime.add(4,"04:30AM");
        TrainName.add(5,"Rangpur Express");
        RoadNo.add(5,106);
        TrainDestination.add(5,"Rangpur To Dhaka");
        TrainTime.add(5,"04:30PM");

        TrainName.add(6,"Jayantika Express");
        RoadNo.add(6,107);
        TrainDestination.add(6,"Dhaka To Sylhet");
        TrainTime.add(6,"09:00AM");
        TrainName.add(7,"Jayantika Express");
        RoadNo.add(7,108);
        TrainDestination.add(7,"Sylhet To Dhaka");
        TrainTime.add(7,"07:30PM");

        TrainName.add(8,"Sundarban Express");
        RoadNo.add(8,109);
        TrainDestination.add(8,"Dhaka To Khulna");
        TrainTime.add(8,"04:00AM");
        TrainName.add(9,"Sundarban Express");
        RoadNo.add(9,110);
        TrainDestination.add(9,"Khulna To Dhaka");
        TrainTime.add(9,"05:30PM");

    }

    public void TrainScadule(){

           trainDetailes();

        System.out.println("\t\t----Train Scadule----");
        for(int i=0; i<10; i++){
            System.out.println("\t"+(i+1)+"."+TrainName.get(i));
            System.out.println("\t\tRoad No: "+RoadNo.get(i));
            System.out.println("\t\tTrain Destination: "+TrainDestination.get(i));
            System.out.println("\t\tDepature Time: "+TrainTime.get(i));
            System.out.println();
        }
    }

    public void aDtC(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[0][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[0]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[0][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[0]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[0][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[0]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[0][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[0]+"Tk");
    }

    public void aCtD(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[1][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[1]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[1][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[1]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[1][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[1]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[1][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[1]+"Tk");
    }

    public void aDtR(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[2][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[0]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[2][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[0]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[2][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[0]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[2][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[2]+"Tk");
    }

    public void aRtD(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[3][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[3]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[3][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[3]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[3][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[3]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[3][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[3]+"Tk");
    }

    public void aDtRn(){
        a=0;
        System.out.println("\t----Available seat----");
        for(int i=0; i<25; i++){
            if(aAc_S[4][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[4]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[4][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[4]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[4][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[4]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[4][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[4]+"Tk");
    }

    public void aRntD(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[5][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[5]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[5][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[5]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[5][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[5]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[5][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[5]+"Tk");
    }

    public void aDtS(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[6][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[6]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[6][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[6]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[6][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[6]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[6][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[6]+"Tk");
    }

    public void aStD(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[7][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[7]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[7][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[7]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[7][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[7]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[7][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[7]+"Tk");
    }
    
    public void aDtK(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[8][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[8]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[8][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[8]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[8][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[8]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[8][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[8]+"Tk");
    }

    public void aKtD(){
        System.out.println("\t----Available seat----");
        a=0;
        for(int i=0; i<25; i++){
            if(aAc_S[9][i] == null){
                a++;
            }
        }
        System.out.println("\t1. AC_S: "+a+"\tFare: "+fAc_S[9]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aF_Seat[9][i] == null){
                a++;
            }
        }
        System.out.println("\t2. F_Seat: "+a+"\tFare: "+fF_Seat[9]+"Tk");
        a=0;
        for(int i=0; i<40; i++){
            if(aSnigdha[9][i] == null){
                a++;
            }
        }
        System.out.println("\t3. Snigdha: "+a+"\tFare: "+fSnigdha[9]+"Tk");
        a=0;
        for(int i=0; i<50; i++){
            if(aSovon[9][i] == null){
                a++;
            }
        }
        System.out.println("\t4. Sovon: "+a+"\tFare: "+fSovon[9]+"Tk");
    }
}
