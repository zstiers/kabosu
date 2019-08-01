pushd ..
conan config install https://github.com/zstiers/conan-config.git
mkdir .build
pushd .build
	conan install .. -g cmake_multi -s build_type=Release -e CONAN_IMPORT_PATH=Release --build=missing
	conan install .. -g cmake_multi -s build_type=Debug -e CONAN_IMPORT_PATH=Debug --build=missing
	cmake .. -DCMAKE_GENERATOR_PLATFORM=x64 -DCMAKE_CONFIGURATION_TYPES="Debug;Release"
popd
popd