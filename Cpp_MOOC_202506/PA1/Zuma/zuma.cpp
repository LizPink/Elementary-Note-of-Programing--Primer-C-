#include <iostream>

const int MAX_INITIAL_LENGTH = 10000;
const int MAX_OPERATIONS = 10000;
const int MAX_TOTAL_LENGTH = MAX_INITIAL_LENGTH + MAX_OPERATIONS + 5;

int getLength(const char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        ++length;
    }

    return length;
}

void insertAt(char sequence[], int& length, int position, char color) {
    for (int i = length; i > position; --i) {
        sequence[i] = sequence[i - 1];
    }

    sequence[position] = color;
    ++length;
    sequence[length] = '\0';
}

void removeRange(char sequence[], int& length, int left, int right) {
    int count = right - left;

    for (int i = right; i < length; ++i) {
        sequence[i - count] = sequence[i];
    }

    length -= count;
    sequence[length] = '\0';
}

void eliminate(char sequence[], int& length, int position) {
    int current = position;

    while (length > 0 && current >= 0 && current < length) {
        char color = sequence[current];

        int left = current;
        int right = current + 1;

        while (left > 0 && sequence[left - 1] == color) {
            --left;
        }

        while (right < length && sequence[right] == color) {
            ++right;
        }

        if (right - left < 3) {
            break;
        }

        removeRange(sequence, length, left, right);

        if (length == 0) {
            break;
        }

        if (left < length) {
            current = left;
        } else {
            current = length - 1;
        }
    }
}

void printSequence(const char sequence[], int length) {
    if (length == 0) {
        std::cout << "-\n";
        return;
    }

    for (int i = 0; i < length; ++i) {
        std::cout << sequence[i];
    }

    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char sequence[MAX_TOTAL_LENGTH];

    std::cin.getline(sequence, MAX_TOTAL_LENGTH);

    int length = getLength(sequence);

    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int position = 0;
        char color = '\0';

        std::cin >> position >> color;

        insertAt(sequence, length, position, color);
        eliminate(sequence, length, position);

        printSequence(sequence, length);
    }

    return 0;
}