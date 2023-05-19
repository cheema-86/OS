numProc = int(input("Enter number of processes: "))

print("Enter burst time for each process: ")

burst = [int(input()) for i in range (numProc)]

wait = [0]

for i in range(1,numProc):
    wait.append(0)
    for j in range(i):
        wait[i] += burst[j]

tat = []

print("Process\tBurst Time\tWaiting Time\tTurnaround Time")
for i in range (numProc):
    tat.append(burst[i] + wait[i])
    print(i,"\t",burst[i],"\t\t",wait[i],"\t\t",tat[i])

print("Average waiting time:",sum(wait)/numProc)
print("Average turnaround time:",sum(tat)/numProc)

