/*
PSEUDO CODE: 

FORWARD DECLARATOON OF VECTOR FUNCTION GETFIVENUMBERS
FORWARD DECLARATION OF FUNCTION VERIFY INT NUMBER
FORWARD DELCARATION OF FUNCTION SUM(VECTOR NUMBERS)
FORWARD DECLARATION OF FUNCTION AVERAGE(VECTOR NUMBERS, SUM)
FORWARD DECLARATION OF FUNCTION CHECK FOR EVEN (VECTOR NUMBERS) 
FORWARD DECLARATION OF FUNCTION CHECK FOR ODD (VECTOR NUMBER)
FORWARD DECLARATION OF VECTOR FUNCTION SORT (VECTOR NUMBERS)
FORWARD DECLARATION OF FUNCTION LARGEST NUMBER (VECTOR NUMBERS)
FORWARD DECLARATION OF FUNCTION SMALLEST NUMBER (VECTOR NUMBERS)

BEGIN NUMBER PATTERN ANALYZER
    INITIALIZE LARGEST NUMBER {0}, SMALLEST NUMBER {0}, AVERAGE {0}, SUM {0}, EVEN COUNT {0}, ODD COUNT {0}
    INITIALIZE VECTOR FIVENUMBERSNUMBERS[0], 
    VECTOR FIVENUMBERS = GETFIVENUMBERS();
    LARGEST NUMBER = LARGEST NUMBER(FIVENUMBERS)
    SMALLEST NUMBER = SMALLEST NUMBER(FIVENUMBERS)
    SUM = SUM(FIVENUMBERS)
    AVERAGE = AVERAGE (FIVENUMBERS, SUM)
    EVEN COUNT = CHECK FOR EVEN (FIVENUMBERS)
    ODD COUNT = CHECK FOR ODD (FIVENUMBERS)


    PRINT "THE LARGEST NUMBER AMONG THE FIVE NUMBERS: {LARGEST NUMBER}"
    PRINT "THE SMALLEST NUMBER AMONG THE FIVE NUMBERS: {SMALLES NUMBER}"
    PRINT "THE SUM OF THE FIVE NUMBERS: {SUM}"
    PRINT "THE AVERAGE OF THE FIVE NUMBERS: {AVERAGE}"
    PRINT "THE SORTED FROM BIGGEST TO SMALLEST NUMBER {FIVENUMBERS[0], FIVENUMBERS[1], FIVENUMBERS[2], FIVENUMBERS[3], FIVENUMBERS[4],}
    RETURN 0;

END NUMBER PATTER ANALYZER

FUNCTION SUM(VECTOR NUMBERS) 
    INITIALIZE SUM {0}
    FOR I FROM 0 TO VECTOR SIZE DO    
        SUM += VECTOR[I]
    END FOR

    RETURN SUM 
END FUNCTION

FUNCTION AVERAGE(VECTOR NUMBERS, SUM)
    INITIALIZE AVERGAE {0.O}
    AVERAGE = STATIC CAST TO DOUBLE SUM / VECTOR SIZE
    RETURN AVERAGE;
END FUNCTION

FUNCTION CHECK FOR EVEN (VECTOR NUMBERS)
    INITIALIZE EVEN COUNT {0}
    FOR I FROM 0 TO VECTOR SIZE DO
        IF VECTOR[I] / 2 == 0
            COUNT++
        END IF
    END FOR
    RETURN COUNT
END FUNCTION

FUNCTION CHECK FOR ODD (VECTOR NUMBERS)
    INITIALIZE EVEN COUNT {0}
    FOR I FROM 0 TO VECTOR SIZE DO
        IF VECTOR[I] / 2 != 0
            COUNT++
        END IF
    END FOR
    RETURN COUNT
END FUNCTION

FUNCTION VECTOR SORT (VECTOR NUMBERS)
    INITIALIZE NOTSORTED {TRUE}
    INITIALIZED N {LENGTH(NUMBERS)}
    WHILE NOTSORTED DO
        FOR I FROM 0 TO (N - 2) SIZE DO
            IF NUMBERS[I] > NUMBERS [I+1]
                SWAP(NUMBERS[I], NUMBERS[(I+1)])
                NOTSORTED = TRUE
            END IF
        END FOR
        N = N - 1
    END WHILE
    RETURN NUMBERS
END FUNCTION

FUNCTION LARGEST NUMBER (VECTOR NUMBERS)
    INITIALIZE LARGEST NUMBER {0}
    INITIALIZED N {LENGTH(NUMBERS)}
    FOR I FROM 0 TO (N - 2) SIZE DO
        IF NUMBERS[I] > LARGEST NUMBER
            LARGEST NUMBER = NUMBRES[I]
            END IF
        END FOR
    RETURN LARGEST NUMBER
END FUNCTION

FUNCTION SMALLEST NUMBER (VECTOR NUMBERS)
    INITIALIZE SMALLEST NUMBER {VECTOR[0]}
    INITIALIZED N {LENGTH(NUMBERS)}
    FOR I FROM 1 TO (N - 1) SIZE DO
        IF NUMBERS[I] > SMALLEST NUMBER
            SMALLEST NUMBER = NUMBERS[I]
        END IF
    END FOR
    RETURN SMALLEST NUMBER
END FUNCTION


FUNCTION GETFIVENUMBERS
    INITIALIZE VECTOR NUMBERS[5]
    INITIALIZE I {0}
    WHILE TRUE
        NUMBERS[I] = VERIFYINTNUMBER("ENTER NUMBER {(I + 1)}: ")
        IF I == 4
            BREAK
        END IF
    I++;
    END WHILE
    RETURN NUMBERS
END FUNCTION



FUNCTION VERIFYINTNUMBER(STRING PROMPT)
    INITIALIZE VALUE {0}
    INITIALIZE VALIDINPUT {FALSE}
    DO 
        PRINT PROMPT 
        IF READ TO VALUE
            VALIDINPUT = TRUE
        ELSE 
            CLEAR READ
            IGNORE READ 
            PRINT "ERROR: INVALID INPUT! PLEASE ENTER ONLY INTEGERS"
        END IF
    WHILE VALIDINPUT IS NOT TRUE
    END DO-WHILE
        RETURN VALUE
END FUNCTION
*/
// Create a program that analyzes a sequence of numbers entered by the user.
/*
* Accept up to 5 numbers from the user
* Find the largest and smallest numbers
* Calculate the sum and average
* Determine how many numbers are even vs odd
* Allow user to stop entering numbers early
*/

// Header files
#include <iostream>
#include <vector>
#include <limits>
#include <format>
#include <string>
#include <cmath>

// Forward declarations
std::vector<int> getFiveNumbers();
int getIntNumbers(const std::string& prompt); 
int sum(std::vector<int> numbers);
int average(std::vector<int> numbers, int sum);
int even(std::vector<int> numbers);
int odd(std::vector<int> numbers);
std::vector<int> sorted(std::vector<int> numbers);
int largestNumber(std::vector<int> numbers);
int smallestNumber(std::vector<int> numbers);

int main() {
    int lNumber {0}, sNumber {0}, avg {0}, sumN {0}, evenCount {0}, oddCount {0};
    std::vector<int> fiveNumbers(5), sortedFiveNumbers(5);
    fiveNumbers = getFiveNumbers();
    lNumber = largestNumber(fiveNumbers);
    sNumber = smallestNumber(fiveNumbers);
    sumN = sum(fiveNumbers);
    avg = average(fiveNumbers, sumN);
    evenCount = even(fiveNumbers);
    oddCount = odd(fiveNumbers);
    sortedFiveNumbers = sorted(fiveNumbers);


    std::cout << "The largest number among the five is: " << lNumber << '\n';
    std::cout << "The smallest number among the five is: " << sNumber << '\n';
    std::cout << "The sum of the five numbers is: " << sumN << '\n';
    std::cout << "The average of the five numbers is: " << avg << '\n';
    std::cout << "Numbers sorted from smalles to biggest: " << sortedFiveNumbers[0] << ", " << sortedFiveNumbers[1] << ", " << sortedFiveNumbers[2] << ", " << sortedFiveNumbers[3] << ", " << sortedFiveNumbers[4] << '\n'; 
    return 0;
}

// Get five numbers then stores it inside the vector for use
std::vector<int> getFiveNumbers() {
    std::vector<int> numbers(5);
    int value = 0, count {0};
    while (true) {
        std::string prompt = std::format("Please enter number {}: ", count + 1);
        numbers[count] = getIntNumbers(prompt);
        count++;
        if (count == 5) {
            break; 
        }
    }
    return numbers;   
}

// Verify if user entered integers only
int getIntNumbers(const std::string& prompt) {
    int value {0};
    bool validInput {false};
    do {
        std::cout << prompt;
        if (std::cin >> value) {
            validInput = true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input! Enter only integers." << '\n';
        } 
    } while (!validInput);
    return value;
}

int largestNumber(std::vector<int> numbers) {
    int value {0}, n {numbers.size()};
    for (int i = 0; i <= (n - 1); i++) {
        if (numbers[i] >= value) {
            value = numbers[i];
        }
    } 
    return value;
} 

int smallestNumber(std::vector<int> numbers) {
    int value {numbers[0]}, n {numbers.size()};
    for (int i = 0; i <= (n-1); i++) {
        if (numbers[i] <= value) {
            value = numbers[i];
        }
    }
    return value;
}

int sum(std::vector<int> numbers) {
    int value {0};
    for (int i = 0; i < numbers.size(); i++) {
        value += numbers[i];
    }
    return value;
}

int average(std::vector<int> numbers, int sum) {
    double value {0.0};
    value = static_cast<double>(sum)/static_cast<double>(numbers.size());
    return std::round(value);
}

int even(std::vector<int> numbers) {
    int count {0};
    for (int i = 0; i < (numbers.size() - 1); i++) {
        if (numbers[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int odd(std::vector<int> numbers) {
    int count {0};
    for (int i = 0; i < (numbers.size() - 1); i++) {
        if (numbers[i] % 2 == 1) {
            count++;
        }
    }
    return count;
}


std::vector<int> sorted(std::vector<int> numbers) {
    bool notSorted {true};
    int n {numbers.size()};
    while (notSorted) {
        notSorted = false;
        for (int i = 0; i < (n-1); i++) {
            if (numbers[i] > numbers[i+1]) {
                std::swap(numbers[i], numbers[i+1]);
                notSorted = true;
            }
        }
        n = n - 1;
    }
    return numbers;
}
