import java.util.ArrayList;

public class AgentInfo {
    int i,id;
    int count=1;

    ArrayList <String> AgentName= new ArrayList <String>();
    ArrayList <String> AgentPhone = new ArrayList<String>();
    ArrayList <String> AgentAddress = new ArrayList<String>();
    ArrayList <Integer> AgentId = new ArrayList<Integer>();
    ArrayList <String> AgentPass = new ArrayList<String>();

    AgentInfo (){
        
    }

    public void CounterLogin(){
        CreateAcc();

        System.out.println("\n\t----Counter Login----");
        if(AgentId.size()!=0){
            System.out.print("\n\tEnter ID: ");
            for (int x : AgentId) {
                if(Scan_F.scan.nextInt() == x){
                    Scan_F.scan.nextLine();
                    System.out.print("\tEnter Password: ");
                    for (String y : AgentPass) {
                        if(y.equals(Scan_F.scan.nextLine())){
                            System.out.println("Login Successfull.");

                        }
                        else{
                            System.out.println("Incorrect Password");
                            CounterLogin();
                        }
                    }
                }
                else{
                    System.out.println("Id Not Found");
                    if(count!=3){
                        count++;
                        
                    }
                    else{
                        Scan_F.scan.nextLine();
                        CreateAcc();
                    }
                }
            }
        }
        else{
            System.out.println("\n\tYou have no account.");
            CreateAcc();
        }     
    }

    public void CreateAcc(){
        AgentName.add(0,"Md Kamal");
        AgentPhone.add(0,"01700000000");
        AgentAddress.add(0,"Dhaka");
        AgentId.add(0,501);
        AgentPass.add(0,"Kamal501");

        AgentName.add(1,"Md Rofiq");
        AgentPhone.add(1,"01711111111");
        AgentAddress.add(1,"Chittagong");
        AgentId.add(1,502);
        AgentPass.add(1,"Rofiq502");

        AgentName.add(1,"Md Jakir");
        AgentPhone.add(1,"01722222222");
        AgentAddress.add(1,"Rajshahi");
        AgentId.add(1,503);
        AgentPass.add(1,"Jakir503");

        AgentName.add(1,"Md Karim");
        AgentPhone.add(1,"01733333333");
        AgentAddress.add(1,"Rangpur");
        AgentId.add(1,504);
        AgentPass.add(1,"Karim504");

        AgentName.add(1,"Md Sofiq");
        AgentPhone.add(1,"01744444444");
        AgentAddress.add(1,"Sylhet");
        AgentId.add(1,505);
        AgentPass.add(1,"Sofiq505");

        AgentName.add(1,"Md Barkat");
        AgentPhone.add(1,"01755555555");
        AgentAddress.add(1,"Khulna");
        AgentId.add(1,506);
        AgentPass.add(1,"Barkat506");
    }

}
