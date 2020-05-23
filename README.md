### Air hockey
![](https://github.com/mohamedsayed18/Airhockey2/blob/master/playground.png)<br/>
Applying coevolution startegy on Air hockey game. The environment was built using box2d and SFML. The coevolution algorithm was implemented in this [repo](git@github.com:snolfi/evorobotpy.git) 

#### Requirements
* box2d library
* SFML library<br/>
they can be installed using the [vcpkg](https://github.com/microsoft/vcpkg)

#### Running the environment with GUI
Know the vcpkg cmake for example run:<br/>
`./vcpkg integrate install`<br/>
Copy the output<br/>
`CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/home/mohamed/vcpkg/scripts/buildsystems/vcpkg.cmake"`<br/>
to build the project
```cmake -DCMAKE_TOOLCHAIN_FILE=/home/mohamed/vcpkg/scripts/buildsystems/vcpkg.cmake
make
./Vc_example
```

#### Training the robot
* Compile the environment `python3 setupErPredprey.py build_ext --inplace`
* Copy the .so file to bin/ `cp ErPredprey*.so ../bin`
* Training with random values `sudo python3 ../bin/es.py -f airhockey.ini -s 1 -t`

#### Contents
* predprey.cpp: Contain the function related to environment(step, reset, reward)
* airhockey.ini: specification of the network and training policy