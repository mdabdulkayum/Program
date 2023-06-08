public class App {
    public static void main(String[] args) throws Exception {

        PassengerInfo pasinfo = new PassengerInfo();
        AgentInfo agntinfo = new AgentInfo();
        TrainInfo trinfo = new TrainInfo();
        
        System.out.println("\n\t\t------Welcome to Bangladesh Railway------");
        System.out.println();
        trinfo.TrainScadule();
        while(true){
            System.out.print("\n\tTo buy titcket you should be loged in.");
            System.out.println("\n\t1.User Login");
            System.out.println("\t2.Counter Login");
            System.out.println("\t0.Exit");
            System.out.print("\n\tEnter your choice:");
            Scan_F.Ichoice = Scan_F.scan.nextInt();
            Scan_F.scan.nextLine();
            switch(Scan_F.Ichoice){
                case 1:
                    System.out.print("\n\tDo you have account? (Y/N):");
                    Scan_F.Schoice = Scan_F.scan.nextLine();
                    Scan_F.Schoice = Scan_F.Schoice.toUpperCase();
                    switch(Scan_F.Schoice){
                        case "Y":
                            pasinfo.UserLogin();
                            break;
                        case "N":
                            pasinfo.CreateAcc();
                            break;
                        default:
                            System.out.println("Wrong choice");
                            break;
                    }
                    break;
                case 2:
                    System.out.println("\t----Counter Login----");
                    agntinfo.CounterLogin();
                    break;
                case 0:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong choice");
                    break;
            }
        }
    }
}


