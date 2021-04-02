def kecoak(x,y,x_kecoak,y_kecoak) :
    for k in range (20) :
        if x==x_kecoak[k] and y==y_kecoak[k] :
            return True

def papan():
    for i in range (19,-1,-1):
        for j in range (20):
            if x_robot==j and y_robot==i :
                print("R ", end="")
            elif kecoak(j,i,x_kecoak,y_kecoak)==True :
                print("K ", end="")
            else :
                print("_ ", end="")
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
        while (x!=x_robot and y!=y_robot and cekkecoak(x,y,x_kecoak,y_kecoak) == True) :
            x = random.randrange(0, 20)
            y = random.randrange(0, 20)
    for i in range (20) :
        if -1==x_kecoak[i] or -1==y_kecoak[i] :
            urut = i
            break
    x_kecoak[urut] = x
    y_kecoak[urut] = y
    health_kecoak[urut] = 100
    print("Muncul kecoak", urut, "("+ str(x)+", "+str(y)+")")
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
            if y_robot==y_kecoak[i] :
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot
    elif n=="A":
        x_robot=x_robot - 1
        salah = 0
        for i in range (20) :
            if x_robot==x_kecoak[i] :   
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot
    elif n=="S":
        y_robot=y_robot - 1
        salah = 0
        for i in range (20) :
            if y_robot==y_kecoak[i] :
                salah = salah + 1
        if salah > 0 :
            print("Ada Kecoak X(")
        else :
            return x_robot, y_robot
    elif n=="D":
        x_robot=x_robot + 1
        salah = 0
        for i in range (20) :
            if x_robot==x_kecoak[i] :
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
            if y_kecoak[i] >= y_robot + 1 and y_kecoak[i] <= y_robot + jarak :
                health_kecoak[i] = health_kecoak[i] - att
                print("Health Kecoak", i, "=", health_kecoak[i])
                benar = benar + 1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")
    elif n=="J":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if x_kecoak[i] >= x_robot - 1 and x_kecoak[i] <= x_robot - jarak :
                health_kecoak[i] = health_kecoak[i] - att
                print("Health Kecoak", i, "=", health_kecoak[i])
                benar = benar +1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")
    elif n=="K":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if y_kecoak[i] >= y_robot - 1 and y_kecoak[i] <= y_robot - jarak :
                health_kecoak[i] = health_kecoak[i] - att
                print("Health Kecoak", i, "=", health_kecoak[i])
                benar = benar + 1
        if benar == 0 :
            print("Kecoak diluar jangkauan")
        print("=================================================")
    elif n=="L":
        print("=================================================")
        benar = 0
        for i in range (20) :
            if x_kecoak[i] >= x_robot + 1 and x_kecoak[i] <= x_robot + jarak :
                health_kecoak[i] = health_kecoak[i] - att
                print("Health Kecoak", i, "=", health_kecoak[i])
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
while (health_robot > 0 or kecoakmati(health_kecoak)==20) :
    kecoak_baru(x_robot,y_robot,x_kecoak,y_kecoak)
    papan()
    print("=================================================")
    print("Pindah(1) atau tembak(2) ?")
    a = int(input())
    if a == 1 :
        x_robot, y_robot = pindah(x_robot,y_robot,x_kecoak,y_kecoak)
    elif a == 2 :
        tembak(x_robot,y_robot,x_kecoak,y_kecoak,health_kecoak,att_robot)
    print("=================================================")
