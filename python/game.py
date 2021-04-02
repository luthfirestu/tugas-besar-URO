def kecoak(x,y,x_kecoak,y_kecoak) :
    for k in range (20) :
        if x==x_kecoak[k] and y==y_kecoak[k] :
            return True

def papan():
    for i in range (21,-1,-1):
        if i == 0 :
            for j in range (22) :
                if j == 0 :
                    print(end="   ")
                elif j<11 :
                    print ("", j-1 , end=" ")
                else :
                    print (j-1 , end=" ")
        else :
            for j in range (22):
                if j == 0 :
                    if i < 11 :
                        print("", i-1 , end=" ")
                    else :
                        print(i-1, end=" ")
                else :
                    if x_robot==j-1 and y_robot==i-1 :
                        print(" R ", end="")
                    elif kecoak(j-1,i-1,x_kecoak,y_kecoak)==True :
                        print(" K ", end="")
                    else :
                        print(" _ ", end="")
        print()

def cekkecoak(x,y,x_kecoak,y_kecoak) :
    salah = 0
    for i in range (20) :
        if x==x_kecoak[i] or y==y_kecoak[i] :
            salah = salah + 1
    if salah > 0 :
        return False
    else :
        return True

def kecoak_baru(x,y,x_kecoak,y_kecoak) :
    import random
    if cekkecoak(-1,-1,x_kecoak,y_kecoak) == False :
        x = random.randrange(0, 20)
        y = random.randrange(0, 20)
        while not(x!=x_robot and y!=y_robot and cekkecoak(x,y,x_kecoak,y_kecoak) == True) :
            x = random.randrange(0, 20)
            y = random.randrange(0, 20)
    for i in range (20) :
        if x_kecoak[i]==-1 or y_kecoak[i]==-1 :
            urut = i
            break
    x_kecoak[urut] = x
    y_kecoak[urut] = y
    health_kecoak[urut] = 100
    print("Muncul kecoak", urut+1, "("+ str(x)+", "+str(y)+")")
def pindah(x_robot,y_robot,x_kecoak,y_kecoak) :
    if x_robot != 0 and x_robot != 20 :
        print("A : kiri")
        print("D : kanan")
    elif x_robot != 0 :
        print("A : kiri")
    elif x_robot != 20 :
        print("D : kanan")
    if y_robot != 0 and y_robot != 20 :
        print("W : maju")
        print("S : mundur")
    elif y_robot != 0 :
        print("S : mundur")
    elif y_robot != 20 :
        print("W : maju")
    n = input()
    if n=="W":
        y_robot=y_robot + 1
        salah = 0
        for i in range (20) :
            if y_robot==y_kecoak[i] and x_robot==x_kecoak and (health_kecoak[i]!=0 or health_kecoak[i]!=-1) :
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot
    elif n=="A":
        x_robot=x_robot - 1
        salah = 0
        for i in range (20) :
            if y_robot==y_kecoak[i] and x_robot==x_kecoak and (health_kecoak[i]!=0 or health_kecoak[i]!=-1) :   
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot
    elif n=="S":
        y_robot=y_robot - 1
        salah = 0
        for i in range (20) :
            if y_robot==y_kecoak[i] and x_robot==x_kecoak and (health_kecoak[i]!=0 or health_kecoak[i]!=-1) :
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot
    elif n=="D":
        x_robot=x_robot + 1
        salah = 0
        for i in range (20) :
            if y_robot==y_kecoak[i] and x_robot==x_kecoak and (health_kecoak[i]!=0 or health_kecoak[i]!=-1) :
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot

def tembak(x_robot,y_robot,x_kecoak,y_kecoak,health_kecoak,att) :
    jarak = 5
    print("Pilih arah tembak")
    print("I : depan")
    print("J : kiri")
    print("K : belakang")
    print("L : kanan")
    n = input()
    if n=="I":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if (y_kecoak[i] >= y_robot + 1 and y_kecoak[i] <= y_robot + jarak) and (x_kecoak[i]==x_robot) :
                health_kecoak[i] = health_kecoak[i] - att
                benar = benar + 1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")
    elif n=="J":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if (x_kecoak[i] >= x_robot - 1 and x_kecoak[i] <= x_robot - jarak) and (y_kecoak[i]==y_robot):
                health_kecoak[i] = health_kecoak[i] - att
                benar = benar +1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")
    elif n=="K":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if (y_kecoak[i] >= y_robot - 1 and y_kecoak[i] <= y_robot - jarak) and (x_kecoak[i]==x_robot) :
                health_kecoak[i] = health_kecoak[i] - att
                benar = benar + 1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")
    elif n=="L":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if (x_kecoak[i] >= x_robot + 1 and x_kecoak[i] <= x_robot + jarak) and (y_kecoak[i]==y_robot) :
                health_kecoak[i] = health_kecoak[i] - att
                benar = benar + 1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")

def robot(health, att) :
    print("Health robotmu =", health)    

def kecoakmati(health_kecoak) :
    mati = 0
    for i in range (20) :
        if health_kecoak[i] == 0 :
            mati = mati +1
    return mati
def serangankecoak(x_robot, y_robot, x_kecoak, y_kecoak, health_kecoak, health_robot):
    kecoak = 0
    for i in range (20):
        if x_kecoak[i]!=-1 and y_kecoak[i]!=-1 :
            if ((x_robot<=(x_kecoak[i]+11) and x_robot>=(x_kecoak[i]+1)) or (x_robot>=x_kecoak[i]-11 and x_robot<=x_kecoak[i]-1)) and (y_robot==y_kecoak[i]) and (health_kecoak[i]>0) :
                kecoak = kecoak + 1
            if ((y_robot<=(y_kecoak[i]+11) and y_robot>=(y_kecoak[i]+1)) or (y_robot>=y_kecoak[i]-11 and y_robot<=y_kecoak[i]-1)) and (x_robot==x_kecoak[i]) and (health_kecoak[i]>0):
                kecoak = kecoak + 1
    health_robot = health_robot - (kecoak * 2)  # 2 adalah damage yang diberikan setiap kecoak
    return health_robot  
def nyawa_kecoak(x_kecoak, y_kecoak, health_kecoak) :
    for i in range (20) :
        if health_kecoak[i] != -1 and health_kecoak[i] != 0 :
            print("Health Kecoak",i+1,"("+str(x_kecoak[i])+", "+str(y_kecoak[i])+") :", health_kecoak[i])

# UTAMA
print("=================================================")
print("MULAI")
print("=================================================")
x_robot = 0
y_robot = 0
health_robot = 100
att_robot = 50
x_kecoak = [-1 for i in range (20)]
y_kecoak = [-1 for i in range (20)]
health_kecoak = [-1 for i in range (20)]
turn = 0
while (health_robot > 0 or kecoakmati(health_kecoak)==20) :
    kecoak_baru(x_robot,y_robot,x_kecoak,y_kecoak)
    print("=================================================")
    print()
    turn=turn+1
    if turn%4==0 :
        print("KECOAK MENYERANG !!!")
        print()
        health_robot = serangankecoak(x_robot, y_robot, x_kecoak, y_kecoak, health_kecoak, health_robot)
    print("Health robot ("+str(x_robot)+", "+str(y_robot)+")","saat ini :", health_robot)    
    print()
    print("Kecoak yang telah dibunuh :", kecoakmati(health_kecoak))
    nyawa_kecoak(x_kecoak, y_kecoak, health_kecoak)
    print()
    papan()
    print("=================================================")
    print("Pindah(1) atau tembak(2) ?")
    a = int(input())
    if a == 1 :
        x_robot, y_robot = pindah(x_robot,y_robot,x_kecoak,y_kecoak)
    elif a == 2 :
        tembak(x_robot,y_robot,x_kecoak,y_kecoak,health_kecoak,att_robot)
    print("=================================================")

print("PERMAINAN SELESAI")
print()
print("Kecoak yang berhasil dibunuh :", kecoakmati(health_kecoak))