## Сборка примеров Google Test с установкой из менеджера пакетов Conan.

### Установка менеджера pip, для установки менеджера пакетов Conan
`sudo apt install python3-pip`

### Установка менеджера пакетов Conan
`pip3 install conan`

### Установка Google Test
* Выполнить скрипт
`compile_googletest.sh`

* Выполнить команду в папке со сборкой(build, out)
`conan install ../ -s build_type=Debug`

### Дополнительно
* При установки библиотеки возможно потребуется зарегистироватся на
***https://bintray.com/bincrafters***

* Поменять пути в Conan командой
`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`

* Задать имя пользователя и API Key командой:
`conan user [User] -r bincrafters -p [API]`
User - Имя на bincrafters [API] - Ключ API.

* В файле ***conanfile.txt*** лежит информация в виде
`gtest/1.8.1@bincrafters/stable`
С указанием на путь к библиотеке и её версии.
