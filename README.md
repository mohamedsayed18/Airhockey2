### Air hockey
![](https://github.com/mohamedsayed18/Airhockey2/blob/master/playground.png)

#### Requirements
* box2d library
* SFML library
they can be installed using the [vcpkg](https://github.com/microsoft/vcpkg)

#### Running the environment with GUI
Know the vcpkg cmake for example run:<br/>
`./vcpkg integrate install`<br/>
copy the output<br/>
`CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/home/mohamed/vcpkg/scripts/buildsystems/vcpkg.cmake"`<br/>
to build the project
```
cmake -DCMAKE_TOOLCHAIN_FILE=/home/mohamed/vcpkg/scripts/buildsystems/vcpkg.cmake
make
./Vc_example
```