#ifndef CONSTANTS_H
# define CONSTANTS_H

/* STATUS VALUES */
# define STATUS_NOT_ARE_NUMBERS         -3
# define STATUS_NUMBER_OUT_OF_RANGE     -4
# define STATUS_NUMBER_NEGATIVE         -5
# define STATUS_TOO_FEW_ARGUMENTS       -6
# define STATUS_NUMBER_DUPLICATED       -7

# define ERROR                          -1
# define TRUE                           1
# define FALSE                          0  
# define MIN_COUNT_ARGC                 1
# define MIN_DIGIT_CHAR                 '0'
# define MAX_DIGIT_CHAR                 '9'
# define MAX_INT                        2147483647
# define MIN_INT                        -2147483648

/* ERROR MESSAGES */
# define ERROR_NOT_ARE_NUMBERS      "Error\nThe argvs have to be numbers\n"
# define ERROR_INT_OVERFLOW         "Error\nArgv numbers out of integers range\n"
# define ERROR_NUMBERS_NEGATIVE     "Error\nThe argvs have to be positives\n"
# define ERROR_TO_FEW_ARGUMENTS     "Error\nToo Few Arguments\n"
# define ERROR_TO_FEW_ARGUMENTS     "Error\nToo Few Arguments\n"
# define ERROR_DUPLICATED_NUMBER    "Error\nDuplicated Number In Argv\n"
# define ERROR_MALLOC               "Error\nMalloc fails\n"

#endif //CONSTANTS_H
