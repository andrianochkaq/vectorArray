#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

using namespace std;

int main() {
SetConsoleOutputCP(65001);
srand(time(0));

int n;
cout<<"Введи кількість елементів масиву ";
cin>>n;
 //створення початкового масиву та запис у файл 
vector<double>arr(n);


for(int i=0;i<n;i++)
arr[i]=(rand()/(double)RAND_MAX)*1000.0;

ofstream fileA("a.txt");
if (!fileA) {
    cout<<"Проблема з файлом";
    return 1;
}
fileA<<fixed<<setprecision(3);
for(double x:arr)
fileA<<x<<" ";

fileA.close();
cout<<endl<<"FileA готовий!\n";
//групування масиву(якщо є остача то вона просто видалятиметься(наприклад елемент має 10 елементів і треба грпувати по 3 ,то 1 елемент видалиться)
int unite;
cout<<"Як групуємо числа? ";
cin>>unite;
vector<double>sumB;

for (size_t i = 0; i + unite <= arr.size(); i += unite) {
    double sum=0.0;
    for (size_t j = 0; j < unite; j++) 
        sum+=arr[i+j];
        sumB.push_back(sum);
    
}

//у порядку зростання
vector<double>ASC=arr;
for (size_t i = 0; i < ASC.size()-1; i++) {
    for (size_t j = 0; j < ASC.size() - 1 - i; j++) {
        if(ASC[j]>ASC[j+1])
        swap(ASC[j],ASC[j+1]);
     

    }
}
//спадання
vector<double>DESC = arr;
for (size_t i = 0; i < DESC.size()-1; i++) {
    for (size_t j = 0; j < DESC.size() - 1 - i; j++) {
        if (DESC[j] <DESC[j + 1])
            swap(DESC[j], DESC[j + 1]);

    }
}
//перевірка чи рівні суми
double sumASC=0,sumDESC=0;
for(double x:ASC)sumASC+=x;
for (double x : DESC)sumDESC += x;
if (fabs(sumASC - sumDESC) < 1e-6)
cout<<"Суми однакові,все гаразд\n";
else
cout<<"УПСССС!Десь помилка\n";
//прибирання однакових елементів
vector<double>unique;
int dublicate=0;
for (size_t i = 0; i < arr.size(); i++) {
    bool isDublicate=false;
    for (size_t j = 0; j < unique.size(); j++) {
        if(arr[i]==unique[j]){
        isDublicate=true;
        break;}}
        if(!isDublicate)
        unique.push_back(arr[i]);
        else
        dublicate++;
}
//сума початкового масиву,відсортованого та без повторів
double sumUnique=0,sum=0,sumA=0.0;
for(double x:unique)sumUnique+=x;
for(double x:sumB)sum+=x;
for (double x : arr)sumA += x;
double difference=abs(sum-sumUnique);
//найменший елемент серед об'єднаних
double min_sum=sumB[0];
for (size_t i=1;i<sumB.size();i++) {
  if(min_sum>sumB[i])
  min_sum=sumB[i];
}
//запис у json файл
ofstream JSON("data.json");
if (!JSON) {
    cout << "Проблема з файлом";
    return 2;
}
JSON<< fixed << setprecision(3);
JSON << "\n Сума початкового масиву  " << sumA << "\n Сума масиву без повторів " << sumUnique << "\nСума погрупованого масиву(лишні елементи видалені)\n " << sum <<
"\n Кількість дублікатів " << dublicate << "\n Різниця суми між погрупованим масивом і масивом без повторів " << difference <<
"\n Кількість елементів у початковому масиві " << arr.size() << "\nКількість елементів у погрупованому масиві " << sumB.size() <<
"\nМінмальне значення в погрупованому масиві " << min_sum;
JSON<<"Початковий масив \n";
for(size_t i=0;i<arr.size();i++)
JSON<<arr[i]<<" ";
JSON<<endl;
JSON << "За зростанням\n";
for (size_t i = 0; i < ASC.size(); i++)
    JSON << ASC[i] << " ";
JSON << endl;
JSON << "За спаданням \n";
for (size_t i = 0; i < DESC.size(); i++)
    JSON << DESC[i] << " ";
JSON << endl;
JSON << "Об'єднаний масив\n";
for (size_t i = 0; i < sumB.size(); i++)
    JSON << sumB[i] << " ";
JSON << endl;
JSON << "Масив без повторів\n";
for (size_t i = 0; i < unique.size(); i++)
    JSON << unique[i] << " ";
JSON << endl;

JSON.close();
cout<<"Всі дані в data.json";

    return 0;
}