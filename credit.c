#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_num_ans = get_long("Number: ");
    long credit_num_dummy = credit_num_ans;
    long credit_num_dummy2 = credit_num_ans / 10;
    long credit_num_dummy3 = credit_num_ans;
    int length = 0;

    // check the digit amount of the card
    while (credit_num_dummy != 0)
    {
        credit_num_dummy = credit_num_dummy / 10;

        length++;
    }
    int length_final = length;

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits
    // together
    int first_check1 = 0;
    int first_check = 0;
    for (int divide = 0; divide < length / 2 + 1; divide++)
    {
        first_check1 = credit_num_dummy2 % 10 * 2;
        if ((float) first_check1 / 10 >= 1.0)
        {
            first_check1 = first_check1 / 10 + first_check1 % 10;
        }
        credit_num_dummy2 = credit_num_dummy2 / 100;
        first_check = first_check + first_check1;
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    int second_check1 = 0;
    int second_check = 0;
    for (int divide2 = 0; divide2 < length / 2 + 1; divide2++)
    {
        second_check1 = credit_num_dummy3 % 10;
        credit_num_dummy3 = credit_num_dummy3 / 100;
        second_check = second_check1 + second_check;
    }
    int total = first_check + second_check;

    if (total % 10 == 0)
    {
        long check_first_2digit_long = credit_num_ans;
        for (int p = 0; p < length - 2; p++)
        {
            check_first_2digit_long = check_first_2digit_long / 10;
        }
        int check_first_2digit = check_first_2digit_long;
        int check_first_digit = check_first_2digit / 10;

        if ((length == 15) && (check_first_2digit == 34 || check_first_2digit == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 16) && (check_first_2digit == 51 || check_first_2digit == 52 || check_first_2digit == 53 ||
                                    check_first_2digit == 54 || check_first_2digit == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 16 || length == 13) && (check_first_digit == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}