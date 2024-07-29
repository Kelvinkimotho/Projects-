# Program Topic-- Professor Evaluation Report
# Description-- This program evaluates professors based on student ratings. It uses a class
# to store professor data and calculates average ratings. It also determines the professor
# with the highest average rating and displays the results.

TITLE = "\nWelcome to Professor Evaluation Report Program!"
NUM_RATING = 3
COL_TITLE = "\nProf.Name   Easiness  Helpfulness  Clarity   AvgRating"
LINE = '-' * len(COL_TITLE)

class Rating:
    def __init__(self, name, easy, helpful, clear):
        self.__name = name
        self.__easy = easy
        self.__helpful = helpful
        self.__clear = clear

    def get_name(self):
        return self.__name

    def set_name(self, name):
        self.__name = name

    def get_easy(self):
        return self.__easy

    def set_easy(self, easy):
        self.__easy = easy

    def get_helpful(self):
        return self.__helpful

    def set_helpful(self, helpful):
        self.__helpful = helpful

    def get_clear(self):
        return self.__clear

    def set_clear(self, clear):
        self.__clear = clear

    def calc_avg_rating(self):
        return (self.__easy + self.__helpful + self.__clear) / NUM_RATING

def display_rating(rate_list):
    print(TITLE)
    print(LINE)
    print(COL_TITLE)
    print(LINE)
    for rating in rate_list:
        avg = rating.calc_avg_rating()
        print(f"{rating.get_name():<10}  {rating.get_easy():<9}  {rating.get_helpful():<11}  {rating.get_clear():<7}  {avg:.2f}")
    print(LINE)

def find_hi_index(rate_list):
    highest_avg = 0
    hi_index = 0
    for i, rating in enumerate(rate_list):
        avg = rating.calc_avg_rating()
        if avg > highest_avg:
            highest_avg = avg
            hi_index = i
    return hi_index

def display_hi_rating(rate_list, hi_index):
    highest = rate_list[hi_index]
    avg = highest.calc_avg_rating()
    print(f"Prof. {highest.get_name()} has earned highest rating of {avg:.2f}")
    print(LINE)

def main():
    rate1 = Rating("Mary", 5, 5, 5)
    rate2 = Rating("Joe", 4, 5, 3)
    rate3 = Rating("Ria", 4, 4, 5)
    
    rate_list = [rate1, rate2, rate3]
    
    display_rating(rate_list)
    
    hi_index = find_hi_index(rate_list)
    display_hi_rating(rate_list, hi_index)

# calling the main method
main()
  