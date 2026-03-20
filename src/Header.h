#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <algorithm>
#include <cmath>

using namespace std;

vector<double> generateArray(int n) {
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = (rand() / (double)RAND_MAX) * 1000.0;
    return arr;
}

void writeToFile(const string& filename, const vector<double>& arr) {
    ofstream file(filename);
    file << fixed << setprecision(3);
    for (double x : arr)
        file << x << " ";
}

vector<double> groupArray(const vector<double>& arr, int unite) {
 
    vector<double> result;

    for (size_t i = 0; i + unite <= arr.size(); i += unite) {
        double sum = 0;
        for (int j = 0; j < unite; j++)
            sum += arr[i + j];
        result.push_back(sum);
    }

    return result;
}

vector<double> sortAscending(vector<double> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

vector<double> sortDescending(vector<double> arr) {
    sort(arr.rbegin(), arr.rend());
    return arr;
}

double sumArray(const vector<double>& arr) {
    double sum = 0;
    for (double x : arr)
        sum += x;
    return sum;
}

vector<double> uniqueArray(const vector<double>& arr, int& duplicates) {
    vector<double> unique;
    duplicates = 0;

    for (double x : arr) {
        bool found = false;
        for (double u : unique) {
            if (abs(x - u) < 1e-9) {
                found = true;
                break;
            }
        }
        if (!found)
            unique.push_back(x);
        else
            duplicates++;
    }

    return unique;
}

double maxElement(const vector<double>& arr) {
    if (arr.empty()) return -2;
    double maxVal = arr[0];
    for (double x : arr)
        if (x > maxVal)
            maxVal = x;
    return maxVal;
}
