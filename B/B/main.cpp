#include <iostream>

using namespace std;



int main() {
    
    
    string day[8];
    day[0] = "Monday";
    day[1] = "Tuesday";
    day[2] = "Wednesday";
    day[3] = "Thursday";
    day[4] = "Friday";
    day[5] = "Saturday";
    day[6] = "Sunday";
    
    string mesyac[13];
    mesyac[0] = "January";
    mesyac[1] = "February";
    mesyac[2] = "March";
    mesyac[3] = "April";
    mesyac[4] = "May";
    mesyac[5] = "June";
    mesyac[6] = "July";
    mesyac[7] = "August";
    mesyac[8] = "September";
    mesyac[9] = "October";
    mesyac[10] = "November";
    mesyac[11] = "December";
    
    int d, g;
    string m;
    while (cin >> d) {
        cin >> m >> g;
        int days = d;
        int i = 1980;
        while (i < g){
            if((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
                days = days + 366;
            else
                days = days + 365;
            i++;
        }
        for (int j = 0; j < 12; j++) {
            if (mesyac[j] == m) {
                for (int i = 0; i < j; i++) {
                    if (i != 1 && (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)) {
                        days += 31;
                    }
                    else {
                        if(i == 1) days += (((g % 400 == 0) || (g % 4 == 0 && g % 100 != 0)) ? 29 : 28);
                        
                        else days = days + 30;
                        
                    }
                }
            }
        }
        
        days %= 7;
        cout << day[days] << "\n";
    }
    
    
    return 0;
}



