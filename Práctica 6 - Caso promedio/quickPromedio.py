from time import time
from random import randint, uniform,random

def particione(A,p,r):
    contador=0
    x=A[r]
    i=p-1
    for j in range(p,r):
        #print(A[j])
        #print(x)
        if(A[j]<=x):
            i=i+1
            A[i],A[j]=A[j],A[i]
            contador+=1
    A[i+1],A[r]=A[r],A[i+1]
    contador+=1
    return (i+1),contador

def quicksort(A,p,r):
    contador=0
    if(p<r):
        q,contador=particione(A,p,r)
        contador+=quicksort(A,p,q-1)
        contador+=quicksort(A,q+1,r)
    return contador

def quick(A,n):
    cont=0
    cont=quicksort(A,0,n-1)
    return cont



f=open("datos2.csv","w")
tam=[256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
for i in tam:
    f.write(str(i)+';')
    suma=0
    for j in range(200):
        A=[0]*i
        for k in range(0,i):
	        A[k]=randint(0,i)
        #print(A)
        max=quick(A,i)
        suma=suma+max
        
    promedio=suma/200
    f.write(str(promedio)+'\n')

    print(i)





arr=[5,4,3,2,1]
print(quick(arr,5))

print(arr)
