/*
*Personal Introduction Program
*Created by: Nikko Paolo De Leon
*Date: June 30, 2026
*
*This program Displays personal information in the console
*In a formatted way the personal infromation are displayed
*/

/*
*My Leearning Goals:
*
*Master CPP and land a job
*/

//include the necessary library or header
#include <iostream>

int main(){
    //Lets add a Display Header
    std::cout << "======================================" << '\n';
    std::cout << "          PERSONAL INTRODUCTION       " << '\n';
    std::cout << "======================================" << '\n';

    //Display greeeting and my Name.
    std::cout << "\tMy name is: Nikko Paolo De leon" << '\n';
    //Lets add my home town
    std::cout << "\tI live in the Philippines" << '\n';
    //Display my favorite programming language
    std::cout << "\tMy favorite programming language is CPP" << '\n';
    
    //Display current role/occupation
    std::cout << "\tI am a Computer science Instructor" << '\n';

    //Add header section for educational background
    std::cout << "\n EDUCATION" << '\n';
    std::cout << "-------------------------------------" << '\n';
    std::cout << "\tDegree: BS Computer Science\n";
    std::cout << "\tSchool: University of Santo Tomas-Legazpi\n";
    std::cout << "\tYear: 2025\n";

    //Display a new section for career goals
    std::cout << "\n CAREER GOALS\n";
    std::cout << "--------------------------------------\n";
    std::cout << "\tShort-Term: Master CPP including the deepest concepts\n";
    std::cout << "\tLong-Term: Build any complex systems\n";

    //Display Why did I take this course
    std::cout << "\n WHY I'M TAKING THIS COURSE\n";
    std::cout << "--------------------------------------\n";
    std::cout << "\tI'm taking this course so for mastery of CPP\n";

    //Add a section about topics I'm excited about and display it
    std::cout << "\n TOPICS I'M EXCITE ABOUT\n";
    std::cout << "--------------------------------------\n";
    std::cout << "\tI'm excited about pointers and memory\n";

    //Dsiplay a closing message
    std::cout << "Thank you for reading my intrductions\n";



    //Lets add some footer
    std::cout << "==================================" << std::endl;
    return 0;
}