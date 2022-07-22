#include "Garage.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include<iostream>
#include<fstream>
#include "queue.h"
using namespace std;

int main() {


int numOfProcesses;
ifstream my_file;

//read from file and store all processes into job queue


my_file.open("Jobs.txt");
if (!my_file) {
cout << "File not created! " << endl;
}
else {
cout << "File created succesfully!";


my_file >> numOfProcesses;
Queue readyQueue(numOfProcesses);
Queue jobQueue(numOfProcesses);

//save data into queue
while (!my_file.eof()) {
process myProcess;
my_file >> myProcess.processName >> myProcess.arrivalTime >> myProcess.burstTime;
cout << myProcess.processName << myProcess.arrivalTime << myProcess.burstTime << endl;

jobQueue.Enqueue(myProcess);



}
jobQueue.calcCompTime();
jobQueue.calcWaitTime();
jobQueue.calctat();
jobQueue.print();
jobQueue.calcTotalTime();
cout << "Total time required to run: " << jobQueue.getFinalT() << endl;
cout << "Average Wait Time: " << jobQueue.getTime() / double(numOfProcesses) << endl;
//create a finish queue to avg waiitng time
//dis-play all p-rocess in the finsih queue
//move processes from jobqueue to ready queue if arr time<=time
//execute head process from ready queue
/*jobQueue.calcTotalTime();
for (int i = 0; i <= 20; i++) {
if (jobQueue.front().arrivalTime == i) {
readyQueue.Enqueue(jobQueue.Dequeue());
readyQueue.calcCompTime();
readyQueue.calctat();
//calc for each process
}

if (readyQueue.front().compTime == i) {

cout << readyQueue.front().compTime << endl;
readyQueue.Dequeue();
}

}*/


}






//create time variable
/*int time=0;
while (!readyQueue.isEmpty())
{
if (readyQueue.arr[readyQueue.front()] == time)
{
process temp = readyQueue.Dequeue();
time += temp.burstTime;
temp.tatTime = time - temp.arrivalTime;

}

}
*/
my_file.close();


system("pause");

return 0;

}






