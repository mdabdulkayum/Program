import pandas as pd
from datetime import date
import csv

def menu():
    print("\n\t\t\t1. User\t\t2. Manager")
    c = int(input("\t\t\tEnter Choice: "))
    if c==1:
        user()
    elif c==2:
        pas = input("\n\t\t\tEnter Password: ")
        if pas == "1234":
            manager()
        else:
            menu()
    else:
        print("\n\t\t\tWrong Choice!!\n\t\t\tPlease Enter correctly!!")
        menu()


def user():
    print("\n\n\t\t\t1. View product\t2. Buy\n\t\t\t3. Go to main menu")
    c = int(input("\t\t\tEnter Choice: "))
    if c==1:
        product("user")
    elif c==2:
        buy()
    elif c==3:
        menu()
    else:
        print("\n\t\t\tWrong Choice!!\n\t\t\tPlease Enter correctly!!")
        user()

def buy():
    print("\n\t\t\t\t   ---Choose Product---")
    pid = int(input("\t\t\tProduct ID: "))
    quantity = int(input("\t\t\tEnter Quantity: "))
    name = input("\t\t\tEnter your name: ")
    address = input("\t\t\tEnter your address: ")
    cost = calculate(quantity, pid)
    d = date.today()
    row = [pid,quantity,cost,name,address,d]
    print(f"\n\t\t\tTotal Amount: {cost}")
    print("\t\t\tPay on cash counter!!")

    with open('orderData.csv', 'a+', newline='') as cf:
        cw = csv.writer(cf)
        cw.writerow(row)
    cf.close()
    user()


def calculate(q,pid):
    
    with open('StoreData.csv','r') as cf:
        cw = csv.reader(cf)
        cd = pd.DataFrame(cw)
        for i in cd.index:
            x = list(cd.loc[i])
            if i == pid:
                temp = int(x[1])
                cost = temp * q
        cf.close()
    return cost 


def manager():
    print("\n\t\t\t1. Add Product\t\t2. View Products\n\t\t\t3. Revome Product\t4. Check Orders\n\t\t\t5. Go to main menu")
    c = int(input("\t\t\tEnter Choice: "))

    if c==1:
        add()
    elif c==2:
        product("manager")
    elif c==3:
        remove()
    elif c==4:
        orders()
    elif c==5:
        menu()
    else:
        print("\n\t\t\tWrong Choice!!\n\t\t\tPlease Enter correctly!!")
        manager()

def add():
    print("\n\t\t\t\t---Enter product information---")
    name = input("\n\t\t\tName: ")
    cost = int(input("\t\t\tPrice: "))
    details = input("\t\t\tDetails: ")
    ProductInfo = [name, cost, details]

    with open('StoreData.csv','a',newline='') as cf:
        cw = csv.writer(cf)
        cw.writerow(ProductInfo)
        cf.close()
        manager()

def product(a):
    print("\n\t\t\t\t   ---View Product---")
    with open('StoreData.csv','r') as cf:
        cw = csv.reader(cf)
        cd = pd.DataFrame(cw)
        print("\t\t\t|---------------------------------------|")

        for i in cd.index:
            x = list(cd.loc[i])
            print(f"\t\t\t|  Product ID:{i}")
            print(f"\t\t\t|  Name:{x[0]}")
            print(f"\t\t\t|  Price:{x[1]}")
            print(f"\t\t\t|  Details:{x[2]}")
            print("\t\t\t|---------------------------------------|")
        cf.close()
        if a=="manager":
            manager()
        elif a=="user":
            user()


def remove():
    print("\n\t\t\t\t   ---Remove Product---")
    c = int(input("\n\t\t\tEnter Product ID: "))
 
    with open ('StoreData.csv','r') as cf:
        cw = csv.reader(cf)
        cd = pd.DataFrame(cw)
        cd.drop([c],inplace=True)
        cf.close()
        with open('StoreData.csv','w',newline='') as cf:
            cw = csv.writer(cf)
            for i in cd.index:
                x = list(cd.loc[i])
                cw.writerow(x)
        cf.close()
        manager()

def orders():
    print("\n\t\t\t\t   ---Check Order---")

    with open ('orderData.csv','r') as cf:
        cw = csv.reader(cf)
        cd = pd.DataFrame(cw)
        print("\t\t\t|---------------------------------------|")
        for i in cd.index:
            x = list(cd.loc[i])
            print(f"\t\t\t|  Product ID: {x[0]}")
            print(f"\t\t\t|  Product Quantity: {x[1]}")
            print(f"\t\t\t|  Order Amount : {x[2]}")
            print(f"\t\t\t|  Name: {x[3]}")
            print(f"\t\t\t|  Address: {x[4]}")
            print(f"\t\t\t|  Date: {x[5]}")
            print("\t\t\t|---------------------------------------|")

    manager()

print("\n\n\t\t---------------------------Welcome to Shop---------------------------\n")
menu()