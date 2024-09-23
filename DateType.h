#pragma once
class dateType
{
public:
	dateType(int m = 1, int d = 1, int y = 1900) {
		setDate(m, d, y);
	}

	//Setter

	void setDate(int m, int d, int y) {
		if (y >= 1900) {
			dyear = y;
		}
		else {
			std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
			d = 1;
			m = 1;
			dyear = 1900;
		}

		if (m <= 12 && m > 0) {
			dmonth = m;
		}
		else {
			std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
			d = 1;
			dyear = 1900;
			dmonth = 1;
		}

		if (d <= 31 && getDaysInMonth(dyear, dmonth) == 31) {
			dday = d;
		}
		else if (d <= 30 && getDaysInMonth(dyear, dmonth) == 30) {
			dday = d;
		}
		else if (d <= 29 && getDaysInMonth(dyear, dmonth) == 29) {
			dday = d;
		}
		else if (d <= 28 && getDaysInMonth(dyear, dmonth) == 28) {
			dday = d;
		}
		else {
			std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
			dday = 1;
			dmonth = 1;
			dyear = 1900;
		}
	}

	//Check if the year is a leap year, true means it is
	bool isLeapYear(int dyear) {
		if (dyear % 400 == 0) {
			return true;
		}
		else if (dyear % 100 == 0) {
			return false;
		}
		else if (dyear % 4 == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int getDaysInMonth(int dyear, int dmonth) {
		if (dmonth == 1 || dmonth == 3 || dmonth == 5 || dmonth == 7 || dmonth == 8 || dmonth == 10 || dmonth == 12) {
			return 31;
		}
		else if (dmonth == 4 || dmonth == 6 || dmonth == 9 || dmonth == 11) {
			return 30;
		}
		else if (dmonth == 2 && !isLeapYear(dyear)) {
			return 28;
		}
		else if (dmonth == 2 && isLeapYear(dyear)) {
			return 29;
		}
	}

	//Getters

	int getDay() {
		return dday;
	}
	int getMonth() {
		return dmonth;
	}
	int getYear() {
		return dyear;
	}

	//Print
	void print() {
		std::cout << dmonth << "-" << dday << "-" << dyear << std::endl;
	}

private:
	int dmonth;
	int dday;
	int dyear;
};

