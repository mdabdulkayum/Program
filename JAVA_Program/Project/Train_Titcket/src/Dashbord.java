import java.util.ArrayList;
public class Dashbord {
    int index;
    
   static ArrayList <String> SeatBook = new ArrayList<String>();
   static String[] sBook = new String[0]; 

    Dashbord(){
        
    }
    TrainInfo train = new TrainInfo();
    BuyTitcket buy = new BuyTitcket();
    
    public void userInfo(int id){
        boolean con = true;
        while(con){
            System.out.println("\t1.Show train Scaduel");
            System.out.println("\t2.Buy Titcket");
            System.out.println("\t3.View Booked Titcket");
            System.out.println("\t0.Log out");
            System.out.print("\n\tEnter your choice:");
            Scan_F.Ichoice = Scan_F.scan.nextInt();
            Scan_F.scan.nextLine();
            switch(Scan_F.Ichoice){
                case 1:
                    train.TrainScadule();
                    System.out.print("\tYou want to buy titcket? (Y/N):");
                 
                    Scan_F.Schoice = Scan_F.scan.nextLine();
                    Scan_F.Schoice = Scan_F.Schoice.toUpperCase();
                    if(Scan_F.Schoice.equals("Y")){
                        System.out.print("\tSelect train: ");
                        Scan_F.Ichoice = Scan_F.scan.nextInt();
                        switch(Scan_F.Ichoice){
                            case 1:
                                train.aDtC();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 2:
                                train.aCtD();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 3:
                                train.aDtR();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 4:
                                train.aRtD();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 5:
                                train.aDtRn();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 6:
                                train.aRntD();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 7:
                                train.aDtS();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 8:
                                train.aStD();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 9:
                                train.aDtK();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 10:
                                train.aKtD();
                                System.out.println("\tSelect Seat");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                        }
                    }
                    else if(Scan_F.Schoice.equals("Y")){
                        break;
                    }
                    break;
                
                case 2:
                    train.TrainScadule();
                    System.out.print("Select Train: ");
                    Scan_F.Ichoice = Scan_F.scan.nextInt();
                        switch(Scan_F.Ichoice){
                            case 1:
                                train.aDtC();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(0, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 2:
                                train.aCtD();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(1, "Sonar Bangla Expess");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 3:
                                train.aDtR();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(2, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 4:
                                train.aRtD();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(3, "Padma Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 5:
                                train.aDtRn();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(4, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 6:
                                train.aRntD();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(5, "Rangpur Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 7:
                                train.aDtS();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(6, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 8:
                                train.aStD();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(7, "Jayantika Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 9:
                                train.aDtK();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(8, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                            case 10:
                                train.aKtD();
                                System.out.print("\tSelect Seat: ");
                                Scan_F.Ichoice = Scan_F.scan.nextInt();
                                switch(Scan_F.Ichoice){
                                    case 1:
                                        buy.AC_S(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 2:
                                        buy.F_Seat(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 3:
                                        buy.Snigdha(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    case 4:
                                        buy.Sovon(9, "Sundarban Express");
                                        System.out.println("Seat book successfull.");
                                        break;
                                    default:
                                        System.out.println("Wrong Choice");
                                }
                                break;
                        }
                        break;

                case 3:
                    if(SeatBook==null){
                        System.out.println("No seat booked");
                    }

                    
                    else{
                    System.out.println(SeatBook+"\n");
                    }
                    break;
                case 0:
                    con = false;
                    break;
            }
            
        }
    }
}
