#pragma once
#include <ctime>

class ThoiGian
{
public:
    int Day, Month, Year;
    bool isNamNhuan() {
        return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
    }
    int Ngay() {
        switch (Month) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            return 31;
        case 4:case 6:case 9:case 11:
            return 30;
        case 2:
            if (isNamNhuan() == true)
                return 29;
            return 28;
        }
    }

    void GiaHan() {
        for (int i = 0; i < 30; i++) {
            if (Day < Ngay()) {
                ++Day;
            }
            if (Month != 12 && Day == Ngay()) {
                Day = 1;
                ++Month;
            }
            else if (Month == 12 && Day == Ngay()) {
                Day = Month = 1;
                ++Year;
            }
            else if (Month == 2) {
                if (isNamNhuan()) {
                    if (Day == 29) {
                        Day = 1;
                        ++Month;
                    }
                }
                else {
                    if (Day == 28) {
                        Day = 1;
                        ++Month;
                    }
                }
            }

        }
    }
};