public class App {
    public static void main(String[] args){

            StudentInfo stdinfo = new StudentInfo();

            System.out.println("\n\tEnter Student Information: ");
            stdinfo.input();

            while(true){
                System.out.println("\n\t\tMenu");
                System.out.println("\t1.Find Avarage Marks.");
                System.out.println("\t2.Find Highest Marks.");
                System.out.println("\t3.Sort the students in order of ID.");
                System.out.println("\t4.Sort the students in order of marks.");
                System.out.println("\t5.Display the student list with grade.");
                System.out.println("\t6.Search a student by ROLL.");
                System.out.println("\t7.Display the information who failed in any course.");
                System.out.println("\t8.Display the information who obtained grade A+ in any course.");
                System.out.println("\t0.Exit");

                    
                System.out.print("Enter your choice: ");
                switch(inputData.scan.nextInt()){
    
                    case 1:
                        stdinfo.DisplayAvg();
                        break;
                    case 2:
                        stdinfo.highMark();
                        break;
                    case 3:
                        stdinfo.sortByid();
                        break;
                    case 4:
                        stdinfo.sortBymark();
                        break;
                    case 5:
                        stdinfo.grade();
                        break;
                    case 6:
                        System.out.println("\n\tSearch Student");
                        System.out.print("Enter Roll: ");
                        int id = inputData.scan.nextInt();
                        stdinfo.searchStudent(id);
                        break;
                    case 7:
                        System.out.println("\n\tFaield in course");
                        stdinfo.faieldCourse();
                        break;
                    case 8:
                        System.out.println("\n\tGot A+ in course");
                        stdinfo.gradeAplus();
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

