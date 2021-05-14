## Сборка примеров Google Test с установкой из менеджера пакетов Conan.

### Установка менеджера pip и менеджера пакетов Conan.
`sudo apt install pip`
`pip install conan`
`sudo reboot`

+ Выполнить команду в папке со сборкой(build, out):
  + Для первого вызова:
`conan install ../ -s build_type=Debug --build=gtest`. В случае ошибки необходимо подправить профиль для conan `.conan/profiles/default`:
```sh
[settings]
os=Linux
os_build=Linux
arch=x86_64
arch_build=x86_64
compiler=gcc
compiler.version=8
compiler.libcxx=libstdc++11
build_type=Release
[options]
[build_requires]
[env]
```
В профиле для conan нужно подправить компилятор `compiler=gcc`, его версию `compiler.version=8` и версию C++ `compiler.libcxx=libstdc++11`.

  + Для последующих вызовов:
`conan install ../ -s build_type=Debug`

### Примеры профилей для conan.
* GCC (ver. 9)
```sh
[settings]
os=Linux
os_build=Linux
arch=x86_64
arch_build=x86_64
compiler=gcc
compiler.version=9
compiler.libcxx=libstdc++11
build_type=Release
[options]
[build_requires]

[env]
CC=/usr/bin/gcc-9
CXX=/usr/bin/g++-9
```

* Clang (ver. 10)
```sh
[settings]
os=Linux
os_build=Linux
arch=x86_64
arch_build=x86_64
compiler=clang
compiler.version=10
compiler.libcxx=libstdc++11
build_type=Release
[options]
[build_requires]

[env]
CC=/usr/bin/clang-10
CXX=/usr/bin/clang++10
```

### Дополнительно.
* При установки библиотеки возможно потребуется зарегистироватся на
***https://bintray.com/bincrafters***

* Поменять пути в Conan командой
`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`

* Задать имя пользователя и API Key командой:
`conan user [User] -r bincrafters -p [API]`
User - Имя на bincrafters [API] - Ключ API.

* В файле ***conanfile.txt*** лежит информация в виде:
`gtest/1.8.1@bincrafters/stable`
С указанием на путь к библиотеке и её версии.
