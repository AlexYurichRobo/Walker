# Сборка робота и настройка сервоприводов Walker

Двуногий шагающий робот Гуляка (Walker) задуман,как несложный проект в помощь для изучения С/С++, призваный приучить ориентироваться учащихся в громоздком коде, использовать циклы, и условныеоператоры, и составлять функции. В силу простоты конструкции платформа робота крайне доступна, а детали можно легко распечатать на 3д принтере.
Дляреализации движения шагами в различных направлениях достаточно 4 сервопривода. В последствии робота можно будет уложнять, расширяя его возможности и добавляя новые блоки кода.

![Alt+текст](https://avatars.mds.yandex.net/get-zen_doc/3384412/pub_5fad3c494278375e7ef5dc70_5fad462fc3975f5b3d26d954/scale_2400)

В возможности платформы робота заложено 3 уровня:
1. **Базовый**, для него потребуется минимум деталей. На его базе закрепляем навыки изнания поосновам Ардуино
2. **Расширенный**, дабавляются сервоприводы и датчики. Используются пользовательские библиотеки, и налаживается взаимосвязь с телефоном
3. **Продвинутый**. Добавляется верхний плечевой пояс, разбирается база обратнойкинематики, получаем навыкиработы с различными манипуляторами

## Базовый уровень

Основные элементы:
1. Arduino NANO
2. IO NANO shield (позже добавлю сравнение возможностей разных вариантов шилдов)
3. Сервоприводы MG90, 180 градусов
4. Источник питания (крона 9в, или аккумулятор не менее 7,4 в)
5. Штекер для подключения источника питания
6. [Корпус для деталей](https://www.thingiverse.com/thing:4651195)

