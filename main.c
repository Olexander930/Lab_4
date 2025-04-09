#include <stdio.h>
#include <math.h>

int main() {

    int price = 450;
    float znishka = 0.15;
    int final_price = (int)(price * (1 - znishka));
    printf("Ціна зі знижкою: %d грн\n", final_price);

    int birth_year, current_year = 2025, age;

    printf("Введіть рік народження: ");
    scanf("%d", &birth_year);

    age = current_year - birth_year;

    printf("Ваш вік: %d років\n", age);


    float x1, y1, x2, y2;
    printf("Введіть координати першої точки (x y): ");
    scanf("%f %f", &x1, &y1);
    printf("Введіть координати другої точки (x y): ");
    scanf("%f %f", &x2, &y2);
    float distance = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    printf("Відстань між точками: %.2f\n", distance);

    float prise, discount, discount_amount, final_prise;

    printf("Введіть вартість товару: ");
    scanf("%f", &prise);

    printf("Введіть відсоток знижки: ");
    scanf("%f", &discount);

    discount_amount = (prise * discount) / 100;
    final_prise = prise - discount_amount;

    printf("Кінцева вартість товару: %.f грн\n", final_prise);

    int number;
    printf("Введіть тризначне число: ");
    scanf("%d", &number);
    int sum = number / 100 + (number / 10) % 10 + number % 10;
    printf("Сума цифр: %d\n", sum);

    return 0;
}