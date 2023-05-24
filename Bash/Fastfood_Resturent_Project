#! /bin/bash
function print()
{
  echo
  echo "		  ---- Payment Recept ----"
  echo "  		    --------------------     "
  echo "		     Orderd Item: "$5		# 5 means Orderd Item
  echo "		     Quantity: "$6		# 6 means Quantity
  echo
  echo "		     Total Bill: "$1		# 1 means Total Bill
  echo "	             Given Amount: "$2		# 2 means Given Ammount
  echo "		     Return Amount: "$3		# 3 means Return Ammount
  
  if [[ $4 -eq 1 ]]
  then
  	echo "            Payment Done by Cash. Thank You for your purchase" 
  	
  elif [[ $4 -eq 2 ]]
  then
  	echo "            Payment Done by bKash. Thank You for your purchase" 
  	
  elif [[ $4 -eq 3 ]]
  then
  	echo "            Payment Done by Rocket. Thank You for your purchase" 
  
  fi
}


function payment()
{
  echo									
  echo "            Which way do you want to pay? "
  echo "		1.Cash"
  echo "                2.Bkash"
  echo "                3.Rocket"
  
  echo
  read -p "            Enter your choice: " choice 
                  
  if [[ $choice -eq 1 ]]
  then
  	echo "            Ok sir. Pay your bill by Cash...."
        read -p "            Pay your bill sir: " pay
	ext=$(($pay-$1))
	print "$1" "$pay" "$ext" "1" "$2" "$3"			# 1 means Bill Amount, 2 means Orderd Item, 3 means Quantity


        
   elif [[ $choice -eq 2 ]]
   then
  	echo "            Ok sir. Pay your bill by bKash...."
        read -p "            Pay your bill sir: " pay
	ext=$(($pay-$1))
	print "$1" "$pay" "$ext" "1" "$2" "$3"			# 1 means Bill Amount, 2 means Orderd Item, 3 means Quantity


    elif [[ $choice -eq 3 ]]
    then
  	echo "            Ok sir. Pay your bill by Rocket...."
        read -p "            Pay your bill sir: " pay
	ext=$(($pay-$1))
	print "$1" "$pay" "$ext" "1" "$2" "$3"			# 1 means Bill Amount, 2 means Orderd Item, 3 means Quantity

        
    else
    	echo "--- Wrong Choice ---"
    	payment "$1" "$2" "$3"
    	
    fi

}

echo
echo

echo "----------- ' Welcome to Parizat Fastfood Corner ' ------------"

while true
do
	echo
	echo
	echo "			Items list:		             "
	echo "          	  ======================     		     "
	echo "     			 1.Burger"
	echo "              		 2.Pizza"
	echo "   		         3.Pasta"
	echo "     			 4.Drinks"
	echo "     			 5.Exit"
	echo
	read -p "            Whice item do you want to purches: " choice
	if [[ $choice -eq 1 ]]
	then 
		echo
		echo '		     Price list of Burger: '
		echo
		echo '		1.Vegatable Burger ----- 50tk'
		echo '		2.Regular Burger   ----- 70tk'
		echo '		3.Chicken Burger   ----- 100tk'
		echo '		4.Beef Burger      ----- 180tk'
		echo
		read -p "            Select: " select

		if [[ $select -eq 1 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*50))
			echo "            Bill: $bill"
			payment "$bill" "Vegatable Burger" "$quantity"
			
		elif [[ $select -eq 2 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*70))
			echo "            Bill: $bill"
			payment "$bill" "Regular Burger" "$quantity"
	  	elif [[ $select -eq 3 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*100))
			echo "            Bill: $bill"
			payment "$bill" "Chicken Burger" "$quantity"
		elif [[ $select -eq 4 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*180))
			echo "            Bill: $bill"
			payment "$bill" "Beef Burger" "$quantity"
		else 
			echo
			echo "            	--- Wrong Choice ---"
			echo
		  
		fi
	elif [[ $choice -eq 2 ]]
	then  
		echo
		echo "		     Price list of Pizza: "
		echo
		echo "		1.BBQ Chicken(8')           ----- 250tk"
		echo "		2.Veggia Mexicana(12')      ----- 369tk"
		echo "		3.Spicy Chicken(8')         ----- 239tk"
		echo "		4.Chef Special Pizza(12')   ----- 350tk"
		
		echo
		read -p "            Select: " select

		if [[ $select -eq 1 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*250))
			echo "            Bill: $bill"
			payment "$bill" "BBQ Chicken(8')" "$quantity"
			
		elif [[ $select -eq 2 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*369))
			echo "            Bill: $bill"
			payment "$bill" "Veggia Mexicana(12')" "$quantity"
			
	  	elif [[ $select -eq 3 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*239))
			echo "            Bill: $bill"
			payment "$bill" "Spicy Chicken(8')" "$quantity"
			
		elif [[ $select -eq 4 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*350))
			echo "            Bill: $bill"
			payment "$bill" "Chef Special Pizza(12')" "$quantity"
			
		else 
			echo
			echo "            	--- Wrong Choice ---"
			echo
		  
		fi
		
	elif [[ $choice -eq 3 ]]
	then 
		echo
		echo "		     Price list of Pasta: "
		echo
		echo "		1.Oven Baked Spicy Chicken  ----- 323tk"
		echo "		2.Creamy Oven Baked Chicken ----- 429tk"
		echo "		3.Spicy Chicken Sausage     ----- 399tk"
		echo "		4.Chef Special Pasta        ----- 500tk"
		
		echo
		read -p "            Select: " select

		if [[ $select -eq 1 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*323))
			echo "            Bill: $bill"
			payment "$bill" "Oven Baked Spicy Chicken" "$quantity"
			
		elif [[ $select -eq 2 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*429))
			echo "            Bill: $bill"
			payment "$bill" "Creamy Oven Baked Chicken" "$quantity"
			
	  	elif [[ $select -eq 3 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*399))
			echo "            Bill: $bill"
			payment "$bill" "Spicy Chicken Sausage" "$quantity"
			
		elif [[ $select -eq 4 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*500))
			echo "            Bill: $bill"
			payment "$bill" "Chef Special Pasta" "$quantity"
		else 
			echo
			echo "            	--- Wrong Choice ---"
			echo
		  
		fi
	elif [[ $choice -eq 4 ]]
	then 
		echo
		echo "		     Price list of Drinks: "
		echo
		echo "		1.Normal Water(500ml) ----- 25tk"
		echo "		2.Pepsi(250ml)        ----- 25tk"
		echo "		3.Sprite(250ml)       ----- 25tk"
		echo "		4.Cocacola(250ml)     ----- 25tk"
		echo "		5.Lacci(regular)      ----- 80tk"
		echo "		6.Mango Juice         ----- 100tk"
		echo "		7.Pineapple Juice     ----- 120tk"
		
		echo
		read -p "            Select: " select

		if [[ $select -eq 1 ]] || [[ $select -eq 2 ]] || [[ $select -eq 3 ]] || [[ $select -eq 4 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*25))
			echo "            Bill: $bill"
			payment "$bill" "Drinks" "$quantity"
			
		elif [[ $select -eq 5 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*80))
			echo "            Bill: $bill"
			payment "$bill" "Lacci(regular)" "$quantity"
			
	  	elif [[ $select -eq 6 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*100))
			echo "            Bill: $bill"
			payment "$bill" "Mango Juice" "$quantity"
			
		elif [[ $select -eq 7 ]]
		then
		    	read -p "            Quantity: " quantity
			bill=$((quantity*120))
			echo "            Bill: $bill"
			payment "$bill" "Pineapple Juice" "$quantity"
			
		else 
			echo "            --- Wrong Choice ---"
		  
		fi
	elif [[ $choice -eq 5 ]]
	then
		exit
	else
		echo
		echo "            	--- Wrong Choice ---"
		echo	

	fi

 

done

