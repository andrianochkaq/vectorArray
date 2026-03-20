#include "Header.h"
#include <nlohmann\json.hpp>

using json = nlohmann::json;
#ifndef UNIT_TESTING
int main() {
    SetConsoleOutputCP(65001);
    srand(time(0));

    int n;
    cout << "Введи кількість елементів масиву ";
    cin >> n;

    vector<double> arr = generateArray(n);
    writeToFile("a.txt", arr);

    int unite;
    do{
    cout << "Як групуємо числа? ";
    cin >> unite;}
    while (unite <= 0) ;
    
    vector<double> sumB = groupArray(arr, unite);
    writeToFile("b.txt", sumB);

    vector<double> ASC = sortAscending(arr);
    vector<double> DESC = sortDescending(arr);

    if (abs(sumArray(ASC) - sumArray(DESC)) < 1e-6)
        cout << "Суми однакові\n";

    int duplicates;
    vector<double> unique = uniqueArray(arr, duplicates);

    json j;
    j["sum_initial_array"] = sumArray(arr);
    j["sum_without_duplicates"] = sumArray(unique);
    j["duplicates_count"] = duplicates;
    j["max_value_grouped_array"] = maxElement(sumB);

    ofstream("data.json") << setw(4) << j;

    cout << "Готово\n";
}
#endif