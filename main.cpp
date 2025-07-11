#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

float simulatePH() {
    return 6.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.5));
}

float simulateTurbidity() {
    return 1.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 4.0));
}

float simulateTemperature() {
    return 20.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 15.0));
}

void logToCSV(float pH, float turbidity, float temp, const string& time) {
    ofstream file("water_quality_log.csv", ios::app);
    file << time << "," << pH << "," << turbidity << "," << temp << endl;
    file.close();
}

string getTimeNow() {
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", localtime(&now));
    return string(buffer);
}

int main() {
    srand(time(0));

    ofstream file("water_quality_log.csv", ios::out);
    file << "Time,pH,Turbidity,Temperature" << endl;
    file.close();

    for (int i = 0; i < 20; i++) {
        float pH = simulatePH();
        float turbidity = simulateTurbidity();
        float temp = simulateTemperature();
        string time = getTimeNow();

        cout << "📅 " << time << endl;
        cout << "pH: " << pH << "\tTurbidity: " << turbidity << " NTU\tTemp: " << temp << " °C" << endl;

        if (pH < 6.5 || pH > 8.0) cout << "⚠️ pH NOT SAFE!\n";
        if (turbidity > 4.0) cout << "⚠️ Water is too dirty!\n";
        if (temp < 22.0 || temp > 33.0) cout << "⚠️ Temperature is unusual!\n";

        logToCSV(pH, turbidity, temp, time);
        cout << "----------------------------------\n";

        this_thread::sleep_for(chrono::seconds(2));
    }

    return 0;
}
