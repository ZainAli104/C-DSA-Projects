#include <iostream>
#include <limits>
#include <regex>

using namespace std;

// Max number of players in the stack
const int MAX_PLAYERS = 100;

// Player struct
struct Player
{
    string name;
    int age;
    string position;
};

// Stack class
class Stack
{
private:
    // Array to store players in the stack
    Player players[MAX_PLAYERS];
    // Index of the top element of the stack
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Method to push a player onto the stack
    void push(Player player)
    {
        // Check if the stack is full
        if (top == MAX_PLAYERS - 1)
        {
            cout << "Error: Stack is full" << endl;
            return;
        }
        // Check if player already exists
        if (search(player.name))
        {
            cout << "\n<----------------------------Error: Player already exists!-------------------------------->\n";
            return;
        }
        // Increment top and add player to the stack
        top++;
        players[top] = player;
    }

    // Method to pop a player from the stack
    Player pop()
    {
        // Check if the stack is empty
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
            Player empty;
            return empty;
        }
        // Get the top player and decrement top
        Player player = players[top];
        top--;
        return player;
    }

    // Method to check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Method to delete a player from the stack by name
    void deletePlayer(string name)
    {
        // Check if the stack is empty
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
            return;
        }

        // Create a temporary stack to store players
        Stack temp;
        // Flag to indicate if the player was found
        bool found = false;

        // Pop players from the original stack and push them onto the temporary stack
        // until the player is found or the original stack is empty
        while (!found && !isEmpty())
        {
            Player player = pop();
            if (player.name == name)
            {
                found = true;
            }
            else
            {
                temp.push(player);
            }
        }

        // If the player was not found, print an error message
        if (!found)
        {
            cout << "Error: Player not found" << endl;
        }

        // Pop players from the temporary stack and push them back onto the original stack
        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }

    // Method to get the top player in the stack
    Player peek()
    {
        // Check if the stack is empty
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
            Player empty;
            return empty;
        }
        // Return the top player in the stack
        return players[top];
    }

    bool search(string name)
    {
        for (int i = 0; i <= top; i++)
        {
            if (players[i].name == name)
            {
                return true;
            }
        }
        return false;
    }

    // Method to print the players in the stack
    void print()
    {
        // Check if the stack is empty
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
            return;
        }

        // Print the players in the stack
        cout << "Players in the stack:" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << "\n<-------------------------------- " << i + 1 << "- Player------------------------------------>\n";
            cout << "Player Name: " << players[i].name << endl;
            cout << "Player Age: " << players[i].age << endl;
            cout << "Player Position: " << players[i].position << endl;
        }
    }
};

bool isValidName(string name)
{
    // The regular expression for a valid name
    regex nameRegex("^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$");

    // Check if the name matches the regular expression
    return regex_match(name, nameRegex);
}

string checkName()
{
    while (true)
    {
        string name;
        cout << "Enter Player Name: ";
        cin >> name;
        if (!isValidName(name))
        {
            cout << "Error: Invalid name. Name can only contain letters" << endl;
            continue;
        }
        return name;
    }
}

int checkAge()
{
    int age;
    while (true)
    {
        cout << "\nEnter age: ";
        cin >> age;
        if (cin.fail() || age > 60 || age < 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter age from 10 to 60 only in integers" << endl;
        }
        else
        {
            break;
        }
    }
    return age;
}

string checkPosition()
{
    while (true)
    {
        string position;
        cout << "Enter Player Position: ";
        cin >> position;
        if (!isValidName(position))
        {
            cout << "Error: Invalid position. position can only contain letters" << endl;
            continue;
        }
        return position;
    }
}

int main()
{
    system("CLS"); // To Clear Console Screen
    int age, check;
    string name, position, del;

    Stack team; // Create a stack of players

    for (int i = 1; i <= 100; i++)
    {
        cout << "1- Please Enter 1 to Store a Player";
        cout << "\n2- Please Enter 2 to Delete a Player";
        cout << "\n3- Please Enter 3 to Show all Players";
        cout << "\n4- Please Enter 4 to Print Top Player in Stack";
        cout << "\n5- Please Enter 5 to Pop Player in Stack";
        cout << "\n6- Please Enter 6 to stop this Program";
        cout << "\n<-----------------------------------Select One Option--------------------------------------->\n";
        cin >> check;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter valide option!" << endl;
            continue;
        }

        switch (check)
        {
        case 1:
            // Input Player information
            system("CLS");
            cout << "\n<--------------------------------Input Player information------------------------------------>\n";
            name = checkName();
            age = checkAge();
            cout << "\nEnter Position of player: ";
            cin >> position;
            cout << "\n<-------------------------------------------------------------------------->\n";

            team.push({name, age, position});
            break;

        case 2:
            // Delete a player from the stack
            cout << "Enter Name of player you want to delete:  ";
            cin >> del;
            team.deletePlayer(del);
            cout << "\n<--------------------------------Successfully Deleted------------------------------------>\n";
            break;

        case 3:
            // Print the players in the stack
            system("CLS");
            team.print();
            cout << "\n<-------------------------------------------------------------------------->\n";
            break;

        case 4:
            // Print the top player in the stack
            system("CLS");
            cout << "Top player: " << team.peek().name << endl;
            cout << "\n<-------------------------------------------------------------------------->\n";
            break;
        case 5:
            system("CLS");
            cout << team.pop().name << " Successfully Pop\n";
            cout << "\n<--------------------------------Pop Successfully------------------------------------------>\n";
            break;
        case 6:
            i = 100;
            break;
        default:
            system("CLS");
            cout << "Error: Invalide Input" << endl;
            break;
        }
    }

    return 0;
}