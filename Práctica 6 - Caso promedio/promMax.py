from time import time
from random import randint, uniform,random

def maximo(A):
    max=A[0]
    contador=0
    for i in A:
        if i>max:
            max=i
            contador=contador+1
    return contador




f=open("datos2.csv","w")
tam=[256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
for i in tam:
    f.write(str(i)+';')
    suma=0
    for j in range(200):
        A=[0]*i
        for k in range(0,i):
	        A[k]=randint(0,i*2)
        #print(A)
        max=maximo(A)
        suma=suma+max
        
    promedio=suma/200
    f.write(str(promedio)+'\n')

    print(i)
    #f.write(str(2**i)+',')