import java.util.ArrayList;
public class PassengerInfo{
    int i,id;
    int count=1;
    ArrayList <String> UserName = new ArrayList <String>();
    ArrayList <String> UserPhone = new ArrayList<String>();
    ArrayList <String> UserAddress = new ArrayList<String>();
    ArrayList <String> UserGender = new ArrayList<String>();
    ArrayList <Integer> UserId = new ArrayList<Integer>();
    ArrayList <String> UserPass = new ArrayList<String>();

    PassengerInfo(){
        
    }

    TrainInfo trinfo = new TrainInfo();
    Dashbord dasbDashbord = new Dashbord();

    public void UserLogin(){
        System.out.println("\n\t----User Login----");
        if(UserId.size()!=0){
            System.out.print("\n\tEnter ID: ");
            Scan_F.Ichoice = Scan_F.scan.nextInt();
            Scan_F.scan.nextLine();
            for (int x : UserId) {
                if(Scan_F.Ichoice == x){
                    System.out.print("\tEnter Password: ");
                    Scan_F.Schoice = Scan_F.scan.nextLine();
                    for (String y : UserPass) {
                        if(y.equals(Scan_F.Schoice)){
                            System.out.println("Login Successfull.");
                            System.out.println();
                            dasbDashbord.userInfo(x);
                        }
                        else{
                            System.out.println("Incorrect Password");
                        }
                    }
                }
                else{
                    System.out.println("Id Not Found");
                       // UserLogin();
                    }

            }
        }
        else{
            System.out.println("\n\tYou have no account.");
            CreateAcc();
        }
    
    }

    public void CreateAcc(){
        System.out.println("\t----Create Account----");
        if(UserName.size() == 0){
            i=0;
            id = 1000;
        }
        else if(UserName.size() != 0){
            i = UserName.size();
            ++id;
        }

        System.out.println("\tEnter Your Details: ");
        System.out.print("\tName: ");
        UserName.add(i,Scan_F.scan.nextLine());
        System.out.print("\tPhone Number: ");
        UserPhone.add(i,Scan_F.scan.nextLine());
        System.out.print("\tAddress: ");
        UserAddress.add(i,Scan_F.scan.nextLine());
        System.out.print("\tGender: ");
        UserGender.add(i,Scan_F.scan.nextLine());
        UserId.add(id);
        UserPass.add(UserPhone.get(i));
        System.out.println("\tAccount create successfully");

        System.out.println("\tYour ID is: "+UserId.get(i));
        System.out.print("\tYour Password is: "+UserPass.get(i));

        count=1;
        UserLogin();
    }
}
