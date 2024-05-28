//
//  functions.h
//  laboratory4
//
//  Created by Илья Атмажитов on 26.05.2024.
//

#ifndef functions_h
#define functions_h


int multiply_by_2 (int data) {
    return data * 2;
}

string plus_A (string data) {
    return data + "A";
}

template <class T>
T sum(T a, T b) {
    return a + b;
}

bool is_onedigit(int a) {
    return 0 <= a && a < 10;
}

bool is_polyndrome(string a) {

    for(int i = 0; i < a.length(); i++) {
        if (a[i] != a[a.length() - i - 1]) {
            return false;
        }
    }

    return true;
}




int input(int min, int max) {
    int answer;

    cin >> answer;
    while (answer < min || answer > max) {
        cout << "Ошибка. Введите число от " << min << " до " << max << endl;
        cin >> answer;
    }

    return answer;
}



#endif /* functions_h */
