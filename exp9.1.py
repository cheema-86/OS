#code for simulating round robin cpu scheduling algorithm in python
#the teacher said use the language of your choice
#I asked if I could use python
#he said yes
#when I submitted this code he said he meant any language from C or C++
#I have successfully wasted a hour of my life
#FML

class Process:
    def __init__(self,procNum,arrivalTime,executionTime):
        self.num = procNum
        self.arrival = arrivalTime
        self.execution = executionTime
        self.remaining = executionTime
        self.waiting = 0
        self.response = 0
        self.turnarund = 0

    def execute(self, timeQuantum):
        if (self.remaining - timeQuantum >= 0):
            self.remaining -= timeQuantum
            self.turnarund += timeQuantum
        else:
            self.turnarund += self.remaining
            self.remaining = 0

    def wait(self, timeQuantum):
        if (self.execution == self.remaining):
            self.response += timeQuantum
        self.waiting += timeQuantum
        self.turnarund += timeQuantum

processList = []
num = int(input("Enter number of processes:"))

for i in range(num):
    print("Enter arrival time for process",i, end=": ")
    arr = int(input())

    print("Enter execution time for process",i,end=": ")
    exe = int(input())

    processList.append(Process(i,arr,exe))

quant = int(input("Enter time quantum: "))

queue = []
order = [i.arrival for i in processList]

for i in range(len(processList)):
    queue.append(processList[order.index(min(order))])
    order[order.index(min(order))] += 99

while len(queue):
    for process in queue:
        process.execute(quant)
        queue.pop(0)
        for j in queue:
            j.wait(quant)
        if process.remaining != 0:
            queue.append(process)

print("Number\tArrTime\tBurstTime\tWaitTime\tResponseTime\tTotalTime")
for i in processList:
    print(i.num,"\t",i.arrival,"\t",i.execution,"\t\t",i.waiting,"\t\t",i.response,"\t\t",i.turnarund)