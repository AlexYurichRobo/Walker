# Сборка робота и настройка сервоприводов Walker

## Предисловие

Двуногий шагающий робот Гуляка (Walker) задуман,как несложный проект в помощь для изучения С/С++, призваный приучить ориентироваться учащихся в громоздком коде, использовать циклы, и условныеоператоры, и составлять функции. В силу простоты конструкции платформа робота крайне доступна, а детали можно легко распечатать на 3д принтере.
Дляреализации движения шагами в различных направлениях достаточно 4 сервопривода. В последствии робота можно будет модернизировать, расширяя его возможности и добавляя новые блоки кода.
В возможности платформы робота заложено 3 уровня:
1. **Базовый**, для него потребуется минимум деталей. На его базе закрепляем навыки и знания по основам разработки на Ардуино
2. **Расширенный**, дабавляются сервоприводы и датчики. Используются пользовательские библиотеки, и налаживается взаимосвязь с телефоном
3. **Продвинутый**, добавляется верхний плечевой пояс, разбирается база обратной кинематики, получаем навыки работы с различными манипуляторами

![Alt+текст](https://avatars.mds.yandex.net/get-zen_doc/3384412/pub_5fad3c494278375e7ef5dc70_5fad462fc3975f5b3d26d954/scale_600)

Содержание
0. [Предисловие](#Предисловие)
1. [Перечень элементов для сборки](# 1. Перечень элементов для сборки)
2. [Процесс сборки робота](# 2. Процесс сборки робота)
3. [Настройка перпендикулярности расположения сервоприводов](# 3. Настройка перпендикулярности расположения сервоприводов)
4. [Код настроечного скетча](# 4. Код настроечного скетча)




## 1. Перечень элементов для сборки
***Основные элементы:***
1. Arduino NANO;
2. IO NANO shield *(позже добавлю сравнение возможностей разных вариантов шилдов)*;
3. Сервоприводы MG90, 180 градусов - 4 штуки;
4. Источник питания *(крона 9в, или аккумулятор не менее 7,4 в)*;
5. Штекер для подключения источника питания;
6. [Детали для корпуса](https://www.thingiverse.com/thing:4651195);
7. Винты М3 х 30 - 2 штуки *(для крепления элемонтов ног)*;
8. Шуруп М2,6 х 5 - 4 шт *(для крепления Arduinoна корпус)*;
9. Канцелярские резинки *(для установки аккумулятора)*

## 2. Процесс сборки робота

Для борки всего робота яиспользовал шуруповерт, что ускорило весь процесс. Среднее время сборки 15...30 минут.
Что бы было легче крепить элементы ног винтами М3, отверстия предварительно прошел метчиком ***М3х0,5***

Процесс сборки можно посмотреть по ссылке на YouTube:

[![Сборка робота](https://i9.ytimg.com/vi_webp/9El1E4NTEyo/mqdefault.webp?time=1612863600000&sqp=CPCwiYEG&rs=AOn4CLAuiYpM0T9OyyUcIexfj37YVyLTfg)](https://www.youtube.com/watch?v=9El1E4NTEyo&list=PLPlEq5SS8JN62263Q4-hY7qEeuCIrCNkc)

## 3. Настройка перпендикулярности расположения сервоприводов

Настройка заключается в закреплении рычагов-качалок на сервоприводах, валы которых зафиксированы в положении 90 градусов.
Для этого предварительно загружаем из репозитория в Arduino NANO.
Для удобства дальнейшего обращения к сервоприводам, инициализируем их через массив ***Servo servoLegs[servos]***

Подсоединяем разъёмы сервоприводов, развернув робота ~~*__"К себе задом, к лесу передом"__*~~ к себе спиной, по схемке:

![Alt+текст](https://avatars.mds.yandex.net/get-zen_doc/3445317/pub_5fad3c494278375e7ef5dc70_6022a25853b5a470dc75d874/orig)

Таким образом верхние сервоприводы с вертикальным валом подключаются как четные, а нижние с горизонтальным валом - как нечетные:

| Сервоприводы|Левый|Правый|
|:-----------------:|:-----------------:|:-----------------:|
|Верхний|D8|D10|
|Нижний|D7|D9|

Процесс настройки робота можно посмотреть на **YouTUBE** :

[![Сборка робота](https://i9.ytimg.com/vi/AI0i8CaHVo8/mq2.jpg?sqp=CKTBiYEG&rs=AOn4CLAH-7QCzsSzRICPPAro3QAhZWz9Dw)](https://www.youtube.com/watch?v=AI0i8CaHVo8&list=PLPlEq5SS8JN62263Q4-hY7qEeuCIrCNkc&index=2)

## 4. Код настроечного скетча


