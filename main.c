#include <stdio.h>

char field[3][3];     // Поле гри
char activePlayer;    // Поточний гравець: 'X' або 'O'

// Створення початкового порожнього поля
void setupField()
{
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            field[row][col] = ' ';
}

// Виведення поля на консоль
void displayField()
{
    printf("\n    1   2   3\n");
    for (int i = 0; i < 3; ++i)
    {
        printf("  +---+---+---+\n");
        printf("%d |", i + 1);
        for (int j = 0; j < 3; ++j)
        {
            printf(" %c |", field[i][j]);
        }
        printf("\n");
    }
    printf("  +---+---+---+\n\n");
}

// Перевірка на виграш
char detectWinner()
{
    // Горизонталі та вертикалі
    for (int i = 0; i < 3; ++i)
    {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' ')
            return field[i][0];
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != ' ')
            return field[0][i];
    }

    // Діагоналі
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != ' ')
        return field[0][0];

    if (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != ' ')
        return field[0][2];

    return ' '; // Ніхто не виграв
}

// Перевірка на нічию
int isTie()
{
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (field[r][c] == ' ')
                return 0;
    return 1;
}

// Обробка ходу гравця
void makeTurn()
{
    int r, c;
    while (1)
    {
        printf("Гравець %c, введіть координати (рядок та стовпець через пробіл): ", activePlayer);
        if (scanf("%d %d", &r, &c) != 2)
        {
            printf("Помилка вводу. Спробуйте знову.\n");
            while (getchar() != '\n'); // очищення вводу
            continue;
        }

        if (r < 1 || r > 3 || c < 1 || c > 3)
        {
            printf("Координати мають бути в межах 1-3.\n");
            continue;
        }

        if (field[r - 1][c - 1] != ' ')
        {
            printf("Це місце вже зайняте. Оберіть інше.\n");
            continue;
        }

        field[r - 1][c - 1] = activePlayer;
        break;
    }
}

// Зміна гравця
void togglePlayer()
{
    activePlayer = (activePlayer == 'X') ? 'O' : 'X';
}

// Основна функція програми
int main()
{
    activePlayer = 'X';
    setupField();

    printf("Починаємо гру \"Хрестики проти Нуликів\"!\n");

    while (1)
    {
        displayField();
        makeTurn();

        char result = detectWinner();
        if (result != ' ')
        {
            displayField();
            printf("Гравець %c переміг! Вітаємо!\n", result);
            break;
        }

        if (isTie())
        {
            displayField();
            printf("Нічия. Дякуємо за гру!\n");
            break;
        }

        togglePlayer();
    }
    return 0;
}
