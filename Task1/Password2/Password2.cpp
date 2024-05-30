#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generate_password(int length, bool use_uppercase, bool use_digits, bool use_special)
{
    string chars = "abcdefghijklmnopqrstuvwxyz";
    if (use_uppercase) chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (use_digits) chars += "01234356789";
    if (use_special) chars += "!@#$%^&*()";

    string password = "";
    for (int i = 0; i < length; i++)
    {
        password += chars[rand() % chars.size()];
    }

    return password;
}

bool validate_input(string input, string allowed_chars)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (allowed_chars.find(input[i]) == string::npos)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    srand(time(0));

    int length;
    bool use_uppercase, use_digits, use_special;
    char to_file;

    cout << "Enter password length (positive integer): ";
    cin >> length;
    if (length <= 0 || cin.fail())
    {
        cout << "Invalid input. Exiting program." << endl;
        return 1;
    }

    cout << "Use uppercase letters? (Yes/No): ";
    string uppercase_input;
    cin >> uppercase_input;
    if (!validate_input(uppercase_input, "YesNoyesno"))
    {
        cout << "Invalid input. Exiting program." << endl;
        return 1;
    }
    use_uppercase = (uppercase_input == "Yes" || uppercase_input == "yes");

    cout << "Use digits? (Yes/No): ";
    string digits_input;
    cin >> digits_input;
    if (!validate_input(digits_input, "YesNoyesno"))
    {
        cout << "Invalid input. Exiting program." << endl;
        return 1;
    }
    use_digits = (digits_input == "Yes" || digits_input == "yes");

    cout << "Use special characters? (Yes/No): ";
    string special_input;
    cin >> special_input;
    if (!validate_input(special_input, "YesNoyesno"))
    {
        cout << "Invalid input. Exiting program." << endl;
        return 1;
    }
    use_special = (special_input == "Yes" || special_input == "yes");

    string password = generate_password(length, use_uppercase, use_digits, use_special);

    cout << "Generated password: " << password << endl;

    cout << "Save password to file? (Yes/No): ";
    string file_input;
    cin >> file_input;
    if (!validate_input(file_input, "YesNoyesno"))
    {
        cout << "Invalid input. Exiting program." << endl;
        return 1;
    }
    if (file_input == "Yes" || file_input == "yes")
    {
        ofstream file("password.txt");
        file << password;
        cout << "Password saved to password.txt" << endl;
    }

    return 0;
}
