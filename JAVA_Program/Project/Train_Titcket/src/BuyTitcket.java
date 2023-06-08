public class BuyTitcket {
    int a=0;

    BuyTitcket(){
    }

    TrainInfo tr = new TrainInfo();

    public void AC_S(int i, String trname){
        int j=0, k=0;
        for(j=0; i<25; i++){
            if(tr.aAc_S[i][j]==null){
                tr.aAc_S[i][j]= "Boocked";
                break;
            }
        }
        String s = "Train: "+trname +" Seat: AC_S- "+(j+1)+": "+tr.aAc_S[i][j];

        for(k=0; k<j; k++){
            if(Dashbord.SeatBook.get(k)==null){
                break;
            }
        }
        Dashbord.SeatBook.add(k,s);
    }

    public void F_Seat(int i, String trname){
        int j=0, k=0;
        for(j=0; i<40; i++){
            if(tr.aF_Seat[i][j] == null){
                tr.aF_Seat[i][j]= "Boocked";
                break;
            }
        }
        String s = "Train: "+trname +" Seat: F_Seat- "+(j+1)+": "+tr.aAc_S[i][j];
        for(k=0; k<j; k++){
            if(Dashbord.SeatBook.get(k)==null){
                break;
            }
        }
        Dashbord.SeatBook.add(k,s);
    }

    public void Snigdha(int i, String trname){
        int j=0, k=0;
        for(j=0; i<40; i++){
            if(tr.aSnigdha[i][j] == null){
                tr.aSnigdha[i][j]= "Boocked";
                break;
            }
        }
        String s = "Train: "+trname +" Seat: Snigdha- "+(j+1)+": "+tr.aAc_S[i][j];
        for(k=0; k<j; k++){
            if(Dashbord.SeatBook.get(k)==null){
                break;
            }
        }
        Dashbord.SeatBook.add(k,s);
    }

    public void Sovon(int i, String trname){
        int j=0, k=0;
        for(j=0; i<50; i++){
            if(tr.aSovon[i][j] == null){
                tr.aSovon[i][j]= "Boocked";
                break;
            }
        }
        String s = "Train: "+trname +" Seat: Sovon- "+(j+1)+": "+tr.aAc_S[i][j];
        for(k=0; k<j; k++){
            if(Dashbord.SeatBook.get(k)==null){
                break;
            }
        }
        Dashbord.SeatBook.add(k,s);
    }


    
}
