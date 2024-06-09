#include<stdio.h>
#include<string.h>
#include <stdlib.h> // For strtol

 int checkint(const char* temp) {
    int status = 0;
    int templen = strlen(temp);
    for (int i = 0; i < templen; i++) {
        if (temp[i] >= '0' && temp[i] <= '9')
        {
            status = 1;
        }
        else {
            return 0;
        }
    }
    return status;
}

 int checkfloat(const char* temp) {
    int int_flag = 0;
    int float_flag = 0;
    int templen = strlen(temp);
    for (int i = 0; i < templen; i++) {
        if (temp[i] == '.' || temp[i] >= '0' && temp[i] <= '9')
        {
            if (temp[i] == '.') {
                float_flag = 1;
            }
            else {
                int_flag = 1;
            }
        }
        else {
            return 0;
        }
    }
    if (float_flag == 1 && int_flag == 1) {
        return 1;
    }
    return 0;
}

int checkoperator(const char* temp) {
    int operator_flag = 0;
    int templen = strlen(temp);
    for (int i = 0; i < templen; i++) {
        if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/') {
            operator_flag = 1;
        }
        else {
            return 0;
        }
    }
    return operator_flag;
}

int checkHexDecimal(const char* temp) {
    int hexDecimal_flag = 0;
    int templen = strlen(temp);
    for (int i = 2; i < templen; i++) {
        if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] >= 'A' && temp[i] <= 'F') || (temp[i] >= 'a' && temp[i] <= 'f')) {
            hexDecimal_flag = 1;
        }
        else {
            return 0;
        }
    }
    return hexDecimal_flag;
}

int checkBinary(const char* temp) {
    int binary_flag = 0;
    int templen = strlen(temp);
    for (int i = 2; i < templen; i++) {
        if (temp[i] == '0' || temp[i] == '1') {
            binary_flag = 1;
        }
        else {
            return 0;
        }
    }
    return binary_flag;
}


//char input[] = "23 + * / 12.32 .3654 0xA 0b101001 ?";
char input[] = "1000 + * / - .3654 0xA 0b101001 ?";

void hashmap(int startpos, int endpos) {
    char temp[10] = " ";
    int temppos = 0;
    for (int i = startpos; i < endpos; i++) {
        temp[temppos] = input[i];
        temppos += 1;
    }


    if (checkint(temp)) {
        printf("%s -> int (%s) \n", temp, temp);
    }
    else if (checkfloat(temp)) {
        printf("%s -> float (%s) \n", temp, temp);

    }
    else if (checkoperator(temp)) {
        printf("%s -> operator (%s) \n", temp, temp);

    }
    else if (temp[0] == '0' && temp[1] == 'x' && checkHexDecimal(temp)) {
        long hexValue = strtol(temp, NULL, 16);
        printf("%s -> hex (%ld) \n", temp, hexValue);
    }
    else if (temp[0] == '0' && temp[1] == 'b' && checkBinary(temp)) {
        int templen = strlen(temp);
        char temp_updated[10] =" ";
        for (int i = 2; i < templen; i++) {
            temp_updated[i-2] = temp[i];
        }
        // Convert binary string to decimal
        long binaryValue = strtol(temp_updated, NULL, 2);
        printf("%s -> binary (%ld) \n", temp, binaryValue);
    }
    else {
        printf("%s -> It is not correct \n \n", temp);
    }

}

int main() {

    int startpos = 0;
    int endpos = 0;

    for (int i = startpos; i <= strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\0' || input == '\t') {
            endpos = i;
            hashmap(startpos, endpos);
            startpos = endpos + 1;
        }
    }

    return 0;
}
