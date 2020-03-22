const int instruction_length = 1000;
const int number_of_operators = 6;
struct Operator{
    const char* representation;
    const int priority;
    const bool right_associative;
};
const Operator operators[] = {
        { "=", 8, true },
        { "+", 3, false },
        { "-", 3, false },
        { "/", 2, false },
        { "*", 2, false },
        { "%", 2, false },
};

const char* numbers[] = {
        "0","1","2","3","4","5","6","7","8","9"
};