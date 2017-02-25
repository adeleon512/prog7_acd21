/*
 * prog7_acd21.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: Adam C. De Leon
 *      NetID: acd21
 *      Description: This program is designed to read an input file to the end
 *      of file. The input file that it reads is class_grades.txt. This file
 *      contains student id's, test grade averages, homework grade averages,
 *      and quiz grade averages for a class of no more than 25 students. The
 *      program then displays to the console the student's ID along with their
 *      course average as well as their letter grade.
 */
# include <iostream>
# include <fstream>
# include <iomanip>

using namespace std;

/*****************************************************************************
 * StudentAverage - This function calculates and returns the students course
 * average.
 */

double GetStudentAverage(double test_avg, double hmwk_avg, double qz_avg) {
    double course_avg;
    const double TEST_WEIGHT = .6;
    const double HMWK_WEIGHT = .2;
    const double QZ_WEIGHT = .2;

    course_avg = (test_avg * TEST_WEIGHT) + (hmwk_avg * HMWK_WEIGHT) + (qz_avg
                                                                        * QZ_WEIGHT);
    return course_avg;
}

/*****************************************************************************
 * LetterGrade - This function returns a char value that corresponds to the
 * computed course average of each student.
 */
char GetLetterGrade(double course_avg) {
    char letter_grade;

    if (course_avg >= 89.5)
        letter_grade = 'A';
    else if (course_avg < 89.5 && course_avg >= 79.5)
        letter_grade = 'B';
    else if (course_avg < 79.5 && course_avg >= 69.5)
        letter_grade = 'C';
    else if (course_avg < 69.5 && course_avg >= 59.5)
        letter_grade = 'D';
    else
        letter_grade = 'F';

    return letter_grade;
}

/*****************************************************************************
 * DisplayAverage - This function does not return anything, but displays a
 * sentence to the console stating the student ID, course average, and a
 * letter grade.
 */

void GetDisplayAverage(int student_id, double course_avg, char letter_grade) {
    cout << setprecision(1) << fixed << "Student " << student_id <<
         " has a course average of " << course_avg << " and a letter grade"
                 " of " << letter_grade << "." << endl;
    return;
}

int main() {
    // Declare constants and variables and arrays.
    const int MAX_NUM_STUDENTS = 25;
    int student_id[MAX_NUM_STUDENTS];
    double test_grades[MAX_NUM_STUDENTS];
    double hmwk_grades[MAX_NUM_STUDENTS];
    double quiz_grades[MAX_NUM_STUDENTS];
    double course_avg[MAX_NUM_STUDENTS];
    char letter_grade[MAX_NUM_STUDENTS];
    int i;

    // Input file object.
    ifstream fin;

    // Open the input file.
    fin.open("class_grades.txt");

    // Read in arrays from input file to end of file marker, while securying
    // from running off of the array. This gets the student ID as well as the
    // averages for each type of grade.
    i = 0;
    while (i < MAX_NUM_STUDENTS && fin >> student_id[i]) {
        fin >> test_grades[i];
        fin >> hmwk_grades[i];
        fin >> quiz_grades[i];

        i = i + 1;
    }

    //Perform calculations for determining course average and letter grade.
    //Display the student ID and course average, and letter grade of each
    //student.
    for (int j = 0; j < i; j++) {
        course_avg[j] = GetStudentAverage(test_grades[j], hmwk_grades[j],
                                          quiz_grades[j]);

        letter_grade[j] = GetLetterGrade(course_avg[j]);

        GetDisplayAverage(student_id[j], course_avg[j], letter_grade[j]);
    }

    //Close the input file.
    fin.close();
    return 0;
}



