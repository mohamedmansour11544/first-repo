#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
//this a a change 
using namespace std;
// changing some rules
//this is anew line in file down merged
//this is anew line in file down merged
//this is anew line in file down merged
struct stDate
{
  int Year;
  int Month;
  int Day;
};
int ReadDay()
{
  int Day;
  cout << "\nPlease enter a Day: ";
  cin >> Day;
  return Day;
}
int ReadMonth()
{
  int Month;
  cout << "Please enter a Month: ";
  cin >> Month;
  return Month;
}

int ReadYear()
{
  int Year;
  cout << "Please enter a Year: ";
  cin >> Year;
  return Year;
}

stDate ReadFullDate()
{
  stDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}

struct stPeriod
{
  stDate StartDate;
  stDate EndDate;
};
stPeriod ReadPeriod()
{
  stPeriod Period;
  cout << "\nEnter Start Date:\n";
  Period.StartDate = ReadFullDate();
  cout << "\nEnter End Date:\n";
  Period.EndDate = ReadFullDate();
  return Period;
}
vector<string> SplitString(string &str)
{
  int pos = 0;
  string delima = "/";
  string word = "";
  vector<string> result;
  while ((pos = str.find(delima)) != string::npos)
  {
    word = str.substr(0, pos);
    if (!word.empty())
    {
      result.push_back(word);
    }
    str.erase(0, pos + delima.length());
  }
  if (!str.empty())
  {
    result.push_back(str);
  }
  return result;
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
  return (Date1.Year < Date2.Year) ||
         (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
         (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
  return Date1.Year == Date2.Year &&
         Date1.Month == Date2.Month &&
         Date1.Day == Date2.Day;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
  return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

enum enDateCompare
{
  Before = -1,
  Equal = 0,
  After = 1
};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
  if (IsDate1BeforeDate2(Date1, Date2))
    return enDateCompare::Before;
  if (IsDate1EqualDate2(Date1, Date2))
    return enDateCompare::Equal;
  return enDateCompare::After;
}
bool isLeapYear(short Year)
{
  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{

  if (Month < 1 || Month > 12)
    return 0;

  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
bool IsLastDayInMonth(stDate Date)
{

  return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
  return (Month == 12);
}
stDate IncreaseDateByOneDay(stDate Date)
{
  if (IsLastDayInMonth(Date))
  {
    if (IsLastMonthInYear(Date.Month))
    {
      Date.Month = 1;
      Date.Day = 1;
      Date.Year++;
    }
    else
    {
      Date.Day = 1;
      Date.Month++;
    }
  }
  else
  {
    Date.Day++;
  }
  return Date;
}
/* short PeriodLength(stPeriod period, bool IncludingEndDay = false)
{
  int length = 0;
  while (IsDate1AfterDate2(period.EndDate, period.StartDate))
  {
    period.StartDate = IncreaseDateByOneDay(period.StartDate);
    length++;
  }
  if (IncludingEndDay)
  {
    ++length;
  }
  return length;
} */
bool isDateInPeriod(stDate &Date, stPeriod &Period)
{
  return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before ||
           CompareDates(Date, Period.EndDate) == enDateCompare::After);
}
bool CheakValidateDate(stDate &date)
{
  stPeriod period;
  period.StartDate.Day = 1;
  period.EndDate.Day = NumberOfDaysInAMonth(date.Month, date.Year);
  period.StartDate.Month = date.Month;
  period.EndDate.Month = date.Month;
  period.StartDate.Year = date.Year;
  period.EndDate.Year = date.Year;
  return isDateInPeriod(date, period); // cheak if date is in period
}
stDate StringToDateStructure(string str)
{
  stDate Date;
  vector<string> result = SplitString(str);
  Date.Day = stoi(result.at(0));
  Date.Month = stoi(result.at(1));
  Date.Year = stoi(result.at(2));
  return Date;
}

string DateToString(stDate &Date)
{
  string result;
  result += to_string(Date.Day) + "/";
  result += to_string(Date.Month) + "/";
  result += to_string(Date.Year);
  return result;
}
void PrintDateAsStrucrue(stDate Date)
{
  if (CheakValidateDate(Date))
  {
    cout << "Day:" << Date.Day << endl;
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year << "\n";
  }
  else
  {
    cout << "Invalid date." << endl;
  }
}
int main()
{

  stDate Date = StringToDateStructure("31/1/2023");
  PrintDateAsStrucrue(Date);
  cout << "You Entered " << DateToString(Date) << endl;
  system("pause > 0");
  return 0;
}
